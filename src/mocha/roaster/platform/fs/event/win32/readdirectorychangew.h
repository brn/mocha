#ifndef mocha_roaster_platform_fs_event_readdirectorychangesw_h_
#define mocha_roaster_platform_fs_event_readdirectorychangesw_h_

namespace mocha {

class FSWatcher : public FSWatcherInterface {
  typedef roastlib::unordered_map<std::string, int> DirectoryMap;
  typedef roastlib::unordered_map<std::string, FSEvent*> FileMap;
 public :
  FSWatcher();
  ~FSWatcher();
  void AddWatch(const char* path);
  void RemoveWatch(const char* path);
  void Run();
  void Exit();
  bool IsRunning() const;
  static void* ThreadRunner(void* param);
  static const char kModified[];
  static const char kUpdate[];
  static const char kDelete[];
 private :
  DirectoryMap dir_map_;
  FileMap file_map_;
};

}

#endif
