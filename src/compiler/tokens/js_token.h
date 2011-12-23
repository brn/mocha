
#ifndef mocha_js_token_h_
#define mocha_js_token_h_
#include <utils/class_traits/static.h>
namespace mocha{
  
class JsToken : private Static {
 public:
  static int getType ( const char* token , bool isOperator = false );
  static bool IsBuiltin( const char* token );
  static const char* GetOperatorFromNumber( int id );
  static void Initialize();
};
}

#endif


