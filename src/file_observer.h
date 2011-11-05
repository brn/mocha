#ifndef mocha_file_observer_h_
#define mocha_file_observer_h_

#include "useconfig.h"
#include "scoped_ptr.h"
#include "file_watcher.h"

namespace mocha {
class FileObserver {
 public :
  FileObserver ();
  ~FileObserver() {}
  void Run();
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
