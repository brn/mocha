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
  class Handle {
    
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
    inline Handle ();
    
    /**
     *@constructor
     *Normal constructor.
     */
    template <typename Class>
    inline explicit Handle ( Class *ptr );

    /**
     *@constructor
     *Deleter constructor.
     */
    template <typename Class, typename Deleter>
    inline Handle ( Class *ptr , Deleter deleter );


    
    template <typename Class>
    inline Handle ( Class *ptr , PtrHandleBase* base );
    
    /**
     *@constructor
     *Copy constructor.
     */
    inline Handle ( const Handle& ref );

    /**
     *@destructor
     *@description
     *decrement counter.
     */
    inline ~Handle ();

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
    inline const Handle<T>& operator = ( const Handle<T>& ref );

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
    inline Handle<Class> CastTo();
    
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
  class ArrayHandle : public Handle<T> {
  public :

    template <typename Class>
    inline explicit ArrayHandle ( Class *ptr );

    inline ArrayHandle ();

    template <typename Class>
    inline void operator() ( Class *ptr );
  };


  template <typename T>
  class AllocatorHandle : public Handle<T> {
  public :

    template <typename Class>
    inline AllocatorHandle ( Class *ptr );

    inline AllocatorHandle ();

    template <typename Class>
    inline void operator() ( Class *ptr );
  };

};

#include <utils/smart_pointer/ref_count/handle-impl.h>

namespace mocha {
typedef ArrayHandle<const char> StrHandle;
typedef ArrayHandle<const wchar_t> WStrHandle;
typedef AllocatorHandle<const char> CStrHandle;
typedef AllocatorHandle<const wchar_t> WCStrHandle;
}

#endif
