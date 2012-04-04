#ifndef mocha_fs_event_wrap_h_
#define mocha_fs_event_wrap_h_
#include <time.h>
#include <uv.h>
#include <string.h>
#include <string>
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/platform/thread/thread.h>
namespace mocha {
typedef std::string FileEntry;
typedef std::pair<FileEntry, uv_fs_event_t*> WatchPair;
typedef roastlib::unordered_map<FileEntry, uv_fs_event_t*> WatchList;
typedef uv_fs_event_t UvEvent;
typedef uv_idle_t UvIdle;
typedef uv_idle_cb UvIdleCb;
typedef uv_fs_cb UvFSCb;
class WatcherContainer;
class FileWatcher;
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
struct Info;
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
  void Initialize();
  void Regist(const char* path);
  void ProcessNotification();
  void AddToWatchList(const char* path);
  void BeginIdle();
  void WatchFile();
  void UnWatchEach(WatchList::iterator& it);
  void CheckPool();
  int stop_flag_;
  uv_fs_event_t event_;
  uv_loop_t* loop_;
  memory::Pool* pool_;
  WatchList watch_list_;
  Notificator<FileEvent> file_notificator_;
  Notificator<WatcherEvent> watcher_notificator_;
  static os::Mutex mutex_;
};


}

#endif
