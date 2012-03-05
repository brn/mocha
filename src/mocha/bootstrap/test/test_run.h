#ifndef mocha_test_run_h_
#define mocha_test_run_h_
#include <string.h>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/utils/compile_result.h>
#include <mocha/bootstrap/runners/phantom_runner.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/utils/compile_info.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/file_system/directory.h>
#include <mocha/roaster/misc/thread/thread.h>
namespace mocha {namespace compiler_test {

class TestCallback {
 public :
  TestCallback(int size) :
      size_(size), is_end_(false), current_(0) {}
  ~TestCallback(){}
  void operator() (CompilationResultHandle result) {
    MutexLock lock(mutex_);
    if (Atomic::Increment(&current_) == size_) {
      is_end_ = true;
    }
    const ErrorMap *map = &(result->error_map());
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

std::string GetPath( const char* path ) {
  FileSystem::Path fs_path( Bootstrap::GetSelfPath() );
  std::string result = fs_path.directory();
  result += '/';
  result += path;
  return result;
}

void* ThreadRunner( void* args ) {
  const char* path = reinterpret_cast<std::string*>( args )->c_str();
  PhantomRunner::Run( path );
  return 0;
}

void RunJS( const char* dir ) {
  Directory directory( dir );
  DirectoryIterator iterator = directory.GetFileList( true , false );
  std::string args;
  while ( iterator.HasNext() ) {
    const DirEntry* entry = iterator.Next();
    const char* fullpath = entry->GetFullPath();
    if ( strstr( fullpath , "-cmp.js" ) != NULL ) {
      args += fullpath;
      args += " ";
    }

  }
  Thread thread;
  thread.Create( ThreadRunner , &args );
  thread.Join();
}

void RunTest( bool is_debug , bool is_pretty , bool is_compress , const char* dir ) {
  Directory directory( CURRENT_DIR"/test/js" );
  DirectoryIterator iterator = directory.GetFileList( true , false );
  Roaster roaster;
  CompilationInfoHandleList list;
  while ( iterator.HasNext() ) {
    const DirEntry* entry = iterator.Next();
    const char* fullpath = entry->GetFullPath();
    if ( strstr( fullpath , "-cmp.js" ) == NULL && strstr( fullpath , ".js" ) != NULL ) {
      CompilationInfoHandle info(new CompilationInfo(fullpath));
      if ( is_debug ) {
        info->SetDebug();
      }
      if ( is_pretty ) {
        info->SetPrettyPrint();
      }
      if ( is_compress ) {
        info->SetCompress();
      }
      list.push_back(info);
    }
  }
  TestCallback callback(list.size());
  AsyncCallback async_callback = callback;
  roaster.CompileFilesAsync(list, true, async_callback);
  RunJS( dir );
}

void RunTest() {
  RunTest( true , true , false , CURRENT_DIR"/test/js/out/devel" );
  fprintf( stderr , "------------------end devel test------------------\n" );
  RunTest( false , false , true , CURRENT_DIR"/test/js/out/compressed" );
  fprintf( stderr , "------------------end compress test------------------\n" );
}

}}
#endif
