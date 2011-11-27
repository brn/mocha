#ifndef mocha_stack_scanner_h_
#define mocha_stack_scanner_h_

#include <utils/smart_pointer/scope/scoped_ptr.h>

namespace mocha {
class TokenInfo;
class ParserTracer;
class QueueScanner {
 public :
  QueueScanner( const std::string& source , ParserTracer *tracer );
  ~QueueScanner();
  void CollectToken();
  TokenInfo* GetToken( int yystate );
 private :
  class Scanner;
  class TokenGetter;
  ScopedPtr<Scanner> scanner_;
  ScopedPtr<TokenGetter> token_getter_;
  ParserTracer* tracer_;
};
}

#endif
