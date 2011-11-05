/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <string.h>
#include "scanner.h"
#include "js_token.h"
#include "grammar.tab.hh"
#include "parser_tracer.h"

using namespace mocha;
using namespace std;
using namespace yy;

#define SET_LINE_BREAK (isLt_ = true)
#define UNSET_LINE_BREAK (isLt_ = false)
#define RETURN_TOKEN return &tokenStack_ [ 0 ]

#define SET_FLAG                                \
  Skip_ ();                                     \
  SetRegExpAfter_ ();                           \
  SetNumericAfter_ ()

#define CHECK_LT                                                        \
  if ( isLt_ &&                                                         \
       ( type_ == ParserImplementation::token::JS_RETURN ||                \
         type_ == ParserImplementation::token::JS_BREAK ||                 \
         type_ == ParserImplementation::token::JS_CONTINUE ||              \
         type_ == ParserImplementation::token::JS_THROW ) ) {              \
    BackChar_ ();                                                       \
    type_ = ParserImplementation::token::JS_LINE_BREAK;                    \
    UNSET_LINE_BREAK;                                                               \
    return 0;                                                           \
  } else if ( end_of_block_ == false &&                                 \
              type_ != ';' &&                                           \
              type_ != '{' &&                                           \
              !tracer_->GetState ( ParserTracer::kObjectLiteralEnd ) && \
              ch == '}' ) {                                             \
    BackChar_ ();                                                       \
    type_ = ';';                                                        \
    end_of_block_ = true;                                               \
    tokenStack_ += ';';                                                 \
    tracer_->EndState( ParserTracer::kObjectLiteralEnd );               \
    return &tokenStack_[0];                                             \
  } else if ( end_of_block_ == true ) {                                 \
    end_of_block_ = false;                                              \
  } else if ( use_tmp_ == true ) {                                      \
    BackChar_ ();                                                       \
    type_ = tmp_type_;                                                  \
    tokenStack_ = &tmp_stack_[0];                                       \
    use_tmp_ = false;                                                   \
    RETURN_TOKEN;                                                       \
  }



Scanner::Scanner ( const char* source , ParserTracer* tracer ) :  
  line_ ( 1 ),
  isLt_ ( false ),
  end_of_block_ ( false ),
  use_tmp_ ( false ),
  type_ ( 0 ),
  tracer_ ( tracer ) {
  source_ = source;
  index_ = 0;
  max_ = source_.size();
};
  
Scanner::~Scanner (){};

char* Scanner::GetToken () {
  tokenStack_.erase ();
  
  while ( !IsEof_ () ) {
    SET_FLAG;
    char ch = GetChar_ ();
    if ( ch == 0 ) {
      return 0;
    }
    
    CHECK_LT

    if ( IsIdentStart_ ( ch ) ) {
      CaseIdent_ ( ch );
      if ( type_ == ParserImplementation::token::JS_LINE_BREAK ) { return 0; }
      tracer_->EndState( ParserTracer::kCallExpEnd );
      RETURN_TOKEN;
    } else if ( isdigit ( ch ) ) {
      CaseDigit_ ( ch );
      tracer_->EndState( ParserTracer::kCallExpEnd );
      RETURN_TOKEN;
    } else if ( state_.IsNumericAfter () &&
                ch == '.' ) {
      CaseDigitBeginWithDot_ ( ch );
      tracer_->EndState( ParserTracer::kCallExpEnd );
      RETURN_TOKEN;
    } else if ( IsSingleOperator_ ( ch ) ) {
      UNSET_LINE_BREAK;
      state_.Reset ();
      tokenStack_ = ch;
      type_ = ch;
      tracer_->EndState( ParserTracer::kCallExpEnd );
      RETURN_TOKEN;
    } else if ( IsNotSingleOperator_ ( ch ) ) {
      tracer_->EndState( ParserTracer::kCallExpEnd );
      CaseNotSingleOperator_ ( ch );
      
      if ( ParserImplementation::token::JS_LINE_BREAK == type_ ) {
        return 0;
      }
      RETURN_TOKEN;
    }
  }
  
  if ( tokenStack_.size () > 0 ) {
    type_ = JsToken::getType ( tokenStack_.c_str () );
    RETURN_TOKEN;
  } else {
    return 0;
  }
}

bool Scanner::IsIdentStart_ ( char ch ) const {
  if ( isalpha ( ch ) || 
       ch == '_' || 
       ch == '$' ||
       ch == '@' ) {
    return true;
  } else {
    return false;
  }
}


