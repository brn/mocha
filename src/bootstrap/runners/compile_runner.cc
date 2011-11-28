#include <stdio.h>
#include <bootstrap/runners/compile_runner.h>
#include <compiler/utils/compiler_starter.h>

namespace mocha {
CompileRunner::CompileRunner( Options *options ) : ICommandLineRunner( options ) {}

void CompileRunner::Run() {
  CompilerStarter::StartCompile( options_->GetPath() );
}

}
