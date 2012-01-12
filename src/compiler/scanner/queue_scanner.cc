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
#include <utils/bits.h>
#include <grammar/grammar.tab.hh>

#define ITERATOR(name) begin=name.begin(),end=name.end()
#define RITERATOR(name) begin=name.rbegin(),end=name.rend()

namespace mocha {

#define FLAG_LB 0
#define FLAG_REST 1
#define FLAG_NUMERIC 2
#define FLAG_REGEXP 3

class QueueScanner::Scanner {
 public :
  typedef std::deque<TokenInfo*> TokenQueue;
  Scanner( const std::string& source ) :
      index_( 0 ), line_(0) , source_( source ) {
    max_ = source_.size();
  }

  /**
   * @public
   * Collect token and push into the token queue.
   */
  inline void CollectToken() {
    while ( !IsEof_() ) {
      Skip_();
      if ( flags_.At( FLAG_LB ) ) {
        PushBack_( Token::JS_LINE_BREAK );
        flags_.UnSet( FLAG_LB );
      }
      char ch = GetChar_();
      if ( IsIdentStart_( ch ) ) {
        //identifier
        CaseIdent_( ch );
      } else if ( isdigit( ch ) ) {
        //numeric begin with 0...9
        CaseDigit_( ch );
      } else if ( flags_.At( FLAG_NUMERIC ) && ch == '.' ) {
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
        flags_.Set( FLAG_LB );
        line_++;
      }
      isbreak = false;
      
      //Loop while whitespace or linebreak is continue.
      while ( IsWhiteSpace_ ( next ) ||
              ( isbreak = IsBreak_ ( next ) ) ) {
        if ( isbreak ) {
          line_++;
          flags_.Set( FLAG_LB );
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
          flags_.Set( FLAG_LB );
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
        flags_.Set( FLAG_LB );
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
    PushBack_( token_str_.c_str() , Token::JS_NUMERIC_LITERAL );
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
          PushBack_( token_str_.c_str() , Token::JS_PARAMETER_REST );
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
    PushBack_( token_str_.c_str() , Token::JS_NUMERIC_LITERAL );
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
        flags_.Set( FLAG_REST );
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
           ch < 127 || flags_.At( FLAG_REST ) ) &&
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
          PushBack_( token_str_.c_str() , Token::JS_PARAMETER_REST );
          flags_.UnSet( FLAG_REST );
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
               flags_.At( FLAG_REGEXP ) ) {
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
    PushBack_( token_str_.c_str() , Token::JS_STRING_LITERAL );
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
      while ( ( *begin )->GetType() == Token::JS_LINE_BREAK ) {
        ++begin;
      }
      if ( (*begin)->GetType() == ')' ) {
        paren_count = 1;
        ( *begin )->SetType( Token::JS_PARAM_END );
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
                info->SetType( Token::JS_PARAM_BEGIN );
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
      while ( ( *begin )->GetType() == Token::JS_LINE_BREAK || (*begin)->GetType() == '=' ||
              (*begin)->GetType() == Token::JS_FROM ) {
        ++begin;
      }
      begin_type = (*begin)->GetType();
      if ( begin_type != ']' && begin_type != '}' && begin_type != ')' ) {
        return;
      } else if ( begin_type == ')' ) {
        ++begin;
        while ( ( *begin )->GetType() == Token::JS_LINE_BREAK || ( *begin )->GetType() == ')' ) {
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
          if ( type != Token::JS_IDENTIFIER && type != Token::JS_STRING_LITERAL && type != Token::JS_NUMERIC_LITERAL &&
               type != Token::JS_PARAMETER_REST &&
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
            while ( ( *begin )->GetType() == Token::JS_LINE_BREAK || ( *begin )->GetType() == '(' ) {
              ++begin;
            }
            ++begin;
            if ( begin != end ) {
              int last = ( *begin )->GetType();
              if ( last == '}' || last == ']' || last == ')' || last == Token::JS_IDENTIFIER || last == Token::JS_STRING_LITERAL ||
                   last == Token::JS_REGEXP_LITERAL || last == Token::JS_THIS || last == Token::JS_K_NULL ||
                   last == Token::JS_TRUE || last == Token::JS_FALSE || last == Token::JS_NUMERIC_LITERAL ||
                   last == '=' ) {
                return;
              }
            }
          }
          {
            TokenQueue::reverse_iterator RITERATOR(token_queue_);
            while ( ( *begin )->GetType() == Token::JS_LINE_BREAK || (*begin)->GetType() == '=' ||
                    (*begin)->GetType() == Token::JS_FROM || (*begin)->GetType() == ')' ) {
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
                  info->SetType( Token::JS_DSTA_END );
                  if ( begin_type == ']' ) {
                    begin_count++;
                  }
                  break;
                case '[' :
                  info->SetType( Token::JS_DSTA_BEGIN );
                  info->SetToken( "" );
                  if ( begin_type == ']' ) {
                    begin_count--;
                  }
                  break;
                case '}' :
                  info->SetToken( "" );
                  info->SetType( Token::JS_DSTO_END );
                  if ( begin_type == '}' ) {
                    begin_count++;
                  }
                  break;
                case '{' :
                  info->SetToken( "" );
                  info->SetType( Token::JS_DSTO_BEGIN );
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
    PushBack_( token_str_.c_str() , Token::JS_REGEXP_LITERAL );
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
    if ( JsToken::IsBinaryOperatorNoIn( type ) ||
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
      flags_.Set( FLAG_NUMERIC );
    } else {
      flags_.UnSet( FLAG_NUMERIC );
    }
  }


  inline void SetRegExpAfter_ () {
    int type = ( token_queue_.size() > 0 )? token_queue_.back()->GetType() : 0;
    if ( JsToken::IsBinaryOperator( type ) ||
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
      flags_.Set( FLAG_REGEXP );
    } else {
      flags_.UnSet( FLAG_REGEXP );
    }
  }
  
  
  /**
   * @private
   * @param {const char*}
   * Get type of token and call DoPushBack_.
   */
  inline void PushBack_( const char* ctoken , int opt_type = 0 ) {
    int type = ( opt_type == 0 )? JsToken::getType( ctoken ) : opt_type;
    if ( type == Token::JS_EACH ) {
      if ( token_queue_.size() > 0 && token_queue_.back()->GetType() != Token::JS_FOR ) {
        type = Token::JS_IDENTIFIER;
      }
    } else if ( type == Token::JS_FROM ) {
      RewriteDst_();
    } else if ( type == Token::JS_IN ) {
      RewriteDst_();
    } else if ( type == Token::JS_IDENTIFIER && strcmp( ctoken , "of" ) == 0 ) {
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
      if ( (*begin)->GetType() == Token::JS_IDENTIFIER ) {
        if ( strcmp( (*begin)->GetToken() , "get" ) == 0 ) {
          (*begin)->SetType( Token::JS_GET );
        } else if ( strcmp( (*begin)->GetToken() , "set" ) == 0 ) {
          (*begin)->SetType( Token::JS_SET );
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
  BitVector8 flags_;
  TokenQueue token_queue_;
  const std::string& source_;
  std::string token_str_;
};


class QueueScanner::TokenGetter {
 public :

  TokenGetter( QueueScanner::Scanner::TokenQueue& queue , ParserTracer *tracer ) :
      last_type_(0) , opt_block_( 0 ) , opt_block_paren_count_( 0 ),
      function_paren_count_( 0 ) , default_paren_type_( 0 ) ,
      default_paren_count_( 0 ) , class_paren_count_( 0 ),
      mode_( 0 ) , is_in_class_( false ), is_default_parameter_( false ),is_object_mark_expect_( false ),
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
    int cache = last_type_;
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

    if ( is_in_class_ &&
         class_paren_count_ == 1 &&
         type == Token::JS_IDENTIFIER &&
         strcmp( info->GetToken() , "constructor" ) == 0 ) {
      
      info->SetType( Token::JS_CONSTRUCTOR );

    } else if ( is_in_class_ &&
                class_paren_count_ == 1 &&
                type == Token::JS_IDENTIFIER &&
                strcmp( info->GetToken() , "prototype" ) == 0 &&
                ( last_type_ == Token::JS_IDENTIFIER || last_type_ == Token::JS_CLASS ) ) {
      info->SetType( Token::JS_PROTOTYPE );
    }
      
    if ( type == Token::JS_FROM ) {
      if (  import_stmt_ ) {
        last_type_ = type;
        import_stmt_ = false;
      } else {
        last_type_ = Token::JS_IDENTIFIER;
        info->SetType( Token::JS_IDENTIFIER );
      }
    } else if ( type == Token::JS_FUNCTION || type == Token::JS_PARAM_BEGIN ) {
      mode_ = kFunction;
    } else if ( mode_ == kFunction ) {
      if ( type == '(' ) {
        function_paren_count_++;
      } else if ( type == ')' ) {
        function_paren_count_--;
        if ( function_paren_count_ == 0 ) {
          mode_ = 0;
        }
      } else if ( type == Token::JS_PARAM_END ) {
        mode_ = 0;
      } else {
        if ( type == '=' ) {
          is_default_parameter_ = true;
        } else if ( is_default_parameter_ && default_paren_type_ == 0 ) {
          if ( type == '{' || type == '[' ) {
            default_paren_type_ = type;
            default_paren_count_++;
          } else {
            is_default_parameter_ = false;
          }
        }
        switch ( type ) {
          case '{' :
            if ( is_default_parameter_ ) {
              if ( default_paren_type_ == '{' ) {
                default_paren_count_++;
              }
            } else {
              info->SetType( Token::JS_DSTO_BEGIN );
            }
            break;
          case '}' :
            if ( is_default_parameter_ ) {
              if ( default_paren_type_ == '}' ) {
                default_paren_count_--;
                if ( default_paren_count_ == 0 ) {
                  is_default_parameter_ = false;
                  default_paren_type_ = 0;
                }
              }
            } else {
              info->SetType( Token::JS_DSTO_END );
            }
            break;
          case '[' :
            if ( is_default_parameter_ ) {
              if ( default_paren_type_ == '[' ) {
                default_paren_count_++;
              }
            } else {
              info->SetType( Token::JS_DSTA_BEGIN );
            }
            break;
          case ']' :
            if ( is_default_parameter_ ) {
              if ( default_paren_type_ == ']' ) {
                default_paren_count_--;
                if ( default_paren_count_ == 0 ) {
                  is_default_parameter_ = false;
                  default_paren_type_ = 0;
                }
              }
            } else {
              info->SetType( Token::JS_DSTA_END );
            }
            break;
        }
      }
      last_type_ = info->GetType();
    }
    
    if ( last_type_ != Token::JS_DSTO_BEGIN &&
         ( JsToken::IsBinaryOperator( cache ) ||
           IsBinaryChar_( cache ) ||
           cache == '!' ||
           tracer_->IsAllowExpression() ||
           ( cache == ':' || cache == '(' || cache == ',' || cache == '[' ||
             cache == Token::JS_RETURN || cache == Token::JS_THROW ||
             cache == Token::JS_EXTENDS || cache == Token::JS_PROTOTYPE ||
             cache == Token::JS_CASE || cache == '?' || cache == '.' ) ) &&
         type == '{' ) {
      is_object_mark_expect_ = true;
    }
    
    if ( type == Token::JS_FOR || type == Token::JS_EACH || type == Token::JS_WHILE || type == Token::JS_IF ) {
      opt_block_ = 1;
    }

    if ( opt_block_ == -1 ) {
      opt_block_ = 0;
    }

    if ( type == Token::JS_ELSE ) {
      opt_block_ = -1;
    }

    if ( type == Token::JS_IMPORT ) {
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
    kFunction = 2,
    kObjectLiteral = 3
  };

  bool IsLiteral_( int type ) {
    switch ( type ) {
      case Token::JS_IDENTIFIER :
      case Token::JS_STRING_LITERAL :
      case Token::JS_NUMERIC_LITERAL :
      case Token::JS_REGEXP_LITERAL :
      case Token::JS_THIS :
      case Token::JS_K_NULL :
      case Token::JS_TRUE :
      case Token::JS_FALSE :
        return true;
    }
    return false;
  }

  bool IsBinaryChar_( int type ) {
    switch ( type ) {
      case '+' :
      case '-' :
      case '*' :
      case '%' :
      case '^' :
      case '&' :
      case '|' :
      case '=' :
      case '>' :
      case '<' :
        return true;
    }
    return false;
  }
  
  TokenInfo* SwitchState_() {
    if ( last_type_ == 0 ) {
      return NormalState_();
    } else if ( last_type_ == Token::JS_FUNCTION_GLYPH || last_type_ == Token::JS_FUNCTION_GLYPH_WITH_CONTEXT ) {
      SkipLineBreak_();
      TokenInfo* info = (*it_);
      int type = info->GetType();
      if ( type != '{' ) {
        info = ManagedHandle::Retain( new TokenInfo( "{" , Token::JS_EXP_CLOSURE_BEGIN , info->GetLineNumber() ) );
        //mode_ = Token::JS_EXP_CLOSURE_BEGIN;
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
    if ( info->GetType() == Token::JS_CLASS ) {
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
         type != Token::JS_ELSE && type != Token::JS_CATCH && type != Token::JS_FINALLY &&
         type != Token::JS_WHILE ) {
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

    if ( is_object_mark_expect_ ) {
      is_incrementable_ = false;
      is_object_mark_expect_ = false;
      TokenInfo *mark_info = ManagedHandle::Retain( new TokenInfo( "@" , '@' , info->GetLineNumber() ) );
      return mark_info;
      last_type_ = '@';
    }
    
    if ( type == Token::JS_CLASS ) {
      if ( ( last_type_ == ']' || last_type_ == '}' || last_type_ == ')' || is_last_literal ) ) {
        return SemicolonInsertion_();
      }
      is_in_class_ = true;
      last_type_ = type;
      return info;
    } else if ( type == Token::JS_CONST && ( last_type_ == Token::JS_PRIVATE || last_type_ == Token::JS_PUBLIC ||
                                             last_type_ == Token::JS_EXPORT || last_type_ == Token::JS_STATIC ) ) {
      return NormalState_();
    } else if ( type == '{' && is_in_class_ ) {
      if ( type == '{' ) {
        class_paren_count_++;
      }
      is_in_class_ = true;
      last_type_ = type;
      return info;
    } else if ( ( has_line_break_ || type == ';' ) && ( last_type_ == Token::JS_RETURN || last_type_ == Token::JS_YIELD ) ) {
      if ( last_type_ == Token::JS_YIELD ) {
        TokenInfo* ret = ManagedHandle::Retain( new TokenInfo( "" , Token::JS_YIELD_SENTINEL , info->GetLineNumber() ) );
        last_type_ = Token::JS_YIELD_SENTINEL;
        is_incrementable_ = false;
        return ret;
      } else {
        return SemicolonInsertion_();
      }
    } else if ( type == Token::JS_DSTO_END || type == Token::JS_DSTA_END ) {
      last_type_ = type;
      return info;
    } else if ( last_type_ == ';' || last_type_ == '{' || last_type_ == '(' ||
                type == Token::JS_DSTO_END || type == Token::JS_DSTA_END ) {
      last_type_ = type;
      return info;
    } else if ( type == Token::JS_INCREMENT || type == Token::JS_DECREMENT ) {
      if ( has_line_break_ ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( last_type_ == Token::JS_INCREMENT || last_type_ == Token::JS_DECREMENT ) {
      if ( has_line_break_ || type == '}' ) {
        return SemicolonInsertion_();
      }
      last_type_ = type;
      return info;
    } else if ( opt_block_ != -1 &&
                ( ( is_last_literal && is_literal ) ||
                  ( is_last_literal && ( type == '[' || type == '{' || type == '(' ) ) ||
                  ( ( last_type_ == ']' || last_type_ == '}' || last_type_ == ')' ) && is_literal ) ) ) {
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
                ( type == Token::JS_IF || type == Token::JS_WHILE ||
                  type == Token::JS_WITH || type == Token::JS_FOR ||
                  type == Token::JS_MODULE || type == Token::JS_EXPORT ||
                  type == Token::JS_LET || type == Token::JS_CONST ||
                  type == Token::JS_VAR || type == Token::JS_CONTINUE ||
                  type == Token::JS_RETURN || type == Token::JS_BREAK ||
                  type == Token::JS_SWITCH || type == Token::JS_THROW ||
                  type == Token::JS_TRY ) ) {
      return SemicolonInsertion_();
    } else if ( opt_block_ == -1 ) {
      last_type_ = type;
      return info;
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
    while ( info->GetType() == Token::JS_LINE_BREAK ) {
      has_line_break_ = true;
      ++it_;
      info = (*it_);
    }
  }

  int last_type_;
  int opt_block_;
  int opt_block_paren_count_;
  int function_paren_count_;
  int default_paren_type_;
  int default_paren_count_;
  int class_paren_count_;
  int object_brace_count_;
  int mode_;
  bool is_in_class_;
  bool is_default_parameter_;
  bool is_object_mark_expect_;
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
  if ( info->GetType() > 127 ) {
    printf( "%s %d\n" , info->GetToken() , JsToken::ToParserToken( info->GetType() ) );
  } else {
    printf( "%c\n" , info->GetType() );
  }
  return info;
}

}
