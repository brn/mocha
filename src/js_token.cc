#include <string.h>
#include <stdio.h>
#include "js_token.h"
#include "ast_type.h"
#include "grammar.tab.hh"

using namespace yy;
using namespace mocha;


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
    return ParserImplementation::token::JS_IDENTIFIER;
  }
  return 0;  
}

int JsToken::keywordToken_ [] = {
  ParserImplementation::token::JS_ABSTRACT,
  ParserImplementation::token::JS_BOOLEAN,
  ParserImplementation::token::JS_BREAK,
  ParserImplementation::token::JS_BYTE,
  ParserImplementation::token::JS_CASE, 
  ParserImplementation::token::JS_CATCH,
  ParserImplementation::token::JS_CHAR,
  ParserImplementation::token::JS_CLASS,
  ParserImplementation::token::JS_CONST,
  ParserImplementation::token::JS_CONTINUE,
  ParserImplementation::token::JS_DEBUGGER,
  ParserImplementation::token::JS_DEFAULT,
  ParserImplementation::token::JS_DELETE,
  ParserImplementation::token::JS_DO,
  ParserImplementation::token::JS_DOUBLE,
  ParserImplementation::token::JS_ELSE,
  ParserImplementation::token::JS_ENUM,
  ParserImplementation::token::JS_EXPORT,
  ParserImplementation::token::JS_EXTENDS,
  ParserImplementation::token::JS_FALSE,
  ParserImplementation::token::JS_FINAL,
  ParserImplementation::token::JS_FINALLY,
  ParserImplementation::token::JS_FLOAT,
  ParserImplementation::token::JS_FOR,
  ParserImplementation::token::JS_FUNCTION,
  ParserImplementation::token::JS_GOTO,
  ParserImplementation::token::JS_IF,
  ParserImplementation::token::JS_IMPLEMENTS,
  ParserImplementation::token::JS_IMPORT,
  ParserImplementation::token::JS_IN,
  ParserImplementation::token::JS_INSTANCEOF,
  ParserImplementation::token::JS_INT,
  ParserImplementation::token::JS_INTERFACE,
  ParserImplementation::token::JS_LONG,
  ParserImplementation::token::JS_NATIVE,
  ParserImplementation::token::JS_NEW,
  ParserImplementation::token::JS_K_NULL,
  ParserImplementation::token::JS_PACKAGE_RESERVED,
  ParserImplementation::token::JS_PRIVATE,
  ParserImplementation::token::JS_PROTECTED,
  ParserImplementation::token::JS_PUBLIC,
  ParserImplementation::token::JS_RETURN,
  ParserImplementation::token::JS_SHORT,
  ParserImplementation::token::JS_STATIC,
  ParserImplementation::token::JS_SUPER,
  ParserImplementation::token::JS_SWITCH,
  ParserImplementation::token::JS_SYNCHRONIZED,
  ParserImplementation::token::JS_THIS,
  ParserImplementation::token::JS_THROW,
  ParserImplementation::token::JS_THROWS,
  ParserImplementation::token::JS_TRANSIENT,
  ParserImplementation::token::JS_TRUE,
  ParserImplementation::token::JS_TRY,
  ParserImplementation::token::JS_TYPEOF,
  ParserImplementation::token::JS_VAR,
  ParserImplementation::token::JS_VOID,
  ParserImplementation::token::JS_VOLATILE,
  ParserImplementation::token::JS_WHILE,
  ParserImplementation::token::JS_WITH,
  ParserImplementation::token::JS_SHORTER_FUNCTION
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
  "long" ,
  "native" ,
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
  "fun"
};

char JsToken::operators_ [] = {
  
  '[' , ']' , '{' , '}' , '(' , ')' , '*' , '/' , '+' , '-' , '%' , '^' , '&' , '!' , '|' , '~' ,
  '?' , ',' , '<' , '>' , '.' , ';' , '=' , '\'' , '"' , ':' , '#'

};

int JsToken::operatorToken_ [] = {

  ParserImplementation::token::JS_INCREMENT , ParserImplementation::token::JS_DECREMENT , ParserImplementation::token::JS_EQUAL , ParserImplementation::token::JS_SHIFT_LEFT,
  ParserImplementation::token::JS_SHIFT_RIGHT , ParserImplementation::token::JS_LESS_EQUAL , ParserImplementation::token::JS_GRATER_EQUAL , ParserImplementation::token::JS_EQ,
  ParserImplementation::token::JS_NOT_EQUAL , ParserImplementation::token::JS_NOT_EQ , ParserImplementation::token::JS_U_SHIFT_RIGHT , ParserImplementation::token::JS_ADD_LET , ParserImplementation::token::JS_SUB_LET,
  ParserImplementation::token::JS_DIV_LET , ParserImplementation::token::JS_MOD_LET , ParserImplementation::token::JS_MUL_LET , ParserImplementation::token::JS_LOGICAL_AND,
  ParserImplementation::token::JS_LOGICAL_OR , ParserImplementation::token::JS_SHIFT_LEFT_LET , ParserImplementation::token::JS_SHIFT_RIGHT_LET,
  ParserImplementation::token::JS_U_SHIFT_RIGHT_LET , ParserImplementation::token::JS_NOT_LET , ParserImplementation::token::JS_NOT_EQ , ParserImplementation::token::JS_AND_LET,
  ParserImplementation::token::JS_LOGICAL_OR , ParserImplementation::token::JS_ARROW

};

char JsToken::combineOperators_ [][ 20 ] = {

   "++" , "--" , "==", "<<" , ">>" , "<=" , ">=" , "===" , "!=" ,
   "!==", ">>>" , "+=" , "-=" , "/=" , "%=" , "*=" , "&&" , "||" , "<<=",
   ">>=" , ">>>=" , "^=" , "|==" , "&=" , "|=" , "->"
  
};

int JsToken::operatorsLength_ = sizeof ( JsToken::operators_ );
int JsToken::keywordsLength_ = sizeof ( JsToken::keywordsList_ ) / sizeof ( JsToken::keywordsList_ [ 0 ] );
int JsToken::combineOperatorsLength_ = sizeof ( JsToken::combineOperators_ ) / sizeof ( JsToken::combineOperators_ [ 0 ] );

