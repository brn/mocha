#ifndef mocha_platform_fs_stat_stat_h_
#define mocha_platform_fs_stat_stat_h_
#include <sys/stat.h>
#include <sys/types.h>
namespace mocha {namespace platform {
namespace fs {
class Stat{
 public :
  typedef enum {
    kFifo,
    kChr,
    kDir,
    kBlk,
    kReg,
    kLnk,
    kSock
  } FileType;
  Stat(const char* path);
  ~Stat(){};
  bool IsExist() const { return is_exist_; }
  int Dev() const { return fstat_.st_dev;}
  int Ino() const { return fstat_.st_ino; }
  int NLink() const { return fstat_.st_nlink; }
  int UId() const { return fstat_.st_uid; }
  int GId() const { return fstat_.st_gid; };
  int RDev() const { return fstat_.st_rdev; };
  int Size() const { return fstat_.st_size; };
  const char* ATime();
  const char* MTime();
  const char* CTime();
  bool IsDir();
  bool IsReg();
  bool IsChr();
 private :
  bool is_exist_;
  const char* path_;
  char atime_[200];
  char mtime_[200];
  char ctime_[200];
#ifdef PLATFORM_WIN32
  struct _stat fstat_;
#elif defined PLATFORM_POSIX
  struct stat fstat_;
#endif
};
}
}}
#endif //mocha_stat_h_
