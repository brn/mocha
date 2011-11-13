
#include "token_info.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace mocha;

TokenInfo::TokenInfo () : Managed () {};
TokenInfo::TokenInfo ( const char* val , int type , int line )
    : Managed (), type_ ( type ), line_ ( line )
{

  value_ = val;

};

TokenInfo& TokenInfo::operator =  ( const TokenInfo& info ) {

  type_ = info.type_;
  line_ = info.line_;
  value_ = info.value_.c_str ();
  return (*this);
  
}

TokenInfo::~TokenInfo () {}

const char* TokenInfo::getValue () const {
  
  return value_.c_str();
  
}

int TokenInfo::getLineNumber () const {
  return line_;
}

int TokenInfo::getType () const {  
  return type_;
}

void TokenInfo::SetType ( int type ) {  
  type_ = type;
}

