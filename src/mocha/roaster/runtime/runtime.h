#ifndef mocha_runtime_h_
#define mocha_runtime_h_

namespace mocha {
namespace runtime {
class Runtime {
 public :
  static const char* source() {return runtime_;};
 private :
  static const char runtime_[];
};
}
}

#endif
