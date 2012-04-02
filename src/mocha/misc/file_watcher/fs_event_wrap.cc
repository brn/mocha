#ifndef mocha_misc_file_watcher_file_watcher_normal_impl_h_
#define mocha_misc_file_watcher_file_watcher_normal_impl_h_
#include <stdio.h>
#include <string.h>
#include <mocha/misc/file_watcher/fs_event_wrap.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

namespace mocha {
class FsMediator {
 public :
  typedef FileWatcher::WatchList WatchList;
  FsMediator(FileWatcher* watcher)
      : watcher_(watcher){}
  ~FsMediator(){}
  int WatcherFlag() const { return watcher_->stop_flag_;}
  Notificator<FileEvent>* file_notificator() {return &(watcher_->file_notificator_);}
  Notificator<WatcherEvent>* watcher_notificator() {return &(watcher_->watcher_notificator_);}
  FileWatcher::WatchList* watch_list() {return &(watcher_->watch_list_);}
  uv_loop_t* uv_loop() {return watcher_->loop_;}
  void Exit() {
    delete watcher_->pool_;
    watcher_->pool_ = NULL;
    watcher_->watch_list_.clear();
  }
 private :
  FileWatcher* watcher_;
};

class WatcherContainer : private Uncopyable {
 public :
  WatcherContainer(const char* path, FsMediator* mediator, uv_fs_event_t* e)
      : filename_(path),
        event_(e){
    os::fs::Stat stat(path);
    date_ = stat.MTime();
  }
  ~WatcherContainer(){}
  inline const char* GetDate() { return date_.c_str(); }
  inline void SetDate(const char* date) { date_ = date; }
  inline const char* GetFileName() { return filename_.c_str(); }
  inline UvEvent* uv_event() {return event_;}
 private :
  std::string filename_;
  std::string date_;
  UvEvent *event_;
};

extern "C" {
  static void IdleCallback(UvIdle* uv_idle, int status) {
    FsMediator* mediator = static_cast<FsMediator*>(uv_idle->data);
    os::Sleep(500);
    if (mediator->WatcherFlag() == 2) {
      uv_unref(mediator->uv_loop());
      mediator->Exit();
    }
  }

  static void CloseCb(uv_handle_t* handle){};

  static void FileModifiedCallback(uv_fs_event_t* handle, const char* filename,
                                   int events, int status) {
    printf("!!!!!!!!!!!!!!!!\n");
    FsMediator* mediator = static_cast<FsMediator*>(handle->data);
    FsMediator::WatchList::iterator it = mediator->watch_list()->find(filename);
    os::fs::Stat stat(filename);
    if (mediator->watch_list()->end() != it && stat.IsExist()) {
      WatcherContainer* container = it->second;
      if (strcmp(stat.MTime(), container->GetDate()) != 0) {
        container->SetDate(stat.MTime());
        mediator->file_notificator()->NotifyForKey(FileEvent::kModify, FileEvent(filename));
      }
    } else {
      mediator->file_notificator()->NotifyForKey(FileEvent::kDelete, FileEvent(filename));
      uv_close(reinterpret_cast<uv_handle_t*>(handle), CloseCb);
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
  stop_flag_ = 2;
}

void FileWatcher::Initialize() {
  CheckPool();
  loop_ = uv_default_loop();
  uv_idle_init(loop_, &uv_idle_);
  mediator_ = new(pool_) FsMediator(this);
  event_.data = mediator_;
  uv_idle_.data = mediator_;
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
    if (watch_list_.find(path_info.absolute_path()) == watch_list_.end()) {
      WatcherContainer *watcher_container = new(pool_) WatcherContainer(path, mediator_, &event_);
        
      watch_list_.insert(WatchPair(path_info.absolute_path(), watcher_container));
      printf("!!!!!!!!!!%s\n", path_info.absolute_path());
      int result =
          uv_fs_event_init(loop_, &event_,
                           path_info.absolute_path(), FileModifiedCallback, 0);
      //uv_unref(loop_);
    }
  }
}

void FileWatcher::ProcessNotification() {
  BeginIdle();
  uv_run(loop_);
  const char* name = (stop_flag_ == 1)? WatcherEvent::kStopWatch : WatcherEvent::kEndWatch;
  int type = (stop_flag_ == 1)? WatcherEvent::kStop : WatcherEvent::kEnd;
  watcher_notificator_.NotifyForKey(name, WatcherEvent(type));
}


void FileWatcher::BeginIdle() {
  uv_idle_start(&uv_idle_, &IdleCallback);
  //uv_ref(loop_);
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
