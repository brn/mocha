#include <mocha/roaster/roaster.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/misc/thread/thread.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/fileinfo/fileinfo.h>
namespace mocha {
Roaster::Roaster(){Initialize();}
void Roaster::Initialize() {
  AtomicWord ret = Atomic::CompareAndSwap(&entered_, 0, 1);
  if ( ret == 1) {
    return;
  }
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

typedef std::pair<CompilationInfoHandle,AsyncCallbackHandle> ThreadArgs;
void* AsyncThreadRunner(void* args) {
  ThreadArgs* thread_args = static_cast<ThreadArgs*>(args);
  Compiler compiler(thread_args->first);
  (*(thread_args->second))(compiler.Compile());
  delete thread_args;
  return 0;
}

void AsyncRunner(CompilationInfoHandle info, bool is_join, AsyncCallbackHandle callback) {
  Thread thread;
  ThreadArgs* args = new ThreadArgs(info, callback);
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
  AsyncRunner(info, is_join, callback);
}

void Roaster::CompileFileAsync(CompilationInfoHandle info, bool is_join, AsyncCallbackHandle callback) {
  info->MarkAsFile();
  AsyncRunner(info, is_join, callback);
}

void Roaster::CompileFilesAsync(CompilationInfoHandleList& info_list, bool is_join, AsyncCallbackHandle callback) {
  typedef CompilationInfoHandleList R;
  typedef R::iterator Ri;
  Ri end = info_list.end();
  for (Ri iterator = info_list.begin(); iterator != end; ++iterator) {
    (*iterator)->MarkAsFile();
    AsyncRunner(*iterator, is_join, callback);
  }
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
