#ifndef mocha_phantom_runner_h_
#define mocha_phantom_runner_h_
#include <utils/class_traits/static.h>
namespace mocha {

class PhantomRunner : private Static {
 public :
  static void Run( const char* args );
};

}

#endif
