#ifndef mocha_compiler_utils_h_
#define mocha_compiler_utils_h_

#include "handle.h"

namespace mocha {
class PathInfo;
class CompilerUtils {
 public :
  static StrHandle CreateJsPath( const char* filename , const char* module_path_key );
  static Handle<PathInfo> ChangeDir( const char* js_path );
};
}

#endif
