#include <fcntl.h>
#include <sys/types.h>
#include <sys/event.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/platform/fs/event/macos/kqueue.h>
#include <mocha/roaster/platform/fs/event/macos/fs_handle.h>

namespace mocha {
namespace os {
namespace fs {

class AsyncFSWatcher {
  friend class FSWatcher;
 public :
  AsyncFSWatcher(FSWatcher* fs_watcher)
      : is_exit_(true),
        fs_watcher_(fs_watcher){}
  ~AsyncFSWatcher(){}
  void Run() {
    is_exit_ = false;
    int kq = kqueue();
    memory::Pool pool;
    std::vector<struct kevent> events;
    FSWatcher::FSEventMap::iterator it = fs_watcher_->map_.begin();
    int vnode_events = NOTE_DELETE |  NOTE_WRITE;
    for (; it != fs_watcher_->map_.end(); ++it) {
      struct kevent kev;
      EV_SET(&kev, it->second->handle()->fd(), EVFILT_VNODE, EV_ADD | EV_CLEAR, vnode_events, 0, it->second);
      events.push_back(kev);
    }
    struct kevent *event_data = pool.Alloc<struct kevent>(sizeof(struct kevent) * events.size());
    struct timespec tspec;
    tspec.tv_sec = 2;
    tspec.tv_nsec = 0;
    while (!is_exit_) {
      int ev_count = kevent(kq, &events[0], events.size(), event_data, events.size(), &tspec);
      if (ev_count > 0) {
        for( int i = 0; i < ev_count; i++) {
          FSEvent* e = reinterpret_cast<FSEvent*>(event_data[i].udata);
          if (e->IsExist()) {
            if (e->IsModified()) {
              fs_watcher_->NotifyForKey(fs_watcher_->kModifiy, e);
            }
            if (e->IsUpdate()) {
              fs_watcher_->NotifyForKey(fs_watcher_->kUpdate, e);
            }
          } else {
            if (e->IsModified()) {
              fs_watcher_->NotifyForKey(fs_watcher_->kDelete, e);
            }
          }
        }
      }
    }
  }
  void Exit() {is_exit_ = true;}
 private :
  bool is_exit_;
  FSWatcher* fs_watcher_;
};

void* FSWatcher::ThreadRunner(void* param) {
  AsyncFSWatcher* async = reinterpret_cast<AsyncFSWatcher*>(param);
  async->Run();
  return NULL;
}

FSWatcher::FSWatcher() {
  async_fs_watcher_(new AsyncFSWatcher(this));
}
FSWatcher::~FSWatcher() {
  Exit();
}

void FSWatcher::AddWatch(const char* path) {
  FSEvent* e = new(&pool_) FSEvent(path, this);
  map_.insert(FSEventPair(path, e));
}

void FSWatcher::RemoveWatch(const char* path) {
  FSEventMap::iterator find = map_.find(path);
  if (find != map_.end()) {
    find->second->Close();
    map_.erase(find);
  }
}

void FSWatcher::Exit() {
  async_fs_watcher_->is_exit_ = true;
  FSEventMap::iterator it = map_.begin();
  for (; it != map_.end(); ++it) {
    it->second->Close();
  }
}

void FSWatcher::Run() {
  Thread thread;
  thread.Create(ThreadRunner, async_fs_watcher_.Get());
  thread.Join();
}

bool FSWatcher::IsRunning() const {
  return !async_fs_watcher_->is_exit_;
}

void FSWatcher::RunAsync() {
  async_fs_watcher_->is_exit_ = false;
  Thread thread;
  thread.Create(ThreadRunner, async_fs_watcher_.Get());
  thread.Detach();
}

const char FSWatcher::kModify[] = {"Modified<kqueue>"};
const char FSWatcher::kUpdate[] = {"Modified<update>"};
const char FSWatcher::kDelete[] = {"Delete<kqueue>"};
}
}
}
