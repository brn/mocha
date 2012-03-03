#ifndef mocha_compiler_utils_h_
#define mocha_compiler_utils_h_
#include <useconfig.h>
#include <utils/smart_pointer/ref_count/handle.h>

namespace mocha {
class PathInfo;
class CompilerUtils {
 public :
  static StrHandle CreateJsPath( const char* filename , const char* module_path_key );
  static Handle<PathInfo> ChangeDir( const char* js_path );
  static Handle<PathInfo> GetRuntimePathInfo();
};
}

#endif
