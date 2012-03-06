#ifndef mocha_compiler_utils_h_
#define mocha_compiler_utils_h_
#include <useconfig.h>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>

namespace mocha {
class PathInfo;
class CompilerUtils {
 public :
  static SharedPtr<filesystem::Path> CreateJsPath(const char* filename, const char* module_path_key);
  static SharedPtr<filesystem::Path> ChangeDir(const char* js_path);
};
}

#endif
