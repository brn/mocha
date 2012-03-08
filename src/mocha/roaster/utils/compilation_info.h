#ifndef mocha_compile_info_h_
#define mocha_compile_info_h_
#include <string>
#include <vector>
#include <mocha/roaster/misc/bits.h>
#include <mocha/misc/int_types.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
typedef std::vector<std::string> LibDirectories;
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
  void SetCharset(const char* charset);
  bool HasCharset() const { return !charset_.empty();}
  const char* charset() const {return charset_.c_str();};
  const char* string() const {return str_.c_str();}
  void SetLibDirectory(const char* dir);
  void set_optional_identifier(const char* ident) {optional_identifier_ = ident;};
  bool HasOptionalIdentifier() const { return !optional_identifier_.empty(); }
  const char* optional_identifier() const { return optional_identifier_.c_str(); }
  const LibDirectories& lib_directories() const { return lib_dir_; };
 private :
  std::string str_;
  std::string charset_;
  std::string optional_identifier_;
  LibDirectories lib_dir_;
  BitVector8 flags_;
  Versions versions_;
};

}

#endif
