#include "stat.h"
#include "useconfig.h"
#ifdef HAVE_TIME_H
#include <time.h>
#endif
#ifdef HAVE_SYS_STAT_H
  #include <sys/stat.h>
#endif

#ifdef HAVE_SYS_TYPES_H
  #include <sys/types.h>
#endif

#ifdef HAVE_STRUCT_STAT
  #define STAT struct stat
#elif HAVE_STRUCT__STAT
  #define STAT struct _stat
#endif

#ifdef HAVE_STAT
#define STAT_FN( filename , statObj ) ::stat ( filename , statObj )
#elif HAVE__STAT
#define STAT_FN( filename , statObj ) ::_stat ( filename , statObj )
#endif

#ifdef HAVE__CTIME64
#define CTIME(str) ::_ctime64(str)
#elif HAVE_CTIME
#define CTIME(str) ::ctime(str)
#endif

#define MODE ( fstat_->st_mode & S_IFMT )

namespace mocha {

class Stat::PtrImpl {
 public :
  PtrImpl( const char* path , STAT *fstat ) : path_( path ) , fstat_( fstat ) {
    is_exist_ = ( STAT_FN( path , fstat_ ) != -1 );
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
  inline const char* STATime() { return CTIME(&(fstat_->st_atime)); }
  inline const char* STMTime() { return CTIME(&(fstat_->st_mtime)); }
  inline const char* STCTime() { return CTIME(&(fstat_->st_ctime)); }
  inline bool ISDir() { return MODE == S_IFDIR; }
  inline bool ISReg() { return MODE == S_IFREG; }
  inline bool ISChr() { return MODE == S_IFCHR; }
 private :
  bool is_exist_;
  const char* path_;
  STAT *fstat_;
};

Stat::Stat( const char* path ) : implementation_( new PtrImpl( path , new STAT ) ) {}
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
