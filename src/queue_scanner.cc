#include <stdint.h>
#include <deque>
#include <string>
#include "js_token.h"
#include "token_info.h"
#include "grammar.tab.hh"
#include "queue_scanner.h"
#include "scoped_list.h"
#include "managed_handle.h"
#include "parser_tracer.h"

#define TOKEN yy::ParserImplementation::token
#define ITERATOR(name) begin=name.begin(),end=name.end()
#define RITERATOR(name) begin=name.rbegin(),end=name.rend()

namespace mocha {

class QueueScanner::Scanner {
 public :
  typedef std::deque<TokenInfo*> TokenQueue;
  Scanner( const std::string& source ) :
      index_( 0 ), line_(0) , is_rest_( false ) , is_numeric_after_( false ),
      is_regexp_after_( false ), source_( source ) {
    max_ = source_.size();
  }

  /**
   * @public
   * Collect token and push into the token queue.
   */
  inline void CollectToken() {
    while ( !IsEof_() ) {
      Skip_();
      if ( is_line_break_ ) {
        printf( "set line break %d\n" , line_ );
        PushBack_( TOKEN::JS_LINE_BREAK );
        is_line_break_ = false;
      }
      char ch = GetChar_();
      if ( IsIdentStart_( ch ) ) {
        //identifier
        CaseIdent_( ch );
      } else if ( isdigit( ch ) ) {
        //numeric begin with 0...9
        CaseDigit_( ch );
      } else if ( is_numeric_after_ && ch == '.' ) {
        //numeric begin with '.'
        //treat as float.
        CaseDigitBeginWithDot_( ch );
      } else if ( IsSingleOperator_( ch ) ) {
        //operator that is not continue after operator. Like { } [ ]
        TokenInfo* info = ManagedHandle::Retain( new TokenInfo( "" , ch , line_ ) );
        token_queue_.push_back( info );
      } else if ( IsNotSingleOperator_( ch ) ) {
        //operator like + - =
        CaseNotSingleOperator_( ch );
      }
      SetRegExpAfter_();
      SetNumericAfter_();
    }
    //Sentinel.
    TokenInfo* info = ManagedHandle::Retain( new TokenInfo( "" , 0 , 0 ) );
    token_queue_.push_back( info );
  }

  inline TokenQueue& GetQueue() {
    return token_queue_;
  }
  
 private :

  /**
   * @private
   * Check source is end or not.
   */
  inline bool IsEof_ () {
    return index_ >= max_;
  }

  /**
   * @private
   * Get next char form source.
   */
  inline char GetChar_ () {
    if ( IsEof_ () ) {
      index_++;
      return 0;
    } else {
      char ret = source_.at( index_ );
      index_++;
      return ret;
    }
  }

  /**
   * @private
   * Decrement source index.
   */
  inline void BackChar_ ( int len = 1 ) {
    for ( int i = 0; i < len; i++ ) {
      index_--;
    }
  }
  
  /**
   * @private
   * Skip all comment , whitespace and linebreak.
   */
  void Skip_() {
    char ch = GetChar_();
    char next = GetChar_ ();
    bool isbreak = IsBreak_ ( ch );
    //Check that token is whitespace or line break.
    if ( IsWhiteSpace_ ( ch ) || isbreak ) {
      //Add line number.
      if ( isbreak ) {
        is_line_break_ = true;
        line_++;
      }
      isbreak = false;
      
      //Loop while whitespace or linebreak is continue.
      while ( IsWhiteSpace_ ( next ) ||
              ( isbreak = IsBreak_ ( next ) ) ) {
        if ( isbreak ) {
          line_++;
          is_line_break_ = true;
          isbreak = false;
        }
        next = GetChar_ ();
      }
      
      BackChar_ ();
      //Check is comment after.
      Skip_ ();
    } else if ( ch == '/' && next == '*' ) {
      //Process multiline comment.
      SkipMultiLineComment_ ();
      //Check is whitespace or singleline comment continue. 
      Skip_ ();
    } else if ( ch == '/' && next == '/' ) {
      //Process single line comment.
      SkipComment_ ();
      //Check is whitespace or multiline comment continue.
      Skip_ ();
    } else {
      //Not match.
      BackChar_ ( 2 );
    }
  }

  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Check is whitespace or not.
   */
  inline bool IsWhiteSpace_ ( char ch ) {
    if ( ch == ' ' ||
         ch == '\t'||
         ch == '\r' ) {
      return true;
    } else {
      return false;
    }
  }

