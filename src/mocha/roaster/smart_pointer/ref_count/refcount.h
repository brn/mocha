
#ifndef mocha_ref_count_h_
#define mocha_ref_count_h_

#include <mocha/roaster/smart_pointer/ref_count/refcount_base.h>
#include <mocha/roaster/smart_pointer/common/ptr_handle.h>


namespace mocha {
/**
 *@class
 *@extends
 *RefCountBase
 *@description
 *Manage reference count and pointer.
 */
template <typename T>
class RefCount : public RefCountBase {
    
 public:
    
  /*
   *@constructor
   *Normal constructor.
   */
  inline explicit RefCount (T *target);
    
  /*
   *@constructor
   *Has deleter constructor.
   */
  template <typename Deleter>
  inline RefCount (T *target, Deleter deleter );


  /*
   *@constructor
   *Covert constructor.
   */
  inline explicit RefCount (PtrHandleBase* base);
  
  /*
   *@destructor
   *Normal destructor.
   */
  inline ~RefCount ();

 private :
    
  /**
   *@private
   *@description
   *This pointer type is RefPtrBase,
   *but real type is upcast pointer of RefPtr or RefPtrDeleter.
   */
  PtrHandleBase *ptr_handle_;
    
};
}

#include <mocha/roaster/smart_pointer/ref_count/refcount-impl.h>

#endif

