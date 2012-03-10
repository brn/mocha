#include <mocha/roaster/platform/fs/fs.h>
#ifdef PLATFORM_WIN32
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif
#ifdef PLATFORM_POSIX
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include <mocha/roaster/platform/fs/stat.h>

#ifdef PLATFORM_POSIX
#define STAT struct stat
#elif PLATFORM_WIN32
#define STAT struct _stat
#endif

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

#define MODE (fstat_->st_mode & S_IFMT)

namespace mocha {namespace platform {
namespace fs {
class Stat::PtrImpl {
 public :
  PtrImpl(const char* path, STAT *fstat) : path_(path), fstat_(fstat) {
    is_exist_ = (STAT_FN(path, fstat_) != -1);
  }
  ~PtrImpl() { delete fstat_; }
  inline bool IsExist() { return is_exist_; }
  inline int STDev() { return fstat_->st_dev;}
  inline int STIno() { return fstat_->st_ino; }
  inline int STNLink() { return fstat_->st_nlink; }
  inline int STUId() { return fstat_->st_uid; }
  inline int STGId() { return fstat_->st_gid; }
  inline int STRDev() { return fstat_->st_rdev; }
  inline int STSize() { return fstat_->st_size; }
  inline const char* STATime() {
    CTIME(&(fstat_->st_atime),atime_);
    return atime_;
  }
  inline const char* STMTime() {
    CTIME(&(fstat_->st_mtime),mtime_);
    return mtime_;
  }
  inline const char* STCTime() {
    CTIME(&(fstat_->st_ctime),ctime_);
    return ctime_;
  }
  inline bool ISDir() { return MODE == S_IFDIR; }
  inline bool ISReg() { return MODE == S_IFREG; }
  inline bool ISChr() { return MODE == S_IFCHR; }
 private :
  bool is_exist_;
  const char* path_;
  char atime_[200];
  char mtime_[200];
  char ctime_[200];
  STAT *fstat_;
};

Stat::Stat(const char* path) : implementation_(new PtrImpl(path, new STAT)) {}
bool Stat::IsExist() { return implementation_->IsExist(); }
int Stat::Dev() { return implementation_->STDev(); }
int Stat::Ino() { return implementation_->STIno(); }
int Stat::NLink() { return implementation_->STNLink(); }
int Stat::UId() { return implementation_->STUId(); }
int Stat::GId() { return implementation_->STGId(); }
int Stat::RDev() {return implementation_->STRDev(); }
int Stat::Size() { return implementation_->STSize(); }
const char* Stat::ATime() { return implementation_->STATime(); }
const char* Stat::MTime() { return implementation_->STMTime(); }
const char* Stat::CTime() { return implementation_->STCTime(); }
bool Stat::IsDir() { return implementation_->ISDir(); }
bool Stat::IsReg() { return implementation_->ISReg(); }
bool Stat::IsChr() { return implementation_->ISChr(); }
}
}}
