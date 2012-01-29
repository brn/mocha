
#ifndef mocha_token_info_h_
#define mocha_token_info_h_
#include <string>
#include <utils/pool/managed.h>
#include <utils/bits.h>
namespace mocha {
class CompilerInfo;
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
  void SetInfo( CompilerInfo* info ) { info_ = info; }
  CompilerInfo* GetInfo() { return info_; }
  bool HasLineBreakBefore() { return vector_.At( 0 ); }
  bool HasLineBreakAfter() { return vector_.At( 1 ); }
  void SetLineBreakBefor() { vector_.Set( 0 ); }
  void SetLineBreakAfter() { vector_.Set( 1 ); }
 private:
  int type_;
  int line_;
  bool is_const_;
  bool is_let_;
  std::string token_;
  std::string renamed_;
  BitVector8 vector_;
  CompilerInfo* info_;
};

}

#endif

