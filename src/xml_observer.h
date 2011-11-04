#ifndef mocha_xml_observer_h_
#define mocha_xml_observer_h_

#include "scoped_ptr.h"
#include "file_observer.h"
#include "file_watcher.h"

namespace mocha {

class XMLObserver {
 public :
  XMLObserver();
  ~XMLObserver() {}
  void Run();
  inline FileObserver& GetFileObserver(){ return file_observer_; }
 private :
  static void* ThreadRunner_( void* arg );
  inline void Initialize_( const char* path );
  inline void RegistFile_( const char* file );
  FileWatcher file_watcher_;
  FileObserver file_observer_;
  class XMLUpdater;
  ScopedPtr<XMLUpdater> xml_updater_;
};

}

#endif //mocha_xml_observer_h_
