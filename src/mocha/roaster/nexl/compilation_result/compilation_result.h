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
#ifndef mocha_compile_result_h_
#define mocha_compile_result_h_
#include <mocha/roaster/platform/fs/path/path.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
namespace mocha {
typedef SharedPtr<CodegenVisitor> CodeHandle;
typedef SharedPtr<ErrorReporter> ErrorHandle;
class CompilationResult {
  typedef SharedPtr<std::vector<std::string> > DepsListHandle;
 public :
  CompilationResult(SharedPtr<os::fs::Path> path,  CodeHandle visitor, ErrorHandle reporter, DepsListHandle handle);
  ~CompilationResult(){}
  const char* filename() { return path_->filename(); }
  const char* fullpath() {return path_->absolute_path();}
  const char* dir() {return path_->directory();}
  const char* source() { return codegen_->GetCode(); }
  const ErrorReporter* error() { return reporter_.Get(); }
  const DepsListHandle deps() const {return deps_;}
 private :
  SharedPtr<os::fs::Path> path_;
  CodeHandle codegen_;
  ErrorHandle reporter_;
  DepsListHandle deps_;
};
typedef SharedPtr<CompilationResult> CompilationResultHandle;
}

#endif
