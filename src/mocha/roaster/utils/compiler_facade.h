#ifndef mocha_compiler_starter_h_
#define mocha_compiler_starter_h_
#include <vector>
#include <useconfig.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/misc/thread/thread.h>
namespace mocha {
class CompilationInfo;
class Thread;
class ExternalAst;
class FinishDelegator {
 public :
  virtual void Delegate(SharedPtr<CompilationInfo> result){};
};

struct ThreadArgs {
 public :
  ThreadArgs(Thread* th, const char* name, FinishDelegator *delegator) :
      exit(false), filename(name), callback(delegator), thread(th ) {}
  ~ThreadArgs() { delete thread; }
  bool exit;
  const char* filename;
  FinishDelegator* callback;
  Thread *thread;
};

class CompilerFacade{
 public :
  typedef std::pair<const char*, bool> EachArgs;
  typedef std::vector<EachArgs> FileList;
  CompilerFacade(){};
  static void Compile(const char* path, bool is_join);
  static void Compile(const char* path, bool is_join, FinishDelegator* callback);
  static SharedPtr<ExternalAst> GetAst(const char* path, bool is_runtime);
  static void* ExternalThreadRunner(void *arg);
  void AddCompileList(const char* path, bool is_join);
  void Compile();
 private :
  static void Compile_(ThreadArgs* args, bool is_join);
  static void* InternalThreadRunner(void *arg);
  static FinishDelegator noop_;
  FileList file_list_;
};
}

#endif
