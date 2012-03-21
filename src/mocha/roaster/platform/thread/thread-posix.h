#ifndef mocha_thread_posix_h_
#define mocha_thread_posix_h_
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mocha/roaster/misc/class_traits/static.h>

namespace mocha {
namespace os {
typedef pthread_t ThreadId;
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
  pthread_t thread_t_;
  pthread_attr_t thread_attr_t_;
};

class ScopedLock;
class Mutex{
  friend class os::ScopedLock;
 public :
  Mutex();
  ~Mutex();
 private :
  pthread_mutex_t mutex_t_;
  pthread_t thread_id_;
};

class ScopedLock {
 public :
  ScopedLock (Mutex& mutex);
  ~ScopedLock();
  void Unlock ();
 private :
  Mutex* mutex_;
  bool unlocked_;
};

class ThreadLocalStorage;
class ThreadLocalStorageKey {
  friend class ThreadLocalStorage;
 public :
  typedef void (*Destructor) (void* ptr);
  explicit ThreadLocalStorageKey(Destructor destructor);
  ThreadLocalStorageKey();
  ~ThreadLocalStorageKey(){};
  void DeleteKey();
 private :
  bool is_init_;
  pthread_key_t local_key_t_;
  Mutex mutex_;
};

class ThreadLocalStorage : private Static {
 public :
  static void* Get (ThreadLocalStorageKey* key) { return pthread_getspecific(key->local_key_t_); }
  static void Set (ThreadLocalStorageKey* key, void* ptr) { pthread_setspecific (key->local_key_t_, ptr); }
};

}
}
#undef PTR_IMPL
#endif


