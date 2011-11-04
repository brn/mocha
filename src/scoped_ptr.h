#ifndef mocha_scoped_ptr_h_
#define mocha_scoped_ptr_h_
#include <stdexcept>
#include "uncopyable.h"
#include "ptr_release.h"
namespace mocha {

template <typename T >
class ScopedPtr : private Uncopyable {
 public :
  typedef void ( *ReleaseCallback ) ( T* ptr );
  inline ScopedPtr ( T* ptr ,  ReleaseCallback callback = ptr_release::Release<T> )
      : is_renounced_ ( false ) , ptr_ ( ptr ) , callback_ ( callback ) {};
  inline ScopedPtr ()
      : is_renounced_ ( false ) , ptr_ ( 0 ) , callback_ ( ptr_release::Release ) {}
  inline ~ScopedPtr () {
    if ( ptr_ != 0 && is_renounced_ == false ) {
      callback_ ( ptr_ );
    }
  }
  inline void operator () ( T* ptr , ReleaseCallback callback = ptr_release::Release<T> ) throw() {
    if ( ptr_ == 0 ) {
      ptr_ = ptr;
      callback_ = callback;
    } else {
      throw std::runtime_error ( "ScopedPtr::operator () called after initializaion." );
    }
  }
  inline T* operator -> () {
    CheckInit_ ( "ScopedPtr::operator-> called before initialized." );
    return Get ();
  }
  inline const T& operator * () const {
    return GetReference_ ();
  }
  inline T& operator * () {
    return GetReference_ ();
  }
  inline T* Get () {
    CheckInit_ ( "ScopedPtr::Get called before initialized." );
    return ptr_;
  }
  inline T* Renounce () {
    is_renounced_ = true;
    T* ret = ptr_;
    ptr_ = 0;
    return ret;
  }
 private :
  inline T& GetReference_ () {
    CheckInit_ ( "ScopedPtr reference type getter called before initialized." );
    return (*ptr_);
  }
  inline void CheckInit_ ( const char* message ) throw () {
    if ( ptr_ == 0 ) {
      throw std::runtime_error ( message );
    }
  }
  
  bool is_renounced_;
  T* ptr_;
  ReleaseCallback callback_;
};

}

#endif
