#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/platform/fs/directory/directory.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexc/events/compilation_event/compilation_event.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/ast/translator/translator.h>
namespace mocha {

void CompileRuntime() {
  Logging::Initialize(stdout);
  os::fs::Directory dir(CURRENT_DIR"/mocha/module");
  os::fs::Directory::const_iterator it;
  Nexc::Results results;
  CompilationInfo info;
  Nexc nexc(&info);
  for (it = dir.Entries(true); it != dir.end(); ++it) {
    if (!it->IsDir()) {
      printf("%s\n", it->GetFullPath());
      nexc.Pack(it->GetFullPath());
      results.push_back(std::pair<const char*, AstRoot*>(it->GetName(), nexc.GetResult()));
    }
  }
  Nexc::PackFile(results);
}

}

int main() {
  mocha::CompileRuntime();
}

