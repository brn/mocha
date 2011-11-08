
#ifndef RefPtrBase_h
#define RefPtrBase_h

#include "uncopyable.h"

namespace mocha {
  class PtrHandleBase : private Uncopyable {
  public :
    inline virtual ~PtrHandleBase () {};
    inline virtual void Dispose () = 0;
  };
}

#endif

