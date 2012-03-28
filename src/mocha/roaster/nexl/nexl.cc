/**
 *@author Taketoshi Aono
 *@fileOverview
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
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/nexl/nexl.h>
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/ast/visitors/optimizer_visitor.h>
#include <mocha/roaster/ast/visitors/symbol_collector.h>
namespace mocha {
Nexl::Nexl(const char* filename, CompilationInfo* info, memory::Pool* pool)
    : info_(info),
      pool_(pool) {
  os::fs::Path path(filename);
  filename_ = path.filename();
}

CompilationResultHandle Nexl::Link(AstRoot* root, SharedPtr<ErrorReporter> reporter) {
  ScopeRegistry scope_registry(pool_);
  SymbolCollector collector(&scope_registry, info_->Debug());
  root->Accept(&collector);
  if (info_->Compress()) {
    scope_registry.Rename();
  }
  OptimizerVisitor optimizer(info_);
  root->Accept(&optimizer);
  CodeHandle visitor(new CodegenVisitor(info_));
  root->Accept(visitor.Get());
  return CompilationResultHandle(new CompilationResult(filename_.c_str(), visitor, reporter));
}
}