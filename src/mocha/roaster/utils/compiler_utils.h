#ifndef mocha_compiler_utils_h_
#define mocha_compiler_utils_h_
#include <useconfig.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>

namespace mocha {
class PathInfo;
class CompilerUtils {
 public :
  static SharedStr CreateJsPath(const char* filename, const char* module_path_key);
  static SharedPtr<PathInfo> ChangeDir(const char* js_path);
  static SharedPtr<PathInfo> GetRuntimePathInfo();
};
}

#endif
