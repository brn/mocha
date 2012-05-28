#ifndef mocha_file_watcher_inotify_impl_cc_
#define mocha_file_watcher_inotify_impl_cc_
#include <sys/inotify.h>
#include <string.h>
#include <vector>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/smart_pointer/common/ptr_handle.h>
#include <mocha/roaster/lib/unordered_map.h>

#define SETTINGS Setting::GetInstance()
namespace mocha {
#define ITERATOR(type,name1,name2) name1 = type.begin(),name2 = type.end()
#define ITERATOR_LOOP(name1,name2) while (name1 != name2)
#define ITERATOR_NEXT(name) ++name
#define GET(it) (*it)

////////////////////////////////////////////////
// Case have Inotify. To many case it's linux //
////////////////////////////////////////////////
/**
 * @private
 * @return {int} -> file descriptor
 * Open inotify fd.
 */
int OpenInotifyFD() {
  int fd = inotify_init();
  if (fd < 0) {
    fprintf(stderr ,"inotify_init fail.\n" );
    //SETTINGS->LogError("inotify_init fail.");
  }
  return fd;
}

class WatcherContainer {
 public :
  WatcherContainer(const char* path, int wd)
      : filename_(path),
        wd_(wd){};
  inline const char* GetFileName() const { return filename_.c_str(); }
  inline int GetWatchDescriptor() const { return wd_; }
 private :
  std::string filename_;
  int wd_;
};


FileWatcher::FileWatcher()
    : fd_(OpenInotifyFD()),
      is_watch_(true),
      is_end_(false){}

FileWatcher::~FileWatcher() {
  is_end_ = true;
  ::close(fd_);
  array_.clear();
}
  
void FileWatcher::AddWatch(const char* path) {
  os::fs::Stat stat(path);
  if (stat.IsExist()) {
    InotifyMask mask = IN_CLOSE_WRITE | IN_DELETE_SELF;
    int wd = inotify_add_watch(fd_, path, mask);
    Regist(path, wd);
    if (wd < 0) {
      fprintf(stderr, "Can not add watch for %s with event mask %ld.", path, mask);
      //      SETTINGS->LogFatal("Can not add watch for %s with event mask %ld.", path, mask);
    }
  }
}

void FileWatcher::UnWatch(const char* path) {
  WatchList::iterator iterator;
  for (iterator = watch_list_.begin(); iterator != watch_list_.end(); ++iterator) {
    if (strcmp(iterator->second->GetFileName(), path) == 0) {
      inotify_rm_watch(fd_, iterator->second->GetWatchDescriptor());
      watch_list_.erase(iterator->second->GetWatchDescriptor());
      break;
    }
  }
}

void FileWatcher::UnWatchAll() {
  watch_list_.clear();
}

void FileWatcher::Stop() {
  is_watch_ = false;
  watcher_notificator_.NotifyForKey(kStopWatch, WatcherEvent(WatcherEvent::kEnd));
}

void FileWatcher::End() {
  is_watch_ = false;
  is_end_ = true;
}

void FileWatcher::Start() {
  ProcessInotifyEvent_();
}
  
void FileWatcher::Regist(const char* path, int wd) {
  SharedPtr<WatcherContainer> handle(new WatcherContainer(path, updater, type, wd));
  watch_list_.insert(WatchPair(wd, handle));
}
  
void FileWatcher::ProcessInotifyEvent() {
  while (!is_end_) {
    if (is_watch_ && watch_list_.size() > 0) {
      if (CheckEvent()) {
        int read_event = ReadInotifyEvents_();
        if (read_event > 0) {
          ProcessEvent();
        }
      }
    } else {
      sleep(1);
    }
  }
  watcher_notificator_.NotifyForKey(kEndWatch, WatcherEvent(WatcherEvent::kEnd));
}


int FileWatcher::CheckEvent() {
  fd_set rfds;
  timeval waitval;
  waitval.tv_sec  = 0;
  waitval.tv_usec = 500;
  FD_ZERO(&rfds);
  FD_SET(fd_, &rfds);
  return ::select(FD_SETSIZE, &rfds, NULL, NULL, &waitval);
}


int FileWatcher::ReadInotifyEvents() {
  array_.clear();
  char buffer[ 16384 ];
  size_t buffer_i = 0;
  inotify_event *pevent;
  size_t read_size;
  size_t event_size;
  size_t q_event_size;
  int count = 0;
  read_size = ::read(fd_, buffer, 16384);
  if (read_size <= 0) {
    return 0;
  }
  while (buffer_i < read_size) {
    pevent = reinterpret_cast<inotify_event*>(&buffer[buffer_i]);
    event_size = offsetof(inotify_event, name) + pevent->len;
    q_event_size = offsetof(inotify_event, name) + pevent->len;
    inotify_event* ret = new inotify_event;
    memcpy(ret, pevent, event_size);
    SharedPtr<inotify_event> handle(ret);
    array_.push_back(handle);
    buffer_i += event_size;
    count++;
  }
  return count;
}

  
void FileWatcher::ProcessEvent() {
  EventArray::iterator ITERATOR(array_,begin,end);
  ITERATOR_LOOP(begin, end) {
    inotify_event *cont = (*begin).Get();
    int wd = cont->wd;
    WatchList::iterator find = watch_list_.find(wd);
    if (find != watch_list_.end() && !(GET(begin)->mask & IN_ISDIR)) {
      SwitchEvents((GET(begin)->mask & (IN_ALL_EVENTS | IN_UNMOUNT | IN_Q_OVERFLOW | IN_IGNORED)), find->second.Get());
    }
    ++begin;
  }
}
  
void FileWatcher::SwitchEvents(InotifyMask mask, WatcherContainer* container) {
  switch (mask) {
    case IN_CLOSE_WRITE :
      FileEvent event(container->GetFileName());
      file_notificator_.NotifyForKey(kModify, event);
      break;
    case IN_DELETE_SELF :
      FileEvent event(container->GetFileName());
      file_notificator_.NotifyForKey(kDelete, event);
      UnWatch(container->GetFileName());
      break;
  }
}

}
#endif
