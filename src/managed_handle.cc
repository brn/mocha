#include "managed_handle.h"

namespace mocha {
int PtrCollector::Assign () {
  int ret = base_id_;
  base_id_++;
  return ret;
}

void PtrCollector::Retain ( Managed* ptr , ReleaseCallback callback ) {
  if ( ptr->Retained_ () != true ) {
    ptr->Retain_ ();
    ptr->id_ = ( base_id_ - 1 );
    ptr->destructor_ = callback;
    if ( last_ == 0 ) {
      last_ = ptr;
      ptr->next_ = ptr->prev_ = 0;
    } else {
      last_->next_ = ptr;
      ptr->prev_ = last_;
      ptr->next_ = 0;
      last_ = ptr;
    }
  }
}

void PtrCollector::Release ( int id ) {
  Release_ ( id );
  base_id_--;
}

void PtrCollector::Release_ ( int id ) {
  Managed* managed_ptr = last_;
  Managed* tmp;
  Managed* unfree_list = 0;
  Managed* unfree_head_;
  while ( managed_ptr ) {
    tmp = managed_ptr->prev_;
    if ( managed_ptr->Retained_() &&  managed_ptr->id_ == id ) {
      managed_ptr->Release_();
    } else if ( unfree_list == 0 ) {
      unfree_list = managed_ptr;
      unfree_head_ = managed_ptr;
    } else {
      unfree_list->prev_ = managed_ptr;
      managed_ptr->next_ = unfree_list;
      unfree_list = managed_ptr;
    }
    managed_ptr = tmp;
  }

  if ( unfree_list != 0 ) {
    last_ = unfree_head_;
    last_->next_ = 0;
  } else {
    last_ = 0;
  }
}

int ManagedHandle::AssignId () {
  MutexLock mutex_lock ( mutex_ );
  PtrCollector* pool = GetPool_ ();
  return pool->Assign ();
}

void ManagedHandle::EnsureScopeCreated_ ( PtrCollector* ptrc ) throw ()  {
  if ( ptrc == NULL ) {
    throw std::runtime_error ( "ManagedHandle::Retain called before create ManagedScope." );
  }
}

void ManagedHandle::Release_ ( int id ) {
  MutexLock mutex_lock ( mutex_ );
  PtrCollector* pool = GetPool_ ();
  pool->Release ( id );
}

void ManagedHandle::Allocate_ () {
  MutexLock mutex_lock ( mutex_ );
  PtrCollector* pool = GetPool_ ();
  if ( pool == NULL ) {
    pool =  new PtrCollector ();
    ThreadLocalStorage::Set ( &key_ , pool );
  }
}

PtrCollector* ManagedHandle::GetPool_ () {
  return reinterpret_cast<PtrCollector*> ( ThreadLocalStorage::Get ( &key_ ) );
}

void ManagedHandle::Destructor_ ( void* ptr ) {
  PtrCollector* ptrc = reinterpret_cast<PtrCollector*>(ptr);
  delete ptrc;
}
ThreadLocalStorageKey ManagedHandle::key_ ( ManagedHandle::Destructor_ );
Mutex ManagedHandle::mutex_;

inline void* ManagedScope::operator new ( size_t size ) throw () {return 0;}
inline void* ManagedScope::operator new [] ( size_t size ) throw () {return 0;}
inline void ManagedScope::operator delete ( void* ptr ){}
inline void ManagedScope::operator delete [] ( void* ptr ){}
inline void* ManagedScope::operator new ( size_t size , void* ) throw () {return 0;}
inline void* ManagedScope::operator new [] ( size_t size , void* ) throw () {return 0;}
inline void ManagedScope::operator delete ( void* ptr , void* ){}
inline void ManagedScope::operator delete [] ( void* ptr , void* ){}

}
