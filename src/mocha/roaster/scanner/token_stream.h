#ifndef mocha_scanner_token_stream_h_
#define mocha_scanner_token_stream_h_
#include <mocha/misc/int_types.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class TokenContainer;
class TokenInfo;
class TokenStream : public memory::Allocated {
 public :
  ~TokenStream();
  static TokenStream* New();
  TokenInfo* Advance(int index = 1);
  TokenInfo* Seek(int index);
  TokenInfo* Undo(int index = 0);
  void Append(const char* token, int type, int64_t line);  
  int size() const { return size_; }
  TokenInfo* last() const;
  TokenInfo* first() const;
  static TokenInfo* kEmpty;
 private :
  TokenStream();
  memory::Pool* pool() { return pool_; }
  int cursor_;
  int size_;
  TokenContainer* current_;
  TokenContainer* first_;
  TokenContainer* last_;
  memory::Pool* pool_;
};

}

#endif
