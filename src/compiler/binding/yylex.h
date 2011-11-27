
#ifndef mocha_yylex_h
#define mocha_yylex_h
#include <compiler/binding/parser_connector.h>

extern int yylex( void* yylval,
                  void* yyloc,
                  mocha::ParserConnector* connector,
                  int yystate )
{
  return connector->InvokeScanner ( yylval , yystate );
}

extern int yylex( void* yylval,
                  mocha::ParserConnector* connector,
                  int yystate )
{
  return connector->InvokeScanner (  yylval , yystate );
}
#endif
