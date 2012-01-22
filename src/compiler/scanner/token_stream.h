#ifndef mocha_token_stream_h_
#define mocha_token_stream_h_
#include <utils/pool/managed.h>

namespace mocha {
class TokenContainer;
class TokenInfo;
class TokenStream : public Managed {
 public :
  ~TokenStream();
  static TokenStream* Create();
  TokenInfo* Advance( int index = 1 );
  TokenInfo* Seek( int index );
  TokenInfo* Undo( int index = 0 );
  void Append( const char* token , int type , long line );  
  int Size() const;
  TokenInfo* Last() const;
  TokenInfo* First() const;
  static TokenInfo* kEmpty;
 private :
  TokenStream();
  int cursor_;
  int size_;
  TokenContainer* current_;
  TokenContainer* head_;
  TokenContainer* tail_;
};

}

#endif
