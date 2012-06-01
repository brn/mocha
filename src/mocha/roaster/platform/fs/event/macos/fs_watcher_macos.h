#ifndef mocha_roaster_fs_event_macos_fsevent_kqueue_h_
#define mocha_roaster_fs_event_macos_fsevent_kqueue_h_
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
namespace os {
namespace fs {
class FSEvent;
class FSEventData;
class FSWatcher : public Notificator<FSEvent*>{
  typedef SharedPtr<FSEventData> FSEventDataHandle;
  typedef SharedPtr<FSEvent> FSEventHandle;
  typedef std::pair<const char*, FSEventDataHandle> FSEventPair;
  typedef roastlib::unordered_map<std::string, FSEventDataHandle> FSEventMap;
 public :
  FSWatcher();
  ~FSWatcher();
  bool AddWatch (const char* path);
  bool RemoveWatch(const char* path);
  void RemoveWatch();
  bool IsWatched(const char* path);
  bool Run();
  bool RunAsync();
  void Exit();
  bool IsRunning() const;
  static const char kModify[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  void Start();
  int GetState();
  static void* ThreadRunner(void* param);
  BitVector8 flags_;
  int kq_;
  Mutex mutex_;
  FSEventMap map_;
};

}
}
}
#endif
