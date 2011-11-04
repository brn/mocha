#ifndef mocha_help_runner_h_
#define mocha_help_runner_h_
#include "icommandline_runner.h"

namespace mocha {
class HelpRunner : public ICommandLineRunner {
 public :
  HelpRunner( Options* option );
  virtual void Run();
};
}

#endif
