#ifndef mocha_roaster_platform_fs_event_linux_fs_watcher_h_
#define mocha_roaster_platform_fs_event_linux_fs_watcher_h_
#include <sys/inotify.h>
#include <vector>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/notificator/notificator.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
namespace mocha { namespace os { namespace fs {
class FSEvent;
typedef SharedPtr<FSEvent> FSEventHandle;
typedef std::pair<int, FSEventHandle> InotifyFDPair;
typedef roastlib::unordered_map<int,  FSEventHandle> InotifyFDMap;
typedef unsigned long InotifyMask;
typedef SharedPtr<inotify_event> EventHandle;
typedef struct inotify_event InotifyEvent;
class FSWatcher : public Notificator<FSEvent*>{
 public :
  FSWatcher();
  ~FSWatcher();
  void AddWatch(const char* path);
  void RemoveWatch(const char* path);
  void RemoveWatch();
  void Run();
  void RunAsync();
  void Exit();
  bool IsRunning() const {return !is_exit_;};
  bool IsWatched(const char* path) const;
  static const char kModify[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  static void* ThreadRunner(void* args);
  void Regist(const char* abpath);
  void Start();
  void ReadInotifyEvents();
  void CheckEvent(InotifyEvent* ev);
  bool is_exit_;
  int epoll_fd_;
  int inotify_fd_;
  Mutex mutex_;
  InotifyFDMap fd_map_;
};
}}}

#endif
