#include <stdio.h>
#include <bootstrap/runners/error_runner.h>

namespace mocha {
ErrorRunner::ErrorRunner( Options *options ) : ICommandLineRunner( options ) {}

void ErrorRunner::Run() {
  options_->ShowError();
}

}
