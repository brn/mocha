
#ifndef mocha_token_info_h_
#define mocha_token_info_h_
#include <string>
#include <utils/bits.h>
#include <utils/int_types.h>
#include <mocha/roaster/memory/pool.h>
#define SET(num) flags_.Set(num);
#define HAS(num) flags_.At(num);
namespace mocha {
class CompilerInfo;
class TokenInfo : public memory::Allocated {
 public:
  TokenInfo();
  TokenInfo(const char* val, int type, int line);
  TokenInfo& operator = (const TokenInfo& info);
  ~TokenInfo();
  const char* token() const { return value_.c_str(); }
  inline const char* compressed_name() const { return (compressed_value_.size() > 0)? compressed_value_.c_str() : value_.c_str(); };
  inline void set_compressed_name(const char* token) { compressed_value_ = token; }
  inline void set_token(const char* token) { value_ = token; }
  inline bool IsCompressed() const { return !compressed_value_.empty(); }
  inline void Rollback() { compressed_value_.clear(); }
  inline int type() const { return type_; };
  inline void set_type(int type) { type_ = type; };
  inline int64_t line_number() const { return line_; }
  inline void set_const_declaration() { SET(0); }
  inline bool const_declaration() const { return HAS(0); }
  inline void set_let_declaration() { SET(1); }
  inline bool let_declaration() const { return HAS(1); }
  inline void set_compile_info(CompilerInfo* info) { info_ = info; }
  inline CompilerInfo* compile_info() const { return info_; }
  inline bool linebreak_before() const { return HAS(2); }
  inline bool linebreak_after() const { return HAS(3); }
  inline void set_linebreak_befor() { SET(2); }
  inline void set_linebreak_after() { SET(3); }
 private:
  int type_;
  int64_t line_;
  std::string value_;
  std::string compressed_value_;
  BitVector8 flags_;
  CompilerInfo* info_;
};

}
#undef SET
#undef HAS
#endif

