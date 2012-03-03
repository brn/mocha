
#ifndef RefPtrBase_h
#define RefPtrBase_h

#include <utils/class_traits/uncopyable.h>

namespace mocha {
  class PtrHandleBase : private Uncopyable {
  public :
    inline PtrHandleBase(){}
    inline virtual ~PtrHandleBase () {};
    virtual void Dispose () = 0;
  };
}

#endif

