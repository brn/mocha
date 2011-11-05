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
#include "refcount.h"
#include "ptr_deleter.h"
#include "ptr_traits.h"

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
    inline explicit Handle ( unsigned int isbase = 0 ) :
      ptr ( 0 ) ,
      rc ( 0 ) ,
      isbase ( isbase ) {};
    
    /**
     *@constructor
     *Normal constructor.
     */
    template <typename Class>
    inline explicit Handle ( Class *ptr ) : 
      ptr ( ptr ),
      rc ( new RefCount<Class> ( ptr ) ) ,
      isbase ( 0 ){};

    /**
     *@constructor
     *Deleter constructor.
     */
    template <typename Class, typename Deleter>
    inline Handle ( Class *ptr , Deleter deleter , int type = 0 ) :
      ptr ( ptr ),
      rc ( new RefCount<Class> ( ptr , deleter ) ) ,
      isbase ( type ){};

    template <typename Class>
    inline Handle ( Class *ptr , PtrHandleBase* base ) :
        ptr ( ptr ),
        rc ( new RefCount<T> ( base ) ) ,
        isbase ( 0 ){};
    
    /**
     *@constructor
     *Copy constructor.
     */
    inline Handle ( const Handle& ref ) : ptr ( ref.ptr ) , isbase ( ref.isbase ) {
      if ( ref.rc != 0 ) {
        ref.rc->add ();
      }
      rc = ref.rc;
    };
    
    /**
     *@constructor
     *Copy constructor.
     */
    template <typename Class>
    inline Handle ( const Handle<Class>& ref ) : ptr ( ref.ptr ) , isbase ( ref.isbase ) {
      if ( ref.rc != 0 ) {
        ref.rc->add ();
      }
      rc = ref.rc;
    };

    /**
     *@destructor
     *@description
     *decrement counter.
     */
    inline virtual ~Handle () {
      if ( rc != 0 ) {
        rc->release ();
      }
    }

    /**
     *@public
     *Delay initialize.
     */
    template <typename Class>
    inline void operator () ( Class *ptr ) {
      CheckInit_( "mocha::Handle is already initilized." , false );
      this->ptr = ptr;
      rc = ( isbase == 0 )?
          new RefCount <Class> ( ptr ,  PtrDeleter<Class>::deleter ):
          ( isbase == 1 )?
          new RefCount <Class> ( ptr , PtrDeleter<Class>::deleterArray ):
          new RefCount <Class> ( ptr , PtrDeleter<Class>::freePtr );
    }

    /**
     *@public
     *Delay initializer with deleter.
     */
    template <typename Class , typename Deleter>
    inline void operator () ( Class *ptr , Deleter deleter ) {
      CheckInit_( "mocha::Handle is already initilized." , false );
      this->ptr = ptr;
      rc = new RefCount <Class> ( ptr ,  deleter );
    }
    
    /**
     *@public
     *Assignment operator.
     *Decrement counter and increment counter of copy. 
     */
    inline const Handle<T>& operator = ( const Handle<T>& ref ) {
      if ( rc != 0 ) {
        rc->release ();
      };
      
      if ( ref.rc != 0 ) {
        ref.rc->add ();
      }
      
      ptr = ref.ptr;
      rc = ref.rc;
      isbase = ref.isbase;
      return *this;
    }

    /**
     *@public
     *Dereference pointer.
     */
    inline PtrType operator * () const {
      CheckInit_( "mocha::Handle::operator * called before initilized." );
      return *( ptr );
    }
    
    /**
     *@public
     *Get raw pointer.
     */
    inline T* get () const {
      CheckInit_( "mocha::Handle::get called before initilized." );
      return ptr;
    }

    inline void unwatch () const {
      if ( rc != 0 ) {
        rc->free ();
      }
    }

    /**
     *@public
     *Memeber operator.
     */
    inline T* operator -> () const {
      CheckInit_( "mocha::Handle::operator -> called before initilized." );
      return ptr;
    }

    inline bool operator == ( T* target ) const {
      return ptr == target;
    }

    inline bool operator != ( T* target ) const {
      return ptr != target;
    }

    template <typename Class>
    inline Handle<Class> cast () {
      Handle<Class> handle ( *this );
      return handle;
    }
    
    inline T operator [] ( int num ) {
      return ptr [ num ];
    }
    
  private:

    inline void CheckInit_( const char* message , bool is_before_init_ = true ) const {
      if ( is_before_init_ && rc == 0 ) {
        throw std::runtime_error( message );
      } else if ( !is_before_init_ && rc != 0 ) {
        throw std::runtime_error( message );
      }
    }
    
    /**
     *@private
     *This class not has the property of pointer.
     *This pointer is used only reference.
     */
    T *ptr;

    /**
     *@private
     *Manage counter and pointer.
     */
    RefCountBase* rc;
  
  protected:
    /**
     *@protected
     *Check class called as Ref or RefArray or CRef.
     *Ref => 0
     *RefArray => 1
     *CRef => 2
     */
    unsigned int isbase;
    
  };
  

  template <typename T>
  class ArrayHandle : public Handle<T> {
  public :
    template <typename Class>
    inline explicit ArrayHandle ( Class *ptr ) :
      Handle<T> ( ptr , PtrDeleter<Class>::deleterArray , 1 )
    {};
    inline explicit ArrayHandle ():
      Handle<T> ( 1 )
    {}
  private :
    int isbase;
  };

  template <typename T>
  class AllocaterHandle : public Handle<T> {
  public :
    template <typename Class>
    inline AllocaterHandle ( Class *ptr ) :
      Handle<T> ( ptr , PtrDeleter<Class>::freePtr , 2 )
    {}
    inline explicit AllocaterHandle () :
      Handle<T> ( 2 )
    {}
  };

  typedef ArrayHandle<const char> StrHandle;
  typedef ArrayHandle<const wchar_t> WStrHandle;
  typedef AllocaterHandle<const char> CStrHandle;
  typedef AllocaterHandle<const wchar_t> WCStrHandle;

};

#endif
