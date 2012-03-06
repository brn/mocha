#include <string.h>
#include <string>
#include <mocha/roaster/utils/compiler_facade.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/file_watcher/observer/file_observer.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/utils/compile_result.h>
#include <mocha/roaster/misc/atomic.h>
#include <mocha/roaster/file_system/file_system.h>
namespace mocha {

void CompilerFacade::Compile(const char* path, bool is_join) {
  ThreadArgs *args = new ThreadArgs(new Thread, path, &noop_);
  Compile_(args, is_join);
}

void CompilerFacade::Compile(const char* path, bool is_join, FinishDelegator* callback) {
  ThreadArgs *args = new ThreadArgs(new Thread, path, callback);
  Compile_(args, is_join);
}


SharedPtr<ExternalAst> CompilerFacade::GetAst(const char* path, bool is_runtime) {
  Compiler compiler(path, &noop_);
  SharedPtr<PathInfo> info = filesystem::GetPathInfo(path);
  ErrorReporter reporter;
  return compiler.GetAst(&reporter, info, is_runtime);
}


void CompilerFacade::Compile_(ThreadArgs *args, bool is_join) {
  if (!args->thread->Create (InternalThreadRunner, args)) {
    Setting::GetInstance()->LogFatal("in %s thread create fail.", __func__);
  } else {
    if (is_join) {
      args->thread->Join();
    } else {
      args->thread->Detach();
    }
  }
}

void* CompilerFacade::ExternalThreadRunner(void* args) {
  const char *filename = reinterpret_cast<const char*>(args);
  Compiler compiler(filename, &noop_);
  compiler.Compile();
  delete filename;
  return 0;
}

class ParallelDelegator : public FinishDelegator {
 public :
  ParallelDelegator(int size) :
      size_(size), is_end_(false), current_(0) {}
  ~ParallelDelegator(){}
  void Delegate(SharedPtr<CompilationInfo> result) {
    MutexLock lock(mutex_);
    if (Atomic::Increment(&current_) == size_) {
      is_end_ = true;
    }
    const ErrorMap *map = &(result->GetErrorMap());
    if (map->size() > 0) {                    
      ErrorMap::const_iterator iterator;
      for (iterator = map->begin(); iterator != map->end(); ++iterator) {
        std::string buf;
        iterator->second->SetRawError(&buf);
        if (buf.size() > 0) {
          errors_ += "---error---filename => ";
          errors_ += iterator->first.c_str();
          errors_ += "---\n";
          errors_ += buf.c_str();
          errors_ += "-------------------------------------------------------------------\n\n";
        }
      }
    }
  }
  bool IsEnd() { return is_end_; }
  void PrintError() {
    if (errors_.size() > 0) {
      fprintf(stderr, "%s\n", errors_.c_str());
    }
  }
 private :
  static Mutex mutex_;
  int size_;
  bool is_end_;
  std::string errors_;
  AtomicWord current_;
};

Mutex ParallelDelegator::mutex_;

void CompilerFacade::Compile() {
  int i = file_list_.size();
  FileList::iterator begin = file_list_.begin(),end = file_list_.end();
  ParallelDelegator delegator(i);
  while (begin != end) {
    CompilerFacade::Compile(begin->first, begin->second, &delegator);
    ++begin;
  }
  while (!delegator.IsEnd()){}
  delegator.PrintError();
}

void CompilerFacade::AddCompileList(const char* filename, bool is_join) {
  EachArgs args(filename, is_join);
  file_list_.push_back(args);
}

void* CompilerFacade::InternalThreadRunner(void* args) {
  ThreadArgs *compile_args = static_cast<ThreadArgs*>(args);
  Compiler compiler(compile_args->filename, compile_args->callback);
  compiler.Compile();
  delete compile_args;
  return 0;
}

FinishDelegator CompilerFacade::noop_;
}
