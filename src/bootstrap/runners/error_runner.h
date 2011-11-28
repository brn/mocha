#ifndef mocha_error_runner_h_
#define mocha_error_runner_h_
#include <bootstrap/runners/icommandline_runner.h>

namespace mocha {
class ErrorRunner : public ICommandLineRunner {
 public :
  ErrorRunner( Options* option );
  virtual void Run();
};
}

#endif
