#ifndef mocha_misc_file_watcher_watcher_server_h_
#define mocha_misc_file_watcher_watcher_server_h_
#include <mocha/misc/file_watcher/fs_event_wrap.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/notificator/notificator.h>
namespace mocha {
class WatcherServerEvent {
 public :
  WatcherServerEvent(const char* name)
      : name_(name){}
  const char* name() {return name_;}
 private :
  const char* name_;
};

class WatcherProxy : public memory::Allocated {
 public :
  WatcherProxy(const char* name)
      : name_(name){}
  ~WatcherProxy(){}
  FileWatcher* watcher() {return &watcher_;}
  void Enter() {is_run_ = true;}
  bool IsEntered() const {return is_run_;}
  void Escape() {is_run_ = false;}
  const char* name() const {return name_.c_str();}
 private :
  bool is_run_;
  std::string name_;
  FileWatcher watcher_;
};

class WatcherServer : public Notificator<WatcherServerEvent>{
  typedef roastlib::unordered_map<std::string, WatcherProxy*> Watchers;
 public :
  static WatcherServer* GetInstance() {return &instance_;}
  ~WatcherServer(){}
  void AddWatcher(const char* watcher_name);
  void RemoveWatcher(const char* watcher_name);
  WatcherProxy* GetWatcherProxy(const char* name);
  bool HasWatcher(const char* name);
  void Run(const char* name);
  void RunAll();
  void ExitWatcher(const char* name);
  static const char kEnd[];
  static const char kStop[];
 private :
  WatcherServer();
  void RunThread(FileWatcher* watcher);
  Watchers watchers_;
  memory::Pool pool_;
  static WatcherServer instance_;
  static os::Mutex mutex_;
};
}

#endif
