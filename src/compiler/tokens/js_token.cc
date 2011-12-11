#include <string.h>
#include <stdio.h>
#include <compiler/tokens/js_token.h>
#include <grammar/grammar.tab.hh>

using namespace yy;
using namespace mocha;
#define TOKEN ParserImplementation::token

JsToken::JsToken (){};  



int JsToken::getType ( const char* token , bool isOperator ) {
  if ( isOperator ) {
    if ( token [ 1 ] == 0 ) {
      for ( int i = 0; i < operatorsLength_; ++i ) {
        if ( token [ 0 ] == operators_ [ i ] ) {       
          return operators_ [ i ];
        }
      }
    } else {
      for ( int i = 0; i < combineOperatorsLength_; i++ ) {        
        if ( strcmp ( token , combineOperators_ [ i ] ) == 0 ) {
          return operatorToken_ [ i ];          
        }        
      };                  
    }    
  } else {
    for ( int i = 0; i < keywordsLength_; i++ ) {
      if ( strcmp ( token , keywordsList_ [ i ] ) == 0 ) {
        return keywordToken_ [ i ];        
      }      
    }
    return TOKEN::JS_IDENTIFIER;
  }
  return 0;  
}

const char* JsToken::GetOperatorFromNumber( int id ) {
  for ( int i = 0; i < combineOperatorsLength_; i++ ) {        
    if ( id == operatorToken_[ i ] ) {
      return combineOperators_[ i ];          
    }
  };
  return 0;
}

int JsToken::keywordToken_ [] = {
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

char JsToken::keywordsList_ [] [ 20 ] = {  
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

char JsToken::operators_ [] = {
  
  '[' , ']' , '{' , '}' , '(' , ')' , '*' , '/' , '+' , '-' , '%' , '^' , '&' , '!' , '|' , '~' ,
  '?' , ',' , '<' , '>' , '.' , ';' , '=' , '\'' , '"' , ':' , '#'

};

int JsToken::operatorToken_ [] = {

  TOKEN::JS_INCREMENT , TOKEN::JS_DECREMENT , TOKEN::JS_EQUAL , TOKEN::JS_SHIFT_LEFT,
  TOKEN::JS_SHIFT_RIGHT , TOKEN::JS_LESS_EQUAL , TOKEN::JS_GRATER_EQUAL , TOKEN::JS_EQ,
  TOKEN::JS_NOT_EQUAL , TOKEN::JS_NOT_EQ , TOKEN::JS_U_SHIFT_RIGHT , TOKEN::JS_ADD_LET , TOKEN::JS_SUB_LET,
  TOKEN::JS_DIV_LET , TOKEN::JS_MOD_LET , TOKEN::JS_MUL_LET , TOKEN::JS_LOGICAL_AND,
  TOKEN::JS_LOGICAL_OR , TOKEN::JS_SHIFT_LEFT_LET , TOKEN::JS_SHIFT_RIGHT_LET,
  TOKEN::JS_U_SHIFT_RIGHT_LET , TOKEN::JS_NOT_LET , TOKEN::JS_NOT_EQ , TOKEN::JS_AND_LET,
  TOKEN::JS_LOGICAL_OR , TOKEN::JS_FUNCTION_GLYPH , TOKEN::JS_FUNCTION_GLYPH_WITH_CONTEXT

};

char JsToken::combineOperators_ [][ 20 ] = {

   "++" , "--" , "==", "<<" , ">>" , "<=" , ">=" , "===" , "!=" ,
   "!==", ">>>" , "+=" , "-=" , "/=" , "%=" , "*=" , "&&" , "||" , "<<=",
   ">>=" , ">>>=" , "^=" , "|==" , "&=" , "|=" , "->" , "=>"
  
};

int JsToken::operatorsLength_ = sizeof ( JsToken::operators_ );
int JsToken::keywordsLength_ = sizeof ( JsToken::keywordsList_ ) / sizeof ( JsToken::keywordsList_ [ 0 ] );
int JsToken::combineOperatorsLength_ = sizeof ( JsToken::combineOperators_ ) / sizeof ( JsToken::combineOperators_ [ 0 ] );

