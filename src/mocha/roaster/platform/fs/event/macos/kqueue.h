#ifndef mocha_roaster_fs_event_macos_fsevent_kqueue_h_
#define mocha_roaster_fs_event_macos_fsevent_kqueue_h_
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
namespace os {
namespace fs {
class AsyncFSWatcher;
class FSEvent;
class FSWatcher : public Notificator<FSEvent*>{
  friend class AsyncFSWatcher;
  typedef std::pair<const char*, FSEvent*> FSEventPair;
  typedef roastlib::unordered_map<std::string, FSEvent*> FSEventMap;
 public :
  FSWatcher();
  ~FSWatcher();
  void AddWatch (const char* path);
  void RemoveWatch(const char* path);
  void Run();
  void RunAsync();
  void Exit();
  bool IsRunning() const;
  static const char kModify[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  static void* ThreadRunner(void* param);
  ScopedPtr<AsyncFSWatcher> async_fs_watcher_;
  FSEventMap map_;
  memory::Pool pool_;
};

}
}
}
#endif
