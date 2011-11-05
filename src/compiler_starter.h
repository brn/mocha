#ifndef mocha_compiler_starter_h_
#define mocha_compiler_starter_h_
#include "useconfig.h"
namespace mocha {
class CompilerStarter{
 public :
  static void StartCompile( const char* path );
  static void* ThreadRunner( void *arg );
 private :
};
}

#endif
