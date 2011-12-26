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
#include <compiler/binding/parser_connector.h>
#include <compiler/binding/parser_tracer.h>
#include <compiler/scopes/scope.h>
#include <ast/ast.h>
#include <grammar/grammar.tab.hh>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/js_token.h>
#include <compiler/scanner/queue_scanner.h>

namespace mocha {
ParserConnector::ParserConnector ( Compiler *compiler,
                                     ParserTracer* tracer ,
                                     AstRoot* ast_root,
                                     const std::string& source ) :
    line_( 0 ) , is_end_( false ), compiler_ ( compiler ) , tracer ( tracer ),
    ast_root_ ( ast_root ) , scanner_( new QueueScanner( source , tracer ) ){
  scanner_->CollectToken();
}

ParserConnector::~ParserConnector () {};


int ParserConnector::InvokeScanner ( void* yylval_ , int yystate ) {
  if ( is_end_ ) return 0;
  yy::ParserImplementation::semantic_type* yylval = reinterpret_cast<yy::ParserImplementation::semantic_type*> ( yylval_ );
  TokenInfo* info = scanner_->GetToken( yystate );
  if ( info->GetType() == 0 ) {
    is_end_ = true;
    return 0;
  }
  line_ = info->GetLineNumber();
  yylval->info = info;
printf( "%s\n" ,info->GetToken() );
  return JsToken::ToParserToken( info->GetType() );
}

int ParserConnector::ParseStart () {
  yy::ParserImplementation parser ( compiler_ , this , tracer , ast_root_ );
  return parser.parse ();
}

long int ParserConnector::GetLineNumber () { return line_; }

}
