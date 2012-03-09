#include <stdio.h>
#include <sstream>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/misc/file_writer.h>
#include <mocha/roaster/roaster.h>
#include <mocha/bootstrap/runners/compile_runner.h>
#include <mocha/roaster/roaster.h>

namespace mocha {
CompileRunner::CompileRunner(Options *options) : ICommandLineRunner(options) {}
void CompileRunner::Run() {
  Roaster roaster;
  std::stringstream st;
  st << platform::fs::Path::current_directory();
  st << '/' << options_->GetPath();
  std::string path = st.str();
  CompilationInfoHandle handle(new CompilationInfo(path.c_str()));
  if (options_->IsPrettyPrint()) {
    handle->SetPrettyPrint();
  }
  if (options_->IsDebug()) {
    handle->SetDebug();
  }
  if (options_->IsCompress()) {
    handle->SetCompress();
  }
  if (options_->IsFile()) {
    CompilationResultHandle result = roaster.CompileFile(handle);
    if (result->error_map().size() > 0) {
      printf("error!\n");
    } else {
      printf("%s\n", result->source());
    }
  }
}

}
