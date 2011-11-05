#include "useconfig.h"
#ifdef HAVE_DIRECT_H
#include <direct.h>
#endif
#include <string.h>
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#include "mkdir.h"
#include "stat.h"
#include "file_system.h"
#include "thread.h"
#include "static.h"

#ifdef _WIN32
#define MKDIR(path) _mkdir(path)
#else
#define MKDIR(path) mkdir(path,0777)
#endif

namespace mocha {

class MutexHolder : private Static {
 public :
  static Mutex mutex;
};

Mutex MutexHolder::mutex;

bool Mkdir( const char* path , int permiss ) {
  MutexLock lock( MutexHolder::mutex );
  int len = strlen( path );
  if ( len > 0 ) {
    std::string processed_path = path;
    if ( path[ len - 1 ] != '/' ) {
      processed_path += '/';
      len += 1;
    }
    StrHandle handle = FileSystem::pwd();
    char tmp[ 200 ];
    for ( int i = 0,count = 0; i < len; ++i ) {
      if ( processed_path[ i ] == '/' ) {
        if ( i == 0 ) {
          FileSystem::Chdir( "/" );
        } else {
          if ( tmp[ count - 1 ] == ':' ) {
            tmp[ count ] = '/';
            count++;
          } 
          tmp[ count ] = '\0';
          Stat st( tmp );
          if ( !st.IsExist() || !st.IsDir() ) {
            if ( -1 == MKDIR( tmp ) ) {
              FileSystem::Chdir( handle.get() );
              return false;
            }
            FileSystem::Chmod( tmp , permiss );
            FileSystem::Chdir( tmp );
          } else if ( st.IsDir() ) {
            FileSystem::Chdir( tmp );
          }
          tmp[ 0 ] = '\0';
          count = 0;
        }
      } else {
        tmp[ count ] = processed_path[ i ];
        count++;
      }
    }
    FileSystem::Chdir( handle.get() );
    return true;
  }
  return false;
}

}
