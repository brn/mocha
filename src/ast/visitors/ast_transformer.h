/**
 *@author Taketoshi Aono
 *@fileOverview
 *The convertor of abstract syntax tree.
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
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
#ifndef mocha_ast_transformer_h_
#define mocha_ast_transformer_h_

#include <string>
#include <useconfig.h>
#include <ast/visitors/ivisitor.h>
#include <utils/smart_pointer/scope/scoped_ptr.h>

namespace mocha{
  
class Scope;
class Compiler;
class VisitorInfo;
class ProcessorInfo;

/**
 * @class
 * Transform harmony's ast to ecmascript3's.
 */
class AstTransformer : public IVisitor {
 public :
  /**
   * @constructor
   * @param {bool} is_runtime -> Compile module or not.
   * @param {Scope*} scope
   * @param {Compiler*} compiler 
   * @param {const char*} modulename -> Current file name.
   * @param {const char*} filename -> Main js file name.
   */
  AstTransformer( bool is_runtime,
                  ScopeRegistry* scope_registry,
                  Compiler* compiler,
                  const char* modulename,
                  const char* filename );
  ~AstTransformer();

#include <ast/visitors/visitor_decl.h>
  
 private:
  void JumpStmt_( AstNode* ast_node , int type );
  
  ScopedPtr<VisitorInfo> visitor_info_;
  ScopedPtr<ProcessorInfo> proc_info_;
  ScopeRegistry* scope_registry_;
};

}

#endif

