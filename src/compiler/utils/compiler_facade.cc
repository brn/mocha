#include <string.h>
#include <string>
#include <compiler/utils/compiler_facade.h>
#include <compiler/utils/error_reporter.h>
#include <compiler/external/external_ast.h>
#include <compiler/compiler.h>
#include <utils/thread/thread.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/file_watcher/observer/file_observer.h>
#include <options/setting.h>
#include <compiler/utils/compile_result.h>
#include <utils/atomic.h>
#include <utils/file_system/file_system.h>
namespace mocha {

void CompilerFacade::Compile( const char* path , bool is_join ) {
  Thread thread;
  ThreadArgs *args = new ThreadArgs( path , &noop_ );
  Compile_( &thread , args  , is_join );
}

void CompilerFacade::Compile( const char* path , bool is_join , FinishDelegator* callback ) {
  Thread thread;
  ThreadArgs *args = new ThreadArgs( path , callback );
  Compile_( &thread , args , is_join );
}


Handle<ExternalAst> CompilerFacade::GetAst( const char* path , bool is_runtime ) {
  Compiler* compiler = Compiler::CreateInstance( path , &noop_ );
  Handle<PathInfo> info = FileSystem::GetPathInfo( path );
  ErrorReporter reporter;
  return compiler->GetAst( &reporter , info , is_runtime );
}


void CompilerFacade::Compile_( Thread *thread , ThreadArgs *args , bool is_join ) {
  if ( !thread->Create ( InternalThreadRunner , args ) ) {
    Setting::GetInstance()->LogFatal( "in %s thread create fail." , __func__ );
  } else {
    if ( is_join ) {
      thread->Join();
    } else {
      thread->Detach();
    }
  }
}

void* CompilerFacade::ExternalThreadRunner( void* args ) {
  const char *filename = reinterpret_cast<const char*>( args );
  Compiler* compiler = Compiler::CreateInstance( filename , &noop_ );
  compiler->Compile();
  delete filename;
  return 0;
}

class ParallelDelegator : public FinishDelegator {
 public :
  ParallelDelegator( int size ) :
      size_( size ) , is_end_( false ) , current_( 0 ) {}
  ~ParallelDelegator(){}
  void Delegate( Handle<CompileResult> result ) {
    MutexLock lock( mutex_ );
    printf( "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@end %s\n" , result->GetFilename() );
    if ( Atomic::Increment( &current_ ) == size_ ) {
      is_end_ = true;
    }
    const ErrorMap *map = &(result->GetErrorMap());
    if ( map->Size() > 0 ) {      
      ErrorMap::EntryIterator iterator = map->Entries();
      while ( iterator.HasNext() ) {
        std::string buf;
        ErrorMap::HashEntry entry = iterator.Next();
        if ( !entry.IsEmpty() ) {
          entry.Value()->SetRawError( &buf );
          if ( buf.size() > 0 ) {
            errors_ += "---error---filename => ";
            errors_ += entry.Key().c_str();
            errors_ += "---\n";
            errors_ += buf.c_str();
            errors_ += "-------------------------------------------------------------------\n\n";
          }
        }
      }
    }
  }
  bool IsEnd() { return is_end_; }
  void PrintError() {
    if ( errors_.size() > 0 ) {
      fprintf( stderr , "%s\n" , errors_.c_str() );
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
  ParallelDelegator delegator( i );
  while ( begin != end ) {
    CompilerFacade::Compile( begin->first , begin->second , &delegator );
    ++begin;
  }
  while ( !delegator.IsEnd() ){}
  delegator.PrintError();
}

void CompilerFacade::AddCompileList( const char* filename , bool is_join ) {
  EachArgs args( filename , is_join );
  file_list_.push_back( args );
}

void* CompilerFacade::InternalThreadRunner( void* args ) {
  ThreadArgs *compile_args = reinterpret_cast<ThreadArgs*>( args );
  Compiler* compiler = Compiler::CreateInstance( compile_args->first , compile_args->second );
  compiler->Compile();
  delete compile_args;
  return 0;
}

FinishDelegator CompilerFacade::noop_;
}
