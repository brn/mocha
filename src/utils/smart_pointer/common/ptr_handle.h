
#ifndef mocha_ptr_handle_h_
#define mocha_ptr_handle_h_

#include <stdio.h>
#include <utils/smart_pointer/common/ptr_handle_base.h>
#include <utils/smart_pointer/common/ptr_deleter.h>

namespace mocha {

template <typename T , typename Deleter>
class PtrHandleDeleter : public PtrHandleBase {
 public :
  inline explicit PtrHandleDeleter( T* ptr , Deleter deleter );
  inline T* Get();
  inline void Dispose();
 private :
  T *ptr_;
  Deleter deleter_;
};

template <typename T>
class PtrHandle : public PtrHandleBase {
 public :
  inline explicit PtrHandle( T* ptr );
  inline T* Get();
  inline void Dispose();
 private :
  T *ptr_;
};

}

#include <utils/smart_pointer/common/ptr_handle-impl.h>

#endif

