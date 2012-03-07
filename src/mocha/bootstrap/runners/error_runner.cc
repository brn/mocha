#include <stdio.h>
#include <mocha/bootstrap/runners/error_runner.h>

namespace mocha {
ErrorRunner::ErrorRunner(Options *options) : ICommandLineRunner(options) {}

void ErrorRunner::Run() {
  options_->ShowError();
}

}
