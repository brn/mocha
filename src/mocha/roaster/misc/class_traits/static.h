
#ifndef Static_h
#define Static_h

#include <cstddef>

namespace mocha {

  class Static{
    inline Static (){};
    inline Static (const Static&){};
    inline void operator = (const Static&){};
    inline void operator delete [] (void*) {};
  };
  
}

#endif

