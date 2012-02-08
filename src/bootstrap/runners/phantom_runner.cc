#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <bootstrap/runners/phantom_runner.h>
#include <options/setting.h>

namespace mocha {
#ifdef _WIN32
void DoRun( const char* ) {
  
}
#else
#define R (0)
#define W (1)
int DoRun( const char* command ) {
  int pid;
  char *env = getenv( "PHANTOM_INSTALL_DIR" );
  if ( env == NULL ) {
    return -1;
  }
  std::string arg = "";
  arg += env;
  arg += "phantomjs ";
  arg += Setting::GetInstance()->GetBasePath();
  arg += "run-phantom.js ";
  arg += command;
  arg += "";

  
  FILE *fp;
  if ( ( fp = popen( arg.c_str() , "r" ) ) == NULL ) {
    fprintf( stderr , "error!!!\n" );
    exit( -1 );
  }
  char ch;
  std::string buf;
  while ( ( ch = fgetc( fp ) ) != EOF && ch ) {
    buf += ch;
  }
  fprintf( stderr , "%s" , buf.c_str() );
  pclose( fp );
  /*
  if ( ( pid = fork() ) < 0 ) {
    perror( "popen2" );
    return -1;
  }
  if ( pid == 0 ) {
    if ( execlp( "sh" , "sh" , "-c", arg.c_str(), static_cast<char*>( NULL ) ) < 0 ) {
      perror("popen2");
    }
  } else {
    int status;
    ::wait( &status );
  }
  return(pid);*/
}
#endif
void PhantomRunner::Run( const char* command ) {
  DoRun( command );
}

}