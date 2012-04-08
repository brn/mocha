#include <mocha/process/process.h>
#include <mocha/roaster/platform/utils/utils.h>
#include <mocha/roaster/log/logging.h>
namespace mocha {
namespace os {
bool Process::Spawn(const char* name, const char* args) {
  result_.clear();
  std::string sh_args;
  SPrintf(&sh_args, "%s %s", name, args);
  FILE *fp;
  if ((fp = os::POpen(sh_args.c_str(), "r")) == NULL) {
    os::FPrintf(stderr, "Cant open process %s", name);
    Logging::GetInstance()->Fatal("Cant open process %s", name);
    return false;
  }
  ReadFromFp(fp);
  os::PClose(fp);
  return true;
}

void Process::ReadFromFp(FILE* fp) {
  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    result_ += ch;
  }
}
}
}
