
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
  inline const char* GetAnotherName() const { return ( renamed_.size() > 0 )? renamed_.c_str() : token_.c_str(); };
  inline void Rename( const char* token ) { renamed_ = token; }
  inline void SetToken( const char* token ) { token_ = token; }
  inline bool IsRenamed() { return renamed_.size() > 0; }
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
  std::string renamed_;

};

}

#endif

