
#ifndef mocha_yylex_h
#define mocha_yylex_h
#include "parser_connector.h"

extern int yylex( void* yylval,
                  void* yyloc,
                  mocha::ParserConnector* connector )
{
  return connector->InvokeScanner ( yylval );
}

extern int yylex( void* yylval,
                  mocha::ParserConnector* connector )
{
  return connector->InvokeScanner (  yylval );
}
#endif