inline void Scanner::Skip_ () {
  char ch = GetChar_ ();
  char next = GetChar_ ();
  bool isbreak = false;
  
  if ( IsWhiteSpace_ ( ch ) ||
       ( isbreak = IsBreak_ ( ch ) ) ) {
    if ( isbreak ) {
      line_++;
    }
    
    isbreak = false;
    while ( IsWhiteSpace_ ( next ) ||
            ( isbreak = IsBreak_ ( next ) ) ) {
      
      if ( isbreak ) {
        line_++;
        isbreak = false;
      }
      
      next = GetChar_ ();

    }
    
    BackChar_ ();
    Skip_ ();
  } else if ( ch == '/' && next == '*' ) {
    SkipMultiLineComment_ ();
    Skip_ ();
  } else if ( ch == '/' && next == '/' ) {
    SkipComment_ ();
    Skip_ ();
  } else {
    BackChar_ ( 2 );
  }
  
}

inline bool Scanner::IsWhiteSpace_ ( char ch ) const {
  if ( ch == ' ' ||
       ch == '\t'||
       ch == '\r' ) {
    return true;
  } else {
    return false;
  }
}

inline bool Scanner::IsBreak_ ( char ch ) {
  if ( ch == '\n' ) {
    SET_LINE_BREAK;
    return true;
  }
  return false;
}

inline bool Scanner::IsClose_ ( char ch ) const {
  if ( ch == ')' ||
       ch == '}' ||
       ch == ']'
       ) {
    return true;
  }
  return false;
}

inline bool Scanner::IsSingleOperator_ ( char ch ) const {
  if ( ch == '(' ||
       ch == ')' ||
       ch == '{' ||
       ch == '}' ||
       ch == '[' ||
       ch == ']' ||
       ch == '~' ||
       ch == ',' ||
       ch == '.' || 
       ch == ':' ||
       ch == ';' ||
       ch == '?' ) {
    return true;
  }
  return false;
}

inline bool Scanner::IsNotSingleOperator_ ( char ch ) const {
  if ( !IsSingleOperator_ ( ch ) && 
       ( ch > 32 ||
         ch < 48 ||
         ch > 57 ||
         ch < 65 ||
         ch > 90 ||
         ch < 97 ||
         ch > 122 ||
         ch < 127 ) &&
       !isalpha ( ch ) ) {
    return true;
  } else {
    return false;
  }
}

inline char Scanner::GetChar_ () {
  if ( IsEof_ () ) {
    index_++;
    return 0;
  } else {
    char ret = source_.at( index_ );
    index_++;
    return ret;
  }
}

inline void Scanner::BackChar_ ( int len ) {
  for ( int i = 0; i < len; i++ ) {
    index_--;
  }
}

inline void Scanner::SkipMultiLineComment_ () {
  int ch;
  while ( !IsEof_ () ) { 
    ch = GetChar_ ();
    char next = GetChar_ ();
    if ( ch == '*' && next == '/' ) {
      return;
    } else {
      if ( ch == '\n' ) {
        line_++;
        BackChar_ ();
      } else {
        BackChar_ ();
      }
    }
  }  
}


inline void Scanner::SkipComment_ () {
  int ch;
  while ( !IsEof_ () ) {
    ch = GetChar_ ();
    if ( ch == '\n' ) {
      line_++;
      return;
    }    
  }
}

inline bool Scanner::IsEof_ () const {
  return index_ >= max_;
}

inline void Scanner::SetNumericAfter_ () {
  if ( type_ == ParserImplementation::token::JS_EQ ||
       type_ == ParserImplementation::token::JS_EQUAL ||
       type_ == ParserImplementation::token::JS_LOGICAL_OR ||
       type_ == ParserImplementation::token::JS_OR_LET ||
       type_ == ParserImplementation::token::JS_NOT_LET ||
       type_ == ParserImplementation::token::JS_GRATER_EQUAL ||
       type_ == ParserImplementation::token::JS_EQUAL ||
       type_ == ParserImplementation::token::JS_LESS_EQUAL ||
       type_ == ParserImplementation::token::JS_AND_LET ||
       type_ == ParserImplementation::token::JS_LOGICAL_AND ||
       type_ == ParserImplementation::token::JS_NOT_EQUAL ||
       type_ == ParserImplementation::token::JS_RETURN ||
       type_ == ParserImplementation::token::JS_INCREMENT ||
       type_ == ParserImplementation::token::JS_DECREMENT ||
       type_ == ParserImplementation::token::JS_MUL_LET ||
       type_ == ParserImplementation::token::JS_DIV_LET ||
       type_ == ParserImplementation::token::JS_MOD_LET ||
       type_ == ParserImplementation::token::JS_ADD_LET ||
       type_ == ParserImplementation::token::JS_SUB_LET ||
       type_ == ParserImplementation::token::JS_SHIFT_LEFT ||
       type_ == ParserImplementation::token::JS_SHIFT_LEFT_LET ||
       type_ == ParserImplementation::token::JS_SHIFT_RIGHT ||
       type_ == ParserImplementation::token::JS_SHIFT_RIGHT_LET ||
       type_ == ParserImplementation::token::JS_U_SHIFT_RIGHT ||
       type_ == ParserImplementation::token::JS_U_SHIFT_RIGHT_LET ||
       type_ == '{' ||
       type_ == '(' ||
       type_ == '*' ||
       type_ == '/' ||
       type_ == '+' ||
       type_ == '-' ||
       type_ == '=' ||
       type_ == '^' ||
       type_ == '&' ||
       type_ == '|' ) {
    state_.NumericAfter ();
  } else {
    state_.NotNumericAfter ();
  }
}

