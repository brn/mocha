#ifndef mocha_stat_h_
#define mocha_stat_h_

#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>

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
  bool IsExist();
  int Dev();
  int Ino();
  int NLink();
  int UId();
  int GId();
  int RDev();
  int Size();
  const char* ATime();
  const char* MTime();
  const char* CTime();
  bool IsDir();
  bool IsReg();
  bool IsChr();
 private :
  class PtrImpl;
  ScopedPtr<PtrImpl> implementation_;
};
}
}}
#endif //mocha_stat_h_
