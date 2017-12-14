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
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/environment/environment.h>

namespace mocha {
Roaster::Roaster() {
  int flag = atomic_val_.load(std::memory_order_relaxed);
  std::atomic_thread_fence(std::memory_order_acquire);
  if (flag == 0) {
    std::atomic_thread_fence(std::memory_order_release);
    atomic_val_.store(1, std::memory_order_relaxed);
    std::string path = os::fs::Path::home_directory();
    path += '/';
    path += ".roaster";
    os::fs::Stat stat(path.c_str());
    if (!stat.IsExist()) {
      os::fs::mkdir(path.c_str(), 0777);
      os::fs::Directory::chmod(path.c_str(), 0777);
    }
    path += "/roaster.log";
    //Logging::Initialize(path.c_str(), "a+b");
    Logging::Initialize(stdout);
  }
}

template <bool is_file>
class CompileTypeOf{};

template <>
class CompileTypeOf<true> {
 public :
  static void Run(Nexc* nexc, const char* str, const char* charset) {
    nexc->CompileFile(str, charset);
  }
};

template <>
class CompileTypeOf<false> {
 public :
  static void Run(Nexc* nexc, const char* str, const char* charset) {
    nexc->Compile(str, charset);
  }
};

template <bool is_file>
class CompileRunner {
 public :
  CompileRunner(const char* str, const char* charset, CompilationInfo* info)
      : str_(str),
        charset_(charset),
        info_(info){}
  void operator()() {
    Nexc nexc(info_);
    CompileTypeOf<is_file>::Run(&nexc, str_, charset_);
    Nexl nexl(str_, info_, nexc.GetDepends(), memory::Pool::Local());
    result_ = nexl.Link(nexc.GetResult(), nexc.Errors());
  }
  CompilationResultHandle result() const {return result_;}
 private :
  const char* str_;
  const char* charset_;
  CompilationInfo* info_;
  CompilationResultHandle result_;
};

class DepsRunner {
 public :
  DepsRunner(const char* name)
      : name_(name){}
  ~DepsRunner(){}
  void operator()() {
    CompilationInfo info;
    Nexc nexc(&info);
    nexc.CompileFile(name_);
    result_ = nexc.GetDepends();
  }
  DepsListHandle result() const {return result_;}
 private :
  DepsListHandle result_;
  const char* name_;
};

template <bool is_file>
CompilationResultHandle DoCompile(const char* filename, const char* charset, CompilationInfo* info) {
  CompileRunner<is_file> runner(filename, charset, info);
  Environment::Create(&runner);
  return runner.result();
}

//Run compiler.
//Compile javascript from source file.
CompilationResultHandle Roaster::CompileFile(const char* filename, const char* charset, CompilationInfo* info) {
  return DoCompile<true>(filename, charset, info);
}

//Run compiler
//Directly compile javascript from source.
CompilationResultHandle Roaster::Compile(const char* source, const char* charset, CompilationInfo* info) {
  return DoCompile<false>(source, charset, info);
}

//Run the thread.
void* Roaster::AsyncThreadRunner(void* args) {
  ThreadArgs* thread_args = static_cast<ThreadArgs*>(args);
  Nexc nexc(thread_args->info);
  if (thread_args->is_file) {
    nexc.CompileFile(thread_args->source_or_filename.c_str(), thread_args->charset);
  } else {
    nexc.Compile(thread_args->source_or_filename.c_str(), thread_args->charset);
  }
  Nexl nexl(thread_args->source_or_filename.c_str(), thread_args->info, nexc.GetDepends(), memory::Pool::Local());
  CompilationResultHandle ret = nexl.Link(nexc.GetResult(), nexc.Errors());
  thread_args->NotifyForKey(ThreadArgs::kComplete, ret.Get());
  delete thread_args;
  return 0;
}

//Create thread.
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

const DepsListHandle Roaster::CheckDepends(const char* name) {
  DepsRunner runner(name);
  Environment::Create(&runner);
  return runner.result();
}

const char Roaster::ThreadArgs::kComplete[] = {"Roaster<Complete>"};
std::atomic<uint32_t> Roaster::atomic_val_(0);
}
