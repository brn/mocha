
#ifndef RefPtrBase_h
#define RefPtrBase_h

#include "uncopyable.h"

namespace mocha {
  class PtrHandleBase : private Uncopyable {
  public :
    inline virtual ~PtrHandleBase () {};
    inline virtual void dispose () = 0;
  };
}

#endif

