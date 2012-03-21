#include <mocha/roaster/roaster.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/fileinfo/fileinfo.h>

namespace mocha {
#ifdef _WIN32
static void YieldSleep(int num) {
	Sleep(num * 1000);
}
#else
static void YieldSleep(int num) {
	sleep(num);
}
#endif
Roaster::Roaster(){Initialize();}
void Roaster::Initialize() {
  AtomicWord ret = Atomic::CompareAndSwap(&entered_, 0, 1);
  if ( ret == 1) {
    return;
  }
  entered_ = 1;
  JsToken::Initialize();
  Compiler::BuildRuntime();
}
AtomicWord Roaster::entered_ = 0;
CompilationResultHandle Roaster::CompileFile(CompilationInfoHandle info) {
  info->MarkAsFile();
  Compiler compiler(info);
  return compiler.Compile();
}

CompilationResultHandle Roaster::Compile(CompilationInfoHandle info) {
  Compiler compiler(info);
  return compiler.Compile();
}

CompilationResultHandleList Roaster::CompileFiles(CompilationInfoHandleList& info_list) {
  typedef CompilationInfoHandleList R;
  typedef R::iterator Ri;
  Ri end = info_list.end();
  CompilationResultHandleList result(new CompilationResultList);
  for (Ri iterator = info_list.begin(); iterator != end; ++iterator) {
    (*iterator)->MarkAsFile();
    Compiler compiler(*iterator);
    result->push_back(compiler.Compile());
  }
  return result;
}
struct BoolContainer {
	bool end;
};
class ThreadArgs {
 public :
  ThreadArgs(CompilationInfoHandle hd, AsyncCallbackHandle cb, int count, AtomicWord* current_val, BoolContainer* is_end)
      : handle(hd), callback(cb), all_file_count(count), current(current_val), end(is_end){}
  CompilationInfoHandle handle;
  AsyncCallbackHandle callback;
  int all_file_count;
  AtomicWord* current;
  BoolContainer* end;
};
void* AsyncThreadRunner(void* args) {
  ThreadArgs* thread_args = static_cast<ThreadArgs*>(args);
  Compiler compiler(thread_args->handle);
  CompilationResultHandle result = compiler.Compile();
  thread_args->callback->operator()(result);
  if (thread_args->current != 0) {
    if (Atomic::Increment(thread_args->current) == thread_args->all_file_count) {
      thread_args->end->end = true;
    }
  }
  delete thread_args;
  return 0;
}

void AsyncRunner(ThreadArgs* args, bool is_join) {
  os::Thread thread;
  if (!thread.Create(AsyncThreadRunner, args)) {
    fprintf(stderr, "error at Roaster::CompileAsync");
  } else {
    if (is_join) {
      thread.Join();
    } else {
      thread.Detach();
    }
  }
}

void Roaster::CompileAsync(CompilationInfoHandle info, bool is_join, AsyncCallbackHandle callback) {
  ThreadArgs* args = new ThreadArgs(info, callback, 1, 0, 0);
  AsyncRunner(args, is_join);
}

void Roaster::CompileFileAsync(CompilationInfoHandle info, bool is_join, AsyncCallbackHandle callback) {
  info->MarkAsFile();
  ThreadArgs* args = new ThreadArgs(info, callback, 1, 0, 0);
  AsyncRunner(args, is_join);
}

void Roaster::CompileFilesAsync(CompilationInfoHandleList& info_list, bool is_join, AsyncCallbackHandle callback) {
  typedef CompilationInfoHandleList R;
  typedef R::iterator Ri;
  Ri end = info_list.end();
  int size = info_list.size();
  AtomicWord count = 0;
  BoolContainer flg;
  flg.end = false;
  for (Ri iterator = info_list.begin(); iterator != end; ++iterator) {
    CompilationInfoHandle handle = (*iterator);
    handle->MarkAsFile();
    ThreadArgs* args = new ThreadArgs(handle, callback, size, &count, &flg);
    AsyncRunner(args, is_join);
  }
  while (!(flg.end)) {YieldSleep(1);}
}

AstReserver Roaster::GetAstFromFile(CompilationInfoHandle info) {
  info->MarkAsFile();
  Compiler compiler(info);
  return compiler.GetAst();
}

AstReserver Roaster::GetAst(CompilationInfoHandle info) {
  Compiler compiler(info);
  return compiler.GetAst();
}
}
