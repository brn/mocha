#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <compiler/tokens/token_info.h>
#include <ast/ast.h>

using namespace mocha;

TokenInfo::TokenInfo () : Managed () {};
TokenInfo::TokenInfo ( const char* token , int type , int line )
    : Managed (), type_ ( type ), line_ ( line ) , is_const_( false ), is_let_( false )
{
  token_.assign( token );
};

TokenInfo& TokenInfo::operator =  ( const TokenInfo& info ) {
  type_ = info.type_;
  line_ = info.line_;
  token_ = info.token_;
  return (*this);
}

TokenInfo::~TokenInfo () {}

const char* TokenInfo::GetToken () const {
  return token_.c_str();
}

int TokenInfo::GetLineNumber () const {
  return line_;
}

int TokenInfo::GetType () const {  
  return type_;
}

void TokenInfo::SetType ( int type ) {  
  type_ = type;
}

