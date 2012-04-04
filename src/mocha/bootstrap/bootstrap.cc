#include <stdio.h>
#include <string>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/stat/stat.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/options/commandline/commandline_options.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/bootstrap/test/test_run.h>

namespace mocha {
void CreateMochaDir() {
  const char* path = Setting::base();
  if (!mocha::os::fs::mkdir(path, 0777)) {
    fprintf(stderr, "Can not create directory %s mocha boot failed.", path);
    exit(2);
  }
}

void Bootstrap::Initialize(int argc, char** argv) {
  Setting::Initialize();
  CreateMochaDir();
  argv_ = argv;
  self_path_ = os::fs::Path(argv[ 0 ]).absolute_path();
  Interaction::Begin();
  Setting::Destruct();
}

const char* Bootstrap::GetSelfPath() { return self_path_.c_str(); }

char** Bootstrap::argv_;
std::string Bootstrap::self_path_;

}
