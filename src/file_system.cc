
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

#ifdef _WIN32
#define HOME "HOMEPATH"
#else
#define HOME "HOME"
#endif

#ifndef MAXPATHLEN
#define MAXPATHLEN 1028
#endif

using namespace mocha;

StrHandle FileSystem::pwd () {

  return GetCwd ();

}

Handle<PathInfo> FileSystem::GetPathInfo( const char* path ) {
  const char* dir = GetDirectoryFromPath_( path );
  const char* file = GetFileNameFromPath_( path );
  char* raw_path = new char[ strlen( path ) + 1 ];
  strcpy( raw_path , path );
  Handle<PathInfo> handle( new PathInfo( file , dir , raw_path ) );
  return handle;
}

StrHandle FileSystem::NormalizePath( const char* path ) {
  std::string tmp = path;
  while ( 1 ) {
    int pos = tmp.find( "../" , 0 );
    if ( pos == std::string::npos ) {
      int pos = tmp.find( "./" , 0 );
      if ( pos != std::string::npos ) {
        tmp.erase( pos , 2 );
      } else {
        int pos = tmp.find( "//" , 0 );
        if ( pos != std::string::npos ) {
          tmp.erase( pos , 1 );
        } else {
          break;
        }
      }
    } else {
      int cache = pos;
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
  char* ret = new char[ tmp.size() + 1 ];
  strcpy( ret , tmp.c_str() );
  StrHandle handle( ret );
  return handle;
}



StrHandle FileSystem::GetUserHomeDir() {
#ifdef _WIN32
  return mocha::ReplaceBackSlash( getenv( HOME ) );
#else
  char* ret = new char[ MAXPATHLEN ];
  strcpy( ret , getenv( HOME ) );
  StrHandle handle( ret );
  return handle;
#endif
}


StrHandle FileSystem::GetAbsolutePath( const char* path ) {
#ifdef HAVE_REALPATH
  char* ret = new char[ MAXPATHLEN ];
  realpath( path , ret );
  printf( "current = %s\nreal path = %s\n" , pwd().get(), ret );
#elif HAVE__FULLPATH
  char tmp_buf[ MAXPATHLEN ];
  _fullpath( tmp_buf , path , MAXPATHLEN );
  return mocha::ReplaceBackSlash( tmp_buf );
#endif
  StrHandle handle( ret );
  return handle;
}


const char* FileSystem::GetDirectoryFromPath_( const char* path ) {
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

const char* FileSystem::GetFileNameFromPath_( const char* path ) {
  std::string tmp;
  const char* ptr = strrchr( path , '/' );
  if ( ptr ) {
    tmp = ( ptr + 1 );
  }
  char* ret = new char[ tmp.size() + 1 ];
  strcpy( ret, tmp.c_str() );
  return ret;
}

void FileSystem::Chdir ( const char* path ) {

#ifdef _WIN32
  SetCurrentDirectory ( path );
#else
  chdir ( path );
#endif

}

bool FileSystem::Mkdir( const char* path , int permiss ) {
  mocha::Mkdir( path , permiss );
}

int FileSystem::Chmod( const char* path , int permiss ) {
  if ( FileIO::isExist( path ) ) {
    chmod( path , permiss );
  }
}

int FileSystem::IsDirExist ( const char* path ) {

#undef HOME  

}
