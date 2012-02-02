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
#include <utils/int_types.h>
#include <utils/thread/thread.h>
#include <utils/pool/managed.h>
#include <utils/smart_pointer/common/ptr_deleter.h>
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
  typedef void(* ReleaseCallback )( Managed* ptr );
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

class ManagedHandle {
  friend class ManagedScope;
 public :
  
  static int AssignId();
  
  template <typename T>
  inline static T* Retain ( T* ptr , PtrCollector::ReleaseCallback callback = PtrDeleter<Managed>::Delete ) {
    return Retain_<T> ( ptr , callback );
  }
  
  template <typename T>
  inline static T* Retain ( PtrCollector::ReleaseCallback callback = PtrDeleter<Managed>::Delete ) {
    T* ptr = new T;
    return Retain_<T> ( ptr , callback );
  }

  inline static void Renounce ( Managed* ptr ) { ptr->id_--; }
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
  static void EnsureScopeCreated_ ( PtrCollector* ptrc );
  static PtrCollector* GetPool_ ();
  static void Destructor_ ( void* ptr ); 
  static ThreadLocalStorageKey key_;
};

class ManagedScope {
 public :
  ManagedScope () : is_closed_ ( false ) {
    ManagedHandle::Allocate_();
    //printf( "%X allocate\n" , Thread::GetThreadId() );
    handle_id_ = ManagedHandle::AssignId();
    if ( handle_id_ > MAX_MANAGED_SCOPE ) {
      fprintf( stderr , "too many ManagedScope created." );
      abort();
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

