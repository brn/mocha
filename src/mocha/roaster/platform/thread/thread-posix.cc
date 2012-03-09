#include <stdio.h>
#include <stdlib.h>
#include <mocha/roaster/platform/thread/thread-posix.h>
namespace mocha {
namespace platform {
Thread::Thread() {
  pthread_attr_init(&thread_attr_t_);
}

bool Thread::Create (pThreadStartFunc start_func, void* param) {
  return 0 == pthread_create(&thread_t_, &thread_attr_t_, start_func, param);
}

int Thread::Detach() {
  return pthread_detach(thread_t_);
}

void Thread::Exit() {
  pthread_exit(NULL);
}

void Thread::Cancel() {
  pthread_cancel(thread_t_);
}

bool Thread::Join () {
  return 0 == pthread_join(thread_t_, NULL);
}

bool Thread::IsJoinable () {
  int state = 0;
  if (0 == pthread_attr_getdetachstate(&thread_attr_t_, &state)) {
    return state == PTHREAD_CREATE_JOINABLE;
  }
  return false;
}

ThreadId Thread::GetThreadId () {
  return pthread_self();
}

Mutex::Mutex () {
  pthread_mutex_init(&mutex_t_, NULL);
}

Mutex::~Mutex(){}

ScopedLock::ScopedLock (Mutex& mutex) : mutex_(&mutex), unlocked_(false) {
  pthread_mutex_lock(&(mutex_->mutex_t_));
}

ScopedLock::~ScopedLock () {
  Unlock();
}

void ScopedLock::Unlock () {
  if (unlocked_ == false) { 
    pthread_mutex_unlock(&(mutex_->mutex_t_));
    unlocked_ = true;
  }
}

ThreadLocalStorageKey::ThreadLocalStorageKey (Destructor destructor) {
  if (!is_init_) {
    platform::ScopedLock lock(mutex_);
    if (!is_init_) {
      is_init_ = true;
      pthread_key_create(&local_key_t_, destructor);
    }
  }
}

ThreadLocalStorageKey::ThreadLocalStorageKey() {
  if (!is_init_) {
    platform::ScopedLock lock(mutex_);
    if (!is_init_) {
      is_init_ = true;
      pthread_key_create(&local_key_t_, 0);
    }
  }
}

void ThreadLocalStorageKey::DeleteKey() {
  pthread_key_delete(local_key_t_);
}

pthread_once_t once_control = PTHREAD_ONCE_INIT;
}
}
