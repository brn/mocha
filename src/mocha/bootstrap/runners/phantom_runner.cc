#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <mocha/bootstrap/runners/phantom_runner.h>
#include <mocha/options/setting.h>

namespace mocha {
#ifdef _WIN32
void DoRun(const char*) {
  
}
#else
#define R (0)
#define W (1)
void DoRun(const char* command) {
  char *env = getenv("PHANTOM_INSTALL_DIR");
  if (env == NULL) {
    return;
  }
  std::string arg = "";
  arg += env;
  arg += "phantomjs ";
  arg += Setting::GetInstance()->GetBasePath();
  arg += "run-phantom.js ";
  arg += command;
  arg += "";

  
  FILE *fp;
  if ((fp = popen(arg.c_str(), "r")) == NULL) {
    fprintf(stderr, "error!!!\n");
    exit(-1);
  }
  
  char ch;
  std::string buf;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') {
      if (buf.find("failed") != std::string::npos || buf.find("Error") != std::string::npos) {
        fprintf(stderr, "\x1b[1m");
        fprintf(stderr, "\x1b[31m");
      } else if (buf.find("success") != std::string::npos) {
        fprintf(stderr, "\x1b[1m");
        fprintf(stderr, "\x1b[32m");
      } else {
        fprintf(stderr, "\x1b[49m");
        fprintf(stderr, "\x1b[0m");
      }
      fprintf(stderr, "%s", buf.c_str());
      buf.clear();
    }
    buf += ch;
  }
  fprintf(stderr, "\x1b[49m");
  fprintf(stderr, "\x1b[0m");
  fprintf(stderr, "\n");
  pclose(fp);
}
#endif
void PhantomRunner::Run(const char* command) {
  DoRun(command);
}

}
