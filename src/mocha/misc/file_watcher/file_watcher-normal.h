#ifndef mocha_file_watcher_file_watcher_normal_h_
#define mocha_file_watcher_file_watcher_normal_h_
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>

namespace mocha {
class FileEvent {
 public :
  FileEvent(const char* filename)
      : filename_(filename){}
  ~FileEvent(){}
  const char* filename() const {return filename_;};
  static const char kModify[];
  static const char kDelete[];
 private :
  const char* filename_;
};

class WatcherEvent {
 public :
  enum {
    kStop,
    kEnd
  };
  WatcherEvent(int type)
      : type_(type){}
  static const char kEndWatch[];
  static const char kStopWatch[];
 private :
  int type_;
};

class WatcherContainer {
 public :
  WatcherContainer(const char* path)
      : filename_(path) {
    os::fs::Stat stat(path);
    date_ = stat.MTime();
  }
  WatcherContainer(){}
  WatcherContainer(const WatcherContainer& container) {
    filename_ = container.filename_;
    date_ = container.date_;
  }
  inline const char* GetDate() { return date_.c_str(); }
  inline void SetDate(const char* date) { date_ = date; }
  inline const char* GetFileName() { return filename_.c_str(); }
 private :
  std::string filename_;
  std::string date_;
};

class FileWatcher {
 public :
  FileWatcher();
  ~FileWatcher();
  void AddWatch(const char* path);
  void UnWatch(const char* path);
  template <typename T>
  void AddFileEventListener(const char* type, T listener) {
    file_notificator_.AddListener(type, listener);
  }
  template <typename T>
  void AddWatcherEventListener(const char* type, T listener) {
    watcher_notificator_.AddListener(type, listener);
  }
  void UnWatchAll();
  void Stop();
  void Start();
  void Exit();
 private :
  typedef std::string FileEntry;
  typedef roastlib::unordered_map<FileEntry, WatcherContainer> WatchList;
  void Regist(const char* path);
  void AddToWatchList(const char* path);
  void ProcessNotification();
  void WatchFile();
  void UnWatchEach(WatchList::iterator& it);
  bool is_stop_;
  bool is_end_;
  WatchList watch_list_;
  Notificator<FileEvent> file_notificator_;
  Notificator<WatcherEvent> watcher_notificator_;
  class PtrImpl;
  PtrImpl* implementation_;
};

}
#endif
