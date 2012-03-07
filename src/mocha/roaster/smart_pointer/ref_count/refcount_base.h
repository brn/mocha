
#ifndef mocha_refcount_base_h_
#define mocha_refcount_base_h_
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/misc/atomic.h>
#include <define.h>
namespace mocha {

  class RefCountBase : private Uncopyable {
  public :
    RefCountBase (int num = 0) : count_(num) {};
    virtual ~RefCountBase (){};
    inline void Add() { Atomic::Increment(&count_); };
    inline void Release() {
      if (Atomic::Decrement(&count_) == 0) {
        delete this;
      }
    };
  private :
    AtomicWord count_;
  };
}


#endif


