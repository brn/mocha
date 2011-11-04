
#ifndef mocha_codegen_h
#define mocha_codegen_h

#include "uncopyable.h"
#include "define.h"

namespace mocha {

  class Codegen : private Uncopyable {

  public :
    inline Codegen () {};
    inline ~Codegen () {};
    
    void Write ( const char* str );
    void Write ( const char* str , long int line );
    void WriteLine ( long int line );
    inline const char* JPM_CONST GetCode () const {
      return &result_ [ 0 ];
    }
    
  private :
    std::string result_;
  };

}


#endif
