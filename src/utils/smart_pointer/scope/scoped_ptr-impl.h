/**
 *@author Taketoshi Aono
 *@fileOverview
 * Implementation of mocha::ScopedPtr , mocha::ScopedArray , mocha::ScopedAllocater.
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

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
    handle_->Dispose();
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
  CheckInit_ ( "ScopedPtr<T>::operator->" );
  return Get ();
}


template<typename T>
inline const T* ScopedPtr<T>::operator -> () const {
  CheckInit_ ( "ScopedPtr<T>::operator->" );
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
  CheckInit_ ( "ScopedPtr<T>::Get" );
  return ptr_;
}


template<typename T>
inline const T* ScopedPtr<T>::Get () const {
  CheckInit_ ( "ScopedPtr<T>::Get" );
  return ptr_;
}


template<typename T>
inline SharedPtr<T> ScopedPtr<T>::ToSharedPtr () {
  CheckInit_( "ScopedPtr::ToHandle" );
  is_renounced_ = true;
  SharedPtr<T> handle( ptr_ , handle_ );
  return handle;
}


template <typename T>
inline void ScopedPtr<T>::LazyInitialize_( PtrHandleBase* base , T* ptr ) {
  if ( ptr_ == 0 ) {
    ptr_ = ptr;
    handle_ = base;
  } else {
    CheckInit_( "ScopedPtr<T>::operator()" );
  }
}


template <typename T>
inline void ScopedPtr<T>::CheckInit_( const char* message ) const {
  if ( ptr_ == 0 ) {
    fprintf( stderr , "%s called before initialized." , message );
    abort();
  }
}


template<typename T>
inline T& ScopedPtr<T>::GetReference_ () {
  CheckInit_ ( "ScopedPtr reference type getter" );
  return (*ptr_);
}


template <typename T>
template <typename Class>
ScopedArray<T>::ScopedArray( Class *ptr ) : ScopedPtr<T>( ptr , PtrDeleter<Class>::DeleteArray ) {}

template <typename T>
ScopedArray<T>::ScopedArray() : ScopedPtr<T>(){}

template <typename T>
template <typename Class>
inline void ScopedArray<T>::operator () ( Class* ptr ) {
  ScopedPtr<T>::operator()( ptr , PtrDeleter<Class>::DeleteArray );
}

template <typename T>
template <typename Class>
ScopedAllocater<T>::ScopedAllocater( Class *ptr ) : ScopedPtr<T>( ptr , PtrDeleter<Class>::Free ) {}

template <typename T>
ScopedAllocater<T>::ScopedAllocater() : ScopedPtr<T>(){}

template <typename T>
template <typename Class>
inline void ScopedAllocater<T>::operator () ( Class* ptr ) {
  ScopedPtr<T>::operator()( ptr , PtrDeleter<Class>::Free );
}

}

#endif
