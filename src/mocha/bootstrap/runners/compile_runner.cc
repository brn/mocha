#include <stdio.h>
#include <mocha/misc/file_writer.h>
#include <mocha/roaster/roaster.h>
#include <mocha/bootstrap/runners/compile_runner.h>
#include <mocha/roaster/roaster.h>

namespace mocha {
CompileRunner::CompileRunner( Options *options ) : ICommandLineRunner( options ) {}
class Writer : public AsyncCallback {
 public :
  void operator()(CompilationResultHandle handle) {WriteFile(handle);}
};
void CompileRunner::Run() {
  Roaster roaster;
  CompilationInfoHandle handle(new CompilationInfo(options_->GetPath()));
  AsyncCallbackHandle callback(new Writer);
  roaster.CompileAsync(handle, true, callback);
}

}
