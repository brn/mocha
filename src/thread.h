#ifndef mocha_thread_h_
#define mocha_thread_h_
#include "platform.h"
#include "static.h"

namespace mocha {
class Thread{
 public :
  typedef void* (*pThreadStartFunc) ( void* param );
  Thread ();
  ~Thread ();
  bool Create ( pThreadStartFunc fn , void* param );
  int Detach();
  void Exit ();
  void Cancel ();
  bool Join ();
  bool IsJoinable ();
  static ThreadId GetThreadId ();
 private :
  Thread_t thread_t_;
  ThreadAttr_t thread_attr_t_;
};

class MutexLock;
class Mutex{
  friend class MutexLock;
 public :
  Mutex ();
 private :
  Mutex_t mutex_t_;
  ThreadId thread_id_;
  bool unlocked_;
};

class MutexLock {
 public :
  MutexLock ( Mutex& mutex );
  ~MutexLock();
  void Unlock ();
 private :
  Mutex* mutex_;
  bool unlocked_;
};

class MutexCond {
 public :
  MutexCond ();
  ~MutexCond ();
  void Lock ();
  void Unlock ();
  void Wait ();
 private :
  static Mutex_t mutex_t_;
};

class ThreadLocalStorageKey;

class ThreadLocalStorage : private Static {
 public :
  static void* Get ( ThreadLocalStorageKey* key );
  static void Set ( ThreadLocalStorageKey* key , void* );
};

class ThreadLocalStorageKey {
  friend class ThreadLocalStorage;
 public :
  typedef void (*Destructor) ( void* ptr );
  explicit ThreadLocalStorageKey ( Destructor destructor );
  ThreadLocalStorageKey ();
  void DeleteKey();
 private :
  ThreadLocalStorageKey_t local_key_t_;
  bool is_init_;
};

}

#endif


