#ifndef mocha_compile_runner_h_
#define mocha_compile_runner_h_
#include <mocha/bootstrap/runners/icommandline_runner.h>

namespace mocha {
class CompileRunner : public ICommandLineRunner {
 public :
  CompileRunner( Options* options );
  void Run();
};
}

#endif //mocha_compile_runner_h_
