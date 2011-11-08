#include "useconfig.h"
#ifdef HAVE_WINDOWS_H
#include <windows.h>
#else
#include <unistd.h>
#include <string.h>
#endif
#include "pwd.h"
#include "char_allocator.h"

using namespace mocha;

#ifdef _WIN32
StrHandle mocha::ReplaceBackSlash( const char* path ) {
  char* ret = utils::CharAlloc( path );
  int len = strlen( path );
  for ( int i = 0; i < len; i++ ) {
    if ( ret[ i ] == '\\' ) {
      ret[ i ] = '/';
    }
  }
  return StrHandle( ret );
}
#endif

StrHandle mocha::GetCwd () {

#ifdef HAVE_WINDOWS_H
  char tmp[ GW_BUF_SIZE ];
  DWORD isSuccess = GetCurrentDirectory ( sizeof ( tmp ) , tmp );
  
  if ( !isSuccess ) {
    fprintf( stderr , "GetCwd fail." );
  }

  return ReplaceBackSlash( tmp );

#else

  char tmp[ GW_BUF_SIZE ];
  char* dir = getcwd ( tmp , sizeof ( tmp ) );
  if ( !dir ) {
    fprintf( stderr , "GetCwd fail." );
  };
  char* ret = utils::CharAlloc( tmp );
  return StrHandle( ret ); 

#endif

};

