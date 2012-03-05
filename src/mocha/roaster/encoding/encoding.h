#ifndef mocha_encoding_h_
#define mocha_encoding_h_
#include <vector>
#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/misc/class_traits/static.h>
namespace mocha {

struct DetectResult {
  const char* charset;
  const char* lang;
  bool error;
};

class ICUWrapper : private Static{
 public :
  static SharedPtr<DetectResult> GetEncode(const char* source);
  static SharedStr EncodeToUtf8(const char* source, const char* type);
};

}

#endif
