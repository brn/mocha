#include <string.h>
#include <stdio.h>
#include <compiler/tokens/js_token.h>
#include <grammar/grammar.tab.hh>
#include <utils/hash/hash_map/hash_map.h>

using namespace yy;

namespace mocha {


#define TOKEN ParserImplementation::token

typedef HashMap<const char*,int> TokenMap;

int token_id_list [] = {
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
  TOKEN::MOCHA_VERSIONOF
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
  "versionof"
};

char single_operators[] = {
  
  '[' , ']' , '{' , '}' , '(' , ')' , '*' , '/' , '+' , '-' , '%' , '^' , '&' , '!' , '|' , '~' ,
  '?' , ',' , '<' , '>' , '.' , ';' , '=' , '\'' , '"' , ':' , '#'

};

int combine_operator_id_list[] = {

  TOKEN::JS_INCREMENT , TOKEN::JS_DECREMENT , TOKEN::JS_EQUAL , TOKEN::JS_SHIFT_LEFT,
  TOKEN::JS_SHIFT_RIGHT , TOKEN::JS_LESS_EQUAL , TOKEN::JS_GRATER_EQUAL , TOKEN::JS_EQ,
  TOKEN::JS_NOT_EQUAL , TOKEN::JS_NOT_EQ , TOKEN::JS_U_SHIFT_RIGHT , TOKEN::JS_ADD_LET , TOKEN::JS_SUB_LET,
  TOKEN::JS_DIV_LET , TOKEN::JS_MOD_LET , TOKEN::JS_MUL_LET , TOKEN::JS_LOGICAL_AND,
  TOKEN::JS_LOGICAL_OR , TOKEN::JS_SHIFT_LEFT_LET , TOKEN::JS_SHIFT_RIGHT_LET,
  TOKEN::JS_U_SHIFT_RIGHT_LET , TOKEN::JS_NOT_LET , TOKEN::JS_NOT_EQ , TOKEN::JS_AND_LET,
  TOKEN::JS_LOGICAL_OR , TOKEN::JS_FUNCTION_GLYPH , TOKEN::JS_FUNCTION_GLYPH_WITH_CONTEXT

};

char combine_operators[][ 20 ] = {

   "++" , "--" , "==", "<<" , ">>" , "<=" , ">=" , "===" , "!=" ,
   "!==", ">>>" , "+=" , "-=" , "/=" , "%=" , "*=" , "&&" , "||" , "<<=",
   ">>=" , ">>>=" , "^=" , "|==" , "&=" , "|=" , "->" , "=>"
  
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
  
int operators_length = sizeof ( single_operators );
int keywords_length = sizeof ( reserved_words ) / sizeof ( reserved_words[ 0 ] );
int combine_operators_length = sizeof ( combine_operators ) / sizeof ( combine_operators[ 0 ] );
int builtin_length = sizeof( builtins ) / sizeof( builtins[ 0 ] );
TokenMap reserved_map;
TokenMap builtin_map;

void JsToken::Initialize() {
  for ( int i = 0; i < combine_operators_length; i++ ) {
    reserved_map.Insert( combine_operators[ i ] , combine_operator_id_list[ i ] );
  };
  for ( int i = 0; i < keywords_length; i++ ) {
    reserved_map.Insert( reserved_words[ i ] , token_id_list[ i ] );
  }
  for ( int i = 0; i < builtin_length; i++ ) {
    builtin_map.Insert( builtins[ i ] , 1 );
  }
}


int JsToken::getType ( const char* token , bool is_operator ) {
  if ( is_operator ) {
    if ( token[ 1 ] == 0 ) {
      for ( int i = 0; i < operators_length; ++i ) {
        if ( token [ 0 ] == single_operators[ i ] ) {       
          return single_operators [ i ];
        }
      }
    } else {
      TokenMap::HashEntry find = reserved_map.Find( token );
      if ( !find.IsEmpty() ) {
        return find.Value();
      }
    }    
  } else {
    TokenMap::HashEntry find = reserved_map.Find( token );
    if ( !find.IsEmpty() ) {
      return find.Value();
    }
    return TOKEN::JS_IDENTIFIER;
  }
  return 0;  
}

bool JsToken::IsBuiltin( const char* token ) {
  TokenMap::HashEntry find = builtin_map.Find( token );
  if ( !find.IsEmpty() ) {
    return true;
  }
  return false;
}

const char* JsToken::GetOperatorFromNumber( int id ) {
  for ( int i = 0; i < combine_operators_length; i++ ) {        
    if ( id == combine_operator_id_list[ i ] ) {
      return combine_operators[ i ];
    }
  };
  return 0;
}

}
