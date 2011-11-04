#include <stdio.h>
#include "compile_runner.h"
#include "compiler_starter.h"

namespace mocha {
CompileRunner::CompileRunner( Options *options ) : ICommandLineRunner( options ) {}

void CompileRunner::Run() {
  CompilerStarter::StartCompile( options_->GetPath().get() );
}

}
