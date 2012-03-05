#include <stdio.h>
#include <mocha/bootstrap/runners/compile_runner.h>
#include <mocha/roaster/roaster.h>

namespace mocha {
CompileRunner::CompileRunner( Options *options ) : ICommandLineRunner( options ) {}

void Noop(CompilationResultHandle handle){}

void CompileRunner::Run() {
  Roaster roaster;
  CompilationInfoHandle handle(new CompilationInfo(options_->GetPath()));
  AsyncCallback callback = Noop;
  roaster.CompileAsync(handle, true, callback);
}

}
