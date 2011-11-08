
#include "file_system.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <string>

#include "file_io.h"
#include "useconfig.h"
#include "stat.h"
#include "mkdir.h"
#include "char_allocator.h"

#ifdef _WIN32
#define HOME "HOMEPATH"
#ifdef HAVE_IO_H
#include <io.h>
#endif
#define chmod(name,permiss) _chmod(name,permiss)
#else
#define HOME "HOME"
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 1028
#endif

#ifdef HAVE_REALPATH
#define FULL_PATH( path , tmp ) realpath( path , tmp )
#elif HAVE__FULLPATH
#define FULL_PATH( path , tmp ) _fullpath( tmp , path , MAXPATHLEN )
#endif

using namespace mocha;

PathInfo::PathInfo( const char* path ) :
    raw_path_( path ) , filepath_( GetFileNameFromPath_( path ) ) , dir_( GetDirectoryFromPath_( path ) ){}

const char* PathInfo::GetDirectoryFromPath_( const char* path ) {
  int index = strlen( path );
  std::string tmp = path;
  bool is_slashed = false;
  while ( index-- ) {
    if ( is_slashed ) {
      break;
    }
    if ( path[ index ] == '/' ) {
      is_slashed = true;
    }
  }
  tmp.erase( index + 1 , tmp.size() );
  char* ret = new char[ tmp.size() + 1 ];
  strcpy( ret , tmp.c_str() );
  return ret;
}

const char* PathInfo::GetFileNameFromPath_( const char* path ) {
  std::string tmp;
  const char* ptr = strrchr( path , '/' );
  if ( ptr ) {
    tmp = ( ptr + 1 );
  }
  char* ret = new char[ tmp.size() + 1 ];
  strcpy( ret, tmp.c_str() );
  return ret;
}

StrHandle FileSystem::pwd () {
  return GetCwd ();
}

Handle<PathInfo> FileSystem::GetPathInfo( const char* path ) {
  char* raw_path = new char[ strlen( path ) + 1 ];
  strcpy( raw_path , path );
  Handle<PathInfo> handle( new PathInfo( raw_path ) );
  return handle;
}

StrHandle FileSystem::NormalizePath( const char* path ) {
  std::string tmp = path;
  while ( 1 ) {
    unsigned pos = tmp.find( "../" , 0 );
    if ( pos == std::string::npos ) {
      unsigned pos = tmp.find( "./" , 0 );
      if ( pos != std::string::npos ) {
        tmp.erase( pos , 2 );
      } else {
        unsigned pos = tmp.find( "//" , 0 );
        if ( pos != std::string::npos ) {
          tmp.erase( pos , 1 );
        } else {
          break;
        }
      }
    } else {
      int count = 0;
      int matched = 0;
      bool has_ch = false;
      while ( tmp[ pos ] ) {
        if ( tmp[ pos ] == '/' ) {
          if ( matched == 1 && has_ch ) {
            break;
          }
          matched = 1;
        }
        if ( tmp[ pos ] != '.' && tmp[ pos ] != '/' ) {
          has_ch = true;
        }
        pos--;
        count++;
      }
      tmp.erase( pos , count + 2 );
    }
  }
  if ( tmp[ tmp.size() - 1 ] == '/' ) {
    tmp.erase( tmp.size() - 1 , tmp.size() );
  }
  return StrHandle( utils::CharAlloc( tmp.c_str() ) );
}



StrHandle FileSystem::GetUserHomeDir() {
#ifdef _WIN32
  return GetAbsolutePath( getenv( HOME ) );
#else
  char* ret = utils::CharAlloc( getenv( HOME ) );
  return StrHandle( ret );
#endif
}


StrHandle FileSystem::GetAbsolutePath( const char* path ) {
  char tmp[ MAXPATHLEN ];
  FULL_PATH( path , tmp );
  char* ret = utils::CharAlloc( tmp );
  return StrHandle( ret );
}



void FileSystem::Chdir ( const char* path ) {

#ifdef _WIN32
  SetCurrentDirectory ( path );
#else
  chdir ( path );
#endif

}

bool FileSystem::Mkdir( const char* path , int permiss ) {
  return mocha::Mkdir( path , permiss );
}

bool FileSystem::Chmod( const char* path , int permiss ) {
  if ( FileIO::IsExist( path ) ) {
    chmod( path , permiss );
    return true;
  }
  return false;
}

#undef HOME
