#include <utils/int_types.h>
#include <string.h>
#include <deque>
#include <string>
#include <compiler/scanner/queue_scanner.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/binding/parser_tracer.h>
#include <utils/smart_pointer/scope/scoped_list.h>
#include <utils/pool/managed_handle.h>
#include <grammar/grammar.tab.hh>

#define TOKEN yy::ParserImplementation::token
#define ITERATOR(name) begin=name.begin(),end=name.end()
#define RITERATOR(name) begin=name.rbegin(),end=name.rend()

namespace mocha {

class QueueScanner::Scanner {
 public :
  typedef std::deque<TokenInfo*> TokenQueue;
  Scanner( const std::string& source ) :
      index_( 0 ), line_(0) , is_line_break_( false ), is_rest_( false ) , is_numeric_after_( false ),
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
    int index = 0;
  
    while ( ( next = GetChar_ () ) ) {
      if ( isdigit ( next ) ) {
        token_str_ += next;
        last = next;
      } else if ( next == '.' && index == 0 ) {
        if ( GetChar_() == '.' ) {
          token_str_ += "..";
          PushBack_( token_str_.c_str() , TOKEN::JS_PARAMETER_REST );
          return;
        } else {
          BackChar_( 1 );
        }
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
      index++;
    }
    PushBack_( token_str_.c_str() , TOKEN::JS_NUMERIC_LITERAL );
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
      RewriteDst_();
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

  inline void RewriteDst_() {
    if ( token_queue_.size() > 0 ) {
      TokenQueue::reverse_iterator RITERATOR(token_queue_);
      int begin_type = 0;
      int begin_count = 1;
      while ( ( *begin )->GetType() == TOKEN::JS_LINE_BREAK || (*begin)->GetType() == '=' ||
              (*begin)->GetType() == TOKEN::JS_FROM ) {
        ++begin;
      }
      begin_type = (*begin)->GetType();
      if ( begin_type != ']' && begin_type != '}' && begin_type != ')' ) {
        return;
      } else if ( begin_type == ')' ) {
        ++begin;
        while ( ( *begin )->GetType() == TOKEN::JS_LINE_BREAK || ( *begin )->GetType() == ')' ) {
          ++begin;
        }
        if ( (*begin)->GetType() == ']' || (*begin)->GetType() == '}' ) {
          begin_type = (*begin)->GetType();
        } else {
          return;
        }
      }
      ++begin;
      if ( begin_type != 0 ) {
        bool no_dst = false;
        while ( begin_count > 0 && begin != end ) {
          TokenInfo *info = ( *begin );
          int type = info->GetType();
          if ( type != TOKEN::JS_IDENTIFIER && type != TOKEN::JS_STRING_LITERAL && type != TOKEN::JS_NUMERIC_LITERAL &&
               type != TOKEN::JS_PARAMETER_REST &&
               type != ':' && type != ')' && type != '(' && type != '}' && type != '{' && type != ']' &&
               type != '[' && type != ',' ) {
            return;
          }
          switch ( type ) {
            case ']' :
              if ( begin_type == ']' ) {
                begin_count++;
              }
              break;
            case '[' :
              if ( begin_type == ']' ) {
                begin_count--;
              }
              break;
            case '}' :
              if ( begin_type == '}' ) {
                begin_count++;
              }
              break;
            case '{' :
              if ( begin_type == '}' ) {
                begin_count--;
              }
          }
          if ( begin_count == 0 ) {
            break;
          }
          ++begin;
        }
        
        if ( !no_dst ) {
          if ( begin != end ) {
            while ( ( *begin )->GetType() == TOKEN::JS_LINE_BREAK || ( *begin )->GetType() == '(' ) {
              ++begin;
            }
            ++begin;
            if ( begin != end ) {
              int last = ( *begin )->GetType();
              if ( last == '}' || last == ']' || last == ')' || last == TOKEN::JS_IDENTIFIER || last == TOKEN::JS_STRING_LITERAL ||
                   last == TOKEN::JS_REGEXP_LITERAL || last == TOKEN::JS_THIS || last == TOKEN::JS_K_NULL ||
                   last == TOKEN::JS_TRUE || last == TOKEN::JS_FALSE || last == TOKEN::JS_NUMERIC_LITERAL ) {
                return;
              }
            }
          }
          {
            TokenQueue::reverse_iterator RITERATOR(token_queue_);
            while ( ( *begin )->GetType() == TOKEN::JS_LINE_BREAK || (*begin)->GetType() == '=' ||
                    (*begin)->GetType() == TOKEN::JS_FROM || (*begin)->GetType() == ')' ) {
              ++begin;
            }
            int begin_type = (*begin)->GetType();
            int begin_count = 0;
            while ( begin != end ) {
              TokenInfo *info = ( *begin );
              int type = info->GetType();
              switch ( type ) {
                case ']' :
                  info->SetToken( "" );
                  info->SetType( TOKEN::JS_DSTA_END );
                  if ( begin_type == ']' ) {
                    begin_count++;
                  }
                  break;
                case '[' :
                  info->SetType( TOKEN::JS_DSTA_BEGIN );
                  info->SetToken( "" );
                  if ( begin_type == ']' ) {
                    begin_count--;
                  }
                  break;
                case '}' :
                  info->SetToken( "" );
                  info->SetType( TOKEN::JS_DSTO_END );
                  if ( begin_type == '}' ) {
                    begin_count++;
                  }
                  break;
                case '{' :
                  info->SetToken( "" );
                  info->SetType( TOKEN::JS_DSTO_BEGIN );
                  if ( begin_type == '}' ) {
                    begin_count--;
                  }
              }
              if ( begin_count == 0 )break;
              ++begin;
            }
          }
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
    } else {
      BackChar_ ();
    }
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
         type == TOKEN::JS_ADD_LET ||
         type == TOKEN::JS_SUB_LET ||
         type == TOKEN::JS_DIV_LET ||
         type == TOKEN::JS_MUL_LET ||
         type == TOKEN::JS_MOD_LET ||
         type == TOKEN::JS_SHIFT_LEFT ||
         type == TOKEN::JS_SHIFT_RIGHT ||
         type == TOKEN::JS_U_SHIFT_LEFT ||
         type == TOKEN::JS_U_SHIFT_RIGHT ||
         type == TOKEN::JS_SHIFT_LEFT_LET ||
         type == TOKEN::JS_U_SHIFT_RIGHT_LET ||
         type == TOKEN::JS_SHIFT_RIGHT_LET ||
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
         type == '!' ||
         type == '+' ||
         type == '-' ||
         type == '/' ||
         type == '%' ||
         type == '*' ||
         type == '~' ) {
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
    if ( type == TOKEN::JS_EACH ) {
      if ( token_queue_.size() > 0 && token_queue_.back()->GetType() != TOKEN::JS_FOR ) {
        type = TOKEN::JS_IDENTIFIER;
      }
    } else if ( type == TOKEN::JS_FROM ) {
      RewriteDst_();
    } else if ( type == TOKEN::JS_IN ) {
      RewriteDst_();
    }
    DoPushBack_( ctoken , type );
  }

  /**
   * @private
   * @param {char}
   * Call DoPushBack_ with set type to arguments.
   */
  inline void PushBack_( int ch ) {
    if ( ch == '(' && token_queue_.size() >= 2 ) {
      TokenQueue::reverse_iterator begin = token_queue_.rbegin();
      --begin;
      --begin;
      if ( (*begin)->GetType() == TOKEN::JS_IDENTIFIER ) {
        if ( strcmp( (*begin)->GetToken() , "get" ) == 0 ) {
          (*begin)->SetType( TOKEN::JS_GET );
        } else if ( strcmp( (*begin)->GetToken() , "set" ) == 0 ) {
          (*begin)->SetType( TOKEN::JS_SET );
        }
      }
    }
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
      last_type_(0) , opt_block_( 0 ) , opt_block_paren_count_( 0 ),
      function_paren_count_( 0 ) , class_paren_count_( 0 ) , mode_( 0 ) , is_in_class_( false ),
      import_stmt_( false ),is_incrementable_( true ), has_line_break_( false ),
      tracer_( tracer ) , queue_( queue ) {
    it_ = queue_.begin();
  }
  TokenInfo* GetToken( int yystate ) {
    if ( last_type_ == -100 ) {
      return ManagedHandle::Retain( new TokenInfo( "" , 0 , 0 ) );
    }
    has_line_break_ = false;
    is_incrementable_ = true;
    TokenInfo* info = SwitchState_();
    int type = info->GetType();
    //TokenInfo* info =(*it_);
    if ( is_incrementable_ ) {
      ++it_;
    }

    if ( type == '}' ) {
      if ( is_in_class_ ) {
        class_paren_count_--;
        if ( class_paren_count_ == 0 ) {
          is_in_class_ = false;
        }
      }
    }
    
    printf( "is in class%d brace %d\n" , is_in_class_ , class_paren_count_ );
    if ( is_in_class_ &&
         class_paren_count_ == 1 &&
         type == TOKEN::JS_IDENTIFIER &&
         strcmp( info->GetToken() , "constructor" ) == 0 ) {
      
      info->SetType( TOKEN::JS_CONSTRUCTOR );

    } else if ( is_in_class_ &&
                class_paren_count_ == 1 &&
                type == TOKEN::JS_IDENTIFIER &&
                strcmp( info->GetToken() , "prototype" ) == 0 &&
                ( last_type_ == TOKEN::JS_IDENTIFIER || last_type_ == TOKEN::JS_CLASS ) ) {
      info->SetType( TOKEN::JS_PROTOTYPE );
    }
      
    if ( type == TOKEN::JS_FROM ) {
      if (  import_stmt_ ) {
        last_type_ = type;
        import_stmt_ = false;
      } else {
        last_type_ = TOKEN::JS_IDENTIFIER;
        info->SetType( TOKEN::JS_IDENTIFIER );
      }
    } else if ( type == TOKEN::JS_FUNCTION || type == TOKEN::JS_PARAM_BEGIN ) {
      mode_ = kFunction;
    } else if ( mode_ == kFunction ) {
      if ( type == '(' ) {
        function_paren_count_++;
      } else if ( type == ')' ) {
        function_paren_count_--;
        if ( function_paren_count_ == 0 ) {
          mode_ = 0;
        }
      } else if ( type == TOKEN::JS_PARAM_END ) {
        mode_ = 0;
      } else {
        switch ( type ) {
          case '{' :
            info->SetType( TOKEN::JS_DSTO_BEGIN );
            break;
          case '}' :
            info->SetType( TOKEN::JS_DSTO_END );
            break;
          case '[' :
            info->SetType( TOKEN::JS_DSTA_BEGIN );
            break;
          case ']' :
            info->SetType( TOKEN::JS_DSTA_END );
            break;
        }
      }
      last_type_ = info->GetType();
    }
    
    if ( type == TOKEN::JS_FOR || type == TOKEN::JS_EACH || type == TOKEN::JS_WHILE || type == TOKEN::JS_IF ) {
      opt_block_ = 1;
    }

    if ( opt_block_ == -1 ) {
      opt_block_ = 0;
    }

    if ( type == TOKEN::JS_ELSE ) {
      opt_block_ = -1;
    }

    if ( type == TOKEN::JS_IMPORT ) {
      import_stmt_ = true;
    }
    
    if ( opt_block_ == 1 ) {
      if ( type == '(' ) {
        opt_block_paren_count_++;
      } else if ( type == ')' ) {
        opt_block_paren_count_--;
        if ( opt_block_paren_count_ == 0 ) {
          opt_block_ = -1;
        }
      }
    }

    if ( type == 0 && last_type_ != ';' ) {
      last_type_ = -100;
      return ManagedHandle::Retain( new TokenInfo( "" , ';' , 0 ) );
    }
    
    return info;
  }
  
 private :
  enum {
    kLiteral = 1,
    kFunction = 2
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
    } else if ( last_type_ == TOKEN::JS_FUNCTION_GLYPH || last_type_ == TOKEN::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      SkipLineBreak_();
      TokenInfo* info = (*it_);
      int type = info->GetType();
      if ( type != '{' ) {
        info = ManagedHandle::Retain( new TokenInfo( "{" , TOKEN::JS_EXP_CLOSURE_BEGIN , info->GetLineNumber() ) );
        //mode_ = TOKEN::JS_EXP_CLOSURE_BEGIN;
        is_incrementable_ = false;
      }
      last_type_ = '{';
      return info;
    } else if ( last_type_ == '}' ) {
      return AfterCloseBrace_();
    }
    return MaybeSemicolon_();
  }

  TokenInfo* NormalState_() {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    last_type_ = info->GetType();
    if ( info->GetType() == TOKEN::JS_CLASS ) {
      return MaybeSemicolon_();
    }
    return info;
  }

  TokenInfo* AfterCloseBrace_() {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    int type = info->GetType();
    if ( type != '(' && type != ')' && type != ',' && type != '=' && type != '.' && type != ':' &&
         type != ']' && !import_stmt_ &&
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
    
    if ( type == TOKEN::JS_CLASS ) {
      if ( ( last_type_ == ']' || last_type_ == '}' || last_type_ == ')' || is_last_literal ) ) {
        return SemicolonInsertion_();
      }
      is_in_class_ = true;
      last_type_ = type;
      return info;
    } else if ( type == TOKEN::JS_CONST && ( last_type_ == TOKEN::JS_PRIVATE || last_type_ == TOKEN::JS_PUBLIC ||
                                             last_type_ == TOKEN::JS_EXPORT || last_type_ == TOKEN::JS_STATIC ) ) {
      return NormalState_();
    } else if ( type == '{' && is_in_class_ ) {
      if ( type == '{' ) {
        class_paren_count_++;
      }
      is_in_class_ = true;
      last_type_ = type;
      return info;
    } else if ( type == TOKEN::JS_DSTO_END || type == TOKEN::JS_DSTA_END ) {
      last_type_ = type;
      return info;
    } else if ( last_type_ == ';' || last_type_ == '{' || last_type_ == '(' ||
                type == TOKEN::JS_DSTO_END || type == TOKEN::JS_DSTA_END ) {
      last_type_ = type;
      return info;
    } else if ( type == TOKEN::JS_INCREMENT || type == TOKEN::JS_DECREMENT ) {
      if ( has_line_break_ ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( last_type_ == TOKEN::JS_INCREMENT || last_type_ == TOKEN::JS_DECREMENT ) {
      if ( has_line_break_ || type == '}' ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( ( is_last_literal && is_literal ) ||
                ( is_last_literal && ( type == '[' || type == '{' || type == '(' ) ) ||
                ( ( last_type_ == ']' || last_type_ == '}' || last_type_ == ')' ) && is_literal )) {
      if ( has_line_break_ ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( type == '}' && last_type_ != '{' && mode_ != kFunction ) {
      if ( last_type_ != ';' ) {
        return SemicolonInsertion_();
      }
      
      last_type_ = type;
      return info;
    } else if ( opt_block_ != -1 &&
                ( type == TOKEN::JS_IF || type == TOKEN::JS_WHILE ||
                  type == TOKEN::JS_WITH || type == TOKEN::JS_FOR ||
                  type == TOKEN::JS_MODULE || type == TOKEN::JS_EXPORT ||
                  type == TOKEN::JS_LET || type == TOKEN::JS_CONST ||
                  type == TOKEN::JS_VAR || type == TOKEN::JS_CONTINUE ||
                  type == TOKEN::JS_RETURN || type == TOKEN::JS_BREAK ||
                  type == TOKEN::JS_SWITCH || type == TOKEN::JS_THROW ||
                  type == TOKEN::JS_TRY ) ) {
      return SemicolonInsertion_();
    } else if ( last_type_ == ')' && is_literal ) {
      return SemicolonInsertion_(); 
    }
    tracer_->EndState( ParserTracer::kNoSemicolon );
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
  int opt_block_;
  int opt_block_paren_count_;
  int function_paren_count_;
  int class_paren_count_;
  int mode_;
  bool is_in_class_;
  bool import_stmt_;
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
  if ( info->GetType() > 200 ) {
  printf( "%s\n" , info->GetToken() );
  } else {
    printf( "%c\n" , info->GetType() );
  }
  return info;
}

}
