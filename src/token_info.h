
#ifndef TokenInfo_h
#define TokenInfo_h
#include <string>
#include "managed.h"
namespace mocha {

class TokenInfo : public Managed {
    
 public:
  TokenInfo ();
  TokenInfo ( const char* val , int type , int line );
  TokenInfo& operator = ( const TokenInfo& info );
  ~TokenInfo ();
  const char* getValue () const;
  int getType () const;
  void SetType( int type );
  int getLineNumber () const;
    
 private:
  int type_;
  int line_;
  std::string value_;

};

}

#endif

