
#include "parser_tracer.h"

using namespace mocha;

#define RESET_SEMICOLON parser_flags_ & 0xFE
#define RESET_ROLLBACK parser_flags_ & 0xFD
#define RESET_LINE_BREAK parser_flags_ & 0xFB
#define RESET_INCLUDE parser_flags_ & 0xF7

ParserTracer::ParserTracer ( const char* filename ) :
  parser_flags_ ( 0 ),
  parser_state_( 0 ),
  errorLine_ ( 0 ),
  filename_( filename )
{};  

void ParserTracer::SetSemicolonFlag ( bool is ) {
  if ( is ) {
    //00000001
    parser_flags_ = parser_flags_ | 0x1;
  } else {
    parser_flags_ = RESET_SEMICOLON;
  }
}

void ParserTracer::SetRollBackFlag ( bool is ) {
  if ( is ) {
    //00000010
    parser_flags_ = parser_flags_ | 0x2;
  } else {
    parser_flags_ = RESET_ROLLBACK;
  }
}

void ParserTracer::SetLineBreakFlag ( bool is ) {
  if ( is ) {
    //00000100
    parser_flags_ = parser_flags_ | 0x4;
  } else {
    parser_flags_ = RESET_LINE_BREAK;
  }
}

void ParserTracer::SetIncludeFlag ( bool is ) {
  if ( is ) {
    //00001000
    parser_flags_ = parser_flags_ | 0x8;
  } else {
    parser_flags_ = RESET_INCLUDE;
  }
}

void ParserTracer::SyntaxError ( long int line , const char* message ) {
  //00010000
  parser_flags_ = parser_flags_ | 0x10;
  errorLine_ = line;
  message_ = message;
}
