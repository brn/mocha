#include <mocha/roaster/roaster.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/misc/thread.h>
#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/external/external_resource.h>
namespace mocha {

Roaster::Roaster(){}
Roaster::~Roaster(){}

void Roaster::CompileFile(CompilationInfoHandle info) {
  info->MarkAsFile();
  Compiler compiler(info);
  compiler.Compile();
}

void Roaster::Compile(CompilationInfoHandle info) {
  Compiler compiler(info);
  return compiler.Compile();
}

void Roaster::CompileFiles(CompilationInfoHandleList& info_list) {
  typedef CompilationInfoHandleList R;
  typedef R::iterator Ri;
  Ri end = info_list.end();
  for (Ri iterator = info_list; iterator != end; ++iterator) {
    (*iterator)->MarkAsFile();
    Compiler compiler(*iterator);
    compiler.Compile();
  }
}

typedef std::pair<CompilationInfoHandle,AsyncCallback> ThreadArgs;
void* AsyncThreadRunner( void* args ) {
  ThreadArgs* thread_args = static_cast<ThreadArgs*>(args);
  Compiler compiler(thread_args->first);
  thread_args->second(compiler.Compile());
  delete args;
}

void AsyncRunner(CompilationInfoHandle info, bool is_join, AsyncCallback callback) {
  Thread thread;
  ThreadArgs args = new ThreadArgs(info, callback);
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

void Roaster::CompileAsync(CompilationInfoHandle info, bool is_join, AsyncCallback callback) {
  AsyncRunner(info, is_join, callback);
}

void Roaster::CompileFileAsync(CompilationInfoHandle info, bool is_join, AsyncCallback callback) {
  info->MarkAsFile();
  AsyncRunner(info, is_join, callback);
}

void Roaster::CompileFilesAsync(CompilationInfoHandleList& info_list, bool is_join, AsyncCallback callback) {
  typedef CompilationInfoHandleList R;
  typedef R::iterator Ri;
  Ri end = info_list.end();
  for (Ri iterator = info_list; iterator != end; ++iterator) {
    iterator->second->set_file();
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
