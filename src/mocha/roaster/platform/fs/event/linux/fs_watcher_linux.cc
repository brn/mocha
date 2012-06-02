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
  Exit();
  ::close(inotify_fd_);
}

void FSWatcher::AddWatch(const char* path) {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  Stat stat(abpath);
  if (stat.IsExist() && stat.IsReg()) {
    ScopedLock lock(mutex_);
    Regist(abpath);
  }
}

void FSWatcher::RemoveWatch(const char* path) {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  Stat stat(abpath);
  if (stat.IsExist() && stat.IsReg()) {
    ScopedLock lock(mutex_);
    int wd = inotify_add_watch(inotify_fd_, abpath, mask);
    InotifyFDMap::iterator it = fd_map_.find(wd);
    if (it != fd_map_.end()) {
      inotify_rm_watch(wd, inotify_fd_);
      fd_map_.erase(it);
    }
  }
}

void FSWatcher::RemoveWatch() {
  ScopedLock lock(mutex_);
  InotifyFDMap::iterator it = fd_map_.begin();
  for (; it != fd_map_.end(); ++it) {
    inotify_rm_watch(it->first, inotify_fd_);
  }
  fd_map_.clear();
}

bool FSWatcher::IsWatched(const char* path) const {
  Path path_info(path);
  const char* abpath = path_info.absolute_path();
  int wd = inotify_add_watch(inotify_fd_, abpath, mask);
  InotifyFDMap::const_iterator it = fd_map_.find(wd);
  if (it != fd_map_.end()) {
    return true;
  }
  inotify_rm_watch(wd, inotify_fd_);
  return false;
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

void FSWatcher::Exit() {
  is_exit_ = true;
  ScopedLock lock(mutex_);
}

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
    if (nfd > 0) {
      ScopedLock lock(mutex_);
      ReadInotifyEvents();
    }
  }
}

void FSWatcher::ReadInotifyEvents() {
  int i = 0;
  int aux = 0;
  int ret = 0;
  char name_buf[PATH_MAX];
  char buffer[65536];
reread:
  ret = read(inotify_fd_, buffer + aux, sizeof(buffer) - aux);
  if (ret == -1) {
    if (ret == -EINTR) {
      goto reread;
    }
    perror("read");
    exit(EXIT_FAILURE);
  }
  ret += aux;
  int in_size = (sizeof(struct inotify_event));
  if (ret < in_size) {
      fprintf(stderr, "short of red bytes\n");
      exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < ret) {
      struct inotify_event *inotify_p;
      inotify_p = (struct inotify_event *)(buffer + i);
      if (ret < i + offsetof(struct inotify_event, name)) {
        aux = ret - i;
        memmove(buffer, buffer + i, aux);
        goto reread;
      }
      int size = sizeof(struct inotify_event) + inotify_p->len;
      if (ret < i + size) {
        aux = ret - i;
        memmove(buffer, buffer + i, aux);
        goto reread;                
      }
      CheckEvent(inotify_p);
      i += size;
    }
    }

void FSWatcher::CheckEvent(InotifyEvent* ev) {
  int wd = ev->wd;
  InotifyFDMap::iterator find = fd_map_.find(wd);
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

const char FSWatcher::kModify[] = {"Modified<inotify>"};
const char FSWatcher::kUpdate[] = {"Update<inotify>"};
const char FSWatcher::kDelete[] = {"Delete<inotify>"};

}}}
