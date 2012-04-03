#ifndef mocha_misc_file_watcher_file_watcher_normal_impl_h_
#define mocha_misc_file_watcher_file_watcher_normal_impl_h_
#include <stdio.h>
#include <string.h>
#include <mocha/options/setting.h>
#include <mocha/misc/file_watcher/fs_event_wrap.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

namespace mocha {
class WatcherContainer : private Uncopyable {
 public :
  WatcherContainer(const char* path)
      : filename_(path) {
    os::fs::Stat stat(path);
    date_ = stat.MTime();
  }
  ~WatcherContainer(){}
  inline const char* GetDate() { return date_.c_str(); }
  inline void SetDate(const char* date) { date_ = date; }
  inline const char* GetFileName() { return filename_.c_str(); }
 private :
  std::string filename_;
  std::string date_;
};

class EventInfo : public memory::Allocated {
 public :
  EventInfo(const char* filename, Notificator<FileEvent>* e)
      : close_(1),
        filename_(filename),
        notificator_(e),
        container_(filename) {}
  const char* filename() const {return filename_.c_str();}
  WatcherContainer* container() {return &container_;}
  Notificator<FileEvent>* notificator() {return notificator_;}
  uv_fs_event_t* event() {return &event_;}
  void set_close() {close_ = 0;}
  int close() {return close_;}
 private :
  int close_;
  std::string filename_;
  Notificator<FileEvent> *notificator_;
  WatcherContainer container_;
  uv_fs_event_t event_;
};

extern "C" {
  static void CloseCb(uv_handle_t* handle){};
  static void FileModifiedCallback(uv_fs_event_t* handle, const char* fname,
                                   int events, int status) {
    //uv_unref(handle->loop);
    EventInfo* info = static_cast<EventInfo*>(handle->data);
    if (info->close() == 1) {
      const char* filename = info->filename();
      os::fs::Stat stat(filename);
      bool is_exist = stat.IsExist();
      if (is_exist) {
        WatcherContainer* container = info->container();
        if (strcmp(stat.MTime(), container->GetDate()) != 0) {
          container->SetDate(stat.MTime());
          info->notificator()->NotifyForKey(FileEvent::kModify, FileEvent(filename));
        }
      } else {
        info->notificator()->NotifyForKey(FileEvent::kDelete, FileEvent(filename));
        uv_close(reinterpret_cast<uv_handle_t*>(handle), CloseCb);
      }
    } else {
		uv_unref(handle->loop);
      //uv_close(reinterpret_cast<uv_handle_t*>(handle), CloseCb);
    }
  }
}

FileWatcher::FileWatcher()
    : stop_flag_(0),
      pool_(NULL){ Initialize();}

FileWatcher::~FileWatcher() {
  stop_flag_ = 2;
  watch_list_.clear();
}

void FileWatcher::AddWatch(const char* path) {
  Regist(path);
}

void FileWatcher::UnWatch(const char* path) {
  WatchList::iterator find = watch_list_.find(path);
  if (find != watch_list_.end()) {
    UnWatchEach(find);
  }
}

void FileWatcher::UnWatchAll() {
  watch_list_.clear();
}

void FileWatcher::Stop() {
  stop_flag_ = 1;
}

void FileWatcher::Start() {
  ProcessNotification();
}

void FileWatcher::Exit() {
  WatchList::iterator it = watch_list_.begin();
  const char* tmp = Setting::GetInstance()->GetTmpFile();
  for (; it != watch_list_.end(); ++it) {
    EventInfo* info = static_cast<EventInfo*>((it->second->data));
    info->set_close();
    const char* filename = info->filename();
    printf("%s\n", filename);
    if (strcmp(filename, tmp) != 0) {
      os::fs::Stat stat(filename);
      if (stat.IsExist()) {
        //uv_close(reinterpret_cast<uv_handle_t*>(it->second), CloseCb);
		  uv_unref(loop_);
      }
    }
  }
  EventInfo* info = static_cast<EventInfo*>(watch_list_.find(tmp)->second->data);
  info->set_close();
  const char* filename = info->filename();
  os::Utime(filename);
  stop_flag_ = 2;
}

void FileWatcher::Initialize() {
  CheckPool();
  loop_ = uv_default_loop();
}

void FileWatcher::Regist(const char* path) {
  os::fs::Stat stat(path);
  if (stat.IsExist()) {
    AddToWatchList(path);
  }
}

void FileWatcher::AddToWatchList(const char* path) {
  os::fs::Stat stat(path);
  CheckPool();
  if (stat.IsExist() && stat.IsReg()) {
    os::fs::Path path_info(path);
    const char* fullpath = path_info.absolute_path();
    if (watch_list_.find(fullpath) == watch_list_.end()) {
      EventInfo* info = new(pool_) EventInfo(fullpath, &file_notificator_);
      uv_fs_event_t* event = info->event();
      event->data = static_cast<void*>(info);
      watch_list_.insert(WatchPair(fullpath, event));
      int result =
          uv_fs_event_init(loop_, event,
                           fullpath, FileModifiedCallback, 0);
    }
  }
}

void FileWatcher::ProcessNotification() {
  AddToWatchList(Setting::GetInstance()->GetTmpFile());
  uv_run(loop_);
  const char* name = (stop_flag_ == 1)? WatcherEvent::kStopWatch : WatcherEvent::kEndWatch;
  int type = (stop_flag_ == 1)? WatcherEvent::kStop : WatcherEvent::kEnd;
  watcher_notificator_.NotifyForKey(name, WatcherEvent(type));
}


void FileWatcher::CheckPool() {
  if (pool_ == NULL) {
    os::ScopedLock lock(mutex_);
    if (pool_ == NULL) {
      pool_ = new memory::Pool;
    }
    lock.Unlock();
  }
}

void FileWatcher::UnWatchEach(WatchList::iterator& it) { watch_list_.erase(it); }
const char FileEvent::kModify[] = {"FileEvent<Modify>"};
const char FileEvent::kDelete[] = {"FileEvent<Delete>"};
const char WatcherEvent::kEndWatch[] = {"WatcherEvent<End>"};
const char WatcherEvent::kStopWatch[] = {"WatcherEvent<Stop>"};
os::Mutex FileWatcher::mutex_;
}
#endif
