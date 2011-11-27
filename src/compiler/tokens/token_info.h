
#ifndef mocha_token_info_h_
#define mocha_token_info_h_
#include <string>
#include <utils/pool/managed.h>
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
  void SetToken( const char* token ) { token_ = token; }
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

