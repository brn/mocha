#include <string.h>
#include <string>
#include "compiler_starter.h"
#include "compiler.h"
#include "thread.h"
#include "file_observer.h"
#include "setting.h"

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
