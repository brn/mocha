#ifndef mocha_compile_info_h_
#define mocha_compile_info_h_
#include <string>
#include <mocha/roaster/misc/bits.h>
#include <mocha/misc/int_types.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {

class CompilationInfo {
  typedef std::pair<const char*, uint8_t> VersionPair;
  typedef roastlib::unordered_map<std::string, uint8_t> Versions;
 public :
  CompilationInfo(const char* str);
  ~CompilationInfo(){};
  bool Debug() const;
  void SetDebug();
  bool Compress() const;
  void SetCompress();
  bool PrettyPrint() const;
  void SetPrettyPrint();
  bool HasVersion(const char*) const;
  void SetVersion(const char*);
  bool IsFile() const;
  void MarkAsFile();
  const char* string() const {return str_.c_str();}
 private :
  std::string str_;
  BitVector8 flags_;
  Versions versions_;
};

}

#endif
