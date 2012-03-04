#include <utils/pool/managed_shared_ptr.h>
namespace mocha {
int PtrCollector::Assign () {
  return base_id_++;
}

void PtrCollector::Retain ( Managed* ptr , ReleaseCallback callback ) {
  ptr->next_ = ptr->prev_ = 0;
  if ( ptr->Retained_() == false ) {
    ptr->Retain_();
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
  if ( last_ != 0 ) {
    Managed* managed_ptr = last_;
    Managed* tmp;
    Managed* unfree_list = 0;
    Managed* unfree_head_;
    while ( managed_ptr ) {
      tmp = managed_ptr->prev_;
      if ( managed_ptr->Retained_() &&  managed_ptr->id_ == id ) {
        if ( tmp ) {
          tmp->next_ = 0;
        }
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
}

int ManagedHandle::AssignId () {
  PtrCollector* pool = GetPool_ ();
  return pool->Assign();
}

void ManagedHandle::EnsureScopeCreated_ ( PtrCollector* ptrc ) {
  if ( ptrc == NULL ) {
    fprintf( stderr , "ManagedHandle::Retain called before create ManagedScope.\n" );
    abort();
  }
}

void ManagedHandle::Release_ ( int id ) {
  PtrCollector* pool = GetPool_ ();
  pool->Release( id );
}

PtrCollector* ManagedHandle::Allocate_ () {
  PtrCollector* pool = GetPool_();
  if ( pool == NULL || !pool ) {
    pool =  new PtrCollector ();
    ThreadLocalStorage::Set( &key_ , pool );
  }
  return pool;
}

PtrCollector* ManagedHandle::GetPool_ () {
  return reinterpret_cast<PtrCollector*>( ThreadLocalStorage::Get ( &key_ ) );
}

void ManagedHandle::Destructor_ ( void* ptr ) {
  PtrCollector* ptrc = reinterpret_cast<PtrCollector*>(ptr);
  delete ptrc;
}
ThreadLocalStorageKey ManagedHandle::key_( ManagedHandle::Destructor_ );

inline void* ManagedScope::operator new ( size_t size ) throw () {return 0;}
inline void* ManagedScope::operator new [] ( size_t size ) throw () {return 0;}
inline void ManagedScope::operator delete ( void* ptr ){}
inline void ManagedScope::operator delete [] ( void* ptr ){}
inline void* ManagedScope::operator new ( size_t size , void* ) throw () {return 0;}
inline void* ManagedScope::operator new [] ( size_t size , void* ) throw () {return 0;}
inline void ManagedScope::operator delete ( void* ptr , void* ){}
inline void ManagedScope::operator delete [] ( void* ptr , void* ){}

}
