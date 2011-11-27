#ifndef mocha_observer_runner_h_
#define mocha_observer_runner_h_
#include <bootstrap/runners/icommandline_runner.h>
namespace mocha {
class ObserverRunner : public ICommandLineRunner {
 public :
  ObserverRunner( Options* options ) : ICommandLineRunner( options ) {}
  ~ObserverRunner() {};
  void Run();
};
}

#endif
