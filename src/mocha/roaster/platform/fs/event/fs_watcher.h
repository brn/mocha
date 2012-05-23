#ifndef mocha_roaster_fs_event_macos_fsevent_fs_watcher_h_
#define mocha_roaster_fs_event_macos_fsevent_fs_watcher_h_
#include <mocha/roaster/platform/fs/event/event.h>
#include <mocha/roaster/notificator/notificator.h>
namespace mocha {namespace os {namespace fs {
class FSWatcherInterface : public Notificator<FSEvent*> {
 public :
  FSWatcherInterface(){};
  virtual ~FSWatcherInterface(){};
  virtual void AddWatch(const char* filename) = 0;
  virtual void RemoveWatch(const char* filename) = 0;
  virtual void Run() = 0;
  virtual void Exit() = 0;
};
}}}

#include <mocha/roaster/platform/fs/event/macos/kqueue.h>
#endif
