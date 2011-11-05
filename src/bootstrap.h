#ifndef mocha_bootstrap_h_
#define mocha_bootstrap_h_
#include <string>
#include "useconfig.h"
#include "static.h"

namespace mocha {
class Bootstrap : private Static {
 public :
  static void Initialize( int argc, char** argv );
  static void Reboot();
 private :
  static char** argv_;
  static std::string self_path_;
};
}

#endif
