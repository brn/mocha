#ifndef mocha_scanner_h_
#define mocha_scanner_h_
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/pool/managed.h>
namespace mocha {
class ErrorReporter;
class SourceStream;
class TokenInfo;
class TokenStream;
class Scanner : public Managed {
 public :
  static Scanner* Create( SourceStream* source , ErrorReporter *reporter , const char* filename );
  ~Scanner();
  TokenInfo* Advance( int index = 1 );
  TokenInfo* Undo( int index = 1 );
  TokenInfo* Seek( int index );
  static TokenInfo* kEmpty;
 private :
  Scanner( SourceStream* source , ErrorReporter *reporter , const char* filename );
  void CreateTokenStream_();
  
  class InternalScanner;
  ScopedPtr<InternalScanner> scanner_;
  TokenStream* token_stream_;
  ErrorReporter* reporter_;
};
}

#endif
