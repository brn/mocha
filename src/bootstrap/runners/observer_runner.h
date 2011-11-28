#ifndef mocha_observer_runner_h_
#define mocha_observer_runner_h_
#include <bootstrap/runners/icommandline_runner.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>
namespace mocha {
class ObserverRunner : public ICommandLineRunner {
 public :
  ObserverRunner( Options* options );
  ~ObserverRunner() {};
  void Run();
  void Exit();
  virtual ObserverRunner* CastToObserver() { return this; }
 private :
  class PtrImpl;
  ScopedPtr<PtrImpl> pimpl_;
};
}

#endif
