#ifndef mocha_xml_observer_h_
#define mocha_xml_observer_h_

#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/misc/file_watcher/observer/file_observer.h>
#include <mocha/misc/file_watcher/file_watcher.h>

namespace mocha {

class XMLObserver {
 public :
  XMLObserver();
  ~XMLObserver();
  void Run();
  inline FileObserver& GetFileObserver(){ return file_observer_; }
  void Restart();
  void Exit();
  void Die();
  bool IsEnd();
 private :
  static void* ThreadRunner_(void* arg);
  inline bool Initialize_(const char* path);
  inline void RegistFile_(const char* file);
  inline void Erase_();

  bool is_end_;
  FileWatcher file_watcher_;
  FileObserver file_observer_;
  class XMLUpdater;
  XMLUpdater* xml_updater_;
};

}

#endif //mocha_xml_observer_h_
