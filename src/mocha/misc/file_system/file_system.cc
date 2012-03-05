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
#include <vector>
#include <string>

#include <mocha/misc/file_system/file_system.h>
#include <mocha/misc/io/file_io.h>
#include <useconfig.h>
#include <mocha/misc/file_system/stat.h>
#include <mocha/misc/file_system/mkdir.h>
#include <mocha/misc/char_allocator.h>

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
#define MAXPATHLEN 10000
#else
#undef MAXPATHLEN
#define MAXPATHLEN 10000
#endif

#ifdef HAVE_REALPATH
#define FULL_PATH( path , tmp ) tmp = realpath( path , NULL )
#elif HAVE__FULLPATH
#define FULL_PATH( path , tmp ) tmp = _fullpath( NULL , path , 0 )
#endif

using namespace mocha;

PathInfo::PathInfo( const char* path ) :
    filepath_( GetFileNameFromPath_( path ) ) , dir_( GetDirectoryFromPath_( path ) ) , raw_path_( path ){}

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

SharedStr FileSystem::pwd () {
  return GetCwd ();
}

SharedPtr<PathInfo> FileSystem::GetPathInfo( const char* path ) {
  char* raw_path = new char[ strlen( path ) + 1 ];
  strcpy( raw_path , path );
  SharedPtr<PathInfo> handle( new PathInfo( raw_path ) );
  return handle;
}

SharedStr FileSystem::NormalizePath( const char* path ) {
  std::string tmp = path;
  size_t size = tmp.size();
  size_t index = 0;
  while ( ( index = tmp.find( "\\" , 0 ) ) != std::string::npos ) {
    tmp = tmp.replace( index , 1 , "/" );
  }
  while ( 1 ) {
    size_t pos = tmp.find( "../" , 0 );
    if ( pos == std::string::npos ) {
      size_t pos = tmp.find( "./" , 0 );
      if ( pos != std::string::npos ) {
        tmp.erase( pos , 2 );
      } else {
        size_t pos = tmp.find( "//" , 0 );
        if ( pos != std::string::npos ) {
          tmp.erase( pos , 1 );
        } else {
          break;
        }
      }
    } else {
      int count = 0;
      int matched = 0;
      int spos = pos;
      int ssize = size;
      bool has_ch = false;
      while ( spos < ssize && spos > -1 ) {
        if ( tmp[ spos ] == '/' ) {
          if ( matched == 1 && has_ch ) {
            break;
          }
          matched = 1;
        }
        if ( tmp[ spos ] != '.' && tmp[ spos ] != '/' ) {
          has_ch = true;
        }
        spos--;
        count++;
      }
      if ( spos < 0 ) {
        spos = 0;
      }
      tmp.erase( spos , count + 2 );
    }
  }
  if ( tmp[ tmp.size() - 1 ] == '/' ) {
    tmp.erase( tmp.size() - 1 , tmp.size() );
  }
  return SharedStr( utils::CharAlloc( tmp.c_str() ) );
}



SharedStr FileSystem::GetUserHomeDir() {
#ifdef _WIN32
  std::string drive = getenv( "HOMEDRIVE" );
  std::string home = getenv( HOME );
  drive += home;
  return GetAbsolutePath( drive.c_str() );
#else
  char* ret = utils::CharAlloc( getenv( HOME ) );
  return SharedStr( ret );
#endif
}


SharedStr FileSystem::GetAbsolutePath( const char* path ) {
  char *tmp;
  FULL_PATH( path , tmp );
  char* ret = utils::CharAlloc( tmp );
  free( tmp );
  return SharedStr( ret );
}

typedef std::vector<std::string> PathArray;

void GetPathArray( const char* path , PathArray *array ) {
  int len = strlen( path );
  std::string tmp = path;
  std::string slash = "/";
  std::string str;
  if ( path[ len - 1 ] != '/' ) {
    tmp += '/';
  }
  const char* raw = tmp.c_str();
  int i = 0;
  while ( raw[ i ] ) {
    if ( raw[ i ] == '/' ) {
      if ( i == 0 ) {
        array->push_back( slash );
      } else {
        array->push_back( str );
      }
      str.clear();
    } else {
      str += raw[i];
    }
    i++;
  }
}

SharedStr FileSystem::GetModuleKey( const char* base , const char* path ) {
  if ( strcmp( base , path ) == 0 ) {
    return SharedStr( utils::CharAlloc( "./" ) );
  }
  PathArray base_array;
  PathArray target_array;
  GetPathArray( base , &base_array );
  GetPathArray( path , &target_array );
  std::string result;
  int i = 0;
  int base_size = base_array.size();
  int target_size = target_array.size();
  while ( ( i < base_size ) || ( i < target_size ) ) {
    if ( i >= base_size ) {
      result += target_array.at( i );
    } else if ( i >= target_size ) {
      std::string tmp;
      while ( i < base_size ) {
        tmp += "../";
        i++;
      }
      tmp += result;
      return SharedStr( utils::CharAlloc( tmp.c_str() ) );
    } else if ( base_array.at( i ).compare( target_array.at( i ) ) != 0 ) {
      while ( i < base_size ) {
        result += "../";
        base_array.pop_back();
        base_size = base_array.size();
      }
      while ( i < target_size ) {
        result += target_array[ i ];
        result += "/";
        i++;
      }
      return SharedStr( utils::CharAlloc( result.c_str() ) );
    }
    i++;
  }
  return SharedStr( utils::CharAlloc( result.c_str() ) );
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
