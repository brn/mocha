#ifndef mocha_test_run_h_
#define mocha_test_run_h_
#include <string.h>
#include <bootstrap/runners/phantom_runner.h>
#include <compiler/external/external_resource.h>
#include <compiler/compiler.h>
#include <compiler/utils/compiler_facade.h>
#include <compiler/utils/compile_info.h>
#include <utils/file_system/file_system.h>
#include <bootstrap/bootstrap.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/file_system/directory.h>
#include <utils/thread/thread.h>
namespace mocha {namespace compiler_test {

std::string GetPath( const char* path ) {
  Handle<PathInfo> path_info = FileSystem::GetPathInfo( Bootstrap::GetSelfPath() );
  std::string result = path_info->GetDirPath().Get();
  result += '/';
  result += path;
  return result;
}

void* ThreadRunner( void* args ) {
  const char* path = reinterpret_cast<std::string*>( args )->c_str();
  PhantomRunner::Run( path );
  
}

void RunJS() {
  Directory directory( CURRENT_DIR"/test/js" );
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

void RunTest() {
  Directory directory( CURRENT_DIR"/test/js" );
  DirectoryIterator iterator = directory.GetFileList( true , false );
  CompilerFacade facade;
  while ( iterator.HasNext() ) {
    const DirEntry* entry = iterator.Next();
    const char* fullpath = entry->GetFullPath();
    int i = 0;
    if ( strstr( fullpath , "-cmp.js" ) == NULL ) {
      ExternalResource::UnsafeSet( fullpath );
      CompileInfo* info = ExternalResource::UnsafeGet( fullpath )->GetCompileInfo();
      info->SetDebug();
      info->SetPrettyPrint();
      facade.AddCompileList( fullpath , true );
      i++;
    }
  }
  facade.Compile();
  RunJS();
}


}}
#endif
