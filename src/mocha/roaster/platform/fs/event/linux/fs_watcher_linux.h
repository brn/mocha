#ifndef mocha_roaster_platform_fs_event_linux_fs_watcher_h_
#define mocha_roaster_platform_fs_event_linux_fs_watcher_h_

namespace mocha { namespace os { namespace fs {
class FSWatcher {
 public :
  FSWatcher();
  ~FSWatcher();
  void AddWatch(const char* path);
  void RemoveWatch(const char* path);
  void Run();
  void RunAsync();
  void Exit();
  bool IsRunning() const;
  static const char kModify[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  
};
}}}

#endif
