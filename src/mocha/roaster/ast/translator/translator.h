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
#ifndef mocha_ast_translator_translator_h_
#define mocha_ast_translator_translator_h_

#include <string>
#include <mocha/roaster/ast/visitors/ivisitor.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>

namespace mocha{
namespace memory {
class Pool;
}
class Scope;
class Compiler;
class TranslatorData;
class ProcessorInfo;
class AstBuilder;
class CompilationEvent;
/**
 * @class
 * Transform harmony's ast to ecmascript3's.
 */
class Translator : public IVisitor {
 public :
  /**
   * @constructor
   * @param {bool} is_runtime -> Compile module or not.
   * @param {Scope*} scope
   * @param {Compiler*} compiler
   * @param {const char*} modulename -> Current file name.
   * @param {const char*} filename -> Main js file name.
   */
  Translator(bool is_runtime, CompilationEvent* e);
  ~Translator();

#include <mocha/roaster/ast/visitors/visitor_decl.h>

 private:
  void JumpStmt_(AstNode* ast_node, int type);
  memory::Pool* pool() { return pool_; }
  AstBuilder* builder() { return builder_; }
  CompilationEvent* event() {return event_;}

  memory::Pool* pool_;
  AstBuilder* builder_;
  CompilationEvent* event_;
  ScopedPtr<TranslatorData> translator_data_;
  ScopedPtr<TranslatorData> data_;
  ScopedPtr<ProcessorInfo> proc_info_;
};

}

#endif

