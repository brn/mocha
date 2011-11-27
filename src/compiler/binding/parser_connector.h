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

#ifndef mocha_parser_connector_h_
#define mocha_parser_connector_h_

#include <string>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>

namespace mocha {
  
class Compiler;
class ParserTracer;
class Scanner;
class Scope;
class AstPtr;
class AstRoot;
class TokenInfo;
class QueueScanner;

/**
 * @class
 * Connector of mocha and bison generated parser.
 */
class ParserConnector {
  
 public:

  /**
   * @construcor
   * @param {Compiler*} compiler -> Compiler instance.
   * @param {Scanner*} scanner -> Scanner instance.
   * @param {ParserTracer*} tracer -> ParserTracer instance.
   * @param {AstRoot*} ast_root -> AstRoot instance.
   * @param {Scope*} scope -> Scope instance.
   */
  ParserConnector ( Compiler *compiler,
                    ParserTracer* tracer ,
                    AstRoot* ast_root,
                    const std::string& source );
  
  ~ParserConnector ();

  /**
   * @public
   * @param {void*} yylval -> Type erasured args. real type is ParserImplementation::semantic_type*
   * Run mocha::Scanner::GetToken().
   */
  int InvokeScanner ( void* yylval , int yystate );

  /**
   * @public
   * Start bison parser. 
   */
  int ParseStart ();

  /**
   * @public
   * Get current token linenumber.
   */
  long int GetLineNumber ();

 private :
  long int line_;
  bool is_end_;
  Compiler* compiler_;
  ParserTracer *tracer;
  Scope* scope;
  AstRoot* ast_root_;
  //pimpl idiom.
  ScopedPtr<QueueScanner> scanner_;
  
};

}

#endif

