/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include "parser_connector.h"
#include "scanner.h"
#include "parser_tracer.h"
#include "scope.h"
#include "ast_type.h"
#include "grammar.tab.hh"
#include "token_info.h"
#include "managed_handle.h"

namespace mocha {
class ParserConnector::Implementation {
 public :
  typedef yy::ParserImplementation::semantic_type* TokenValue;
  explicit Implementation ( ParserConnector* parent ) : isLine_ ( false ) , parent_ ( parent ) {};

  inline int InsertSemicolon ( TokenValue yylval ) {
    parent_->tracer->SetSemicolonFlag ( false );
    yylval->info = 0;
    return ';';
  }
  
  inline int Rollback ( TokenValue yylval ) {
    parent_->tracer->SetRollBackFlag ( false );
    if ( isLine_ ) {
      yylval->line = line_;
      yylval->info = 0;
    } else {
      yylval->info = &(info_);
    }
    return type_;
  }
  
  inline int GetToken ( TokenValue yylval ) {
    const char *ret = parent_->scanner->GetToken ();
    int type = parent_->scanner->GetType ();
    int line = parent_->scanner->GetLineNumber ();
    
    if ( ret == 0 && type == yy::ParserImplementation::token::JS_LINE_BREAK ) {
      Linebreak_ ( yylval , line );
    } else if ( ret == 0 ) {
      return 0;
    } else {
      GetToken_ ( yylval , ret , type , line );
    }
    return type;
  }
  
 private :
  inline void Linebreak_ ( TokenValue yylval , int line ) {
    yylval->line = line;
    yylval->info = 0;
    parent_->tracer->SetLineBreakFlag ( true );
  }

  inline void GetToken_ ( TokenValue yylval , const char* ret , int type , int line ) {
    if ( type < 200 ) {
      NotTokenType_ ( yylval , line );
    } else {
      TokenType_ ( yylval , ret , type , line );
    }
    type_ = type;
  }

  inline void NotTokenType_ ( TokenValue yylval , int line ) {
    yylval->line = line;
    yylval->info = 0;
    line_ = line;
    isLine_ = true;
  }

  inline void TokenType_ ( TokenValue yylval , const char* ret , int type , int line ) {
    yylval->info = new TokenInfo ( ret , type , line );
    ManagedHandle::Retain ( yylval->info );
    info_ = (*yylval->info);
    isLine_ = false;
  }
  
  TokenInfo info_;
  long int line_;
  bool isLine_;
  int type_;
  ParserConnector* parent_;
};

mocha::ParserConnector::ParserConnector ( Compiler *compiler,
                                        Scanner *scanner,
                                        ParserTracer* tracer ,
                                        AstRoot* ast_root,
                                        Scope* scope ) :
    compiler_ ( compiler ) , scanner ( scanner ) , tracer ( tracer ),
    ast_root_ ( ast_root ) , scope ( scope )
{
  implementation_ ( new Implementation ( this ) );
}

mocha::ParserConnector::~ParserConnector () {};


int mocha::ParserConnector::InvokeScanner ( void* yylval_ ) {
  Implementation::TokenValue yylval = reinterpret_cast<Implementation::TokenValue> ( yylval_ );
  if ( tracer->GetSemicolonFlag () ) { 
    return implementation_->InsertSemicolon ( yylval );
  } else if ( tracer->GetRollBackFlag () ) {
    return implementation_->Rollback ( yylval );
  } else {
    return implementation_->GetToken ( yylval );
  }
}

int mocha::ParserConnector::ParseStart () {
  yy::ParserImplementation parser ( compiler_ , this , tracer , ast_root_ , scope );
  return parser.parse ();  
}

long int ParserConnector::GetLineNumber () { return scanner->GetLineNumber (); }

}
