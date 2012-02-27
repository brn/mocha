#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <compiler/tokens/token_info.h>
#include <ast/ast.h>

using namespace mocha;

TokenInfo::TokenInfo () : Managed () {};
TokenInfo::TokenInfo ( const char* token , int type , int line )
    : Managed (), type_ ( type ), line_ ( line ) , is_const_( false ), is_let_( false ) {
  value_.assign( token );
};

TokenInfo& TokenInfo::operator =  ( const TokenInfo& info ) {
  type_ = info.type_;
  line_ = info.line_;
  value_ = info.value_;
  compressed_value_ = info.compressed_value_;
  flags_ = info.flags_;
  return (*this);
}

TokenInfo::~TokenInfo () {}