  /**
   * @private
   * @param {char}
   * @return {bool}
   * Check is line break or not.
   */
  inline bool IsBreak_ ( char ch ) {
    if ( ch == '\n' ) {
      return true;
    }
    return false;
  }

  /**
   * @private
   * cosume token while multiline comment block is continue.
   */
  inline void SkipMultiLineComment_ () {
    int ch;
    while ( !IsEof_ () ) { 
      ch = GetChar_ ();
      char next = GetChar_ ();
      //End of multiline comment.
      if ( ch == '*' && next == '/' ) {
        return;
      } else {
        if ( ch == '\n' ) {
          line_++;
          is_line_break_ = true;
        }
        BackChar_ ();
      }
    }
  }

  /**
   * @private
   * Consume token while single line comment is continue.
   */
  inline void SkipComment_ () {
    int ch;
    while ( !IsEof_ () ) {
      ch = GetChar_ ();
      if ( ch == '\n' ) {
        line_++;
        is_line_break_ = true;
        return;
      }    
    }
  }
  
  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Check is identifier token start or not.
   */
  inline bool IsIdentStart_ ( char ch ) {
    if ( isalpha ( ch ) || 
         ch == '_' || 
         ch == '$' ||
         //treat special token.
         ch == '@' ) {
      return true;
    } else {
      return false;
    }
  }


  /**
   * @private
   * @param {char}
   * Collect identifier.
   */
  inline void CaseIdent_ ( char ch ) {
    token_str_ = ch;
    char next = GetChar_ ();
  
    while ( IsIdentStart_ ( next ) || isdigit ( next ) ) {
      token_str_ += next;
      next = GetChar_ ();
    }
    
    BackChar_ ();
    PushBack_( token_str_.c_str() );
  }


  /**
   * @private
   * @param {char}
   * In case of numeric literal.
   */
  inline void CaseDigit_ ( char ch ) {
    token_str_ = ch;
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
    PushBack_( token_str_.c_str() , TOKEN::JS_NUMERIC_LITERAL );
  }


  /**
   * @private
   * @param {char}
   * Case float.
   */
  inline void CaseDigitFloat_ ( char ch ) {
    token_str_ += ch;
    bool hasIndex = false;
    char next;
    char last;
    
    while ( ( next = GetChar_ () ) ) {
      next = tolower ( next );
    
      if ( isdigit ( next ) ) {
        token_str_ += next;
        last = next;
        hasIndex = false;
      } else if ( ( next == 'e' && !hasIndex ) &&
                  last != 'e' ) {
        token_str_ += next;
        last = next;
        hasIndex = true;
      } else if ( ( next == '+' || next == '-' ) && last == 'e' ) {
        token_str_ += next;
        last = next;
        hasIndex = false;
      } else {
        BackChar_ ();
        break;
      }
    }
  }


