#ifndef mocha_roaster_fs_event_macos_fsevent_fs_event_h_
#define mocha_roaster_fs_event_macos_fsevent_fs_event_h_
#include <string>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace os {
namespace fs {
class FSWatcher;
class FSEvent {
 public :
  FSEvent(const char* path, FSWatcher*);
  ~FSEvent();
  bool IsExist() const;
  bool IsModified();
  bool IsUpdate();
  void Close();
  FSWatcher* watcher() {return fs_watcher_;}
  const char* filename() const;
  const char* md5() const;
 private :
  std::string path_;
  std::string mtime_;
  std::string md5_;
  FSWatcher* fs_watcher_;
};
}
}
}
#endif
