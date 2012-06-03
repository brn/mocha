#ifndef mocha_roaster_platform_fs_event_readdirectorychangesw_h_
#define mocha_roaster_platform_fs_event_readdirectorychangesw_h_
#include <mocha/roaster/notificator/notificator.h>
namespace mocha { namespace os { namespace fs {
struct FSEventContainer;
class HandleData;
class FSEvent;
class FSWatcherAsync;
class HandleData;
typedef SharedPtr<HandleData> HandleDataHandle;
class FSWatcher : public Notificator<FSEvent*> {
  friend class FSWatcherAsync;
  typedef roastlib::unordered_map<std::string, HandleDataHandle> DirectoryMap;
  typedef roastlib::unordered_map<std::string, bool> FileMap;
 public :
  FSWatcher();
  ~FSWatcher();
  void AddWatch(const char* path);
  void RemoveWatch(const char* path);
  void RemoveWatch();
  void Run();
  void RunAsync();
  void Exit();
  bool IsRunning() const;
  bool IsWatched(const char* path) const;
  static void* ThreadRunner(void* param);
  static const char kModify[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  void Start();
  void EmitEvent(FSEvent* e, HandleData* handle_data);
  void WithFni(HandleData* handle_data);
  void WithoutFni(HandleData* handle_data);
  void ReadDirectoryChangesW(HandleData* handle_data);
  void CreateIOCP();
  bool is_exit_;
  int run_type_;
  HANDLE iocp_handle_;
  memory::Pool pool_;
  DirectoryMap dir_map_;
  FileMap file_map_;
  Mutex mutex_;
};

}}}

#endif
