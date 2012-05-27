#ifndef mocha_roaster_platform_fs_event_readdirectorychangesw_h_
#define mocha_roaster_platform_fs_event_readdirectorychangesw_h_
#include <mocha/roaster/notificator/notificator.h>
namespace mocha { namespace os { namespace fs {
struct FSEventContainer;
class FSEvent;
class FSWatcherAsync;
class FSWatcher : public Notificator<FSEvent*> {
  friend class FSWatcherAsync;
  typedef roastlib::unordered_map<std::string, FSEventContainer*> DirectoryMap;
  typedef roastlib::unordered_map<std::string, bool> FileMap;
 public :
  FSWatcher();
  ~FSWatcher();
  void AddWatch(const char* path);
  void RemoveWatch(const char* path);
  void Run();
  void RunAsync();
  void Exit();
  bool IsRunning() const;
  static void* ThreadRunner(void* param);
  static const char kModify[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  void ReadDirectoryChangesW(void* buf, int size, int filter);
  void CreateIOCP();
  memory::Pool pool_;
  DirectoryMap dir_map_;
  FileMap file_map_;
  ScopedPtr<FSWatcherAsync> async_;
};

}}}

#endif
