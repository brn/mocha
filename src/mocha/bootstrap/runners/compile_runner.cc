#include <stdio.h>
#include <mocha/misc/file_writer.h>
#include <mocha/roaster/roaster.h>
#include <mocha/bootstrap/runners/compile_runner.h>
#include <mocha/roaster/roaster.h>

namespace mocha {
CompileRunner::CompileRunner(Options *options) : ICommandLineRunner(options) {}
void CompileRunner::Run() {
  Roaster roaster;
  CompilationInfoHandle handle(new CompilationInfo(options_->GetPath()));
  AsyncCallbackHandle callback(new FileWriter);
  roaster.CompileAsync(handle, true, callback);
}

}
