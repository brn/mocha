
#include "pwd.h"
#ifdef _WIN32
#include "win32api.h"
#else
#include <unistd.h>
#endif

using namespace mocha;

#ifdef _WIN32
StrHandle mocha::ReplaceBackSlash( const char* path ) {
  int len = strlen( path );
  char* buf = new char[ ( len + 1 ) ];
  strcpy( buf , path );
  for ( int i = 0; i < len; i++ ) {
    if ( buf [ i ] == '\\' ) {
      buf [ i ] = '/';
    }
  }
  StrHandle handle( buf );
  return handle;
}
#endif

StrHandle mocha::GetCwd () {

#ifdef _WIN32  
  char buf[ GW_BUF_SIZE ];
  DWORD isSuccess = GetCurrentDirectory ( sizeof ( buf ) , buf );
  
  if ( !isSuccess ) {
    throw "GetCwd fail.";
  }

  return ReplaceBackSlash( buf );

#else

  char *buf = new char [ GW_BUF_SIZE ];
  char* dir = getcwd ( buf , sizeof ( char ) * GW_BUF_SIZE );
  if ( !dir ) {
    throw "GetCwd fail.";
  };

  StrHandle path ( buf );
  return path;

#endif

};

