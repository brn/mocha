#ifndef mocha_handle_impl_h_
#define mocha_handle_impl_h_

namespace mocha {

template <typename T>
inline Handle<T>::Handle() : ptr_( 0 ) , rc_( 0 ) {};

template <typename T>
template <typename Class>
inline Handle<T>::Handle( Class *ptr ) : ptr_( ptr ) , rc_( new RefCount<Class>( ptr ) ){};

template <typename T>
template <typename Class, typename Deleter>
inline Handle<T>::Handle ( Class *ptr , Deleter deleter ) :
    ptr_( ptr ), rc_( new RefCount<Class>( ptr , deleter ) ){};

template <typename T>
template <typename Class>
inline Handle<T>::Handle ( Class *ptr , PtrHandleBase* base ) :
    ptr_( ptr ), rc_( new RefCount<T> ( base ) ){};

template <typename T>
inline Handle<T>::Handle ( const Handle& ref ) : ptr_( ref.ptr_ ) {
  if ( ref.rc_ != 0 ) {
    ref.rc_->Add();
  }
  rc_ = ref.rc_;
};

template <typename T>
inline Handle<T>::~Handle () {
  if ( rc_ != 0 ) {
    rc_->Release();
  }
}

template <typename T>
inline bool Handle<T>::Contain() {
  return ptr_ != 0;
}

template <typename T>
template <typename Class>
inline void Handle<T>::operator () ( Class *ptr ) {
  CheckInit_();
  ptr_ = ptr;
  rc_ = new RefCount<Class>( ptr ,  PtrDeleter<Class>::Delete );
}

template <typename T>
template <typename Class , typename Deleter>
inline void Handle<T>::operator () ( Class *ptr , Deleter deleter ) {
  CheckInit_();
  ptr_ = ptr;
  rc_ = new RefCount <Class> ( ptr ,  deleter );
}

template <typename T>
inline const Handle<T>& Handle<T>::operator = ( const Handle<T>& ref ) {
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
inline typename Handle<T>::PtrType Handle<T>::operator * () const {
  CheckInit_( "mocha::Handle::operator *" );
  return *ptr_;
}


template <typename T>
inline const T* Handle<T>::Get() const {
  CheckInit_( "mocha::Handle::get" );
  return ptr_;
}


template <typename T>
inline T* Handle<T>::Get() {
  CheckInit_( "mocha::Handle::get" );
  return ptr_;
}


template <typename T>
inline const T* Handle<T>::operator -> () const {
  CheckInit_( "mocha::Handle::operator ->" );
  return ptr_;
}

template <typename T>
inline T* Handle<T>::operator -> () {
  CheckInit_( "mocha::Handle::operator ->" );
  return ptr_;
}


template <typename T>
inline bool Handle<T>::operator == ( T* target ) const {
  return ptr_ == target;
}


template <typename T>
inline bool Handle<T>::operator != ( T* target ) const {
  return ptr_ != target;
}


template <typename T>
inline Handle<T>::operator bool() const {
  return ptr_ != 0;
}


template <typename T>
template <typename Class>
inline Handle<Class> Handle<T>::CastTo () {
  Handle<Class> handle( *this );
  return handle;
}

template <typename T>
inline T Handle<T>::operator [] ( int num ) {
  return ptr_[ num ];
}


template <typename T>
inline void Handle<T>::CheckInit_( const char* message ) const {
  if ( rc_ == 0 ) {
    fprintf( stderr , "%s called before initialized." , message );
    abort();
  }
}

template <typename T>
inline void Handle<T>::CheckInit_() const {
  if ( rc_ != 0 ) {
    throw std::runtime_error( "mocha::Handle is already initilized." );
  }
}

template <typename T>
template <typename Class>
inline ArrayHandle<T>::ArrayHandle( Class *ptr ) :
    Handle<T>( ptr , PtrDeleter<Class>::DeleteArray ){};


template <typename T>
inline ArrayHandle<T>::ArrayHandle() : Handle<T>() {}

template <typename T>
template <typename Class>
inline void ArrayHandle<T>::operator () ( Class *ptr ) {
  Handle<T>::operator()( ptr , PtrDeleter<Class>::DeleteArray );
}


template <typename T>
template <typename Class>
inline AllocatorHandle<T>::AllocatorHandle ( Class *ptr ) :
    Handle<T> ( ptr , PtrDeleter<Class>::Free ) {}

template <typename T>
inline AllocatorHandle<T>::AllocatorHandle () : Handle<T> () {}

template <typename T>
template <typename Class>
inline void AllocatorHandle<T>::operator () ( Class *ptr ) {
  Handle<T>::operator()( ptr , PtrDeleter<Class>::Free );
}

}

#endif
