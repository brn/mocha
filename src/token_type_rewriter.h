#ifndef mocha_token_type_rewriter_h_
#define mocha_token_type_rewriter_h_

namespace mocha {

class TokenTypeRewriter {
 public :

  TokenTypeRewriter();
  ~TokenTypeRewriter();
  int CheckRewrite( int current_type );
  
 private :
  int FunctionState_( int type );
  int FunctionParamState_( int type );
  class ScannerState;
  std::vector<ScannerState*> states_;
  ScopedList<ScannerState> state_handle_;
};

}

#endif
