#ifndef mocha_compiler_starter_h_
#define mocha_compiler_starter_h_
#include <vector>
#include <useconfig.h>
#include <utils/smart_pointer/ref_count/handle.h>
namespace mocha {
class CompileResult;
class Thread;
class ExternalAst;
class FinishDelegator {
 public :
  virtual void Delegate( Handle<CompileResult> result ){};
};
class CompilerFacade{
 public :
  typedef std::pair<const char*,FinishDelegator*> ThreadArgs;
  typedef std::pair<const char* , bool> EachArgs;
  typedef std::vector<EachArgs> FileList;
  CompilerFacade(){};
  static void Compile( const char* path , bool is_join );
  static void Compile( const char* path , bool is_join , FinishDelegator* callback );
  static Handle<ExternalAst> GetAst( const char* path , bool is_runtime );
  static void* ExternalThreadRunner( void *arg );
  void AddCompileList( const char* path , bool is_join );
  void Compile();
 private :
  static void Compile_( Thread *thread , ThreadArgs* args , bool is_join );
  static void* InternalThreadRunner( void *arg );
  static FinishDelegator noop_;
  FileList file_list_;
};
}

#endif
