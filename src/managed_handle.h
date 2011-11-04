/**
 *@author Taketoshi Aono
 *@fileOverview
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

#ifndef mocha_scope_handle_h_
#define mocha_scope_handle_h_
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include "thread.h"
#include "managed.h"
#include "ptr_release.h"
#define MAX_MANAGED_SCOPE 150
namespace mocha {

class PtrCollector;
class ManagedHandle;

/**
 * @class
 * Collect pointor for release.
 */
class PtrCollector {
  friend class ManagedHandle;
 public :
  typedef void ( *ReleaseCallback ) ( Managed* ptr );
  /**
   *@constructor
   */
  inline PtrCollector ()
      : base_id_ ( 0 ) , last_ ( 0 ) {}
  inline ~PtrCollector () {}
  /**
   *@public
   *@returns {int} -> New id.
   *Assign list location id.
   */
  int Assign ();
  /**
   *@public
   *@param {Managed*} ptr -> managed ptr.
   *@param {ReleaseCallback} callback -> release function.
   *Managed ptr.
   */
  void Retain ( Managed* ptr , ReleaseCallback callback );
  void Release ( int id );
  
 private :
  void Release_ ( int id );
  int base_id_;
  Managed* last_;
};


class ManagedScope;
/*
template <typename T>
class ManagedPtr {
 public :

  inline ManagedPtr( T* ptr, PtrCollector::ReleaseCallback callback = Release ) : ptr_( ptr_ ) , managed_( ptr ) {
    ManagedHandle::Retain( ptr, callback );
    managed_->ref_count_++;
  }

  inline ManagedPtr() : ptr_( 0 ) , managed_( 0 ) {}
  
  inline ~ManagedPtr () {
    if ( managed_ ) {
      managed_->ref_count_--;
    }
  }

  inline ManagedPtr( const ManagedPtr& managed_ptr ) {
    managed_ = managed_ptr.managed_;
    ptr_ = managed_ptr.ptr_;
    if ( managed_ ) {
      managed_->refs_count_++;
    }
  }

  inline ManagedPtr& operator = ( const ManagedPtr& managed_ptr ) {
    if ( managed_ ) {
      managed_->ref_count_--;
    }

    ptr_ = managed_ptr.ptr_;
    managed_ = managed_ptr_.managed_;

    if ( managed_ ) {
      managed_->ref_count_++;
    }
    return (*this);
  }

  inline void operator () ( T* ptr, PtrCollector::ReleaseCallback callback = Release ) {
    ManagedHandle::Retain( ptr, callback );
    managed_ = ptr_ = ptr;
    managed_->ref_count_++;
  }

  inline void operator () ( PtrCollector::ReleaseCallback callback = Release ) {
    managed_ = ptr_ = ManagedHandle::Retain( new T, callback );
    managed_->ref_count_++;
  }
  
  template <typename T2>
  inline ManagedPtr<T2> operator ManagedPtr<T2> () {
    ManagedPtr<T2> managed_ptr( ptr_ );
    return managed_ptr;
  }
  inline T* operator -> () {
    return ptr_;
  }
  inline const T* operator -> () const {
    return ptr_;
  }
  inline const T& operator [] ( int index ) const {
    return ptr_[index];
  }
  inline T& operator [] ( int index ) {
    return ptr_[index];
  }
  inline T& operator * () {
    return (*ptr_);
  }
  inline const T& operator * () const {
    return (*ptr_);
  }
 private :
  T* ptr_;
  Managed* managed_;
};
*/

class ManagedHandle {
  friend class ManagedScope;
 public :
  
  static int AssignId();
  
  template <typename T>
  inline static T* Retain ( T* ptr , PtrCollector::ReleaseCallback callback = Release ) throw () {
    MutexLock mutex_lock ( mutex_ );
    return Retain_<T> ( ptr , callback );
  }
  
  template <typename T>
  inline static T* Retain ( PtrCollector::ReleaseCallback callback = Release ) throw () {
    MutexLock mutex_lock ( mutex_ );
    return Retain_<T> ( new T() , callback );
  }

  inline static void Renounce ( Managed* ptr ) { ptr->id_--; }
  inline static void Release ( Managed* ptr ) { ptr_release::Release<Managed> ( ptr ); }
  inline static void ReleaseArray ( Managed* ptr ) { ptr_release::ReleaseArray<Managed> ( ptr ); }
  inline static void Free ( Managed* ptr ) { ptr_release::Free<Managed> ( ptr ); }
 private :
  
  template <typename T>
  static inline T* Retain_ ( T* ptr , PtrCollector::ReleaseCallback callback ) {
    PtrCollector* pool = GetPool_ ();
    EnsureScopeCreated_ ( pool );
    pool->Retain ( ptr , callback );
    return ptr;
  }
  static void Allocate_ ();
  static void Release_ ( int id );
  static void EnsureScopeCreated_ ( PtrCollector* ptrc ) throw ();
  static PtrCollector* GetPool_ ();
  static void Destructor_ ( void* ptr ); 
  static ThreadLocalStorageKey key_;
  static Mutex mutex_;
};

class ManagedScope {
 public :
  ManagedScope () : is_closed_ ( false ) {
    ManagedHandle::Allocate_ ();
    handle_id_ = ManagedHandle::AssignId ();
    if ( handle_id_ > MAX_MANAGED_SCOPE ) {
      throw std::runtime_error ( "too many ManagedScope created." );
    }
  }

  inline void Close () {
    is_closed_ = true;
    ManagedHandle::Release_ ( handle_id_ );
  }
  
  ~ManagedScope () {
    if ( !is_closed_ ) { ManagedHandle::Release_ ( handle_id_ ); }
  }
  
 private :
  inline static void* operator new ( size_t size ) throw ();
  inline static void* operator new [] ( size_t size ) throw ();
  inline static void* operator new ( size_t size, void* ) throw ();
  inline static void* operator new [] ( size_t size, void* ) throw ();
  inline static void operator delete ( void* ptr );
  inline static void operator delete [] ( void* ptr );
  inline static void operator delete ( void* ptr , void* );
  inline static void operator delete [] ( void* ptr , void* );
  int handle_id_;
  bool is_closed_;
};

}

#undef MAX_MANAGED_SCOPE
#endif //mocha_scope_handle_h_