inline void Scanner::SetRegExpAfter_ () {
  if ( type_ == ParserImplementation::token::JS_EQ ||
       type_ == ParserImplementation::token::JS_EQUAL ||
       type_ == ParserImplementation::token::JS_LOGICAL_OR ||
       type_ == ParserImplementation::token::JS_OR_LET ||
       type_ == ParserImplementation::token::JS_NOT_LET ||
       type_ == ParserImplementation::token::JS_GRATER_EQUAL ||
       type_ == ParserImplementation::token::JS_EQUAL ||
       type_ == ParserImplementation::token::JS_LESS_EQUAL ||
       type_ == ParserImplementation::token::JS_AND_LET ||
       type_ == ParserImplementation::token::JS_LOGICAL_AND ||
       type_ == ParserImplementation::token::JS_NOT_EQUAL ||
       type_ == ParserImplementation::token::JS_RETURN ||
       type_ == '}' ||
       type_ == '|' ||
       type_ == '{' ||
       type_ == '^' ||
       type_ == '[' ||
       type_ == '?' ||
       type_ == '=' ||
       type_ == ';' ||
       type_ == ':' ||
       type_ == ',' ||
       type_ == '(' ||
       type_ == '&' ||
       type_ == '!' ) {
    state_.RegExpAfter ();
  } else {
    state_.NotRegExpAfter ();
  }
}

inline void Scanner::CaseIdent_ ( char ch ) {
  state_.Reset ();
  tokenStack_ = ch;
  char next = GetChar_ ();
  
  while ( IsIdentStart_ ( next ) || isdigit ( next ) ) {
    tokenStack_ += next;
    next = GetChar_ ();
  }
  int last_type = type_;
  BackChar_ ();
  type_ = JsToken::getType ( tokenStack_.c_str () );
  
  if ( type_ == ParserImplementation::token::JS_IDENTIFIER ||
       type_ == ParserImplementation::token::JS_DELETE ||
       type_ == ParserImplementation::token::JS_TYPEOF ||
       type_ == ParserImplementation::token::JS_VOID ||
       type_ == ParserImplementation::token::JS_IF ||
       type_ == ParserImplementation::token::JS_WHILE ||
       type_ == ParserImplementation::token::JS_FOR ||
       type_ == ParserImplementation::token::JS_DO ||
       type_ == ParserImplementation::token::JS_SWITCH ||
       type_ == ParserImplementation::token::JS_TRY ||
       type_ == ParserImplementation::token::JS_THROW ||
       type_ == ParserImplementation::token::JS_FUNCTION ||
       type_ == ParserImplementation::token::JS_CONTINUE ||
       type_ == ParserImplementation::token::JS_BREAK ||
       type_ == ParserImplementation::token::JS_VAR ) {
    if ( last_type != ';' &&
         isLt_ == true &&
         ( last_type == ParserImplementation::token::JS_IDENTIFIER ||
           last_type == ']' ) ){
      use_tmp_ = true;
      tmp_stack_ = &tokenStack_[0];
      tmp_type_ = type_;
      type_ = ';';
    } else if ( isLt_ && last_type == ')' &&
                tracer_->GetState( ParserTracer::kCallExpEnd ) ) {
      use_tmp_ = true;
      tmp_stack_ = &tokenStack_[0];
      tmp_type_ = type_;
      type_ = ';';
      tracer_->EndState( ParserTracer::kCallExpEnd );
    }
  }
  UNSET_LINE_BREAK;
}

