#ifdef PLATFORM_WIN32
#include <time.h>
#endif
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

#ifdef PLATFORM_POSIX
#define STAT_FN(filename, statObj) ::stat (filename, statObj)
#elif PLATFORM_WIN32
#define STAT_FN(filename, statObj) ::_stat (filename, statObj)
#endif

#ifdef PLATFORM_WIN32
#define CTIME(str,buf) ::_ctime64_s(buf,200,str)
#elif PLATFORM_POSIX
#define CTIME(str,buf) ::ctime_r(str,buf)
#endif

#define MODE (fstat_.st_mode & S_IFMT)

namespace mocha {namespace platform {
namespace fs {
Stat::Stat(const char* path)
    : path_(path){
  is_exist_ = (STAT_FN(path, &fstat_) != -1);
}
const char* Stat::ATime() {
  CTIME(&(fstat_.st_atime),atime_);
  return atime_;
}
const char* Stat::MTime() {
  CTIME(&(fstat_.st_mtime),mtime_);
  return mtime_;
}
const char* Stat::CTime() {
  CTIME(&(fstat_.st_ctime),ctime_);
  return ctime_;
}
bool Stat::IsDir() { return MODE == S_IFDIR; }
bool Stat::IsReg() { return MODE == S_IFREG; }
bool Stat::IsChr() { return MODE == S_IFCHR; }
}
}}