  inline bool IsHex_( char ch ) {
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


  inline void CaseDigitHex_ ( char ch ) {

    char next;
    token_str_ += ch;
    GetChar_();
    while ( ( next = GetChar_ () ) ) {
      next = tolower ( next );
    
      if ( IsHex_ ( next ) ) {
        token_str_ += next;
      } else if ( isdigit( next ) ) {
        token_str_ += next;
      } else {
        BackChar_ ();
        break;
      }
    }
  }


  inline void CaseDigitNumber_ ( char ch ) {
    token_str_ += ch;
    bool hasIndex = ( ch == 'e' )? true : false;
    char last = ch;
    char next;
        
    while ( ( next = GetChar_ () ) ) {
      next = tolower ( next );
    
      if ( isdigit ( next ) ) {
        token_str_ += next;
        last = next;
      } else if ( next == 'e' &&
                  !hasIndex &&
                  last != 'e' ) {
        token_str_ += next;
        last = next;
      } else if ( ( next == '+' || next == '-' ) &&
                  last == 'e' ) {
        token_str_ += next;
        last = next;
      } else {
        BackChar_ ();
        break;
      }
    }
  }


  inline void CaseDigitBeginWithDot_ ( char ch ) {
    token_str_ = ch;
    bool hasIndex = false;
    char last;
    char next;
  
    while ( ( next = GetChar_ () ) ) {
      if ( isdigit ( next ) ) {
        token_str_ += next;
        last = next;
      } else if ( next == 'e' &&
                  !hasIndex &&
                  last != 'e' ) {
        token_str_ += next;
        last = next;
      } else if ( ( next == '+' || next == '-' ) &&
                  last == 'e' ) {
        token_str_ += next;
        last = next;
      } else {
        BackChar_ ();
        break;
      }
    }
  }
  
  
  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Distinct parameter char is operators that is continue after operator. 
   */
  inline bool IsSingleOperator_ ( char ch ) {
    if ( ch == '(' || ch == ')' ||
         ch == '{' || ch == '}' ||
         ch == '[' || ch == ']' ||
         ch == '~' || ch == ',' ||
         ch == '.' || ch == ':' ||
         ch == ';' || ch == '?' ||
         ch == '#' ) {
      char next = GetChar_();
      char next_after_ = GetChar_();
      if ( ch == '.' && next == ch && next_after_ == ch ) {
        BackChar_( 2 );
        is_rest_ = true;
        return false;
      }
      BackChar_( 2 );
      return true;
    }
    return false;
  }
  

  /**
   * @private
   * @param {char}
   * @returns {bool}
   * Check operator like + = -
   */
  inline bool IsNotSingleOperator_ ( char ch ) {
    if ( !IsSingleOperator_ ( ch ) && 
         ( ch > 32 ||
           ch < 48 ||
                ch > 57 ||
           ch < 65 ||
                ch > 90 ||
           ch < 97 ||
                ch > 122 ||
           ch < 127 || is_rest_ ) &&
         !isalpha ( ch ) ) {
      return true;
    } else {
      return false;
    }
  }


  inline void CaseNotSingleOperator_ ( char ch ) {
    token_str_ = ch;
    
    switch ( ch ) {
      case '.' :
        {
          token_str_ += GetChar_();
          token_str_ += GetChar_();
          PushBack_( token_str_.c_str() , TOKEN::JS_PARAMETER_REST );
          is_rest_ = false;
          break;
        }
      case '"' :
      case '\'' :
        {
          CaseStringLiteral_ ( ch );
          break;
        }
      case '=' :
      case '!' :
        {
          CaseEqualitiesORFunGlyph_ ();
          break;
        }
      case '-' :
      case '+' :
        {
          CaseAddAndSubORFunGlyph_ ( ch );
          break;
        }
      case '/' :
      case '*' :
      case '%' :
        {
          if ( ch == '/' &&
               is_regexp_after_ ) {
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

  
  inline void CaseStringLiteral_ ( char ch ) {
    char next = GetChar_();
    char next_after_ = GetChar_();
    bool escaped = false;
    bool is_seqence = false;

    if ( next == ch && next_after_ == ch ) {
      while ( ( next = GetChar_ () ) ) {
        if ( next == '\n' ) {
          line_++;
        } else if ( next != '\r' ) {
          token_str_ += next;
        }
          
        char next_after = GetChar_();
        char next_after_after = GetChar_();
        if ( next == ch && next_after == ch && next_after_after == ch ) {
          break;
        } else {
          BackChar_( 2 );
        }
      }
    } else {
      BackChar_( 2 );
      while ( ( next = GetChar_ () ) ) {
        if ( !escaped && next == '\\' ) {
          escaped = true;
        } else {
          escaped = false;
        }
      
        token_str_ += next;
        if ( !escaped && next == '\n' ) {
          break;
        }

        if ( !escaped && next == ch ) {
          break;
        }
      }
    }
    PushBack_( token_str_.c_str() , TOKEN::JS_STRING_LITERAL );
  }


  inline void CaseEqualitiesORFunGlyph_ () {
    char next = GetChar_();
    if ( next == '=' ) {
      token_str_ += next;
      next = GetChar_ ();
      if ( next == '=' ) {
        token_str_ += next;
      } else {
        BackChar_();
      }
    } else if ( next == '>' ) {
      token_str_ += next;
      RewriteArrowFunction_();
    } else {
      BackChar_();
    }

    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str () , true ) );
  }


  
  inline void CaseAddAndSubORFunGlyph_ ( char ch ) {
    char next = GetChar_();
    if ( next == ch || next == '=' ) {
      token_str_ += next;
    } else if ( ch == '-' && next == '>' ) {
      token_str_ += next;
      RewriteArrowFunction_();
    } else {
      BackChar_ ();
    }
    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str () , true ) );
  }


  inline void RewriteArrowFunction_() {
    if ( token_queue_.size() > 0 ) {
      TokenQueue::reverse_iterator RITERATOR(token_queue_);
      int paren_count = 0;
      while ( ( *begin )->GetType() == TOKEN::JS_LINE_BREAK ) {
        ++begin;
      }
      if ( (*begin)->GetType() == ')' ) {
        paren_count = 1;
        ( *begin )->SetType( TOKEN::JS_PARAM_END );
        while ( paren_count > 0 && begin != end ) {
          TokenInfo *info = ( *begin );
          int type = info->GetType();
          switch ( type ) {
            case ')' :
              paren_count++;
              break;
            case '(' :
              paren_count--;
              if ( paren_count == 0 ) {
                info->SetType( TOKEN::JS_PARAM_BEGIN );
              }
              return;
          }
          ++begin;
        }
      }
    }
  }
  
  
  inline void CaseRegExpLiteral_ () {            
    bool isescaped = false;
    bool ischar_class = false;
    char next;
    
    while ( ( next = GetChar_ () ) ) {
      if ( !isescaped &&
           next == '\\' ) {
        isescaped = true;
        token_str_ += next;
      } else if ( !isescaped &&
                  next == '[' ) {
        ischar_class = true;
        isescaped = false;
        token_str_ += next;
                
      } else if ( !isescaped &&
                  ischar_class &&
                  next == ']' ) {
                
        ischar_class = false;
        token_str_ += next;
                
      } else if ( !isescaped &&
                  !ischar_class &&
                  next == '/' ) {           
        CaseRegExpFlag_ ( next );
        break;
      } else {  
        isescaped = false;
        token_str_ += next;
      }
    }
  }

  
  inline void CaseRegExpFlag_ ( char ch ) {
    token_str_ += ch;
    char next = GetChar_ ();
    if ( next == 'i' ||
         next == 'g' ||
         next == 'm' ) {
      token_str_ += next;
    
      while ( ( next = GetChar_ () ) ) {
        if ( next == 'i' ||
             next == 'g' ||
             next == 'm' ) {
          token_str_ += next;
        } else {
          BackChar_ ();
          break;
        }
      }
    } else {
      BackChar_ ();
    }
    PushBack_( token_str_.c_str() , TOKEN::JS_REGEXP_LITERAL );
  }

 
  inline void CaseUnary_ () {
    char next = GetChar_ ();
    if ( next == '=' ) {
      token_str_ += next;
    }
    BackChar_ ();
    PushBack_( token_str_.c_str() ,  JsToken::getType ( token_str_.c_str () , true ) );
  }


  inline void CaseLogical_ ( char ch ) {
    char next = GetChar_ ();
  
    if ( next == ch ) {
      token_str_ += next;
    } else if ( ( ch == '|' ||
                  ch == '^' ||
                  ch == '<' ) &&
                next == '=' ) {
      token_str_ += next;
    } else {
      BackChar_ ();
    }
    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str() , true ) );
  }


