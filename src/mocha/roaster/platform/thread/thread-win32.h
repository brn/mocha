#ifndef mocha_thread_win32_h_
#define mocha_thread_win32_h_
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mocha/roaster/misc/class_traits/static.h>

namespace mocha {
namespace platform {
typedef HANDLE ThreadId;
class Thread {
 public :
  typedef void* (*pThreadStartFunc) (void* param);
  Thread();
  ~Thread(){}
  bool Create (pThreadStartFunc fn, void* param);
  int Detach();
  void Cancel();
  bool Join();
  bool IsJoinable();
  static ThreadId GetThreadId();
  void Exit();
 private :
  BitVector8 flags_;
  HANDLE thread_t_;
  unsigned thread_id_;
};

class ScopedLock;
class Mutex{
  friend class ScopedLock;
 public :
  Mutex();
  ~Mutex();
 private :
  CRITICAL_SECTION critical_section_;
};

class ScopedLock {
 public :
  ScopedLock(Mutex& mutex);
  ~ScopedLock();
  void Unlock();
 private :
  Mutex* mutex_;
  bool unlocked_;
};

class ThreadLocalStorageKey;

class ThreadLocalStorage : private Static {
 public :
  static void* Get (ThreadLocalStorageKey* key) { return return TlsGetValue(key->key); }
  static void Set (ThreadLocalStorageKey* key, void*) { TlsSetValue(key->key, val); }
};

class ThreadLocalStorageKey {
  friend class ThreadLocalStorage;
 public :
  typedef void (*Destructor) (void* ptr);
  explicit ThreadLocalStorageKey(Destructor destructor);
  ThreadLocalStorageKey();
  ~ThreadLocalStorageKey();
  void DeleteKey();
 private :
  void Free();
  bool has_fn;
  bool is_free;
  Mutex mutex_;
  ThreadLocalStorageKey_t key_;
  ThreadLocalStorageKey::Destructor destructor;
};
}
}
#undef PTR_IMPL
#endif


