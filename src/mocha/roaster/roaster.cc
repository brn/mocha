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
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/nexc/nexc.h>
#include <mocha/roaster/nexl/nexl.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/external/external_ast.h>

namespace mocha {
Roaster::Roaster(){}
CompilationResultHandle Roaster::CompileFile(const char* filename, const char* charset, CompilationInfo* info) {
  Nexc nexc(info);
  Nexl nexl(filename, info, memory::Pool::Local());
  nexc.CompileFile(filename, charset);
  return nexl.Link(nexc.GetResult(), nexc.Errors());
}

CompilationResultHandle Roaster::Compile(const char* source, const char* charset, CompilationInfo* info) {
  Nexc nexc(info);
  Nexl nexl("anonymouse", info, memory::Pool::Local());
  nexc.Compile(source, charset);
  return nexl.Link(nexc.GetResult(), nexc.Errors());
}
void* Roaster::AsyncThreadRunner(void* args) {
  ThreadArgs* thread_args = static_cast<ThreadArgs*>(args);
  Nexc nexc(thread_args->info);
  Nexl nexl(thread_args->source_or_filename.c_str(), thread_args->info, memory::Pool::Local());
  if (thread_args->is_file) {
    nexc.CompileFile(thread_args->source_or_filename.c_str(), thread_args->charset.c_str());
  } else {
    nexc.Compile(thread_args->source_or_filename.c_str(), thread_args->charset.c_str());
  }
  CompilationResultHandle ret = nexl.Link(nexc.GetResult(), nexc.Errors());
  thread_args->NotifyForKey(ThreadArgs::kComplete, ret.Get());
  delete thread_args;
  return 0;
}

void Roaster::AsyncRunner(ThreadArgs* args, bool is_join) {
  os::Thread thread;
  if (!thread.Create(AsyncThreadRunner, args)) {
    FATAL("error at Roaster::CompileAsync");
  } else {
    if (is_join) {
      thread.Join();
    } else {
      thread.Detach();
    }
  }
}
const char Roaster::ThreadArgs::kComplete[] = {"Roaster<Complete>"};
}
