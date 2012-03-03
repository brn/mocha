#ifndef mocha_encoding_h_
#define mocha_encoding_h_
#include <vector>
#include <string>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/class_traits/static.h>
namespace mocha {

struct DetectResult {
  const char* charset;
  const char* lang;
  bool error;
};

class ICUWrapper : private Static{
 public :
  static Handle<DetectResult> GetEncode( const char* source );
  static StrHandle EncodeToUtf8( const char* source , const char* type );
};

}

#endif
