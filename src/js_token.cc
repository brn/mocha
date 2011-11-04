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
    return ParserImplementation::token::IDENTIFIER;    
  }
  return 0;  
}

int JsToken::keywordToken_ [] = {
  ParserImplementation::token::ABSTRACT,
  ParserImplementation::token::BOOLEAN,
  ParserImplementation::token::BREAK,
  ParserImplementation::token::BYTE,
  ParserImplementation::token::CASE, 
  ParserImplementation::token::CATCH,
  ParserImplementation::token::CHAR,
  ParserImplementation::token::CLASS,
  ParserImplementation::token::CONST,
  ParserImplementation::token::CONTINUE,
  ParserImplementation::token::DEBUGGER,
  ParserImplementation::token::DEFAULT,
  ParserImplementation::token::DELETE,
  ParserImplementation::token::DO,
  ParserImplementation::token::DOUBLE,
  ParserImplementation::token::ELSE,
  ParserImplementation::token::ENUM,
  ParserImplementation::token::EXPORT,
  ParserImplementation::token::EXTENDS,
  ParserImplementation::token::FALSE,
  ParserImplementation::token::FINAL,
  ParserImplementation::token::FINALLY,
  ParserImplementation::token::FLOAT,
  ParserImplementation::token::FOR,
  ParserImplementation::token::FUNCTION,
  ParserImplementation::token::GOTO,
  ParserImplementation::token::IF,
  ParserImplementation::token::IMPLEMENTS,
  ParserImplementation::token::IMPORT,
  ParserImplementation::token::IN,
  ParserImplementation::token::INSTANCEOF,
  ParserImplementation::token::INT,
  ParserImplementation::token::INTERFACE,
  ParserImplementation::token::LONG,
  ParserImplementation::token::NATIVE,
  ParserImplementation::token::NEW,
  ParserImplementation::token::K_NULL,
  ParserImplementation::token::PACKAGE_RESERVED,
  ParserImplementation::token::PRIVATE,
  ParserImplementation::token::PROTECTED,
  ParserImplementation::token::PUBLIC,
  ParserImplementation::token::RETURN,
  ParserImplementation::token::SHORT,
  ParserImplementation::token::STATIC,
  ParserImplementation::token::SUPER,
  ParserImplementation::token::SWITCH,
  ParserImplementation::token::SYNCHRONIZED,
  ParserImplementation::token::THIS,
  ParserImplementation::token::THROW,
  ParserImplementation::token::THROWS,
  ParserImplementation::token::TRANSIENT,
  ParserImplementation::token::TRUE,
  ParserImplementation::token::TRY,
  ParserImplementation::token::TYPEOF,
  ParserImplementation::token::VAR,
  ParserImplementation::token::VOID,
  ParserImplementation::token::VOLATILE,
  ParserImplementation::token::WHILE,
  ParserImplementation::token::WITH
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
  "with"
};

char JsToken::operators_ [] = {
  
  '[' , ']' , '{' , '}' , '(' , ')' , '*' , '/' , '+' , '-' , '%' , '^' , '&' , '!' , '|' , '~' ,
  '?' , ',' , '<' , '>' , '.' , ';' , '=' , '\'' , '"' , ':'

};

int JsToken::operatorToken_ [] = {

  ParserImplementation::token::INCREMENT , ParserImplementation::token::DECREMENT , ParserImplementation::token::EQUAL , ParserImplementation::token::SHIFT_LEFT,
  ParserImplementation::token::SHIFT_RIGHT , ParserImplementation::token::LESS_EQUAL , ParserImplementation::token::GRATER_EQUAL , ParserImplementation::token::EQ,
  ParserImplementation::token::NOT_EQUAL , ParserImplementation::token::NOT_EQ , ParserImplementation::token::U_SHIFT_RIGHT , ParserImplementation::token::ADD_LET , ParserImplementation::token::SUB_LET,
  ParserImplementation::token::DIV_LET , ParserImplementation::token::MOD_LET , ParserImplementation::token::MUL_LET , ParserImplementation::token::LOGICAL_AND,
  ParserImplementation::token::LOGICAL_OR , ParserImplementation::token::SHIFT_LEFT_LET , ParserImplementation::token::SHIFT_RIGHT_LET,
  ParserImplementation::token::U_SHIFT_RIGHT_LET , ParserImplementation::token::NOT_LET , ParserImplementation::token::NOT_EQ , ParserImplementation::token::AND_LET,
  ParserImplementation::token::LOGICAL_OR

};

char JsToken::combineOperators_ [][ 20 ] = {

   "++" , "--" , "==", "<<" , ">>" , "<=" , ">=" , "===" , "!=" ,
   "!==", ">>>" , "+=" , "-=" , "/=" , "%=" , "*=" , "&&" , "||" , "<<=",
   ">>=" , ">>>=" , "^=" , "|==" , "&=" , "|="
  
};

int JsToken::operatorsLength_ = sizeof ( JsToken::operators_ );
int JsToken::keywordsLength_ = sizeof ( JsToken::keywordsList_ ) / sizeof ( JsToken::keywordsList_ [ 0 ] );
int JsToken::combineOperatorsLength_ = sizeof ( JsToken::combineOperators_ ) / sizeof ( JsToken::combineOperators_ [ 0 ] );

