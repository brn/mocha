#ifndef mocha_compile_info_h_
#define mocha_compile_info_h_
#include <string>
#include <vector>
#include <mocha/roaster/misc/bits.h>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/lib/unordered_map.h>
namespace mocha {
typedef std::vector<std::string> LibDirectories;
typedef std::vector<std::string> Libs;
class CompilationInfo {
  typedef std::pair<const char*, uint8_t> VersionPair;
  typedef roastlib::unordered_map<std::string, uint8_t> Versions;
 public :
  CompilationInfo();
  ~CompilationInfo(){};
  bool Debug() const;
  void SetDebug();
  void UnsetDebug();
  bool Compress() const;
  void SetCompress();
  void UnsetCompress();
  bool PrettyPrint() const;
  void SetPrettyPrint();
  void UnsetPrettyPrint();
  bool ShowOrgName() const;
  void SetOrgName();
  bool FileScope() const;
  void SetFileScope();
  void UnsetFileScope();
  bool GlobalScope() const;
  void SetGlobalScope();
  void UnsetGlobalScope();
  bool HasVersion(const char*) const;
  void SetVersion(const char*);
  void UnsetVersion(const char*);
  bool PrototypeExtensions() const;
  void SetPrototypeExtensions();
  void UnsetPrototypeExtensions();
  void SetCharset(const char* charset);
  bool HasCharset() const { return !charset_.empty();}
  const char* charset() const {return (HasCharset())? charset_.c_str() : NULL;};
  void SetLibDirectory(const char* dir);
  const LibDirectories& lib_directories() const { return lib_dir_; };
  void SetLibs(const char* lib);
  const Libs& libs() const {return libs_;}
 private :
  std::string charset_;
  LibDirectories lib_dir_;
  Libs libs_;
  BitVector8 flags_;
  Versions versions_;
};

}

#endif
