#ifdef PLATFORM_WIN32
#include <direct.h>
#endif
#include <string.h>
#ifdef PLATFORM_POSIX
#include <sys/stat.h>
#endif
#include <mocha/roaster/platform/fs/mkdir.h>
#include <mocha/roaster/platform/fs/stat.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/misc/class_traits/static.h>

#ifdef PLATFORM_WIN32
#define MKDIR(path) _mkdir(path)
#elif defined PLATFORM_POSIX
#define MKDIR(path) ::mkdir(path,0777)
#endif

namespace mocha {namespace os {
namespace fs {
class MutexHolder : private Static {
 public :
  static os::Mutex mutex;
};

os::Mutex MutexHolder::mutex;

bool mkdir(const char* path, int permiss) {
  os::ScopedLock lock(MutexHolder::mutex);
  int len = strlen(path);
  if (len > 0) {
    std::string processed_path = path;
    if (path[ len - 1 ] != '/') {
      processed_path += '/';
      len += 1;
    }
    const char* current = os::fs::Path::current_directory();
    char tmp[ 200 ];
    for (int i = 0,count = 0; i < len; ++i) {
      if (processed_path[ i ] == '/') {
        if (i == 0) {
          os::fs::chdir("/");
        } else {
          if (tmp[ count - 1 ] == ':') {
            tmp[ count ] = '/';
            count++;
          } 
          tmp[ count ] = '\0';
          os::fs::Stat st(tmp);
          if (!st.IsExist() || !st.IsDir()) {
            if (-1 == MKDIR(tmp)) {
              os::fs::chdir(current);
              return false;
            }
            os::fs::chmod(tmp, permiss);
            os::fs::chdir(tmp);
          } else if (st.IsDir()) {
            os::fs::chdir(tmp);
          }
          tmp[ 0 ] = '\0';
          count = 0;
        }
      } else {
        tmp[ count ] = processed_path[ i ];
        count++;
      }
    }
    os::fs::chdir(current);
    return true;
  }
  return false;
}
}
}}
