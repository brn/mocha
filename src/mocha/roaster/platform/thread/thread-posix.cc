#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <sys/time.h>
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/platform/thread/thread-posix.h>
namespace mocha {
namespace os {
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

void ScopedLock::Lock () {
  if (unlocked_ == true) { 
    pthread_mutex_lock(&(mutex_->mutex_t_));
    unlocked_ = false;
  }
}

#ifdef PLATFORM_MACOS

Semaphore::Semaphore(int count) {
  semaphore_create(mach_task_self(), &semaphore_, SYNC_POLICY_FIFO, count);
}

bool Semaphore::Wait() { semaphore_wait(semaphore_);return true; }

bool Semaphore::Wait(int timeout) {
  mach_timespec_t ts;
  ts.tv_sec = timeout / 1000000;
  ts.tv_nsec = (timeout % 1000000) * 1000;
  return semaphore_timedwait(semaphore_, ts) != KERN_OPERATION_TIMED_OUT;
}

void Semaphore::Post() { semaphore_signal(semaphore_); }

#else
Semaphore::Semaphore(int count) {
  sem_init(&semaphore_, 0, count);
}

Semaphore::~Semaphore() {
  sem_destroy(&semaphore_);
}

void Semaphore::Post() {
  sem_post(&semaphore_);
}

bool Semaphore::Wait() {
  while (true) {
    int result = sem_wait(&semaphore_);
    if (result == 0) {
      return true;
    } else if (result == -1 && errno == EINTR) {
      std::string buf;
      os::Strerror(&buf, K_ERRNO);
      FATAL(buf.c_str());
      return false;
    }
  }
}


bool Semaphore::Wait(int timeout) {
  const long kOneSecondMicros = 1000000;
  struct timeval delta;
  delta.tv_usec = timeout % kOneSecondMicros;
  delta.tv_sec = timeout / kOneSecondMicros;
  struct timeval current_time;
  if (gettimeofday(&current_time, NULL) == -1) {
    return false;
  }
  struct timeval end_time;
  timeradd(&current_time, &delta, &end_time);
  struct timespec ts;
  (&ts)->tv_sec = (&end_time)->tv_sec;
  (&ts)->tv_nsec = (&end_time)->tv_usec * 1000;
  while (true) {
    int result = sem_timedwait(&semaphore_, &ts);
    if (result == 0) {
      return true;
    }
    if (result > 0) {
      errno = result;
      result = -1;
    }
    if (result == -1 && errno == ETIMEDOUT) {
      return false;
    } else if (result == -1 && errno == EINTR) {
      std::string buf;
      os::Strerror(&buf, K_ERRNO);
      FATAL(buf.c_str());
    }
  }
}
#endif
ThreadLocalStorageKey::ThreadLocalStorageKey(Destructor destructor) {
  pthread_key_create(&local_key_t_, destructor);
}

ThreadLocalStorageKey::ThreadLocalStorageKey() {
  pthread_key_create(&local_key_t_, 0);
}

ThreadLocalStorageKey::~ThreadLocalStorageKey() {
  pthread_key_delete(local_key_t_);
}


}
}