inline void Scanner::CaseDigit_ ( char ch ) {
  UNSET_LINE_BREAK;
  state_.Reset ();
  tokenStack_ = ch;
  char next = tolower ( GetChar_ () );
      
  if ( next == '.' ) {
    CaseDigitFloat_ ( next );
  } else if ( next == 'x' && ch == '0' ) {
    CaseDigitHex_ ( next );
  } else if ( isdigit ( next ) || next == 'e' ) {
    CaseDigitNumber_ ( next );
  } else {
    BackChar_ ();
  }

  type_ = ParserImplementation::token::JS_NUMERIC_LITERAL;
}

inline void Scanner::CaseDigitFloat_ ( char ch ) {

  tokenStack_ += ch;
  bool hasIndex = false;
  char next;
  char last;
    
  while ( ( next = GetChar_ () ) ) {
      
    next = tolower ( next );
      
    if ( isdigit ( next ) ) {
        
      tokenStack_ += next;
      last = next;
      hasIndex = false;
      
    } else if ( ( next == 'e' && !hasIndex ) &&
                last != 'e' ) {
        
      tokenStack_ += next;
      last = next;
      hasIndex = true;
      
    } else if ( ( next == '+' || next == '-' ) && last == 'e' ) {
        
      tokenStack_ += next;
      last = next;
      hasIndex = false;
      
    } else {
        
      BackChar_ ();
      break;
      
    }

  }

}

inline bool IsHexNum ( char ch ) {

  if ( isdigit ( ch ) ||
       ch == 'a' ||
       ch == 'b' ||
       ch == 'c' ||
       ch == 'd' ||
       ch == 'e' ||
       ch == 'f' )  {

    return true;

  }

  return false;
  
}

inline void Scanner::CaseDigitHex_ ( char ch ) {

  char next;
  tokenStack_ += ch;
  GetChar_();
  while ( ( next = GetChar_ () ) ) {
    
    next = tolower ( next );
    
    if ( IsHexNum ( next ) ) {
      tokenStack_ += next;
    } else if ( isdigit( next ) ) {
      tokenStack_ += next;
    } else {
      BackChar_ ();
      break;
    }
  }
}

inline void Scanner::CaseDigitNumber_ ( char ch ) {

  tokenStack_ += ch;
  bool hasIndex = ( ch == 'e' )? true : false;
  char last = ch;
  char next;
        
  while ( ( next = GetChar_ () ) ) {
    
    next = tolower ( next );
    
    if ( isdigit ( next ) ) {
      
      tokenStack_ += next;
      last = next;
    
    } else if ( next == 'e' &&
                !hasIndex &&
                last != 'e' ) {
      
      tokenStack_ += next;
      last = next;
    
    } else if ( ( next == '+' || next == '-' ) &&
                last == 'e' ) {
      
      tokenStack_ += next;
      last = next;
    
    } else {
      
      BackChar_ ();
      break;
    
    }

  }

}

inline void Scanner::CaseDigitBeginWithDot_ ( char ch ) {

  UNSET_LINE_BREAK;
  state_.Reset ();
  tokenStack_ = ch;
  bool hasIndex = false;
  char last;
  char next;
  
  while ( ( next = GetChar_ () ) ) {

    if ( isdigit ( next ) ) {
      
      tokenStack_ += next;
      last = next;
    
    } else if ( next == 'e' &&
                !hasIndex &&
                last != 'e' ) {
      
      tokenStack_ += next;
      last = next;
    
    } else if ( ( next == '+' || next == '-' ) &&
                last == 'e' ) {
      
      tokenStack_ += next;
      last = next;
    
    } else {
      
      BackChar_ ();
      break;
    
    }

  }
  
  type_ = JsToken::getType ( tokenStack_.c_str () );

}

inline void Scanner::CaseNotSingleOperator_ ( char ch ) {

  tokenStack_ = ch;
  
  switch ( ch ) {
  case '"' :
  case '\'' :
    {
      CaseStringLiteral_ ( ch );
      break;
    }
  case '=' :
  case '!' :
    {
      CaseEqualities_ ();
      break;
    }
  case '-' :
  case '+' :
    {
      CaseAddAndSub_ ( ch );
      break;
    }
  case '/' :
  case '*' :
  case '%' :
    {
      UNSET_LINE_BREAK;
      if ( ch == '/' &&
           state_.IsRegExpAfter () ) {
        
        CaseRegExpLiteral_ ();
      
      } else {
      
        CaseUnary_ ();
      
      }
      break;    
    }
  case '|' :
  case '&' :
  case '^' :
  case '<' :
    {
      CaseLogical_ ( ch );
      break;
    }

  case '>' :
    {
      CaseShiftRight_ ();
      break;
    }

  }

}

