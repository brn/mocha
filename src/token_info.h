
#ifndef TokenInfo_h
#define TokenInfo_h
#include <string>
#include "managed.h"
namespace mocha {

class TokenInfo : public Managed {
    
 public:
  TokenInfo();
  TokenInfo( const char* val , int type , int line );
  TokenInfo& operator = ( const TokenInfo& info );
  ~TokenInfo();
  const char* GetToken() const;
  int GetType() const;
  void SetType( int type );
  int GetLineNumber() const;
  void Const() { is_const_ = true; }
  bool IsConst() { return is_const_; }
  void Let() { is_let_ = true; }
  bool IsLet() { return is_let_; }
    
 private:
  int type_;
  int line_;
  bool is_const_;
  bool is_let_;
  std::string token_;

};

}

#endif

