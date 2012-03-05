#ifndef mocha_handle_impl_h_
#define mocha_handle_impl_h_
#include <assert.h>
namespace mocha {

template <typename T>
inline SharedPtr<T>::SharedPtr() : ptr_( 0 ) , rc_( 0 ) {};

template <typename T>
template <typename Class>
inline SharedPtr<T>::SharedPtr( Class *ptr ) : ptr_( ptr ) , rc_( new RefCount<Class>( ptr ) ){};

template <typename T>
template <typename Class, typename Deleter>
inline SharedPtr<T>::SharedPtr ( Class *ptr , Deleter deleter ) :
    ptr_( ptr ), rc_( new RefCount<Class>( ptr , deleter ) ){};

template <typename T>
template <typename Class>
inline SharedPtr<T>::SharedPtr ( Class *ptr , PtrHandleBase* base ) :
    ptr_( ptr ), rc_( new RefCount<T> ( base ) ){};

template <typename T>
inline SharedPtr<T>::SharedPtr ( const SharedPtr& ref ) : ptr_( ref.ptr_ ) {
  if ( ref.rc_ != 0 ) {
    ref.rc_->Add();
  }
  rc_ = ref.rc_;
};

template <typename T>
inline SharedPtr<T>::~SharedPtr () {
  if ( rc_ != 0 ) {
    rc_->Release();
  }
}

template <typename T>
inline bool SharedPtr<T>::Contain() {
  return ptr_ != 0;
}

template <typename T>
template <typename Class>
inline void SharedPtr<T>::operator () ( Class *ptr ) {
  CheckInit();
  ptr_ = ptr;
  rc_ = new RefCount<Class>( ptr ,  PtrDeleter<Class>::Delete );
}

template <typename T>
template <typename Class , typename Deleter>
inline void SharedPtr<T>::operator () ( Class *ptr , Deleter deleter ) {
  CheckInit();
  ptr_ = ptr;
  rc_ = new RefCount <Class> ( ptr ,  deleter );
}

template <typename T>
inline const SharedPtr<T>& SharedPtr<T>::operator = ( const SharedPtr<T>& ref ) {
  if ( rc_ != 0 ) {
    rc_->Release ();
  };
      
  if ( ref.rc_ != 0 ) {
    ref.rc_->Add ();
  }
      
  ptr_ = ref.ptr_;
  rc_ = ref.rc_;
  return *this;
}

template <typename T>
inline typename SharedPtr<T>::PtrType SharedPtr<T>::operator * () const {
  CheckInit( "mocha::SharedPtr::operator *" );
  return *ptr_;
}


template <typename T>
inline const T* SharedPtr<T>::Get() const {
  CheckInit( "mocha::SharedPtr::get" );
  return ptr_;
}


template <typename T>
inline T* SharedPtr<T>::Get() {
  CheckInit( "mocha::SharedPtr::get" );
  return ptr_;
}


template <typename T>
inline const T* SharedPtr<T>::operator -> () const {
  CheckInit( "mocha::SharedPtr::operator ->" );
  return ptr_;
}

template <typename T>
inline T* SharedPtr<T>::operator -> () {
  CheckInit( "mocha::SharedPtr::operator ->" );
  return ptr_;
}


template <typename T>
inline bool SharedPtr<T>::operator == ( T* target ) const {
  return ptr_ == target;
}


template <typename T>
inline bool SharedPtr<T>::operator != ( T* target ) const {
  return ptr_ != target;
}


template <typename T>
inline SharedPtr<T>::operator bool() const {
  return ptr_ != 0;
}

template <typename T>
inline typename SharedPtr<T>::PtrType SharedPtr<T>::operator [] ( int num ) {
  assert(false);
  return *ptr_;
}

template <typename T>
template <typename Class>
inline SharedPtr<Class> SharedPtr<T>::CastTo () {
  SharedPtr<Class> handle( *this );
  return handle;
}


template <typename T>
inline void SharedPtr<T>::CheckInit( const char* message ) const {
  if ( rc_ == 0 ) {
    fprintf( stderr , "%s called before initialized." , message );
    assert(false);
  }
}

template <typename T>
inline void SharedPtr<T>::CheckInit() const {
  if ( rc_ != 0 ) {
    fprintf( stderr , "mocha::SharedPtr is already initilized." );
    assert(false);
  }
}

template <typename T>
template <typename Class>
inline SharedArray<T>::SharedArray( Class *ptr ) :
    SharedPtr<T>( ptr , PtrDeleter<Class>::DeleteArray ){};


template <typename T>
inline SharedArray<T>::SharedArray() : SharedPtr<T>() {}

template <typename T>
template <typename Class>
inline void SharedArray<T>::operator() ( Class *ptr ) {
  SharedPtr<T>::operator()( ptr , PtrDeleter<Class>::DeleteArray );
}

template <typename T>
inline typename SharedPtr<T>::PtrType SharedArray<T>::operator [] ( int num ) {
  return SharedPtr<T>::ptr_[ num ];
}

template <typename T>
template <typename Class>
inline SharedAllocator<T>::SharedAllocator( Class *ptr ) :
    SharedPtr<T> ( ptr , PtrDeleter<Class>::Free ) {}

template <typename T>
inline SharedAllocator<T>::SharedAllocator() : SharedPtr<T> () {}

template <typename T>
template <typename Class>
inline void SharedAllocator<T>::operator() ( Class *ptr ) {
  SharedPtr<T>::operator()( ptr , PtrDeleter<Class>::Free );
}

}

#endif
