#ifndef mocha_file_observer_h_
#define mocha_file_observer_h_

#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {
class FileObserver {
 public :
  FileObserver ();
  ~FileObserver() {}
  void Run();
  void Exit(FileWatcher::EndCallBack fn, void* arg);
  typedef roastlib::unordered_multimap<std::string, std::string> DependsMap;
  static const DependsMap& depends_map() {return map_;};
 private :
  void RegistFile_(const char* filename);
  static void* ThreadRunner_(void *arg);
  void Initialize_();
  class FileUpdater;
  ScopedPtr<FileUpdater> file_updater_;
  FileWatcher file_watcher_;
  static DependsMap map_;
};
}

#endif //mocha_file_observer_h_
