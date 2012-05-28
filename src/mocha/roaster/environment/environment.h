#ifndef mocha_roaster_environment_h_
#define mocha_roaster_environment_h_
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/notificator/listener_adapter.h>
namespace mocha {
class Environment {
 public :
  template <typename Listener>
  static void Create(Listener callback, bool is_async = false);
 private :
  static void* ThreadRunner(void* arg);
  static void SetThreadType(os::Thread* thread, bool is_async);
  static os::ThreadLocalStorageKey key_;
};
}
#include <mocha/roaster/environment/environment-inl.h>
#endif
