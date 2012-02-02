#include <stdio.h>
#include <bootstrap/runners/compile_runner.h>
#include <compiler/utils/compiler_facade.h>

namespace mocha {
CompileRunner::CompileRunner( Options *options ) : ICommandLineRunner( options ) {}

void CompileRunner::Run() {
  CompilerFacade::Compile( options_->GetPath() , false );
}

}
