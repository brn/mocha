
#ifndef mocha_js_token_h_
#define mocha_js_token_h_
#include <utils/class_traits/static.h>
namespace mocha{

//Bison compatible token list.
class Token : private Static {
 public :
  enum {
    JS_ABSTRACT = 128,//Token index begin from the out of ascii code range.
    JS_BOOLEAN,
    JS_BREAK,
    JS_BYTE,
    JS_CASE, 
    JS_CATCH,
    JS_CHAR,
    JS_CLASS,
    JS_CONST,
    JS_CONTINUE,
    JS_DEBUGGER,
    JS_DEFAULT,
    JS_DELETE,
    JS_DO,
    JS_DOUBLE,
    JS_ELSE,
    JS_ENUM,
    JS_EXPORT,
    JS_EXTENDS,
    JS_FALSE,
    JS_FINAL,
    JS_FINALLY,
    JS_FLOAT,
    JS_FOR,
    JS_FUNCTION,
    JS_GOTO,
    JS_IF,
    JS_IMPLEMENTS,
    JS_IMPORT,
    JS_IN,
    JS_INSTANCEOF,
    JS_INT,
    JS_INTERFACE,
    JS_LET,
    JS_LONG,
    JS_MODULE,
    JS_NATIVE,
    JS_NEW,
    JS_K_NULL,
    JS_PACKAGE_RESERVED,
    JS_PRIVATE,
    JS_PROTECTED,
    JS_PUBLIC,
    JS_RETURN,
    JS_SHORT,
    JS_STATIC,
    JS_SUPER,
    JS_SWITCH,
    JS_SYNCHRONIZED,
    JS_THIS,
    JS_THROW,
    JS_THROWS,
    JS_TRANSIENT,
    JS_TRUE,
    JS_TRY,
    JS_TYPEOF,
    JS_VAR,
    JS_VOID,
    JS_VOLATILE,
    JS_WHILE,
    JS_WITH,
    JS_EACH,
    JS_FROM,
    JS_YIELD,
    JS_ASSERT,
    MOCHA_VERSIONOF,
    MOCHA_PRAGMA,
    JS_INCREMENT,
    JS_DECREMENT,
    JS_EQUAL,
    JS_SHIFT_LEFT,
    JS_SHIFT_RIGHT,
    JS_LESS_EQUAL,
    JS_GREATER_EQUAL,
    JS_EQ,
    JS_NOT_EQUAL,
    JS_NOT_EQ,
    JS_U_SHIFT_RIGHT,
    JS_ADD_LET,
    JS_SUB_LET,
    JS_DIV_LET,
    JS_MOD_LET,
    JS_MUL_LET,
    JS_LOGICAL_AND,
    JS_LOGICAL_OR,
    JS_SHIFT_LEFT_LET,
    JS_SHIFT_RIGHT_LET,
    JS_U_SHIFT_RIGHT_LET,
    JS_NOT_LET,
    JS_AND_LET,
    JS_OR_LET,
    JS_FUNCTION_GLYPH,
    JS_FUNCTION_GLYPH_WITH_CONTEXT,
    JS_IDENTIFIER,
    JS_NUMERIC_LITERAL,
    JS_STRING_LITERAL,
    JS_REGEXP_LITERAL,
    JS_LINE_BREAK,
    JS_SET,
    JS_GET,
    JS_PARAMETER_REST,
    JS_PARAM_BEGIN,
    JS_PARAM_END,
    JS_DSTA_BEGIN,
    JS_DSTA_END,
    JS_DSTO_BEGIN,
    JS_DSTO_END,
    JS_CONSTRUCTOR,
    JS_PROTOTYPE,
    JS_EXP_CLOSURE_BEGIN,
    JS_PROPERTY,
    JS_YIELD_SENTINEL,
    ILLEGAL,
    END_OF_INPUT,
    END_TOKEN = -1,
  };
};

class JsToken : private Static {
 public:
  static bool IsBinaryOperatorNoIn( int token );
  static bool IsBinaryOperator( int token );
  static int ToParserToken( int token );
  static int getType ( const char* token , bool isOperator = false );
  static bool IsBuiltin( const char* token );
  static const char* GetTokenFromNumber( int id );
  static void Initialize();
};
class TokenInfo;
class TokenConverter {
 public :
  TokenConverter( TokenInfo* token );
  ~TokenConverter();
  operator const char*();
 private :
  std::string buf_;
  TokenInfo* info_;
};
}

#endif


