#ifndef mocha_thread_win_impl_cc_
#define mocha_thread_win_impl_cc_
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mocha/misc/int_types.h>
#include <process.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/options/setting.h>

namespace mocha {

#define IMPL_DEF(name) class name::PtrImpl
#define IMPL implementation_

struct ParamsForWinThread {
  void* arg;
  Thread::pThreadStartFunc fn;
};

#define DETACH 0x00000001
#define EXIT 0x00000002
#define CANCELED 0x00000004
  
IMPL_DEF(Thread) {
  friend class Thread;
public :
  PtrImpl() : flags_( 0 ) {}
  ~PtrImpl() {}
  static unsigned __stdcall ThreadStartFuncWin ( void* param ) {
    ParamsForWinThread* params = reinterpret_cast<ParamsForWinThread*>( param );
    params->fn( params->arg );
    delete params;
    return 0;
  }
  int8_t flags_;
  Thread_t thread_t_;
  ThreadId thread_id_;
};


Thread::Thread() : IMPL( new PtrImpl ) {}
Thread::~Thread() {}
bool Thread::Create( pThreadStartFunc fn , void* param ) {
  ParamsForWinThread *params_for_win = new ParamsForWinThread;
  params_for_win->arg = param;
  params_for_win->fn = fn;
  IMPL->thread_t_ = reinterpret_cast<HANDLE>(
      _beginthreadex( NULL , 0 , PtrImpl::ThreadStartFuncWin , params_for_win , 0 , &(IMPL->thread_id_) ) );
  return true;
}

bool Thread::Join() {
  if ( ( IMPL->flags_ & DETACH ) != DETACH ) {
    WaitForSingleObject( IMPL->thread_t_ , INFINITE );
    return true;
  }
  return false;
}

int Thread::Detach() {
  IMPL->flags_ |= DETACH;
  return 1;
}

void Thread::Exit() {
  unsigned ret = 0;
  IMPL->flags_ |= EXIT;
  _endthreadex( ret );
  CloseHandle( IMPL->thread_t_ );
}

void Thread::Cancel() {
  IMPL->flags_ |= CANCELED;
  LPDWORD ret = 0;
  GetExitCodeThread( IMPL->thread_t_ , ret );
  TerminateThread( IMPL->thread_t_ , *ret );
}

bool Thread::IsJoinable() {
  return ( ( ( IMPL->flags_ & DETACH ) != DETACH ) &&
           ( ( IMPL->flags_ & EXIT ) != EXIT ) &&
           ( ( IMPL->flags_ & CANCELED ) != CANCELED ) );
}



IMPL_DEF(Mutex) {
public :
  Mutex_t mutex_t_;
};

Mutex::Mutex() : IMPL( new PtrImpl ) {
  IMPL->mutex_t_ = OpenMutex( MUTEX_ALL_ACCESS, FALSE , "" );
}


MutexLock::MutexLock( Mutex& mutex ) : mutex_( &mutex ) , unlocked_( false ) {
  WaitForSingleObject( mutex_->IMPL->mutex_t_ , INFINITE );
}

MutexLock::~MutexLock() {
  Unlock();
}

void MutexLock::Unlock() {
  if ( !unlocked_ ) {
    unlocked_ = true;
    ReleaseMutex( mutex_->IMPL->mutex_t_ );
    CloseHandle( mutex_->IMPL->mutex_t_ );
  }
}

IMPL_DEF(ThreadLocalStorageKey) {
public :
  PtrImpl() : has_fn( false ) , is_free( false ) {
    key = TlsAlloc();
  }
  ~PtrImpl() {
    Free();
  }
  void Free() {
    if ( !is_free ) {
      if ( has_fn ) {
        destructor( TlsGetValue( key ) );
      }
      TlsFree( key );
    }
  }
  bool has_fn;
  bool is_free;
  ThreadLocalStorageKey_t key;
  ThreadLocalStorageKey::Destructor destructor;
};

ThreadLocalStorageKey::ThreadLocalStorageKey( ThreadLocalStorageKey::Destructor destructor ) : IMPL( new PtrImpl() ) {
  IMPL->destructor = destructor;
  IMPL->has_fn = true;
}


ThreadLocalStorageKey::ThreadLocalStorageKey() : IMPL( new PtrImpl ) {}

void ThreadLocalStorageKey::DeleteKey() {
  IMPL->Free();
}

void* ThreadLocalStorage::Get( ThreadLocalStorageKey* key ) {
  return TlsGetValue( key->IMPL->key );
}

void ThreadLocalStorage::Set( ThreadLocalStorageKey* key , void* val ) {
  TlsSetValue( key->IMPL->key , val );
}

}
#endif
