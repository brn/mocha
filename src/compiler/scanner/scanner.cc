#include <utils/int_types.h>
#include <string.h>
#include <string>
#include <sstream>
#include <compiler/scanner/scanner.h>
#include <compiler/scanner/token_stream.h>
#include <compiler/scanner/source_stream.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/binding/parser_tracer.h>
#include <compiler/utils/error_reporter.h>
#include <utils/smart_pointer/scope/scoped_list.h>
#include <utils/pool/managed_handle.h>
#include <utils/bits.h>
#include <grammar/grammar.tab.hh>

namespace mocha {

#define FLAG_LB 0
#define FLAG_REST 1
#define FLAG_NUMERIC 2
#define FLAG_REGEXP 3

class Scanner::InternalScanner {
 public :
  InternalScanner( SourceStream* source , ErrorReporter* reporter , const char* filename ) :
      line_( 1 ) , filename_( filename ) , token_stream_( TokenStream::Create() ) , source_stream_( source ) , reporter_( reporter ){}

  /**
   * @public
   * Collect token and push into the token queue.
   */
  inline void CollectToken() {
    while ( !IsEof_() ) {
      Skip_();
      if ( flags_.At( FLAG_LB ) ) {
        TokenInfo* info = token_stream_->Last();
        if ( info ) {
          info->SetLineBreakAfter();
        }
        flags_.UnSet( FLAG_LB );
      }
      char ch = Advance_();
      if ( IsIdentStart_( ch , true ) ) {
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
        token_stream_->Append( "" , ch , line_ );
      } else if ( IsNotSingleOperator_( ch ) ) {
        //operator like + - =
        CaseNotSingleOperator_( ch );
      } else if ( ch != 0 && ch != Token::END_OF_INPUT ){
        std::stringstream st;
        st << "Illegal token '"
           << ch << "' in " << filename_ << " at : " << line_;
        reporter_->ReportSyntaxError( st.str().c_str() );
      }
      SetRegExpAfter_();
      SetNumericAfter_();
    }
    TokenInfo* last = token_stream_->Last();
    if ( last ) {
      last->SetLineBreakAfter();
    }
    //Sentinel.
    token_stream_->Append( "" , Token::END_TOKEN , 0 );
  }

  inline TokenStream* GetStream() {
    return token_stream_;
  }
  
 private :

  /**
   * @private
   * Check char is unicode's byte order mark or not.
   */
  bool IsByteOrderMark_( char data ) {
    return ( data == 0xFEFF || data == 0xFFFE );
  }
  
  /**
   * @private
   * Check source end or not.
   */
  inline bool IsEof_ () {
    return source_stream_->Seek( 1 ) == Token::END_OF_INPUT;
  }


  inline uint8_t Seek_( int len ) {
    return source_stream_->Seek( len );
  }

  /**
   * @private
   * Get next char form source.
   */
  inline uint8_t Advance_ ( int len = 1 ) {
    if ( IsEof_() ) {
      return 0;
    } else {
      return source_stream_->Advance( len );
    }
  }

  /**
   * @private
   * Decrement source index.
   */
  inline void Undo_ ( int len = 1 ) {
    source_stream_->Undo( len );
  }
  
