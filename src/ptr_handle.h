
#ifndef mocha_ptr_handle_h_
#define mocha_ptr_handle_h_

#include "ptr_handle_base.h"
#include "ptr_deleter.h"
#include <stdio.h>
namespace mocha {
  template <typename T , typename Deleter>
  class PtrHandleDeleter : public PtrHandleBase {
  private :
    T *ptr;
    Deleter deleter;
  public:
    inline explicit PtrHandleDeleter ( T* ptr , Deleter deleter ) : ptr ( ptr ) , deleter ( deleter ) {};
    inline T* get () {
      return ptr;
    }
    inline void dispose () {
      if ( ptr != 0 ) {
        deleter ( ptr );
        ptr = 0;
      }
    }
  };

  template <typename T>
  class PtrHandle : public PtrHandleBase {
  private :
    T *ptr;
  public:
    inline explicit PtrHandle ( T* ptr ) : ptr ( ptr ) {};
    inline T* get () {
      return ptr;
    }
    inline void dispose () {
      if ( ptr != 0 ) {
        PtrDeleter<T>::deleter ( ptr );
        ptr = 0;
      }
    }
  };

}

#endif

