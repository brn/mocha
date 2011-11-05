#ifndef mocha_thread_h_
#define mocha_thread_h_
#include "useconfig.h"
#include "platform.h"
#include "static.h"
#include "scoped_ptr.h"

namespace mocha {
#define PTR_IMPL                                \
  class PtrImpl;\
  ScopedPtr<PtrImpl> implementation_

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
  PTR_IMPL;
};

class MutexLock;
class Mutex{
  friend class MutexLock;
 public :
  Mutex ();
 private :
  PTR_IMPL;
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
  PTR_IMPL;
};

}
#undef PTR_IMPL
#endif


