#ifndef mocha_file_watcher_observer_javascript_observer_h_
#define mocha_file_watcher_observer_javascript_observer_h_
#include <string>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
class WatcherProxy;
class JavascriptObserver {
  class ModifyCallback;
  class DeleteCallback;
  class WatcherCallBack;
  class Updater;
  friend class ModifyCallback;
  friend class DeleteCallback;
  friend class WatcherCallback;
  friend class Updater;
  typedef SharedPtr<os::Mutex> MutexHandle;
  typedef roastlib::unordered_map<std::string, MutexHandle> MutexMap;
  typedef roastlib::unordered_multimap<std::string, std::string> DependsMap;
  typedef roastlib::unordered_map<std::string, bool> FileList;
 public :
  JavascriptObserver();
  ~JavascriptObserver(){}
  void Run();
  void AddFile(const char* filename);
  void RemoveFile(const char* filename);
  void Exit();
  void Stop();
  void Resume();
  bool IsRunning() const {return running_;}
  static const char* name() {return server_name_;}
 private :
  void Intialize();
  void AddFileToWatcher(const char* filename, WatcherProxy* proxy);
  static const char server_name_[];
  bool running_;
  FileList file_list_;
  MutexMap mutex_list_;
  DependsMap depends_;
};
}

#endif