  inline void CaseShiftRight_ () {
    char next = GetChar_ ();
    if ( next == '=' ) {
      token_str_ += next;
    } else if ( next == '>' ) {
      token_str_ += next;
      next = GetChar_ ();
      if ( next == '>' ) {
        token_str_ += next;
        BackChar_ ();
      } else {
        BackChar_ ();
      }
    } else {
      BackChar_ ();
    }
    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str() , true ) );
  }


  inline void SetNumericAfter_ () {
    int type = ( token_queue_.size() > 0 )? token_queue_.back()->GetType() : 0;
    if ( type == TOKEN::JS_EQ ||
         type == TOKEN::JS_EQUAL ||
         type == TOKEN::JS_LOGICAL_OR ||
         type == TOKEN::JS_OR_LET ||
         type == TOKEN::JS_NOT_LET ||
         type == TOKEN::JS_GRATER_EQUAL ||
         type == TOKEN::JS_EQUAL ||
         type == TOKEN::JS_LESS_EQUAL ||
         type == TOKEN::JS_AND_LET ||
         type == TOKEN::JS_LOGICAL_AND ||
         type == TOKEN::JS_NOT_EQUAL ||
         type == TOKEN::JS_RETURN ||
         type == TOKEN::JS_INCREMENT ||
         type == TOKEN::JS_DECREMENT ||
         type == TOKEN::JS_MUL_LET ||
         type == TOKEN::JS_DIV_LET ||
         type == TOKEN::JS_MOD_LET ||
         type == TOKEN::JS_ADD_LET ||
         type == TOKEN::JS_SUB_LET ||
         type == TOKEN::JS_SHIFT_LEFT ||
         type == TOKEN::JS_SHIFT_LEFT_LET ||
         type == TOKEN::JS_SHIFT_RIGHT ||
         type == TOKEN::JS_SHIFT_RIGHT_LET ||
         type == TOKEN::JS_U_SHIFT_RIGHT ||
         type == TOKEN::JS_U_SHIFT_RIGHT_LET ||
         type == '{' ||
         type == '(' ||
         type == '*' ||
         type == '/' ||
         type == '+' ||
         type == '-' ||
         type == '=' ||
         type == '^' ||
         type == '&' ||
         type == '|' ) {
      is_numeric_after_ = true;
    } else {
      is_numeric_after_ = false;
    }
  }


  inline void SetRegExpAfter_ () {
    int type = ( token_queue_.size() > 0 )? token_queue_.back()->GetType() : 0;
    if ( type == TOKEN::JS_EQ ||
         type == TOKEN::JS_EQUAL ||
         type == TOKEN::JS_LOGICAL_OR ||
         type == TOKEN::JS_OR_LET ||
         type == TOKEN::JS_NOT_LET ||
         type == TOKEN::JS_GRATER_EQUAL ||
         type == TOKEN::JS_EQUAL ||
         type == TOKEN::JS_LESS_EQUAL ||
         type == TOKEN::JS_AND_LET ||
         type == TOKEN::JS_LOGICAL_AND ||
         type == TOKEN::JS_NOT_EQUAL ||
         type == TOKEN::JS_RETURN ||
         type == '}' ||
         type == '|' ||
         type == '{' ||
         type == '^' ||
         type == '[' ||
         type == '?' ||
         type == '=' ||
         type == ';' ||
         type == ':' ||
         type == ',' ||
         type == '(' ||
         type == '&' ||
         type == '!' ) {
      is_regexp_after_ = true;
    } else {
      is_regexp_after_ = false;
    }
  }
  
  
  /**
   * @private
   * @param {const char*}
   * Get type of token and call DoPushBack_.
   */
  inline void PushBack_( const char* ctoken , int opt_type = 0 ) {
    int type = ( opt_type == 0 )? JsToken::getType( ctoken ) : opt_type;
    DoPushBack_( ctoken , type );
  }

  /**
   * @private
   * @param {char}
   * Call DoPushBack_ with set type to arguments.
   */
  inline void PushBack_( int ch ) {
    DoPushBack_( "" , ch );
  }

  /**
   * @private
   * @param {const char*}
   * @param {int}
   * Push back poninter of TokenInfo to token_queue_.
   */
  inline void DoPushBack_( const char* ctoken , int type ) {
    TokenInfo* info = ManagedHandle::Retain( new TokenInfo( ctoken , type , line_ ) );
    token_queue_.push_back( info );
  }

  uint64_t index_;
  uint64_t max_;
  int32_t bracket_count_;
  int64_t line_;
  bool is_line_break_;
  bool is_rest_;
  bool is_numeric_after_;
  bool is_regexp_after_;
  TokenQueue token_queue_;
  const std::string& source_;
  std::string token_str_;
};


