#ifndef mocha_process_process_win32_h_
#define mocha_process_process_win32_h_
#include <windows.h>
#include <string>
namespace mocha {
namespace os {
class Process {
 public :
  Process(){}
  ~Process(){}
  bool Spawn(const char* name, const char* args);
  const char* result() const {return result_.c_str();};
  bool HasResult() {return !result_.empty();}
 private :
  BOOL SpawnChildProcess(const char* name, const char* args);
  bool ReadFromPipe();
  std::string result_;
  HANDLE child_stdin_rd_;
  HANDLE child_stdin_wr_;
  HANDLE child_stdin_wr_dup_;
  HANDLE child_stdout_rd_;
  HANDLE child_stdout_wr_;
  HANDLE child_stdout_rd_dup_;
  HANDLE input_file_;
  HANDLE saved_stdin_;
  HANDLE saved_stdout_;
};
}
}

#endif
