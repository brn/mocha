#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/event.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/macos/fs_watcher_macos.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
namespace mocha {
namespace os {
namespace fs {
static const int kExit = 0;
static const int kSync = 1;
static const int kAsync = 2;
static const int kStop = 3;
static const int vnode_events = NOTE_DELETE |  NOTE_WRITE;
typedef struct kevent KEvent;
class FSEventData {
 public :
  FSEventData(int fd, FSEvent* fs_event)
      : fd_(fd),
        fs_event_(fs_event){}
  int fd() const {return fd_;}
  FSEvent* fs_event() {return fs_event_.Get();}
  KEvent* kevent() {return &kevent_;}
 private :
  int fd_;
  ScopedPtr<FSEvent> fs_event_;
  KEvent kevent_;
};

void* FSWatcher::ThreadRunner(void* param) {
  FSWatcher* watcher = reinterpret_cast<FSWatcher*>(param);
  watcher->Start();
  return NULL;
}

FSWatcher::FSWatcher() :
    kq_(kqueue()){ flags_.Set(kExit);}

FSWatcher::~FSWatcher() {
  flags_.Set(kExit);
  RemoveWatch();
}

int FSWatcher::GetState() {
  return (flags_.At(kSync))? kSync : (flags_.At(kAsync))? kAsync : kStop;
}

bool FSWatcher::AddWatch(const char* path) {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  Stat stat(abpath);
  if (stat.IsExist() && stat.IsReg()) {
    int state = GetState();
    Exit();
    ScopedLock lock(mutex_);
    FSEventMap::iterator find = map_.find(path);
    if (find == map_.end()) {
      int fd = ::open(abpath, O_EVTONLY);
      if (fd > -1) {
        FSEventDataHandle fs_event_data(new FSEventData(fd, new FSEvent(abpath, this)));
        KEvent* event = fs_event_data->kevent();
        EV_SET(event, fd, EVFILT_VNODE, EV_ADD | EV_CLEAR, vnode_events, 0, fs_event_data->fs_event());
        map_.insert(FSEventPair(abpath, fs_event_data));
        if (state == kSync) {
          Run();
        } else if (state == kAsync) {
          RunAsync();
        }
        return true;
      }
    }
  }
  return false;
}

bool FSWatcher::RemoveWatch(const char* path) {
  FSEventMap::iterator find = map_.find(path);
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  Stat stat(abpath);
  if (stat.IsExist() && stat.IsReg()) {
    if (find != map_.end()) {
      int state = GetState();
      Exit();
      ScopedLock lock(mutex_);
      ::close(find->second->fd());
      map_.erase(abpath);
      if (state == kSync) {
        Run();
      } else if (state == kAsync) {
        RunAsync();
      }
      return true;
    }
  }
  return false;
}

void FSWatcher::RemoveWatch() {
  Exit();
  ScopedLock lock(mutex_);
  FSEventMap::iterator it = map_.begin();
  for (; it != map_.end(); ++it) {
    ::close(it->second->fd());
  }
  map_.clear();
}

bool FSWatcher::IsWatched(const char* path) {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  FSEventMap::iterator find = map_.find(path);
  return find != map_.end();
}

void FSWatcher::Exit() {
  flags_.Set(kExit);
  flags_.UnSet(kSync);
  flags_.UnSet(kAsync);
}

bool FSWatcher::Run() {
  if (flags_.At(kExit)) {
    flags_.Set(kSync);
    Thread thread;
    if (!thread.Create(ThreadRunner, this)) {
      return false;
    }
    thread.Join();
    return true;
  } else {
    return false;
  }
}

bool FSWatcher::IsRunning() const {
  return !flags_.At(kExit);
}

bool FSWatcher::RunAsync() {
  if (flags_.At(kExit)) {
    flags_.Set(kAsync);
    Thread thread;
    if (!thread.Create(ThreadRunner, this)) {
      return false;
    }
    thread.Detach();
    return true;
  }
  return false;
}

void FSWatcher::Start() {
  ScopedLock lock(mutex_);
  flags_.UnSet(kExit);
  memory::Pool pool;
  std::vector<struct kevent> events;
  FSEventMap::iterator it = map_.begin();
  for (; it != map_.end(); ++it) {
    events.push_back(*(it->second->kevent()));
  }
  struct kevent *event_data = pool.Alloc<struct kevent>(sizeof(struct kevent) * events.size());
  struct timespec tspec;
  tspec.tv_sec = 2;
  tspec.tv_nsec = 0;
  while (!flags_.At(kExit)) {
    int ev_count = kevent(kq_, &events[0], events.size(), event_data, 1, &tspec);
    if (ev_count > 0) {
      for( int i = 0; i < ev_count; i++) {
        FSEvent* e = reinterpret_cast<FSEvent*>(event_data[i].udata);
        if (e->IsExist()) {
          if (e->IsModified()) {
            NotifyForKey(FSWatcher::kModify, e);
          }
          if (e->IsUpdate()) {
            NotifyForKey(FSWatcher::kUpdate, e);
          }
        } else {
          if (e->IsModified()) {
            NotifyForKey(FSWatcher::kDelete, e);
          }
        }
      }
    }
  }
}

const char FSWatcher::kModify[] = {"Modified<kqueue>"};
const char FSWatcher::kUpdate[] = {"Update<kqueue>"};
const char FSWatcher::kDelete[] = {"Delete<kqueue>"};
}
}
}
