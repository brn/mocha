#include <stdio.h>
#include <stdlib.h>
#include "thread.h"
#include "setting.h"
namespace mocha {
#ifdef __GNUC__

Thread::Thread () {
  if ( pthread_attr_init ( &thread_attr_t_ ) ) {
    Setting::GetInstance()->LogFatal( "thread attr init failed." );
  }
}

Thread::~Thread () {}

bool Thread::Create ( pThreadStartFunc start_func , void* param ) {
  return 0 == pthread_create ( &thread_t_ , &thread_attr_t_ , start_func , param );
}

int Thread::Detach() {
  return pthread_detach( thread_t_ );
}

void Thread::Exit () {
  pthread_exit ( NULL );
}

void Thread::Cancel () {
  pthread_cancel ( thread_t_ );
}

bool Thread::Join () {
  return 0 == pthread_join ( thread_t_ , NULL );
}

bool Thread::IsJoinable () {
  int state = 0;
  if ( 0 == pthread_attr_getdetachstate ( &thread_attr_t_ , &state ) ) {
    return state == PTHREAD_CREATE_JOINABLE;
  }
}

ThreadId Thread::GetThreadId () {
  return pthread_self ();
}

Mutex::Mutex () {
  //  mutex_t_ = PTHREAD_MUTEX_INITIALIZER;
  pthread_mutex_init ( &mutex_t_ , NULL );
}

MutexLock::MutexLock ( Mutex& mutex ) : mutex_ ( &mutex ) , unlocked_ ( false ) {
  pthread_mutex_lock ( &(mutex_->mutex_t_) );
}

MutexLock::~MutexLock () {
  Unlock ();
}

void MutexLock::Unlock () {
  if ( unlocked_ == false ) { 
    pthread_mutex_unlock ( &(mutex_->mutex_t_) );
    unlocked_ = true;
  }
}

void* ThreadLocalStorage::Get ( ThreadLocalStorageKey* key ) {
  return pthread_getspecific ( key->local_key_t_ );
}

void ThreadLocalStorage::Set ( ThreadLocalStorageKey* key , void* ptr ) {
  pthread_setspecific ( key->local_key_t_ , ptr );
}

ThreadLocalStorageKey::ThreadLocalStorageKey ( Destructor destructor ) : is_init_( false ) {
  if ( !is_init_ ) {
    is_init_ = true;
    pthread_key_create ( &local_key_t_ , destructor );
  }
}

ThreadLocalStorageKey::ThreadLocalStorageKey() : is_init_( false ) {
  if ( !is_init_ ) {
    is_init_ = true;
    pthread_key_create ( &local_key_t_ , 0 );
  }
}

void ThreadLocalStorageKey::DeleteKey () {
  pthread_key_delete ( local_key_t_ );
}

ThreadLocalStorageOnce_t once_control = PTHREAD_ONCE_INIT;
#endif
}

