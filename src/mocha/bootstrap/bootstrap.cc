#include <stdio.h>
#include <string>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/fio.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/options/commandline/commandline_options.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/roaster/misc/bits.h>
#include <mocha/bootstrap/test/test_run.h>

namespace mocha {
static char data[] = {32,95,95,32,32,32,32,95,95,32,32,32,32,32,95,95,95,95,95,95,32,32,32,32,32,95,95,95,95,95,95,32,32,32,32,32,95,95,32,32,95,95,32,32,32,32,32,95,95,95,95,95,95,32,32,32,32,10,32,47,92,32,45,46,47,32,32,92,32,32,32,47,92,32,32,95,95,32,92,32,32,32,47,92,32,32,95,95,95,92,32,32,32,47,92,32,92,95,92,32,92,32,32,32,47,92,32,32,95,95,32,92,32,32,32,10,32,92,32,92,32,92,45,46,47,92,32,92,32,32,92,32,92,32,92,47,92,32,92,32,32,92,32,92,32,92,95,95,95,95,32,32,92,32,92,32,32,95,95,32,92,32,32,92,32,92,32,32,95,95,32,92,32,32,10,32,32,92,32,92,95,92,32,92,32,92,95,92,32,32,92,32,92,95,95,95,95,95,92,32,32,92,32,92,95,95,95,95,95,92,32,32,92,32,92,95,92,32,92,95,92,32,32,92,32,92,95,92,32,92,95,92,32,10,32,32,32,92,47,95,47,32,32,92,47,95,47,32,32,32,92,47,95,95,95,95,95,47,32,32,32,92,47,95,95,95,95,95,47,32,32,32,92,47,95,47,92,47,95,47,32,32,32,92,47,95,47,92,47,95,47,32,10,32,32,87,101,108,99,111,109,101,32,116,111,32,109,111,99,104,97,33,32,84,104,105,115,32,102,105,108,101,32,104,97,115,32,97,108,108,32,108,111,103,32,111,102,32,109,111,99,104,97,32,97,99,116,105,118,105,116,121,4};

const char* CreateXML() {
  return
      "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\n"
      "<settings>\n"
      "    <dir>\n"
      "    </dir>\n"
      "</settings>";
}

void BeginLog() {
  mocha::Setting::GetInstance()->SetLogFileHandle();
  mocha::Setting::GetInstance()->LogNoDate(data);
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
  if (!os::fs::FileIO::IsExist(path)) {
    SharedPtr<os::fs::File> file = os::fs::FileIO::Open(path, "rwn", os::fs::FileIO::P_ReadWrite);
    if (file->IsValidFile()) {
      mocha::os::fs::chmod(path, 0777);
      file->Write(CreateXML());
    } else {
      fprintf(stderr, "Can not create setting file %s mocha boot failed." , path);
    }
  }
}

void LoadLog() {
  CreateSetting();
  const char* path = mocha::Setting::GetInstance()->GetLogPath();
  if (!os::fs::FileIO::IsExist(path)) {
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
}

void Bootstrap::Initialize(int argc, char** argv) {
  Setting::instance_ = new Setting();
  LoadLog();
  Setting::instance_->Log("mocha initialize end.");
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
