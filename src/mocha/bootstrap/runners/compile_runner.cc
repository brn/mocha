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
  st << os::fs::Path::current_directory()
     << '/' << options_->GetPath();
  std::string path = st.str();
  CompilationInfo compilation_info;
  if (options_->IsPrettyPrint()) {
    compilation_info.SetPrettyPrint();
  }
  if (options_->IsDebug()) {
    compilation_info.SetDebug();
  }
  if (options_->IsCompress()) {
    compilation_info.SetCompress();
  }
  if (options_->IsFile()) {
    CompilationResultHandle result = roaster.CompileFile(path.c_str(), NULL, &compilation_info);
    if (result->error()->Error()) {
      std::string buf;
      result->error()->SetRawError(&buf);
      Logging::GetInstance()->Info("ERROR OCCURED\n[\n%s\n]", buf.c_str());
    } else {
      Logging::GetInstance()->Info("COMPILE SUCCESS\n[\n%s\n]", result->source());
    }
  }
}

}
