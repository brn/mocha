#include <stdint.h>
#include <list>
#include <string>
#include "js_token.h"
#include "token_info.h"
#include "grammar.tab.hh"
#include "queue_scanner.h"
#include "scoped_list.h"
#include "managed_handle.h"

#define TOKEN yy::ParserImplementation::token
#define ITERATOR(name) begin=name.begin(),end=name.end()
#define RITERATOR(name) begin=name.rbegin(),end=name.rend()

namespace mocha {

class QueueScanner::Scanner {
 public :
  typedef std::list<TokenInfo*> TokenQueue;
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
    bool isbreak = false;

    //Check that token is whitespace or line break.
    if ( IsWhiteSpace_ ( ch ) ||
         ( isbreak = IsBreak_ ( ch ) ) ) {
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
      while ( ( *begin )->getType() == TOKEN::JS_LINE_BREAK ) {
        ++begin;
      }
      if ( (*begin)->getType() == ')' ) {
        paren_count = 1;
        ( *begin )->SetType( TOKEN::JS_PARAM_END );
        while ( paren_count > 0 && begin != end ) {
          TokenInfo *info = ( *begin );
          int type = info->getType();
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
    int type = ( token_queue_.size() > 0 )? token_queue_.back()->getType() : 0;
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
    int type = ( token_queue_.size() > 0 )? token_queue_.back()->getType() : 0;
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
  TokenGetter( QueueScanner::Scanner::TokenQueue& queue ) : last_type_(0),queue_( queue ) , state_( 0 ) {
    it_ = queue_.begin();
  }
  const TokenInfo* GetToken( int yystate ) {
    TokenInfo* info = SwitchState_( yystate );
    //TokenInfo* info =(*it_);
    ++it_;
    last_type_ = info->getType();
    return info;
  }
 private :
  enum {
    kNone = 0,

    //Search . JS_FUNCTION_IDENTIFIER from grammar.output.
    //function . Example() {...}
    kFunctionDeclIdentBeg = 23,
    kFunctionDeclIdentBeg2 = 132,

    //Search JS_CONST . , JS_VAR . and JS_LET . from grammar.output. 
    //
    //var . x = 2;
    //const . Example (){...}
    kVariableDeclBeg1 = 17,//JS_CONST
    kVariableDeclBeg2 = 130,//JS_CONST
    kVariableDeclBeg3 = 133,//JS_LET
    kVariableDeclBeg4 = 44,//JS_LET
    kVariableDeclBeg5 = 36,//JS_VAR
    kVariableDeclBeg6 = 250,//JS_VAR
    kVariableDeclBeg7 = 378,//JS_VAR
    kVariableDeclBeg8 = 245,//,variable_declaration
    kVariableDeclBeg9 = 425,//,variable_declaration_no_in
    

    /**
     *function_declaration: JS_CONST JS_FORMAL_PARAMETER_IDENT . JS_PARAM_BEGIN
     *formal_parameter_list__opt JS_PARAM_END '{' function_body '}'
     *
     *variable_declaration: JS_FORMAL_PARAMETER_IDENT . initialiser__opt
     */
    kVariableDeclEndORParamBegin = 123,

    //Search . initiliser , . initiliser__opt , . initiliser__opt and . initialiser_no_in__opt from grammar.output
    //var x . = 2;
    kVariableDeclEnd1 = 126,//initiliser
    kVariableDeclEnd2 = 148,//initiliser__opt
    kVariableDeclEnd3 = 291,//initiliser__opt
    kVariableDeclEnd4 = 294,//initiliser
    kVariableDeclEnd5 = 355,//initiliser_no_in__opt
    kVariableDeclEnd6 = 358,

    //. JS_EXP_CLOSURE_BEGIN
    //( x , y )-> . {...}
    kArrowFunctionExpBlockBegin = 40,
    
    //. JS_EXP_CLOSURE_BEGIN
    //( x, y )=> . {...}
    KArrowFunctionExpWBlockBegin = 41,

    /*
     *function_declaration: JS_FUNCTION JS_FUNCTION_IDENTIFIER . JS_PARAM_BEGIN formal_parameter_list__opt JS_PARAM_END '{' function_body '}'
     */
    kFormalParameterBegin1 = 138,
    kFormalParameterBegin2 = 139,

    /*
     *function_declaration: JS_CONST JS_FORMAL_PARAMETER_IDENT JS_PARAM_BEGIN formal_parameter_list__opt . JS_PARAM_END '{' function_body '}'
     *function_declaration: JS_FUNCTION JS_FUNCTION_IDENTIFIER JS_PARAM_BEGIN formal_parameter_list__opt . JS_PARAM_END '{' function_body '}'
     *function_expression: JS_FUNCTION identifier__opt JS_PARAM_BEGIN formal_parameter_list__opt . JS_PARAM_END '{' function_body '}'
     */
    kFormalParameterEnd1 = 157,
    kFormalParameterEnd2 = 350,
    kFormalParameterEnd3 = 380,
    kFormalParameterEnd4 = 381,

    //current state.
    kFormalParameter = 1,
    kVarDecl = 2,

    //Search . terminator from grammar.output.
    kTerminate1 = 98,
    kTerminate2 = 124,
    kTerminate3 = 143,
    kTerminate4 = 149,
    kTerminate5 = 161,
    kTerminate6 = 235,
    kTerminate7 = 246,
    kTerminate8 = 270,
    kTerminate9 = 485
  };
  
  TokenInfo* SwitchState_( int yystate ) {
    switch ( yystate ) {
      /*
      case kFunctionDeclIdentBeg :
      case kFunctionDeclIdentBeg2 :
        return RewriteType_( TOKEN::JS_IDENTIFIER , TOKEN::JS_FUNCTION_IDENTIFIER );
        
      case kVariableDeclBeg1 :
      case kVariableDeclBeg2 :
      case kVariableDeclBeg3 :
      case kVariableDeclBeg4 :
      case kVariableDeclBeg5 :
      case kVariableDeclBeg6 :
      case kVariableDeclBeg7 :
      case kVariableDeclBeg8 :
      case kVariableDeclBeg9 :
        state_.push_back( kVarDecl );
        return MatchState_();

      case kVariableDeclEnd2 :
      case kVariableDeclEnd3 :
      case kVariableDeclEnd4 :
      case kVariableDeclEnd5 :
      case kVariableDeclEnd6 :
        state_.pop_back();
        SkipLineBreak_();
        return (*it_);

      case kArrowFunctionExpBlockBegin :
      case KArrowFunctionExpWBlockBegin :
        return RewriteType_( '{' , TOKEN::JS_EXP_CLOSURE_BEGIN );
        

      case kFormalParameterBegin1 :
      case kFormalParameterBegin2 :
        state_.push_back( kFormalParameter );
        return RewriteType_( '(' , TOKEN::JS_PARAM_BEGIN );

      case kVariableDeclEndORParamBegin :
        state_.pop_back();
        state_.push_back( kFormalParameter );
        return RewriteType_( '(' , TOKEN::JS_PARAM_BEGIN );

      case kFormalParameterEnd1 :
      case kFormalParameterEnd2 :
      case kFormalParameterEnd3 :
        state_.pop_back();
        return RewriteType_( ')' , TOKEN::JS_PARAM_END );*/

      /**case kTerminate1 :
      case kTerminate2 :
      case kTerminate3 :
      case kTerminate4 :
      case kTerminate5 :
      case kTerminate6 :
      case kTerminate7 :
      case kTerminate8 :
      case kTerminate9 :
      case 396 :
      case 399 :
      case 535 :
      case 536 :
      case 359 :*/
      case 9999 :
        return (*it_);
        
      default :
        return MatchState_();
    }
  }

  TokenInfo* RewriteType_( int type , int type2 ) {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    if ( info->getType() == type ) {
      info->SetType( type2 );
    }
    
    return info;
  }

  void SkipLineBreak_() {
    TokenInfo* info = (*it_);
    while ( info->getType() == TOKEN::JS_LINE_BREAK && it_ != queue_.end() ) {
      ++it_;
      info = (*it_);
    }
  }
  
  TokenInfo* MatchState_() {
    int state = ( state_.size() > 0 )? state_.back() : 0;
    switch ( state ) {
      case kFormalParameter :
      case kVarDecl :
        return CaseFormalParameter_();
      default :
        SkipLineBreak_();
        return (*it_);
    }
  }
  
  TokenInfo* CaseFormalParameter_() {
    SkipLineBreak_();
    TokenInfo* info = (*it_);
    int type = info->getType();
    switch ( type ) {
      case '[' :
        info->SetType( TOKEN::JS_DSTA_BEGIN );
        break;
      case ']' :
        info->SetType( TOKEN::JS_DSTA_END );
        break;
      case TOKEN::JS_IDENTIFIER :
        info->SetType( TOKEN::JS_FORMAL_PARAMETER_IDENT );
        break;
    }
    return info;
  }
  int last_type_;
  std::list<int> state_;
  QueueScanner::Scanner::TokenQueue& queue_;
  QueueScanner::Scanner::TokenQueue::const_iterator it_;
};


QueueScanner::QueueScanner( const std::string& source ) :
    scanner_( new Scanner( source ) ) {}
QueueScanner::~QueueScanner(){}

void QueueScanner::CollectToken() {
  scanner_->CollectToken();
  token_getter_( new TokenGetter( scanner_->GetQueue() ) );
}

const TokenInfo* QueueScanner::GetToken( int yystate ) {
  const TokenInfo* info =  token_getter_->GetToken( yystate );
  if ( info->getType() > 200 ) {
    printf( "%s %d state %d\n" , info->getValue() , info->getType() , yystate );
  } else {
    printf( "%c %d state %d\n" , info->getType() , info->getType() , yystate );
  }
  return info;
}

}