class QueueScanner::TokenGetter {
 public :

  TokenGetter( QueueScanner::Scanner::TokenQueue& queue , ParserTracer *tracer ) :
      last_type_(0) , is_incrementable_( true ), has_line_break_( false ),
      queue_( queue ) , tracer_( tracer ) {
    it_ = queue_.begin();
  }
  TokenInfo* GetToken( int yystate ) {
    if ( last_type_ == -100 ) {
      return ManagedHandle::Retain( new TokenInfo( "" , 0 , 0 ) );
    }
    printf( "state %d  " , last_type_ );
    has_line_break_ = false;
    is_incrementable_ = true;
    TokenInfo* info = SwitchState_();
    int type = info->GetType();
    //TokenInfo* info =(*it_);
    if ( is_incrementable_ ) {
      ++it_;
    }

    if ( type > 200 && type != TOKEN::JS_PARAM_BEGIN && type != TOKEN::JS_PARAM_END ) {
      printf( "%s %d\n" , info->GetToken() , info->GetType() );
    } else {
      if ( type != TOKEN::JS_PARAM_BEGIN && type != TOKEN::JS_PARAM_END )
      printf( "%c %d\n" , info->GetType() , info->GetType() );
      else if ( type == TOKEN::JS_PARAM_BEGIN )
        printf( "(\n" );
      else if ( type == TOKEN::JS_PARAM_END )
        printf( ")\n" );
    }

    if ( type == 0 && last_type_ != ';' ) {
      last_type_ = -100;
      return ManagedHandle::Retain( new TokenInfo( "" , ';' , 0 ) );
    }
    
    return info;
  }
  
 private :
  enum {
    kLiteral = 22
  };