  /**
   * @private
   * Skip all comment , unicode's byte order mark , whitespace and linebreak.
   */
  void Skip_() {
    uint8_t ch = Seek_( 1 );
    uint8_t next = Seek_( 2 );
    bool isbreak = IsBreak_ ( ch );
    //Check that token is whitespace or line break.
    if ( IsWhiteSpace_ ( ch ) || IsByteOrderMark_( ch ) || isbreak ) {
      Advance_();
      //Add line number.
      if ( isbreak ) {
        flags_.Set( FLAG_LB );
        line_++;
      }
      isbreak = false;
      Skip_ ();
    } else if ( ch == '/' && next == '*' ) {
      Advance_( 2 );
      //Process multiline comment.
      SkipMultiLineComment_ ();
      //Check is whitespace or singleline comment continue.
      Skip_ ();
    } else if ( ch == '/' && next == '/' ) {
      Advance_( 2 );
      //Process single line comment.
      SkipComment_ ();
      //Check is whitespace or multiline comment continue.
      Skip_ ();
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
      ch = Advance_();
      uint8_t next = Advance_();
      //End of multiline comment.
      if ( ch == '*' && next == '/' ) {
        return;
      } else {
        if ( ch == '\n' ) {
          line_++;
          flags_.Set( FLAG_LB );
        }
        Undo_ ();
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
      ch = Advance_ ();
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
  inline bool IsIdentStart_ ( char ch , bool is_begin ) {
    char next = Seek_( 1 );
    if ( isalpha ( ch ) || 
         ch == '_' || 
         ch == '$' ||
         //treat special token.
         ch == '@' ) {
      return true;
    } else if ( is_begin && ch == '\\' && next == 'u' ) {
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
    char next = Advance_();
    while ( IsIdentStart_ ( next , false ) || isdigit ( next ) ) {
      token_str_ += next;
      next = Advance_();
    }
    Undo_();
    PushBack_( token_str_.c_str() );
  }


  /**
   * @private
   * @param {char}
   * In case of numeric literal.
   */
  inline void CaseDigit_ ( char ch ) {
    token_str_ = ch;
    char next = tolower ( Advance_() );
      
    if ( next == '.' ) {
      CaseDigitFloat_ ( next );
    } else if ( next == 'x' && ch == '0' ) {
      CaseDigitHex_ ( next );
    } else if ( isdigit ( next ) || next == 'e' ) {
      CaseDigitNumber_ ( next );
    } else {
      Undo_ ();
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
    
    while ( ( next = Advance_() ) ) {
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
        Undo_ ();
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
    Advance_();
    while ( ( next = Advance_ () ) ) {
      next = tolower ( next );
    
      if ( IsHex_ ( next ) ) {
        token_str_ += next;
      } else if ( isdigit( next ) ) {
        token_str_ += next;
      } else {
        Undo_ ();
        break;
      }
    }
  }


  inline void CaseDigitNumber_ ( char ch ) {
    token_str_ += ch;
    bool hasIndex = ( ch == 'e' )? true : false;
    char last = ch;
    char next;
        
    while ( ( next = Advance_() ) ) {
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
        Undo_ ();
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
  
    while ( ( next = Advance_() ) ) {
      if ( isdigit ( next ) ) {
        token_str_ += next;
        last = next;
      } else if ( next == '.' && index == 0 ) {
        if ( Advance_() == '.' ) {
          token_str_ += "..";
          PushBack_( token_str_.c_str() , Token::JS_PARAMETER_REST );
          return;
        } else {
          Undo_( 1 );
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
        Undo_ ();
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
         ch == ';' || ch == '?' ) {
      char next = Seek_( 1 );
      char next_after_ = Seek_( 2 );
      if ( ch == '.' && next == ch && next_after_ == ch ) {
        flags_.Set( FLAG_REST );
        return false;
      }
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
         ( ( ch > 32 && ch < 48 ) ||
           ( ch > 57 && ch < 65 ) ||
           ( ch > 90 && ch < 97 ) ||
           ( ch > 122 && ch < 127 ) ||
           flags_.At( FLAG_REST ) ) &&
         ch != 35 && ch != 127 && ch != 96 &&
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
          if ( flags_.At( FLAG_REST ) ) {
            token_str_ += Advance_();
            token_str_ += Advance_();
            PushBack_( token_str_.c_str() , Token::JS_PARAMETER_REST );
            flags_.UnSet( FLAG_REST );
          }
        }
        break;
        
      case '"' :
      case '\'' :
        {
          CaseStringLiteral_ ( ch );
        }
        break;
        
      case '=' :
      case '!' :
        {
          CaseEqualitiesORFunGlyph_ ();
        }
        break;
        
      case '-' :
      case '+' :
        {
          CaseAddAndSubORFunGlyph_ ( ch );
        }
        break;
        
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
        }
        break;
        
      case '|' :
      case '&' :
      case '^' :
      case '<' :
        {
          CaseLogical_ ( ch );
        }
        break;
        
      case '>' :
        {
          CaseShiftRight_ ();
        }
        break;
    }
  }

  
  inline void CaseStringLiteral_ ( char ch ) {
    char next = Seek_( 1 );
    char next_after_ = Seek_( 2 );
    bool escaped = false;

    if ( next == ch && next_after_ == ch ) {
      Advance_( 2 );
      while ( ( next = Advance_() ) ) {
        if ( next == '\n' ) {
          line_++;
        } else if ( next != '\r' ) {
          token_str_ += next;
        }
          
        char next_after = Advance_();
        char next_after_after = Advance_();
        if ( next == ch && next_after == ch && next_after_after == ch ) {
          break;
        } else {
          Undo_( 2 );
        }
      }
    } else {
      while ( ( next = Advance_() ) ) {
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
    char next = Advance_();
    if ( next == '=' ) {
      token_str_ += next;
      next = Advance_ ();
      if ( next == '=' ) {
        token_str_ += next;
      } else {
        Undo_();
      }
    } else if ( next == '>' ) {
      token_str_ += next;
    } else {
      Undo_();
    }

    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str () , true ) );
  }


  
  inline void CaseAddAndSubORFunGlyph_ ( char ch ) {
    char next = Advance_();
    if ( next == ch || next == '=' ) {
      token_str_ += next;
    } else if ( ch == '-' && next == '>' ) {
      token_str_ += next;
    } else {
      Undo_ ();
    }
    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str () , true ) );
  }
  
  
  inline void CaseRegExpLiteral_ () {            
    bool isescaped = false;
    bool ischar_class = false;
    char next;
    
    while ( ( next = Advance_ () ) ) {
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
    char flag = Seek_( 1 );
    bool has_error = false;
    std::string flag_list;
    BitVector8 flags;
    while ( isalpha( flag ) ) {
      if ( flag == 'i' ||
           flag == 'g' ||
           flag == 'm' ) {
        if ( !CheckRegExpFlags_( &flags , flag , &flag_list ) ) {
          has_error = true;
        } else {
        }
      } else {
        has_error = true;
        flag_list += flag;
      }
      Advance_();
      flag = Seek_( 1 );
    }
    if ( has_error ) {
      std::stringstream st;
      st << "Illegal regular expression flags '"
         << flag_list << "' in " << filename_ << " at : " << line_;
      reporter_->ReportSyntaxError( st.str().c_str() );
    } else {
      PushBack_( token_str_.c_str() , Token::JS_REGEXP_LITERAL );
    }
  }

  
  inline bool CheckRegExpFlags_( BitVector8 *flags , char flag , std::string *flag_list ) {
    if ( flag == 'i' ) {
      return SetRegExpFlags_( flags , flag , flag_list , 0 );
    } else if ( flag == 'g' ) {
      return SetRegExpFlags_( flags , flag , flag_list , 1 );
    } else if ( flag == 'm' ) {
      return SetRegExpFlags_( flags , flag , flag_list , 2 );
    }
  }

  
  inline bool SetRegExpFlags_( BitVector8 *flags , char flag , std::string *flag_list , int pos ) {
    if ( !flags->At( pos ) ) {
      flags->Set( pos );
      token_str_ += flag;
      (*flag_list) += flag;
      return true;
    } else {
      (*flag_list) += flag;
      return false;
    }
  }

  
  inline void CaseUnary_ () {
    char next = Advance_ ();
    if ( next == '=' ) {
      token_str_ += next;
    } else {
      Undo_ ();
    }
    PushBack_( token_str_.c_str() ,  JsToken::getType ( token_str_.c_str () , true ) );
  }


  inline void CaseLogical_ ( char ch ) {
    char next = Advance_ ();
  
    if ( next == ch ) {
      token_str_ += next;
    } else if ( ( ch == '|' ||
                  ch == '^' ||
                  ch == '<' ) &&
                next == '=' ) {
      token_str_ += next;
    } else {
      Undo_ ();
    }
    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str() , true ) );
  }


  inline void CaseShiftRight_ () {
    char next = Advance_ ();
    if ( next == '=' ) {
      token_str_ += next;
    } else if ( next == '>' ) {
      token_str_ += next;
      next = Advance_ ();
      if ( next == '>' ) {
        token_str_ += next;
        Undo_ ();
      } else {
        Undo_ ();
      }
    } else {
      Undo_ ();
    }
    PushBack_( token_str_.c_str() , JsToken::getType ( token_str_.c_str() , true ) );
  }


  inline void SetNumericAfter_ () {
    int type = ( token_stream_->Size() > 0 )? token_stream_->Last()->GetType() : 0;
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
    int type = ( token_stream_->Size() > 0 )? token_stream_->Last()->GetType() : 0;
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
      if ( token_stream_->Size() > 0 && token_stream_->Last()->GetType() != Token::JS_FOR ) {
        type = Token::JS_IDENTIFIER;
      }
    }
    DoPushBack_( ctoken , type );
  }

  /**
   * @private
   * @param {char}
   * Call DoPushBack_ with set type to arguments.
   */
  inline void PushBack_( int ch ) {
    if ( ch == '(' && token_stream_->Size() >= 2 ) {
      TokenInfo* info = token_stream_->Seek( 2 );
      if ( info != Scanner::kEmpty && info->GetType() == Token::JS_IDENTIFIER ) {
        if ( info && strcmp( info->GetToken() , "get" ) == 0 ) {
          info->SetType( Token::JS_GET );
        } else if ( info && strcmp( info->GetToken() , "set" ) == 0 ) {
          info->SetType( Token::JS_SET );
        }
      }
    }
    DoPushBack_( "" , ch );
  }

  /**
   * @private
   * @param {const char*}
   * @param {int}
   * Push back a pointer of TokenInfo to token_stream_.
   */
  inline void DoPushBack_( const char* ctoken , int type ) {
    TokenInfo* info = token_stream_->Last();
    token_stream_->Append( ctoken , type , line_ );
    if ( info && info->HasLineBreakAfter() ) {
      token_stream_->Last()->SetLineBreakBefor();
    }
  }

  int64_t line_;
  const char* filename_;
  BitVector8 flags_;
  TokenStream* token_stream_;
  SourceStream* source_stream_;
  std::string token_str_;
  ErrorReporter *reporter_;
};

Scanner* Scanner::Create( SourceStream* stream , ErrorReporter* reporter , const char* filename ) {
  Scanner* scanner = ManagedHandle::Retain( new Scanner( stream , reporter , filename ) );
  scanner->CreateTokenStream_();
  scanner->token_stream_ = scanner->scanner_->GetStream();
  return scanner;
}

Scanner::Scanner( SourceStream* source , ErrorReporter* reporter , const char* filename ) :
    scanner_( new InternalScanner( source , reporter , filename ) ) , reporter_( reporter ){}
Scanner::~Scanner(){}

TokenInfo* Scanner::Advance( int index ) {
  return token_stream_->Advance( index );
}

TokenInfo* Scanner::Undo( int index ) {
  return token_stream_->Undo( index );
}

TokenInfo* Scanner::Seek( int index ) {
  return token_stream_->Seek( index );
}

void Scanner::CreateTokenStream_() {
  scanner_->CollectToken();
}

TokenInfo* Scanner::kEmpty = 0;

}
