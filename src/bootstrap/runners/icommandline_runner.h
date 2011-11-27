#ifndef mocha_icommandline_runner_h_
#define mocha_icommandline_runner_h_
#include <options/commandline/commandline_options.h>
namespace mocha {
class ICommandLineRunner {
 public :
  ICommandLineRunner( Options* option ) {}
  virtual ~ICommandLineRunner(){}
  virtual void Run() = 0;
 protected :
  Options* options_;
};
}

#endif
