#ifndef mocha_list_runner_h_
#define mocha_list_runner_h_
#include <mocha/bootstrap/runners/icommandline_runner.h>
namespace mocha {
class Options;
class ListRunner : public ICommandLineRunner {
 public :
  ListRunner(Options* option);
  virtual ListRunner* CastToList() { return this; }
  virtual void Run();
};
}

#endif
