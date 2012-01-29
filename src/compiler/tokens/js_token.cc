#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <compiler/tokens/js_token.h>
#include <grammar/grammar.tab.hh>
#include <utils/hash/hash_map/hash_map.h>

using namespace yy;

namespace mocha {


#define NOT_USE -1
#define ASCII_MAX_RAGE 127
#define TOKEN yy::ParserImplementation::token

typedef HashMap<const char*,int> TokenMap;

int token_id_list [] = {
  NOT_USE,//0
  NOT_USE,//1
  NOT_USE,//2
  NOT_USE,//3
  NOT_USE,//4
  NOT_USE,//5
  NOT_USE,//6
  NOT_USE,//7
  NOT_USE,//8
  NOT_USE,//9
  NOT_USE,//10
  NOT_USE,//11
  NOT_USE,//12
  NOT_USE,//13
  NOT_USE,//14
  NOT_USE,//15
  NOT_USE,//16
  NOT_USE,//17
  NOT_USE,//18
  NOT_USE,//19
  NOT_USE,//20
  NOT_USE,//21
  NOT_USE,//22
  NOT_USE,//23
  NOT_USE,//24
  NOT_USE,//25
  NOT_USE,//26
  NOT_USE,//27
  NOT_USE,//28
  NOT_USE,//29
  NOT_USE,//30
  NOT_USE,//31
  NOT_USE,//32
  '!',//33
  '"',//34
  '#',//35
  '$',//36
  '%',//37
  '&',//38
  '\'',//39
  '(',//40
  ')',//41
  '*',//42
  '+',//43
  ',',//44
  '-',//45
  '.',//46
  '/',//47
  NOT_USE,//48
  NOT_USE,//49
  NOT_USE,//50
  NOT_USE,//51
  NOT_USE,//52
  NOT_USE,//53
  NOT_USE,//54
  NOT_USE,//55
  NOT_USE,//56
  NOT_USE,//57
  ':',//58
  ';',//59
  '<',//60
  '=',//61
  '>',//62
  '?',//63
  '@',//64
  NOT_USE,//65
  NOT_USE,//66
  NOT_USE,//67
  NOT_USE,//68
  NOT_USE,//69
  NOT_USE,//70
  NOT_USE,//71
  NOT_USE,//72
  NOT_USE,//73
  NOT_USE,//74
  NOT_USE,//75
  NOT_USE,//76
  NOT_USE,//77
  NOT_USE,//78
  NOT_USE,//79
  NOT_USE,//80
  NOT_USE,//81
  NOT_USE,//82
  NOT_USE,//83
  NOT_USE,//84
  NOT_USE,//85
  NOT_USE,//86
  NOT_USE,//87
  NOT_USE,//88
  NOT_USE,//89
  NOT_USE,//90
  '[',//91
  '\\',//92
  ']',//93
  '^',//94
  '_',//95
  '`',//96
  NOT_USE,//97
  NOT_USE,//98
  NOT_USE,//99
  NOT_USE,//100
  NOT_USE,//101
  NOT_USE,//102
  NOT_USE,//103
  NOT_USE,//104
  NOT_USE,//105
  NOT_USE,//106
  NOT_USE,//107
  NOT_USE,//108
  NOT_USE,//109
  NOT_USE,//110
  NOT_USE,//111
  NOT_USE,//112
  NOT_USE,//113
  NOT_USE,//114
  NOT_USE,//115
  NOT_USE,//116
  NOT_USE,//117
  NOT_USE,//118
  NOT_USE,//119
  NOT_USE,//120
  NOT_USE,//121
  NOT_USE,//122
  '{',//123
  '|',//124
  '}',//125
  '~',//126
  NOT_USE,//127
  TOKEN::JS_ABSTRACT,
  TOKEN::JS_BOOLEAN,
  TOKEN::JS_BREAK,
  TOKEN::JS_BYTE,
  TOKEN::JS_CASE, 
  TOKEN::JS_CATCH,
  TOKEN::JS_CHAR,
  TOKEN::JS_CLASS,
  TOKEN::JS_CONST,
  TOKEN::JS_CONTINUE,
  TOKEN::JS_DEBUGGER,
  TOKEN::JS_DEFAULT,
  TOKEN::JS_DELETE,
  TOKEN::JS_DO,
  TOKEN::JS_DOUBLE,
  TOKEN::JS_ELSE,
  TOKEN::JS_ENUM,
  TOKEN::JS_EXPORT,
  TOKEN::JS_EXTENDS,
  TOKEN::JS_FALSE,
  TOKEN::JS_FINAL,
  TOKEN::JS_FINALLY,
  TOKEN::JS_FLOAT,
  TOKEN::JS_FOR,
  TOKEN::JS_FUNCTION,
  TOKEN::JS_GOTO,
  TOKEN::JS_IF,
  TOKEN::JS_IMPLEMENTS,
  TOKEN::JS_IMPORT,
  TOKEN::JS_IN,
  TOKEN::JS_INSTANCEOF,
  TOKEN::JS_INT,
  TOKEN::JS_INTERFACE,
  TOKEN::JS_LET,
  TOKEN::JS_LONG,
  TOKEN::JS_MODULE,
  TOKEN::JS_NATIVE,
  TOKEN::JS_NEW,
  TOKEN::JS_K_NULL,
  TOKEN::JS_PACKAGE_RESERVED,
  TOKEN::JS_PRIVATE,
  TOKEN::JS_PROTECTED,
  TOKEN::JS_PUBLIC,
  TOKEN::JS_RETURN,
  TOKEN::JS_SHORT,
  TOKEN::JS_STATIC,
  TOKEN::JS_SUPER,
  TOKEN::JS_SWITCH,
  TOKEN::JS_SYNCHRONIZED,
  TOKEN::JS_THIS,
  TOKEN::JS_THROW,
  TOKEN::JS_THROWS,
  TOKEN::JS_TRANSIENT,
  TOKEN::JS_TRUE,
  TOKEN::JS_TRY,
  TOKEN::JS_TYPEOF,
  TOKEN::JS_VAR,
  TOKEN::JS_VOID,
  TOKEN::JS_VOLATILE,
  TOKEN::JS_WHILE,
  TOKEN::JS_WITH,
  TOKEN::JS_EACH,
  TOKEN::JS_FROM,
  TOKEN::JS_YIELD,
  TOKEN::MOCHA_VERSIONOF,
  TOKEN::MOCHA_PRAGMA,
  TOKEN::JS_INCREMENT,
  TOKEN::JS_DECREMENT,
  TOKEN::JS_EQUAL,
  TOKEN::JS_SHIFT_LEFT,
  TOKEN::JS_SHIFT_RIGHT,
  TOKEN::JS_LESS_EQUAL,
  TOKEN::JS_GRATER_EQUAL,
  TOKEN::JS_EQ,
  TOKEN::JS_NOT_EQUAL,
  TOKEN::JS_NOT_EQ,
  TOKEN::JS_U_SHIFT_RIGHT,
  TOKEN::JS_ADD_LET,
  TOKEN::JS_SUB_LET,
  TOKEN::JS_DIV_LET,
  TOKEN::JS_MOD_LET,
  TOKEN::JS_MUL_LET,
  TOKEN::JS_LOGICAL_AND,
  TOKEN::JS_LOGICAL_OR,
  TOKEN::JS_SHIFT_LEFT_LET,
  TOKEN::JS_SHIFT_RIGHT_LET,
  TOKEN::JS_U_SHIFT_RIGHT_LET,
  TOKEN::JS_NOT_LET,
  TOKEN::JS_AND_LET,
  TOKEN::JS_OR_LET,
  TOKEN::JS_FUNCTION_GLYPH,
  TOKEN::JS_FUNCTION_GLYPH_WITH_CONTEXT,
  TOKEN::JS_IDENTIFIER,
  TOKEN::JS_NUMERIC_LITERAL,
  TOKEN::JS_STRING_LITERAL,
  TOKEN::JS_REGEXP_LITERAL,
  TOKEN::JS_LINE_BREAK,
  TOKEN::JS_SET,
  TOKEN::JS_GET,
  TOKEN::JS_PARAMETER_REST,
  TOKEN::JS_PARAM_BEGIN,
  TOKEN::JS_PARAM_END,
  TOKEN::JS_DSTA_BEGIN,
  TOKEN::JS_DSTA_END,
  TOKEN::JS_DSTO_BEGIN,
  TOKEN::JS_DSTO_END,
  TOKEN::JS_CONSTRUCTOR,
  TOKEN::JS_PROTOTYPE,
  TOKEN::JS_EXP_CLOSURE_BEGIN,
  TOKEN::JS_PROPERTY,
  TOKEN::JS_YIELD_SENTINEL
};

char reserved_words[][ 20 ] = {
  "abstract",
  "boolean" ,
  "break" ,
  "byte" ,
  "case" ,
  "catch" ,
  "char" ,
  "class" ,
  "const" ,
  "continue" ,
  "debugger" ,
  "default" ,
  "delete" ,
  "do" ,
  "double" ,
  "else" ,
  "enum" ,
  "export" ,
  "extends" ,
  "false" ,
  "final" ,
  "finally" ,
  "float" ,
  "for" ,
  "function" ,
  "goto" ,
  "if" ,
  "implements" ,
  "import" ,
  "in" ,
  "instanceof" ,
  "int" ,
  "interface" ,
  "let",
  "long" ,
  "module",
  "native",
  "new" ,
  "null" ,
  "package" ,
  "private" ,
  "protected",
  "public" ,
  "return" ,
  "short" ,
  "static" ,
  "super"  ,
  "switch" ,
  "synchronized" ,
  "this" ,
  "throw" ,
  "throws" ,
  "transient" ,
  "true" ,
  "try" ,
  "typeof" ,
  "var" ,
  "void" ,
  "volatile" ,
  "while" ,
  "with",
  "each",
  "from",
  "yield",
  "@version",
  "@pragma",
  "++" , "--" , "==", "<<" , ">>" , "<=" , ">=" , "===" , "!=" ,
   "!==", ">>>" , "+=" , "-=" , "/=" , "%=" , "*=" , "&&" , "||" , "<<=",
   ">>=" , ">>>=" , "^=" , "&=" , "|=" , "->" , "=>"
};



char builtins[][ 30 ] = {
  "Array",
  "Boolean"
  "Date",
  "Error",
  "EvalError",
  "Function",
  "Infinity",
  "Math",
  "NaN",
  "Number",
  "Object",
  "RangeError",
  "ReferenceError",
  "RegExp",
  "String",
  "SyntaxError",
  "TypeError",
  "URIError",
  "arguments",
  "decodeURI",
  "decodeURIComponent",
  "encodeURI",
  "encodeURIComponent",
  "escape",
  "eval",
  "isFinite",
  "isNaN",
  "parseFloat",
  "parseInt",
  "undefined",
  "unescape",
  "Attr",
  "CDATASection",
  "CharacterData",
  "Comment",
  "DOMException",
  "DOMImplementation",
  "Document",
  "DocumentFragment"
  "DocumentType",
  "Element",
  "Entity",
  "EntityReference",
  "ExceptionCode",
  "NamedNodeMap",
  "Node",
  "NodeList",
  "Notation"
  "ProcessingInstruction",
  "Text",
  "HTMLAnchorElement",
  "HTMLAppletElement",
  "HTMLAreaElement",
  "HTMLBRElement",
  "HTMLBaseElement",
  "HTMLBaseFontElement",
  "HTMLBodyElement",
  "HTMLButtonElement",
  "HTMLCollection",
  "HTMLDListElement",
  "HTMLDirectoryElement",
  "HTMLDivElement",
  "HTMLDocument",
  "HTMLElement",
  "HTMLFieldSetElement",
  "HTMLFontElement",
  "HTMLFormElement",
  "HTMLFrameElement",
  "HTMLFrameSetElement",
  "HTMLHRElement",
  "HTMLHeadElement",
  "HTMLHeadingElement",
  "HTMLHtmlElement",
  "HTMLIFrameElement",
  "HTMLImageElement",
  "HTMLInputElement",
  "HTMLIsIndexElement",
  "HTMLLIElement",
  "HTMLLabelElement",
  "HTMLLegendElement",
  "HTMLLinkElement",
  "HTMLMapElement",
  "HTMLMenuElement",
  "HTMLMetaElement",
  "HTMLModElement",
  "HTMLOListElement",
  "HTMLObjectElement",
  "HTMLOptGroupElement",
  "HTMLOptionElement",
  "HTMLOptionsCollection",
  "HTMLParagraphElement",
  "HTMLParamElement",
  "HTMLPreElement",
  "HTMLQuoteElement",
  "HTMLScriptElement",
  "HTMLSelectElement",
  "HTMLStyleElement",
  "HTMLTableCaptionElement",
  "HTMLTableCellElement",
  "HTMLTableColElement",
  "HTMLTableElement",
  "HTMLTableRowElement",
  "HTMLTableSectionElement",
  "HTMLTextAreaElement",
  "HTMLTitleElement",
  "HTMLUListElement",
  "DOMConfiguration",
  "DOMError",
  "DOMException",
  "DOMImplementationList",
  "DOMImplementationSource",
  "DOMLocator",
  "DOMStringList",
  "NameList",
  "TypeInfo",
  "UserDataHandler"
  "window",
  "alert",
  "confirm",
  "document",
  "java",
  "navigator",
  "prompt",
  "screen",
  "self",
  "top",
  "CSSCharsetRule",
  "CSSFontFace",
  "CSSFontFaceRule",
  "CSSImportRule",
  "CSSMediaRule",
  "CSSPageRule",
  "CSSPrimitiveValue",
  "CSSProperties",
  "CSSRule",
  "CSSRuleList",
  "CSSStyleDeclaration",
  "CSSStyleRule",
  "CSSStyleSheet",
  "CSSValue",
  "CSSValueList",
  "Counter",
  "DOMImplementationCSS",
  "DocumentCSS",
  "DocumentStyle",
  "ElementCSSInlineStyle",
  "LinkStyle",
  "MediaList",
  "RGBColor",
  "Rect",
  "StyleSheet",
  "StyleSheetList",
  "ViewCSS",
  "EventListener",
  "EventTarget",
  "Event",
  "DocumentEvent",
  "UIEvent",
  "MouseEvent",
  "MutationEvent",
  "KeyboardEvent",
  "DocumentRange",
  "Range",
  "RangeException",
  "XPathResult",
  "XMLHttpRequest"
};

static bool binary_operator[] = {
  false,//NOT_USE:0
  false,//NOT_USE:1
  false,//NOT_USE:2
  false,//NOT_USE:3
  false,//NOT_USE:4
  false,//NOT_USE:5
  false,//NOT_USE:6
  false,//NOT_USE:7
  false,//NOT_USE:8
  false,//NOT_USE:9
  false,//NOT_USE:10
  false,//NOT_USE:11
  false,//NOT_USE:12
  false,//NOT_USE:13
  false,//NOT_USE:14
  false,//NOT_USE:15
  false,//NOT_USE:16
  false,//NOT_USE:17
  false,//NOT_USE:18
  false,//NOT_USE:19
  false,//NOT_USE:20
  false,//NOT_USE:21
  false,//NOT_USE:22
  false,//NOT_USE:23
  false,//NOT_USE:24
  false,//NOT_USE:25
  false,//NOT_USE:26
  false,//NOT_USE:27
  false,//NOT_USE:28
  false,//NOT_USE:29
  false,//NOT_USE:30
  false,//NOT_USE:31
  false,//NOT_USE:32
  false,//'!':33
  false,//'"':34
  false,//'#':35
  false,//'$':36
  false,//'%':37
  false,//'&':38
  false,//'\':/39
  false,//'(':40
  false,//')':41
  false,//'*':42
  false,//'+':43
  false,//',':44
  false,//'-':45
  false,//'.':46
  false,//'/':47
  false,//NOT_USE:48
  false,//NOT_USE:49
  false,//NOT_USE:50
  false,//NOT_USE:51
  false,//NOT_USE:52
  false,//NOT_USE:53
  false,//NOT_USE:54
  false,//NOT_USE:55
  false,//NOT_USE:56
  false,//NOT_USE:57
  false,//':':58
  false,//':':59
  false,//'<':60
  false,//'=':61
  false,//'>':62
  false,//'?':63
  false,//'@':64
  false,//NOT_USE:65
  false,//NOT_USE:66
  false,//NOT_USE:67
  false,//NOT_USE:68
  false,//NOT_USE:69
  false,//NOT_USE:70
  false,//NOT_USE:71
  false,//NOT_USE:72
  false,//NOT_USE:73
  false,//NOT_USE:74
  false,//NOT_USE:75
  false,//NOT_USE:76
  false,//NOT_USE:77
  false,//NOT_USE:78
  false,//NOT_USE:79
  false,//NOT_USE:80
  false,//NOT_USE:81
  false,//NOT_USE:82
  false,//NOT_USE:83
  false,//NOT_USE:84
  false,//NOT_USE:85
  false,//NOT_USE:86
  false,//NOT_USE:87
  false,//NOT_USE:88
  false,//NOT_USE:89
  false,//NOT_USE:90
  false,//'[':91
  false,//'\\:92
  false,//']':93
  false,//'^':94
  false,//'_':95
  false,//'`':96
  false,//NOT_USE:97
  false,//NOT_USE:98
  false,//NOT_USE:99
  false,//NOT_USE:100
  false,//NOT_USE:101
  false,//NOT_USE:102
  false,//NOT_USE:103
  false,//NOT_USE:104
  false,//NOT_USE:105
  false,//NOT_USE:106
  false,//NOT_USE:107
  false,//NOT_USE:108
  false,//NOT_USE:109
  false,//NOT_USE:110
  false,//NOT_USE:111
  false,//NOT_USE:112
  false,//NOT_USE:113
  false,//NOT_USE:114
  false,//NOT_USE:115
  false,//NOT_USE:116
  false,//NOT_USE:117
  false,//NOT_USE:118
  false,//NOT_USE:119
  false,//NOT_USE:120
  false,//NOT_USE:121
  false,//NOT_USE:122
  false,//'{':123
  false,//'|':124
  false,//'}':125
  false,//'~':126
  false,//NOT_USE:127
  false,//JS_ABSTRACT
  false,//JS_BOOLEAN
  false,//JS_BREAK
  false,//JS_BYTE
  false,//JS_CASE 
  false,//JS_CATCH
  false,//JS_CHAR
  false,//JS_CLASS
  false,//JS_CONST
  false,//JS_CONTINUE
  false,//JS_DEBUGGER
  false,//JS_DEFAULT
  false,//JS_DELETE
  false,//JS_DO
  false,//JS_DOUBLE
  false,//JS_ELSE
  false,//JS_ENUM
  false,//JS_EXPORT
  false,//JS_EXTENDS
  false,//JS_FALSE
  false,//JS_FINAL
  false,//JS_FINALLY
  false,//JS_FLOAT
  false,//JS_FOR
  false,//JS_FUNCTION
  false,//JS_GOTO
  false,//JS_IF
  false,//JS_IMPLEMENTS
  false,//JS_IMPORT
  false,//JS_IN
  false,//JS_INSTANCEOF
  false,//JS_INT
  false,//JS_INTERFACE
  false,//JS_LET
  false,//JS_LONG
  false,//JS_MODULE
  false,//JS_NATIVE
  false,//JS_NEW
  false,//JS_K_NULL
  false,//JS_PACKAGE_RESERVED
  false,//JS_PRIVATE
  false,//JS_PROTECTED
  false,//JS_PUBLIC
  false,//JS_RETURN
  false,//JS_SHORT
  false,//JS_STATIC
  false,//JS_SUPER
  false,//JS_SWITCH
  false,//JS_SYNCHRONIZED
  false,//JS_THIS
  false,//JS_THROW
  false,//JS_THROWS
  false,//JS_TRANSIENT
  false,//JS_TRUE
  false,//JS_TRY
  false,//JS_TYPEOF
  false,//JS_VAR
  false,//JS_VOID
  false,//JS_VOLATILE
  false,//JS_WHILE
  false,//JS_WITH
  false,//JS_EACH
  false,//JS_FROM
  false,//MOCHA_VERSIONOF
  false,//JS_INCREMENT,
  false,//JS_DECREMENT,
  true,//JS_EQUAL,
  true,//JS_SHIFT_LEFT,
  true,//JS_SHIFT_RIGHT,
  true,//JS_LESS_EQUAL,
  true,//JS_GRATER_EQUAL,
  true,//JS_EQ,
  true,//JS_NOT_EQUAL,
  true,//JS_NOT_EQ,
  true,//JS_U_SHIFT_RIGHT,
  true,//JS_ADD_LET,
  true,//JS_SUB_LET,
  true,//JS_DIV_LET,
  true,//JS_MOD_LET,
  true,//JS_MUL_LET,
  true,//JS_LOGICAL_AND,
  true,//JS_LOGICAL_OR,
  true,//JS_SHIFT_LEFT_LET,
  true,//JS_SHIFT_RIGHT_LET,
  true,//JS_U_SHIFT_RIGHT_LET,
  true,//JS_NOT_LET,
  true,//JS_AND_LET,
  true,//JS_OR_LET,
  false,//JS_FUNCTION_GLYPH,
  false,//JS_FUNCTION_GLYPH_WITH_CONTEXT
  false,//TOKEN::JS_IDENTIFIER,
  false,//TOKEN::JS_NUMERIC_LITERAL,
  false,//TOKEN::JS_STRING_LITERAL,
  false,//TOKEN::JS_REGEXP_LITERAL,
  false,//TOKEN::JS_LINE_BREAK,
  false,//TOKEN::JS_SET,
  false,//TOKEN::JS_GET,
  false,//TOKEN::JS_PARAMETER_REST,
  false,//TOKEN::JS_PARAM_BEGIN,
  false,//TOKEN::JS_PARAM_END,
  false,//TOKEN::JS_DSTA_BEGIN,
  false,//TOKEN::JS_DSTA_END,
  false,//TOKEN::JS_DSTO_BEGIN,
  false,//TOKEN::JS_DSTO_END,
  false,//TOKEN::JS_CONSTRUCTOR,
  false,//TOKEN::JS_PROTOTYPE,
  false,//TOKEN::JS_EXP_CLOSURE_BEGIN
};

int keywords_length = sizeof ( reserved_words ) / sizeof ( reserved_words[ 0 ] );
int builtin_length = sizeof( builtins ) / sizeof( builtins[ 0 ] );
TokenMap reserved_map;
TokenMap builtin_map;

void JsToken::Initialize() {
  for ( int i = 0; i < keywords_length; i++ ) {
    reserved_map.Insert( reserved_words[ i ] , i + ( ASCII_MAX_RAGE + 1 ) );
  }
  for ( int i = 0; i < builtin_length; i++ ) {
    builtin_map.Insert( builtins[ i ] , 1 );
  }
}

int JsToken::ToParserToken( int token ) {
  return token_id_list[ token ];
}

bool JsToken::IsBinaryOperatorNoIn( int token ) {
  return binary_operator[ token ];
}

bool JsToken::IsBinaryOperator( int token ) {
  return ( token == Token::JS_IN || token == Token::JS_INSTANCEOF )? true : binary_operator[ token ];
}

int JsToken::getType ( const char* token , bool is_operator ) {
  if ( is_operator ) {
    if ( strlen( token ) == 1 ) {
      return token[ 0 ];
    } else {
      TokenMap::HashEntry find = reserved_map.Find( token );
      if ( !find.IsEmpty() ) {
        return find.Value();
      }
      return 0;
    }
  } else {
    TokenMap::HashEntry find = reserved_map.Find( token );
    if ( !find.IsEmpty() ) {
      return find.Value();
    }
    return Token::JS_IDENTIFIER;
  }
}

bool JsToken::IsBuiltin( const char* token ) {
  TokenMap::HashEntry find = builtin_map.Find( token );
  if ( !find.IsEmpty() ) {
    return true;
  }
  return false;
}

const char* JsToken::GetTokenFromNumber( int id ) {
  int token_id = id - ( ASCII_MAX_RAGE + 1 );
  if ( token_id < keywords_length ) {
    return reserved_words[ token_id ];
  }
  return 0;
}

TokenConverter::TokenConverter( TokenInfo* token ) : info_( token ){}
TokenConverter::~TokenConverter(){}
TokenConverter::operator const char*() {
  buf_.clear();
  if ( info_ != 0 ) {
    int type = info_->GetType();
    if ( type > 127 ) {
      return info_->GetToken();
    } else {
      buf_ += static_cast<char>( info_->GetType() );
      return buf_.c_str();
    }
  } else {
    return "empty";
  }
}
}