  bool IsLiteral_( int type ) {
    switch ( type ) {
      case TOKEN::JS_IDENTIFIER :
      case TOKEN::JS_STRING_LITERAL :
      case TOKEN::JS_NUMERIC_LITERAL :
      case TOKEN::JS_REGEXP_LITERAL :
      case TOKEN::JS_THIS :
      case TOKEN::JS_K_NULL :
      case TOKEN::JS_TRUE :
      case TOKEN::JS_FALSE :
        return true;
    }
    return false;
  }
  
  TokenInfo* SwitchState_() {
    if ( last_type_ == 0 ) {
      return NormalState_();
    } else if ( last_type_ == '}' ) {
      return AfterCloseBrace_();
    }
    return MaybeSemicolon_();
  }

  TokenInfo* NormalState_() {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    last_type_ = info->GetType();
    return info;
  }

  TokenInfo* AfterCloseBrace_() {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    int type = info->GetType();
    printf( "type is %c\n" , type );
    if ( type != ')' && type != ',' && type != '=' && type != '.' && type != ':' &&
         type != TOKEN::JS_ELSE && type != TOKEN::JS_CATCH && type != TOKEN::JS_FINALLY &&
         type != TOKEN::JS_WHILE ) {
      return SemicolonInsertion_();
    } else {
      last_type_ = type;
      return info;
    }
  }
  
  TokenInfo* MaybeSemicolon_() {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    int type = info->GetType();
    bool is_literal = IsLiteral_( type );
    bool is_last_literal = IsLiteral_( last_type_ );
    if ( last_type_ == ';' || last_type_ == '{' || last_type_ == '(' ) {
      last_type_ = type;
      return info;
    } else if ( type == TOKEN::JS_INCREMENT || type == TOKEN::JS_DECREMENT ) {
      if ( has_line_break_ ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( last_type_ == TOKEN::JS_INCREMENT || last_type_ == TOKEN::JS_DECREMENT ) {
      if ( has_line_break_ ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( ( is_last_literal && is_literal ) ||
                ( is_last_literal && ( type == '[' || type == '{' || type == '(' ) ) ||
                ( ( last_type_ == ']' || last_type_ == '}' || last_type_ == ')' ) && is_literal )) {
      printf( "is line break %d\n" , has_line_break_ );
      if ( has_line_break_ ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( type == '}' && last_type_ != '{' ) {
      if ( last_type_ != ';' ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( type == TOKEN::JS_IF || type == TOKEN::JS_WHILE ||
                type == TOKEN::JS_WITH || type == TOKEN::JS_FOR ||
                type == TOKEN::JS_MODULE || type == TOKEN::JS_EXPORT ||
                type == TOKEN::JS_LET || type == TOKEN::JS_CONST ||
                type == TOKEN::JS_VAR || type == TOKEN::JS_CONTINUE ||
                type == TOKEN::JS_RETURN || type == TOKEN::JS_BREAK ||
                type == TOKEN::JS_SWITCH || type == TOKEN::JS_THROW ||
                type == TOKEN::JS_TRY ) {
      return SemicolonInsertion_();
    } else if ( last_type_ == ')' && is_literal ) {
      return SemicolonInsertion_(); 
    }
    last_type_ = type;
    return info;
  }

  TokenInfo* SemicolonInsertion_() {
    is_incrementable_ = false;
    last_type_ = ';';
    return ManagedHandle::Retain( new TokenInfo( "" , ';' , (*it_)->GetLineNumber() ) );
  }

  void SkipLineBreak_() {
    TokenInfo* info = (*it_);
    while ( info->GetType() == TOKEN::JS_LINE_BREAK ) {
      has_line_break_ = true;
      ++it_;
      info = (*it_);
    }
  }

  int last_type_;
  bool is_incrementable_;
  bool has_line_break_;
  ParserTracer *tracer_;
  QueueScanner::Scanner::TokenQueue& queue_;
  QueueScanner::Scanner::TokenQueue::iterator it_;
};


QueueScanner::QueueScanner( const std::string& source , ParserTracer *tracer ) :
    scanner_( new Scanner( source ) ) , tracer_( tracer ) {}
QueueScanner::~QueueScanner(){}

void QueueScanner::CollectToken() {
  scanner_->CollectToken();
  token_getter_( new TokenGetter( scanner_->GetQueue() , tracer_ ) );
}

TokenInfo* QueueScanner::GetToken( int yystate ) {
  TokenInfo* info =  token_getter_->GetToken( yystate );
  return info;
}

}
