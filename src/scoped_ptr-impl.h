#ifndef mocha_scoped_ptr_inl_h_
#define mocha_scoped_ptr_inl_h_

namespace mocha {
template<typename T>
template<typename Class , typename Deleter>
inline ScopedPtr<T>::ScopedPtr ( Class* ptr ,  Deleter deleter )
    : is_renounced_ ( false ) , ptr_ ( ptr ) , handle_( new PtrHandleDeleter<Class,Deleter>( ptr , deleter ) ) {};



template<typename T>
template<typename Class>
inline ScopedPtr<T>::ScopedPtr ( Class* ptr )
    : is_renounced_ ( false ) , ptr_ ( ptr ) , handle_( new PtrHandle<Class>( ptr ) ) {};



template<typename T>
inline ScopedPtr<T>::ScopedPtr ()
    : is_renounced_ ( false ) , ptr_ ( 0 ) , handle_( 0 ) {}



template<typename T>
inline ScopedPtr<T>::~ScopedPtr () {
  if ( !is_renounced_ && handle_ != 0 ) {
    handle_->dispose();
    delete handle_;
  }
}



template<typename T>
template<typename Class>
inline void ScopedPtr<T>::operator () ( Class* ptr ) {
  LazyInitialize_( new PtrHandle<Class>( ptr ) , ptr );
}



template<typename T>
template<typename Class , typename Deleter>
inline void ScopedPtr<T>::operator () ( Class* ptr , Deleter deleter ) {
  LazyInitialize_( new PtrHandleDeleter<Class,Deleter>( ptr , deleter ) , ptr );
}



template<typename T>
inline T* ScopedPtr<T>::operator -> () {
  CheckInit_ ( "ScopedPtr<T>::operator-> called before initialized." );
  return Get ();
}


template<typename T>
inline const T& ScopedPtr<T>::operator * () const {
  return GetReference_ ();
}



template<typename T>
inline T& ScopedPtr<T>::operator * () {
  return GetReference_ ();
}


template<typename T>
inline T* ScopedPtr<T>::Get () {
  CheckInit_ ( "ScopedPtr<T>::Get called before initialized." );
  return ptr_;
}



template<typename T>
inline Handle<T> ScopedPtr<T>::ToHandle () {
  CheckInit_( "ScopedPtr::ToHandle called before initialized." );
  is_renounced_ = true;
  Handle<T> handle( ptr_ , handle_ );
  return handle;
}


template <typename T>
inline void ScopedPtr<T>::LazyInitialize_( PtrHandleBase* base , T* ptr ) {
  if ( ptr_ == 0 ) {
    ptr_ = ptr;
    handle_ = base;
  } else {
    CheckInit_( "ScopedPtr<T>::operator () called after initializaion." );
  }
}


template <typename T>
inline void ScopedPtr<T>::CheckInit_( const char* message ) const {
  if ( ptr_ == 0 ) {
    throw std::runtime_error( "ScopedPtr<T>::operator () called after initializaion." );
  }
}


template<typename T>
inline T& ScopedPtr<T>::GetReference_ () {
  CheckInit_ ( "ScopedPtr reference type getter called before initialized." );
  return (*ptr_);
}


template <typename T>
template <typename Class>
ScopedArray<T>::ScopedArray( Class *ptr ) : ScopedPtr<T>( ptr , PtrDeleter<Class>::deleterArray ) {}

template <typename T>
ScopedArray<T>::ScopedArray() : ScopedPtr<T>(){}

template <typename T>
template <typename Class>
inline void ScopedArray<T>::operator () ( Class* ptr ) {
  ScopedPtr<T>::operator()( ptr , PtrDeleter<Class>::deleterArray );
}


template <typename T>
template <typename Class>
ScopedAllocater<T>::ScopedAllocater( Class *ptr ) : ScopedPtr<T>( ptr , PtrDeleter<Class>::freePtr ) {}

template <typename T>
ScopedAllocater<T>::ScopedAllocater() : ScopedPtr<T>(){}

template <typename T>
template <typename Class>
inline void ScopedAllocater<T>::operator () ( Class* ptr ) {
  ScopedPtr<T>::operator()( ptr , PtrDeleter<Class>::freePtr );
}

}

#endif
