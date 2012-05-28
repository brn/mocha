#ifndef mocha_process_process_posix_h_
#define mocha_process_process_posix_h_
#include <stdio.h>
#include <string>
namespace mocha {
namespace os {
class Process {
 public :
  Process(){}
  bool Spawn(const char* name, const char* args);
  ~Process(){}
  const char* result() const {return result_.c_str();};
  bool HasResult() {return !result_.empty();}
 private :
  void ReadFromFp(FILE* fp);
  std::string result_;
};
}
}

#endif