inline void Scanner::CaseStringLiteral_ ( char ch ) {

  UNSET_LINE_BREAK;
  state_.Reset ();
  char next;
  bool escaped = false;
  
  while ( ( next = GetChar_ () ) ) {
    
    if ( !escaped && next == '\\' ) {
      
      escaped = true;
    
    } else {
      
      escaped = false;
    
    }
            
    tokenStack_ += next;

    if ( !escaped && next == '\n' ) {
      
      break;
      
    }

    if ( !escaped && next == ch ) {
      
      break;
    
    }

  }
  
  type_ = ParserImplementation::token::JS_STRING_LITERAL;

}

inline void Scanner::CaseEqualities_ () {

  
  UNSET_LINE_BREAK;
  state_.Reset ();
  char next = GetChar_ ();
          
  if ( next == '=' ) {
    
    tokenStack_ += next;
    next = GetChar_ ();
    
    if ( next == '=' ) {
      
      tokenStack_ += next;
    
    } else {
      
      BackChar_ ();
    
    }
  
  } else {
    
    BackChar_ ();
  
  }
          
  type_ = JsToken::getType ( tokenStack_.c_str () , true );

}

inline void Scanner::CaseAddAndSub_ ( char ch ) {

  state_.Reset ();
  char next = GetChar_ ();
  
  if ( next == ch || next == '=' ) {
    
    if ( next == ch && isLt_ ) {
      
      BackChar_ ( 2 );
      UNSET_LINE_BREAK;
      type_ = ParserImplementation::token::JS_LINE_BREAK;
      return;
    
    }
    
    tokenStack_ += next;
  
  } else {
    
    BackChar_ ();
  
  }
  
  UNSET_LINE_BREAK;
  type_ = JsToken::getType ( tokenStack_.c_str () , true );

}

inline void Scanner::CaseRegExpLiteral_ () {
            
  bool isescaped = false, ischarClass = false;
  char next;
            
  while ( ( next = GetChar_ () ) ) {
              
    if ( !isescaped &&
         next == '\\' ) {
                
      isescaped = true;
      tokenStack_ += next;
                
    } else if ( !isescaped &&
                next == '[' ) {
                
      ischarClass = true;
      isescaped = false;
      tokenStack_ += next;
                
    } else if ( !isescaped &&
                ischarClass &&
                next == ']' ) {
                
      ischarClass = false;
      tokenStack_ += next;
                
    } else if ( !isescaped &&
                !ischarClass &&
                next == '/' ) {
                
      CaseRegExpFlag_ ( next );
      break;
        
    } else {
                
      isescaped = false;
      tokenStack_ += next;
              
    }
  }

}

inline void Scanner::CaseRegExpFlag_ ( char ch ) {

  tokenStack_ += ch;
  char next = GetChar_ ();
  
  if ( next == 'i' ||
       next == 'g' ||
       next == 'm' ) {
    
    tokenStack_ += next;
    
    while ( ( next = GetChar_ () ) ) {
      if ( next == 'i' ||
           next == 'g' ||
           next == 'm' ) {
        tokenStack_ += next;
      } else {
        BackChar_ ();
        break;
      }
    }
    
  } else {
    
    BackChar_ ();
  
  }
                
  state_.Reset ();
  type_ = ParserImplementation::token::JS_REGEXP_LITERAL;

}

inline void Scanner::CaseUnary_ () {

  char next = GetChar_ ();
  
  if ( next == '=' ) {
    
    tokenStack_ += next;
  
  }
  
  BackChar_ ();
  type_ = JsToken::getType ( tokenStack_.c_str () , true );

}

inline void Scanner::CaseLogical_ ( char ch ) {

  UNSET_LINE_BREAK;
  state_.Reset ();
  char next = GetChar_ ();
  
  if ( next == ch ) {
    
    tokenStack_ += next;
  
  } else if ( ( ch == '|' ||
                ch == '^' ||
                ch == '<' ) &&
              next == '=' ) {
    
    tokenStack_ += next;
  
  } else {
    
    BackChar_ ();
  
  }
  
  type_ = JsToken::getType ( tokenStack_.c_str () , true );

}

inline void Scanner::CaseShiftRight_ () {

  UNSET_LINE_BREAK;
  state_.Reset ();
  char next = GetChar_ ();
  
  if ( next == '=' ) {
    
    tokenStack_ += next;
  
  } else if ( next == '>' ) {
    
    tokenStack_ += next;
    next = GetChar_ ();
    
    if ( next == '>' ) {
      
      tokenStack_ += next;
      BackChar_ ();
    
    } else {
      
      BackChar_ ();
    
    }
  } else {
    
    BackChar_ ();
  
  }
  
  type_ = JsToken::getType ( tokenStack_.c_str () , true );

}
