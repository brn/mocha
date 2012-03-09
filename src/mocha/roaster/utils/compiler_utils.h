#ifndef mocha_compiler_utils_h_
#define mocha_compiler_utils_h_
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/utils/compilation_info.h>
namespace mocha {
class PathInfo;
class CompilerUtils {
 public :
  static SharedPtr<platform::fs::Path> CreateJsPath(const char* filename, const char* module_path_key, const LibDirectories& dir, bool* is_runtime);
  static SharedPtr<platform::fs::Path> ChangeDir(const char* js_path);
};
}

#endif
