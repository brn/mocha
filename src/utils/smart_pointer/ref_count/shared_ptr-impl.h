#ifndef mocha_handle_impl_h_
#define mocha_handle_impl_h_

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
  CheckInit_();
  ptr_ = ptr;
  rc_ = new RefCount<Class>( ptr ,  PtrDeleter<Class>::Delete );
}

template <typename T>
template <typename Class , typename Deleter>
inline void SharedPtr<T>::operator () ( Class *ptr , Deleter deleter ) {
  CheckInit_();
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
  CheckInit_( "mocha::SharedPtr::operator *" );
  return *ptr_;
}


template <typename T>
inline const T* SharedPtr<T>::Get() const {
  CheckInit_( "mocha::SharedPtr::get" );
  return ptr_;
}


template <typename T>
inline T* SharedPtr<T>::Get() {
  CheckInit_( "mocha::SharedPtr::get" );
  return ptr_;
}


template <typename T>
inline const T* SharedPtr<T>::operator -> () const {
  CheckInit_( "mocha::SharedPtr::operator ->" );
  return ptr_;
}

template <typename T>
inline T* SharedPtr<T>::operator -> () {
  CheckInit_( "mocha::SharedPtr::operator ->" );
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
template <typename Class>
inline SharedPtr<Class> SharedPtr<T>::CastTo () {
  SharedPtr<Class> handle( *this );
  return handle;
}

template <typename T>
inline T SharedPtr<T>::operator [] ( int num ) {
  return ptr_[ num ];
}


template <typename T>
inline void SharedPtr<T>::CheckInit_( const char* message ) const {
  if ( rc_ == 0 ) {
    fprintf( stderr , "%s called before initialized." , message );
    abort();
  }
}

template <typename T>
inline void SharedPtr<T>::CheckInit_() const {
  if ( rc_ != 0 ) {
    fprintf( stderr , "mocha::SharedPtr is already initilized." );
    abort();
  }
}

template <typename T>
template <typename Class>
inline ArraySharedPtr<T>::ArraySharedPtr( Class *ptr ) :
    SharedPtr<T>( ptr , PtrDeleter<Class>::DeleteArray ){};


template <typename T>
inline ArraySharedPtr<T>::ArraySharedPtr() : SharedPtr<T>() {}

template <typename T>
template <typename Class>
inline void ArraySharedPtr<T>::operator () ( Class *ptr ) {
  SharedPtr<T>::operator()( ptr , PtrDeleter<Class>::DeleteArray );
}


template <typename T>
template <typename Class>
inline AllocatorSharedPtr<T>::AllocatorSharedPtr ( Class *ptr ) :
    SharedPtr<T> ( ptr , PtrDeleter<Class>::Free ) {}

template <typename T>
inline AllocatorSharedPtr<T>::AllocatorSharedPtr () : SharedPtr<T> () {}

template <typename T>
template <typename Class>
inline void AllocatorSharedPtr<T>::operator () ( Class *ptr ) {
  SharedPtr<T>::operator()( ptr , PtrDeleter<Class>::Free );
}

}

#endif
