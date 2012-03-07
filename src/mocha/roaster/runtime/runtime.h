#ifndef mocha_runtime_h_
#define mocha_runtime_h_
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/misc/class_traits/static.h>
namespace mocha {
namespace runtime {
class Runtime : private Static {
  typedef std::pair<std::string,const char*> RuntimePair;
 public :
  typedef roastlib::unordered_map<std::string,const char*> RuntimeMap;
  static void BuildSource();
  static inline const RuntimeMap& runtime_map() { return map_; }
 private :
  static RuntimeMap map_;
};
}
}

#endif
