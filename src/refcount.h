
#ifndef RefCount_h
#define RefCount_h

#include "refcount_base.h"
#include "ptr_handle.h"


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
     *No Arguments constructor.
     */
    inline explicit RefCount () :
      RefCountBase ( 0 ) ,
      is_free_called_ ( false ),
      ptr_handle_ ( 0 ) {};
    
    /*
     *@constructor
     *Normal constructor.
     */
    inline explicit RefCount ( T *target ) : 
      RefCountBase ( 1 ) ,
      is_free_called_ ( false ),
      ptr_handle_ ( new PtrHandle<T> ( target ) ) {};
    
    /*
     *@constructor
     *Has deleter constructor.
     */
    template <typename Deleter>
    inline RefCount ( T *target , Deleter deleter  ) :
      RefCountBase ( 1 ) ,
      is_free_called_ ( false ),
      ptr_handle_ ( new PtrHandleDeleter<T,Deleter> ( target , deleter ) ) {};
    
    /*
     *@destructor
     *Normal destructor.
     */
    inline ~RefCount () {
      
      if ( ptr_handle_ != 0 ) {
        //destruct pointer.
        if ( is_free_called_ == false ) {
          ptr_handle_->dispose ();
        }
        delete ptr_handle_;
        ptr_handle_ = 0;
      }
      
    };

    inline void free () {
      is_free_called_ = true;
    }

  private:
    
    bool is_free_called_;
    /**
     *@private
     *@description
     *This pointer type is RefPtrBase,
     *but real type is upcast pointer of RefPtr or RefPtrDeleter.
     */
    PtrHandleBase *ptr_handle_;
    
  };
}

#endif

