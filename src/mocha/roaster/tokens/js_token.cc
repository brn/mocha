#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/token_info.h>

namespace mocha {


#define NOT_USE -1
#define ASCII_MAX_RANGE 127

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
  "NaN",
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
  "yield",
  "@assert",
  "@version",
  "@pragma",
  "++", "--", "==", "<<", ">>", "<=", ">=", "===", "!=" ,
  "!==", ">>>", "+=", "-=", "/=", "%=", "*=", "&&", "||", "<<=",
  ">>=", ">>>=", "^=", "&=", "|=", "->", "=>"
};



char builtins[][ 30 ] = {
  "Array",
  "JSON",
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
  "XMLHttpRequest",
  "importScript",
  "WeakMap"
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
  false,//ILLEGAL
  false,//END_OF_INPUT
  false//END_TOKEN
};

int keywords_length = sizeof (reserved_words) / sizeof (reserved_words[ 0 ]);
int builtin_length = sizeof(builtins) / sizeof(builtins[ 0 ]);

void JsToken::Initialize() {
  for (int i = 0; i < keywords_length; i++) {
    int id = i + (ASCII_MAX_RANGE + 1);
    reserved_map_.insert(TokenEntry(reserved_words[ i ], id));
  }
  for (int i = 0; i < builtin_length; i++) {
    builtin_map_.insert(TokenEntry(builtins[ i ], 1));
  }
}

bool JsToken::IsBinaryOperatorNoIn(int token) {
  return binary_operator[ token ];
}

bool JsToken::IsBinaryOperator(int token) {
  return (token == Token::JS_IN || token == Token::JS_INSTANCEOF)? true : binary_operator[ token ];
}

int JsToken::GetType (const char* token, bool is_operator) {
  if (is_operator && strlen(token) == 1) {
    return token[ 0 ];
  } else {
	MutexLock lock(mutex_);
    ReservedTokenTable::iterator find = reserved_map_.find(token);
    if (find != reserved_map_.end()) {
      return find->second;
    }
    return (is_operator)? 0 : Token::JS_IDENTIFIER;
  }
}

bool JsToken::IsBuiltin(const char* token) {
  MutexLock lock(mutex_);
  BuiltinTokenTable::iterator find = builtin_map_.find(token);
  if (find != builtin_map_.end()) {
    return true;
  }
  return false;
}

bool JsToken::IsReserved(const char* token) {
  MutexLock lock(mutex_);
  ReservedTokenTable::iterator find = reserved_map_.find(token);
  if (find != reserved_map_.end()) {
    return true;
  }
  return false;
}

const char* JsToken::GetTokenFromNumber(int id) {
  int token_id = id - (ASCII_MAX_RANGE + 1);
  if (token_id < keywords_length) {
    return reserved_words[ token_id ];
  }
  return 0;
}

JsToken::ReservedTokenTable JsToken::reserved_map_;
JsToken::BuiltinTokenTable JsToken::builtin_map_;
Mutex JsToken::mutex_;

TokenConverter::TokenConverter(TokenInfo* info) : info_(info){}

const char* TokenConverter::cstr() {
  buffer_.clear();
  if (info_->type() > 127) {
    return info_->token();
  } else {
    buffer_ += info_->type();
    return buffer_.c_str();
  }
}


}
