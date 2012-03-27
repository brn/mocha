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
#ifndef mocha_roaster_roaster_h_
#define mocha_roaster_roaster_h_
#include <vector>
#include <utility>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/roaster/nexl/compilation_result/compilation_result.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
namespace mocha {
class Roaster {
 public :
  Roaster();
  ~Roaster(){}
  CompilationResultHandle CompileFile(const char* name, const char* charset, CompilationInfo*);
  CompilationResultHandle Compile(const char* source, const char* charset, CompilationInfo*);
  template <typename Listener>
  void CompileAsync(const char* source, const char* charset, CompilationInfo*, Listener, bool is_join = false);
  template <typename Listener>
  void CompileFileAsync(const char* name, const char* charset, CompilationInfo*, Listener, bool is_join = false);
 private :
  class ThreadArgs;
  void AsyncRunner(ThreadArgs* args, bool is_join);
  static void* AsyncThreadRunner(void* args);
};
}

#include <mocha/roaster/roaster-impl.h>

#endif
