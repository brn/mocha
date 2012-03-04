/**
 *@author Taketoshi Aono
 *@fileOverview
 *This Class is controll poninter lifetime.
 *Can use like shared_ptr.
 */


#ifndef mocha_handle_h_
#define mocha_handle_h_

#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <utils/smart_pointer/ref_count/refcount.h>
#include <utils/smart_pointer/common/ptr_deleter.h>
#include <utils/smart_pointer/common/ptr_traits.h>

namespace mocha {

  /**
   *@class
   *@description
   *Pointer resource manager base of Reference count.
   */
  template <typename T>
  class SharedPtr {
    
  private :
    
    /**
     *@private
     *Return type.
     */
    typedef typename PtrTraits<T>::types PtrType;
    
  public :
    
    /**
     *@constructor
     *No arguments constructor.
     */
    inline SharedPtr ();
    
    /**
     *@constructor
     *Normal constructor.
     */
    template <typename Class>
    inline explicit SharedPtr ( Class *ptr );

    /**
     *@constructor
     *Deleter constructor.
     */
    template <typename Class, typename Deleter>
    inline SharedPtr ( Class *ptr , Deleter deleter );


    
    template <typename Class>
    inline SharedPtr ( Class *ptr , PtrHandleBase* base );
    
    /**
     *@constructor
     *Copy constructor.
     */
    inline SharedPtr ( const SharedPtr& ref );

    /**
     *@destructor
     *@description
     *decrement counter.
     */
    inline ~SharedPtr ();

    inline bool Contain();
    
    /**
     *@public
     *Delay initialize.
     */
    template <typename Class>
    inline void operator () ( Class *ptr );
    
    /**
     *@public
     *Delay initializer with deleter.
     */
    template <typename Class , typename Deleter>
    inline void operator () ( Class *ptr , Deleter deleter );
    
    /**
     *@public
     *Assignment operator.
     *Decrement counter and increment counter of copy. 
     */
    inline const SharedPtr<T>& operator = ( const SharedPtr<T>& ref );

    /**
     *@public
     *Dereference pointer.
     */
    inline PtrType operator * () const;
    
    /**
     *@public
     *Get raw pointer.
     */
    inline const T* Get() const;

    /**
     *@public
     *Get raw pointer.
     */
    inline T* Get();

    /**
     *@public
     *Memeber operator.
     */
    inline const T* operator -> () const;

    /**
     *@public
     *Memeber operator.
     */
    inline T* operator -> ();
    
    inline bool operator == ( T* target ) const;

    inline bool operator != ( T* target ) const;

    inline operator bool() const;
    
    template <typename Class>
    inline SharedPtr<Class> CastTo();
    
    inline T operator [] ( int num );
    
  private:

    inline void CheckInit_( const char* message ) const;
    inline void CheckInit_() const;

    /**
     *@private
     *This class not has the property of pointer.
     *This pointer is used only reference.
     */
    T *ptr_;

    /**
     *@private
     *Manage counter and pointer.
     */
    RefCountBase* rc_;
    
  };
  

  template <typename T>
  class ArraySharedPtr : public SharedPtr<T> {
  public :

    template <typename Class>
    inline explicit ArraySharedPtr ( Class *ptr );

    inline ArraySharedPtr ();

    template <typename Class>
    inline void operator() ( Class *ptr );
  };


  template <typename T>
  class AllocatorSharedPtr : public SharedPtr<T> {
  public :

    template <typename Class>
    inline AllocatorSharedPtr ( Class *ptr );

    inline AllocatorSharedPtr ();

    template <typename Class>
    inline void operator() ( Class *ptr );
  };

};

#include <utils/smart_pointer/ref_count/shared_ptr-impl.h>

namespace mocha {
typedef ArraySharedPtr<const char> StrSharedPtr;
typedef ArraySharedPtr<const wchar_t> WStrSharedPtr;
typedef AllocatorSharedPtr<const char> CStrSharedPtr;
typedef AllocatorSharedPtr<const wchar_t> WCStrSharedPtr;
}

#endif
