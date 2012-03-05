#ifndef mocha_bootstrap_h_
#define mocha_bootstrap_h_
#include <string>
#include <useconfig.h>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>

namespace mocha {
class Bootstrap : private Static {
 public :
  static void Initialize( int argc, char** argv );
  static void Reboot();
  static const char* GetSelfPath();
 private :
  static CompilationInfoHandle runtime_info_;
  static char** argv_;
  static std::string self_path_;
};
}

#endif
