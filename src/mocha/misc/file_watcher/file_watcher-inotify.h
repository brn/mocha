#ifndef mocha_file_watcher_inotify_h_
#define mocha_file_watcher_inotify_h_
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>

namespace mocha {
class FileEvent {
 public :
  FileEvent(const char* filename);
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

class WatcherContainer;

class FileWatcher {
  typedef std::vector<SharedPtr<inotify_event> > EventArray;
  typedef std::pair<int,SharedPtr<WatcherContainer> > WatchPair;
  typedef roastlib::unordered_map<int,SharedPtr<WatcherContainer> > WatchList;
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
  typedef unsigned long InotifyMask;
  typedef std::string FileEntry;
  typedef roastlib::unordered_map<FileEntry, WatcherContainer> WatchList;
  void Regist(const char* path, int wd)
  void ProcessInotifyEvent()
  int CheckEvent()
  int ReadInotifyEvents();
  void ProcessEvent();
  void SwitchEvents(InotifyMask mask, WatcherContainer* container);
  int fd_;
  bool is_watch_;
  bool is_end_;
  WatchList watch_list_;
  EventArray array_;
  Notificator<FileEvent> file_notificator_;
  Notificator<WatcherEvent> watcher_notificator_;
  class PtrImpl;
  PtrImpl* implementation_;
};

}
#include <mocha/misc/file_watcher/file_watcher-inotify-impl.h>
#endif
