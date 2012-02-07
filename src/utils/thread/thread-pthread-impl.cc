#ifndef mocha_thread_pthread_impl_cc_
#define mocha_thread_pthread_impl_cc_

#define IMPL_DEF(name) class name::PtrImpl
#define IMPL implementation_
#include <stdio.h>
#include <stdlib.h>
#include <utils/thread/thread.h>
#include <options/setting.h>

namespace mocha {

IMPL_DEF(Thread) {
 public :
  Thread_t thread_t_;
  ThreadAttr_t thread_attr_t_;
};

Thread::Thread () : IMPL( new PtrImpl() ) {
  if ( pthread_attr_init ( &(IMPL->thread_attr_t_) ) ) {
    Setting::GetInstance()->LogFatal( "thread attr init failed." );
  }
}

Thread::~Thread () {}

bool Thread::Create ( pThreadStartFunc start_func , void* param ) {
  return 0 == pthread_create ( &( IMPL->thread_t_ ) , &( IMPL->thread_attr_t_ ) , start_func , param );
}

int Thread::Detach() {
  return pthread_detach( IMPL->thread_t_ );
}

void Thread::Exit () {
  pthread_exit ( NULL );
}

void Thread::Cancel () {
  pthread_cancel ( IMPL->thread_t_ );
}

bool Thread::Join () {
  return 0 == ::pthread_join( IMPL->thread_t_ , NULL );
}

bool Thread::IsJoinable () {
  int state = 0;
  if ( 0 == pthread_attr_getdetachstate ( ( &IMPL->thread_attr_t_ ) , &state ) ) {
    return state == PTHREAD_CREATE_JOINABLE;
  }
  return false;
}

ThreadId Thread::GetThreadId () {
  return pthread_self ();
}

IMPL_DEF(Mutex) {
public :
  Mutex_t mutex_t_;
  ThreadId thread_id_;
  bool unlocked_;
};

Mutex::Mutex () : IMPL( new PtrImpl ) {
  //  mutex_t_ = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_init ( &( IMPL->mutex_t_ ) , NULL );
}

MutexLock::MutexLock ( Mutex& mutex ) : mutex_ ( &mutex ) , unlocked_ ( false ) {
  pthread_mutex_lock ( &(mutex_->IMPL->mutex_t_) );
}

MutexLock::~MutexLock () {
  Unlock ();
}

void MutexLock::Unlock () {
  if ( unlocked_ == false ) { 
    pthread_mutex_unlock ( &(mutex_->IMPL->mutex_t_) );
    unlocked_ = true;
  }
}

IMPL_DEF(ThreadLocalStorageKey){
public :
  PtrImpl() : is_init_( false ) {}
  ThreadLocalStorageKey_t local_key_t_;
  bool is_init_;
  Mutex mutex_;
};

ThreadLocalStorageKey::ThreadLocalStorageKey ( Destructor destructor ) : IMPL( new PtrImpl ) {
  if ( !IMPL->is_init_ ) {
    MutexLock( IMPL->mutex_ );
    if ( !IMPL->is_init_ ) {
      IMPL->is_init_ = true;
      pthread_key_create ( &( IMPL->local_key_t_ ) , destructor );
    }
  }
}

ThreadLocalStorageKey::ThreadLocalStorageKey() : IMPL( new PtrImpl ) {
  if ( !IMPL->is_init_ ) {
    IMPL->is_init_ = true;
    pthread_key_create ( &IMPL->local_key_t_ , 0 );
  }
}

void ThreadLocalStorageKey::DeleteKey () {
  pthread_key_delete ( IMPL->local_key_t_ );
}

ThreadLocalStorageOnce_t once_control = PTHREAD_ONCE_INIT;

void* ThreadLocalStorage::Get ( ThreadLocalStorageKey* key ) {
  return pthread_getspecific ( key->IMPL->local_key_t_ );
}

void ThreadLocalStorage::Set ( ThreadLocalStorageKey* key , void* ptr ) {
  pthread_setspecific ( key->IMPL->local_key_t_ , ptr );
}

}

#undef IMPL_DEF
#undef IMPL

#endif
