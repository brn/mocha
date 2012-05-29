#include <mocha/roaster/platform/fs/event/linux/fs_watcher_linux.h>

namespace mohca { namespace os { namespace fs {
typedef unsigned long InotifyMask;
typedef SharedPtr<inotify_event> EventHandle;
typedef std::vector<EventHandle> EventArray;
class FSWatcherAsync {
 public :
  FSWatcherAsync()
      : is_exit_(false){};
  ~FSWatcherAsync(){}
  void Run() {
    int epfd;
    if((epfd = epoll_create(MAX_EVENTS)) < 0) {
      fprintf(stderr, "epoll_create()\\n");
      exit(1);
    }
    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    ev.events  = EPOLLIN | EPOLLET;
    ev.data.fd = fs_wathcer_->inotify_fd_;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, fs_wathcer_->inotify_fd_, &event) < 0) {
      fprintf(stderr, "epoll_ctl()\\n");
      exit(1);
    }
    int nfd, i;
    struct epoll_event events[MAX_EVENTS];
    while (!is_exit_) {
      nfd = epoll_wait(epfd, events, MAX_EVENTS, 2000);
      if(nfds < 0) {
        fprintf(stderr, "epoll_wait()\\n");
        exit(1);
      }
      EventArray event_array;
      int read_size = ReadInotifyEvents(&event_array);
      if (read_size > 0) {
        CheckEvent(&event_array);
      }
    }
  }
 private :
  int ReadInotifyEvents(EventArray* event_array) {
    char buffer[16384];
    size_t buffer_i = 0;
    inotify_event *pevent;
    size_t read_size;
    size_t event_size;
    size_t q_event_size;
    int count = 0;
    read_size = ::read(fs_wathcer_->inotify_fd_, buffer, 16384);
    if (read_size <= 0) {
      return 0;
    }
    while (buffer_i < read_size) {
      pevent = reinterpret_cast<inotify_event*>(&buffer[buffer_i]);
      event_size = offsetof(inotify_event, name) + pevent->len;
      q_event_size = offsetof(inotify_event, name) + pevent->len;
      inotify_event* ret = new inotify_event;
      memcpy(ret, pevent, event_size);
      EventHandle handle(ret);
      event_array->push_back(handle);
      buffer_i += event_size;
      count++;
    }
    return count;
  }
  void CheckEvent(EventArray* event_array) {
    EventArray::iterator it = event_array->begin();
    int wd = (*it)->wd;
    InotifyFDMap::iterator find = fs_wathcer_->fd_map_.find(wd);
    if (find != fs_wathcer_->fd_map_.end()) {
      FSEvent* e = find->second;
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
  void Exit() {
    is_exit_ = true;
  }
  bool IsExit() const {return is_exit_;}
  bool is_exit_;
};

FSWatcher::FSWatcher()
    : epoll_fd_(epoll_create(10)),
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
  InotifyMask mask = IN_CLOSE_WRITE | IN_DELETE_SELF;
  int wd = inotify_add_watch(inotify_fd_, abpath, mask);
  InotifyFDMap::iterator it = fd_map_.find(wd);
  if (it != fd_map_.end()) {
    FSEvent* event = new(&pool_) FSEvent(abpath);
    fd_map_.insert(InotifyFDPair(wd, event));
  }
}

void* FSWatcher::ThreadRunner(void* arg) {
  FSWatcherAsync* async = reinterpret_cast<FSWatcherAsync*>(arg);
  async->Run();
  return 0;
}

void FSWatcher::Run() {
  Thread thread;
  thread.Create(ThreadRunner, fs_watcher_async_.Get());
  thread.Join();
}

void FSWatcher::RunAsync() {
  Thread thread;
  thread.Create(ThreadRunner, fs_watcher_async_.Get());
  thread.Detach();
}

}}}
