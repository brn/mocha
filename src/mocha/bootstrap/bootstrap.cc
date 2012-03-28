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
const char* CreateXML() {
  return
      "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\n"
      "<settings>\n"
      "    <dir>\n"
      "    </dir>\n"
      "</settings>";
}

void BeginLog() {
}

void CreateMochaDir() {
  const char* path = Setting::GetInstance()->GetBasePath();
  if (!mocha::os::fs::mkdir(path, 0777)) {
    fprintf(stderr, "Can not create directory %s mocha boot failed.", path);
    exit(2);
  }
}

void CreateDir() {
  CreateMochaDir();
  const char* path = Setting::GetInstance()->GetModulePath();
  if (!os::fs::mkdir(path, 0777)) {
    fprintf(stderr, "Can not create directory %s mocha boot failed.", path);
    exit(2);
  }
}

void CreateSetting() {
  CreateDir();
  const char* path = Setting::GetInstance()->GetXMLPath();
  os::fs::Stat stat(path);
  if (!stat.IsExist()) {
    FILE* fp = os::FOpen(path, "w+b");
    if (fp != NULL) {
      mocha::os::fs::Directory::chmod(path, 0777);
      const char* xml = CreateXML();
      fwrite(xml, sizeof(char), strlen(xml), fp);
    } else {
      fprintf(stderr, "Can not create setting file %s mocha boot failed." , path);
      abort();
    }
  }
}

/*
void LoadLog() {
  CreateSetting();
  const char* path = mocha::Setting::GetInstance()->GetLogPath();
  os::fs::Stat stat(path);
  if (!stat.IsExist()) {
 CREATE :
    SharedPtr<os::fs::File> file = os::fs::FileIO::Open(path, "rwn", os::fs::FileIO::P_ReadWrite);
	if (file->IsValidFile()) {
      mocha::os::fs::chmod(path, 0777);
      BeginLog();
    } else {
      fprintf(stderr, "Can not create setting file %s mocha boot failed.", path);
    }
  } else {
    if (os::fs::FileIO::Open(path, "r", os::fs::FileIO::P_ReadOnly)->size() > 524288) {
      char tmp[ 1000 ];
      sprintf(tmp, "%s-%s\n", path, mocha::Setting::GetInstance()->GetTimeStr());
      rename(path, tmp);
      goto CREATE;
    }
    mocha::Setting::GetInstance()->SetLogFileHandle();
  }
  }*/

void Bootstrap::Initialize(int argc, char** argv) {
  Setting::instance_ = new Setting();
  CreateSetting();
  argv_ = argv;
  self_path_ = os::fs::Path(argv[ 0 ]).absolute_path();
  if (argc > 1) {
    if (strcmp(argv[ 1 ], "test") == 0) {
      compiler_test::RunTest();
    }
  } else {
    Interaction::Begin();
  }
  delete Setting::instance_;
}

const char* Bootstrap::GetSelfPath() { return self_path_.c_str(); }

char** Bootstrap::argv_;
std::string Bootstrap::self_path_;

}
