#ifndef mocha_refcount_base_h_
#define mocha_refcount_base_h_
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <atomic>

namespace mocha {

class RefCountBase : private Uncopyable {
 public :
  RefCountBase (int num = 0) {
    count_.store(num, std::memory_order_relaxed);
  };
  virtual ~RefCountBase (){};
  inline void Add() {
    std::atomic_fetch_add_explicit(&count_, 1u, std::memory_order_relaxed);
  };
  inline void Release() {
    if (std::atomic_fetch_sub_explicit(&count_, 1u, std::memory_order_release) == 0) {
      std::atomic_thread_fence(std::memory_order_acquire);
      delete this;
    }
  };
 private :
  std::atomic<uint32_t> count_;
};
}


#endif


