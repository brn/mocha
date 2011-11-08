
#ifndef mocha_refcount_base_h_
#define mocha_refcount_base_h_
#include "uncopyable.h"
#include "define.h"
namespace mocha {

  class RefCountBase : private Uncopyable {
  public :
    RefCountBase ( int num = 0 ) : count_( num ) {};
    virtual ~RefCountBase (){};
    inline void Add() { count_++; };
    inline void Release() {
      if ( count_ != 0 ) {
        count_--;
      }
      if ( count_ == 0 ) {
        delete this;
      }
    };
  private :
    unsigned int count_;
  };
};


#endif


