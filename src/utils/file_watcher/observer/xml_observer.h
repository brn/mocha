#ifndef mocha_xml_observer_h_
#define mocha_xml_observer_h_

#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/file_watcher/observer/file_observer.h>
#include <utils/file_watcher/file_watcher.h>

namespace mocha {

class XMLObserver {
 public :
  XMLObserver();
  ~XMLObserver();
  void Run();
  inline FileObserver& GetFileObserver(){ return file_observer_; }
  void Restart();
  void Exit();
 private :
  static void* ThreadRunner_( void* arg );
  inline void Initialize_( const char* path );
  inline void RegistFile_( const char* file );
  inline void Erase_();
  
  FileWatcher file_watcher_;
  FileObserver file_observer_;
  class XMLUpdater;
  XMLUpdater* xml_updater_;
};

}

#endif //mocha_xml_observer_h_
