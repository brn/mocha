#ifndef mocha_compile_info_h_
#define mocha_compile_info_h_
#include <string>
#include <mocha/roaster/misc/bits.h>
#include <mocha/misc/int_types.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {

class CompileInfo {
  typedef std::pair<const char*, uint8_t> VersionPair;
  typedef roastlib::unordered_map<std::string, uint8_t> Versions;
 public :
  CompileInfo();
  ~CompileInfo(){};
  bool Debug();
  void SetDebug();
  bool Compress();
  void SetCompress();
  bool PrettyPrint();
  void SetPrettyPrint();
  bool HasVersion(const char*);
  void SetVersion(const char*);
 private :
  BitVector8 flags_;
  Versions versions_;
};

}

#endif
