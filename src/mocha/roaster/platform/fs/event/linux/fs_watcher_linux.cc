#include <string.h>
#include <sys/epoll.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/platform/fs/event/linux/fs_watcher_linux.h>
#include <mocha/roaster/platform/fs/event/event.h>
namespace mocha { namespace os { namespace fs {
static const int kMaxEvents = 10;
static InotifyMask mask = IN_CLOSE_WRITE | IN_DELETE_SELF | IN_MODIFY;

FSWatcher::FSWatcher()
    : is_exit_(false),
      epoll_fd_(epoll_create(10)),
      inotify_fd_(inotify_init()){}

FSWatcher::~FSWatcher() {
  ::close(inotify_fd_);
}

void FSWatcher::AddWatch(const char* path) {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  Stat stat(abpath);
  if (stat.IsExist() && stat.IsReg()) {
    Regist(abpath);
  }
}

void FSWatcher::RemoveWatch(const char* path) {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  Stat stat(abpath);
  if (stat.IsExist() && stat.IsReg()) {
    int wd = inotify_add_watch(inotify_fd_, abpath, mask);
    InotifyFDMap::iterator it = fd_map_.find(wd);
    if (it != fd_map_.end()) {
      inotify_rm_watch(wd, inotify_fd_);
      fd_map_.erase(it);
    }
  }
}

void FSWatcher::Regist(const char* abpath) {
  int wd = inotify_add_watch(inotify_fd_, abpath, mask);
  InotifyFDMap::iterator it = fd_map_.find(wd);
  if (it == fd_map_.end()) {
    FSEventHandle handle(new FSEvent(abpath, this));
    fd_map_.insert(InotifyFDPair(wd, handle));
  }
}

void* FSWatcher::ThreadRunner(void* arg) {
  FSWatcher* watcher = reinterpret_cast<FSWatcher*>(arg);
  watcher->Start();
  return 0;
}

void FSWatcher::Run() {
  Thread thread;
  thread.Create(ThreadRunner, this);
  thread.Join();
}

void FSWatcher::RunAsync() {
  Thread thread;
  thread.Create(ThreadRunner, this);
  thread.Detach();
}

void FSWatcher::Exit() {is_exit_ = true;}

void FSWatcher::Start() {
  is_exit_ = false;
  int epfd;
  if((epfd = epoll_create(kMaxEvents)) < 0) {
    fprintf(stderr, "epoll_create()\\n");
    exit(1);
  }
  struct epoll_event event;
  memset(&event, 0, sizeof(event));
  event.events  = EPOLLIN | EPOLLET;
  event.data.fd = inotify_fd_;
  if (epoll_ctl(epfd, EPOLL_CTL_ADD, inotify_fd_, &event) < 0) {
    fprintf(stderr, "epoll_ctl()\\n");
    exit(1);
  }
  int nfd;
  struct epoll_event events[kMaxEvents];
  while (!is_exit_) {
    nfd = epoll_wait(epfd, events, kMaxEvents, 2000);
    if(nfd < 0) {
      fprintf(stderr, "epoll_wait()\\n");
      exit(1);
    } else if (nfd > 0) {
      EventArray event_array;
      int read_size = ReadInotifyEvents(&event_array);
      if (read_size > 0) {
        CheckEvent(&event_array);
      }
    }
  }
}

int FSWatcher::ReadInotifyEvents(EventArray* event_array) {
  char buffer[16384];
  size_t buffer_i = 0;
  inotify_event *pevent;
  size_t read_size;
  size_t event_size;
  int count = 0;
  read_size = ::read(inotify_fd_, buffer, 16384);
  if (read_size <= 0) {
    return 0;
  }
  while (buffer_i < read_size) {
    pevent = reinterpret_cast<inotify_event*>(&buffer[buffer_i]);
    event_size = offsetof(inotify_event, name) + pevent->len;
    inotify_event* ret = new inotify_event;
    memcpy(ret, pevent, event_size);
    EventHandle handle(ret);
    event_array->push_back(handle);
    buffer_i += event_size;
    count++;
  }
  return count;
}

void FSWatcher::CheckEvent(EventArray* event_array) {
  EventArray::iterator it = event_array->begin();
  int wd = (*it)->wd;
  InotifyFDMap::iterator find = fd_map_.find(wd);
  printf("%d\n" , find != fd_map_.end());
  if (find != fd_map_.end()) {
    FSEvent* e = find->second.Get();
    if (e->IsExist()) {
      if (e->IsModified()) {
        NotifyForKey(kModify, e);
      }
      if (e->IsUpdate()) {
        NotifyForKey(kUpdate, e);
      }
    } else {
      if (e->IsModified()) {
        NotifyForKey(kDelete, e);
      }
    }
  }
}

const char FSWatcher::kModify[] = {"Modified<kqueue>"};
const char FSWatcher::kUpdate[] = {"Modified<update>"};
const char FSWatcher::kDelete[] = {"Delete<kqueue>"};

}}}
