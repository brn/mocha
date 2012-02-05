#ifndef mocha_compile_info_h_
#define mocha_compile_info_h_
#include <utils/int_types.h>
#include <utils/hash/hash_map/hash_map.h>
namespace mocha {

class CompileInfo {
  typedef HashMap<const char*,uint8_t> Versions;
 public :
  CompileInfo();
  ~CompileInfo(){};
  bool Debug();
  void SetDebug();
  bool Compress();
  void SetCompress();
  bool PrettyPrint();
  void SetPrettyPrint();
  bool HasVersion( const char* );
  void SetVersion( const char* );
 private :
  BitVector8 flags_;
  Versions versions_;
};

}

#endif
