#include <stdio.h>
#include <mocha/bootstrap/runners/compile_runner.h>
#include <mocha/roaster/utils/compiler_facade.h>

namespace mocha {
CompileRunner::CompileRunner( Options *options ) : ICommandLineRunner( options ) {}

void CompileRunner::Run() {
	CompilerFacade::Compile( options_->GetPath() , false );
}

}
