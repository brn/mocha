#ifndef mocha_icommandline_runner_h_
#define mocha_icommandline_runner_h_
#include <options/commandline/commandline_options.h>
namespace mocha {
class ObserverRunner;
class ListRunner;
class ICommandLineRunner {
 public :
  ICommandLineRunner( Options* option ) : options_( option ) {}
  virtual ~ICommandLineRunner(){}
  virtual void Run() = 0;
  virtual ObserverRunner* CastToObserver() { return 0; }
  virtual ListRunner* CastToList() { return 0; }
 protected :
  Options* options_;
};
}

#endif
