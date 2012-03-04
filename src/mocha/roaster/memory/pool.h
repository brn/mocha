#ifndef mocha_memory_pool_h_
#define mocha_memory_pool_h_
#include <stdio.h>
#include <utils/class_traits/uncopyable.h>
#include <utils/thread/thread.h>
namespace mocha {
namespace memory {
class Pool;
class Allocated {
  friend class Pool;
 public :
  Allocated(){}
  virtual ~Allocated(){}
  void* operator new(size_t size, Pool* pool);
  void operator delete(void* ptr);
  void operator delete(void* ptr, Pool* pool);
 private :
  Allocated* prev_;
  Allocated* next_;
};

class Pool : private Uncopyable {
 public :
  Pool();
  ~Pool();
  void* Alloc(size_t size);
  static Pool* Local();
 private :
  Allocated* current_;
  Allocated* head_;
  static ThreadLocalStorageKey key_;
};

}
}

#endif
