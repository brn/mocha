#include <stdio.h>
#include <string.h>
#include <mocha/roaster/roaster.h>
#ifdef PLATFORM_WIN32
#include <windows.h>
#define sleep(time) Sleep(time##000)
#endif
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/misc/file_watcher/file_watcher.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#define SETTINGS Setting::GetInstance()
#define GET_MASK(mask) (type & mask) == mask
#define ITERATOR(name) begin = name.begin(),end = name.end();

namespace mocha {


class WatcherContainer {
 public :
  WatcherContainer(const char* path, IUpdater* updater, int type) :
      type_(type),  updater_(updater) {
    filename_ = path;
    os::fs::Stat stat(path);
    date_ = stat.MTime();
  }
  WatcherContainer(){}
  WatcherContainer(const WatcherContainer& container) {
    type_ = container.type_;
    filename_ = container.filename_;
    date_ = container.date_;
    updater_ = container.updater_;
  }
  inline const char* GetDate() { return date_.c_str(); }
  inline void SetDate(const char* date) { date_ = date; }
  inline const char* GetFileName() { return filename_.c_str(); }
  inline IUpdater* GetUpdater() { return updater_; }
 private :
  int type_;
  std::string filename_;
  std::string date_;
  IUpdater *updater_;
};

class FileWatcher::PtrImpl {
 public :
  inline PtrImpl() : is_stop_(false), is_end_(false), is_call_back_(false) {}
  inline ~PtrImpl(){
    is_stop_ = true;
    is_end_ = true;
    watch_list_.clear();
  }

  inline void AddWatch(const char* path, IUpdater *updater, int type) {
    Regist_(path, updater, type);
  }

  inline void UnWatch(const char* path) {
    WatchList::iterator find = watch_list_.find(path);
    if (find != watch_list_.end()) {
      UnWatch_(find);
    }
  }

  inline void UnWatchAll() {
    watch_list_.clear();
  }

  inline void Stop() {
    is_stop_ = true;
  }

  inline void Start() {
    ProcessNotification_();
  }

  inline void End() {
    is_stop_ = true;
    is_end_ = true;
  }
  
  inline void End(FileWatcher::EndCallBack fn, void* arg) {
    is_call_back_ = true;
    arg_ = arg;
    fn_ = fn;
    End();
  }

 private :
  typedef std::string FileEntry;
  typedef roastlib::unordered_map<FileEntry, WatcherContainer> WatchList;

  inline void Regist_(const char* path, IUpdater *updater, int type) {
    os::fs::Stat stat(path);
    if (stat.IsExist()) {
      AddToWatchList_(path, updater, type);
    }
  }

  inline void AddToWatchList_(const char* path, IUpdater *updater, int type) {
    WatcherContainer watcherContainer(path,  updater, type);
    watch_list_[ path ] = watcherContainer;
  }

  inline void ProcessNotification_() {
    while (!is_end_) {
      if (!is_stop_ && watch_list_.size() > 0) {
        WatchFile_();
      }
      sleep(1);
    }
    if (is_call_back_) {
      fn_(arg_);
    }
  }


  void WatchFile_() {
    WatchList::iterator ITERATOR(watch_list_);
    int len = watch_list_.size(),count = 0;
    while (begin != end && count < len) {
      WatcherContainer* container = &((*begin).second);
      const char* filename = container->GetFileName();
      const char* date = container->GetDate();
      os::fs::Stat stat(filename);
      const char* last_date = stat.MTime();
      if (stat.IsExist()) {
        if (strcmp(date, last_date) != 0) {
          container->SetDate(last_date);
          watch_traits::Modify modify(filename);
          container->GetUpdater()->Update(&modify);
        }
      } else {
        watch_traits::DeleteSelf missing(filename);
        container->GetUpdater()->Update(&missing);
      }
      ++begin;
      count++;
    }
  }

  inline void UnWatch_(WatchList::iterator& it) { watch_list_.erase(it); }

  bool is_stop_;
  bool is_end_;
  bool is_call_back_;
  void* arg_;
  FileWatcher::EndCallBack fn_;
  WatchList watch_list_;
};

}
