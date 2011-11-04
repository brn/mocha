
#ifndef RefCountBase_h
#define RefCountBase_h
#include "uncopyable.h"

namespace mocha {

  class RefCountBase : private Uncopyable {
  public :
    RefCountBase ( int num = 0 ) : count ( num ) {};
    virtual ~RefCountBase (){};
    virtual void free () = 0;
    inline void add () {
      count ++;
    }
    
    inline void release () {
      
      if ( count != 0 ) {
        count --;
      }

      if ( count == 0 ) {
        delete this;
      }
      
    };
  protected:
    unsigned int count;
  };

};

#endif


