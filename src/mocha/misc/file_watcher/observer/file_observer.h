#ifndef mocha_file_observer_h_
#define mocha_file_observer_h_

#include <useconfig.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {
class FileObserver {
 public :
  FileObserver ();
  ~FileObserver() {}
  void Run();
  void Exit( FileWatcher::EndCallBack fn , void* arg );
 private :
  void RegistFile_( const char* filename );
  static void* ThreadRunner_( void *arg );
  void Initialize_();
  class FileUpdater;
  ScopedPtr<FileUpdater> file_updater_;
  FileWatcher file_watcher_;
};
}

#endif //mocha_file_observer_h_
