#include <string.h>
#include <string>
#include <compiler/utils/compiler_starter.h>
#include <compiler/compiler.h>
#include <utils/thread/thread.h>
#include <utils/file_watcher/observer/file_observer.h>
#include <options/setting.h>

namespace mocha {
void CompilerStarter::StartCompile( const char* path ) {
  Thread thread;
  char* arg = new char[ strlen( path ) + 1 ];
  strcpy( arg , path );
  if ( !thread.Create ( ThreadRunner , arg ) ) {
    Setting::GetInstance()->LogFatal( "in %s thread create fail." , __func__ );
  } else {
    thread.Join();
  }
}
void* CompilerStarter::ThreadRunner( void* args ) {
  const char* filename = reinterpret_cast<const char*> ( args );
  std::string arg = filename;
  Compiler* compiler = Compiler::CreateInstance( arg.c_str() );
  compiler->Compile ();
  delete[] filename;
  return 0;
}


}
