#include "token_type_rewriter.h"
#include "grammar.tab.hh"

#define TOKEN yy::ParserImplementation::token

namespace mocha {

class TokenTypeRewriter::ScannerState {
 public :
  ScannerState();
  ~ScannerState();
  int state;
  int paren_count;
  int brace_count;
};

TokenTypeRewriter(){}
~TokenTypeRewriter(){}

int TokenTypeRewriter::CheckRewrite( int current_type ) {
  int ret = 0;
  int state = ( states_.size() > 0 )? states_.back()->state : 0; 
  switch ( state ) {
    case TOKEN::JS_FUNCTION :
      ret = FunctionState_( current_type );
      break;
    case TOKEN::JS_PARAM_BEGIN :
      ret = FunctionParamState_( current_type );
      break;
    case TOKEN::JS_PARAM_END :
      ret = FunctionBodyState_( current_type );
      break;
    default :
      ret = -1;
  }
  if ( ret > 0 ) {
    SetState_( ret );
  }
  return ret;
}

int TokenTypeRewriter::FunctionState_( int type ) {
  if ( type == JS_IDENTIFIER ) {
    return TOKEN::JS_FUNCTION_IDENTIFIER;
  } else if ( type == '(' ) {
    return TOKEN::JS_PARAM_BEGIN;
  }
}

int TokenTypeRewriter::FunctionParamState_( int type ) {
  state_inst = states_.back();
  switch ( type ) {
    case ')' :
      state_inst->paren_count--;
      if ( paren_count == 0 ) {
        return TOKEN::JS_PARAM_END;
      }
    case '(' :
      state_inst->paren_count++;
      return;
    case TOKEN::JS_IDENTIFIER :
      return TOKEN::JS_FORMAL_PARAMETER_IDENT;
      break;
    case ']' :
      return TOKEN::JS_DARRAY_END;
      break;
    case '[' :
      return TOKEN::JS_DARRAY_BEGIN;
      break;
    case '}' :
      return TOKEN::JS_DOBJECT_END;
      break;
    case '{' :
      return TOKEN::JS_DOBJECT_BEGIN;
      break;
  }
}

void SetState_( int type ) {
  switch ( type ) {
    case TOKEN::JS_FUNCTION :
      ScannerState* state = state_handle_.Retain<ScannerState>();
      state->state = TOKEN::JS_FUNCTION;
      states_.push_back( state );
      break;
    case TOKEN::JS_PARAM_BEGIN :
      ScannerState* state = states_.back();
      state->paren_count = 1;
      state->state = TOKEN::JS_PARAM_BEGIN;
      break;
    case TOKEN::JS_PARAM_END :
      ScannerState* state = states_.back();
      state->state = TOKEN::JS_PARAM_END;
      break;
  }
}

}
