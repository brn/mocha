#ifndef ParserTracer_h
#define ParserTracer_h
#include <string>
#include <utils/int_types.h>
#include "define.h"

namespace mocha{


  class ParserTracer {

  public :
    typedef enum {
      kNone = 0,
      kObjectLiteralEnd = 1,
      kCallExpEnd = 2,
      kFunction = 4,
      kClosureEnd = 8,
      kNoSemicolon = 16
    } ParserState;
    
    explicit ParserTracer ( const char* filename_ );
    inline ~ParserTracer () {}

    void SetSemicolonFlag ( bool is );
    
    inline JPM_PURE bool GetSemicolonFlag () const {
      return ( parser_flags_ & 0x1 ) == 1;
    }
    
    void SetRollBackFlag ( bool is );
    
    inline JPM_PURE bool GetRollBackFlag () const{
      return ( parser_flags_ & 0x2 ) == 2;
    }
    
    void SetLineBreakFlag ( bool is );
    
    inline JPM_PURE bool GetLineBreakFlag () const {
      return ( parser_flags_ & 0x4 ) == 4;
    }
    
    void SetIncludeFlag ( bool is );
    
    inline JPM_PURE bool GetIncludeFlag () const {
      return ( parser_flags_ & 0x8 ) == 8;
    }

    inline void SetState ( ParserState state ) { parser_state_ |= state; }
    inline bool GetState ( ParserState state ) const { return ( parser_state_ & state) == state; }
    inline void EndState ( ParserState state ) { parser_state_ = ( parser_state_ & ~state ); }
    inline void ExpectLBrace() { l_brace_ = true; }
    inline bool IsExpectLBrace() { return l_brace_; }
    inline void ExpectRBrace() { r_brace_ = true; }
    inline bool IsExpectRBrace() { return r_brace_; }
    inline bool IsAllowExpression() { return in_exp_; }
    inline void AllowExpression( bool is ) { in_exp_ = is; }
    
    void LineNumber ( long int num );
    
    void SyntaxError ( long int line , const char* mes );
    
    inline JPM_PURE bool IsSyntaxError () const {
      return ( parser_flags_ & 0x10 ) == 16;
    }
    
    inline JPM_CONST long int GetErrorLine () const {
      return errorLine_;
    }
    
    inline JPM_PURE const char* GetErrorMessage () const {
      return &message_ [ 0 ];
    }
    
    inline const char* GetModuleName () const {
      return &module_name_[0];
    }
    
    void SetModuleName ( const char* name ) {
      module_name_ = name;
    }

    inline const char* GetPath() { return filename_; }
    
  private:
    bool l_brace_;
    bool r_brace_;
    bool in_exp_;
    uint8_t parser_flags_;
    uint8_t parser_state_;
    uint32_t block_literal_stack_;
    long int errorLine_;
    ParserState state_;
    std::string message_;
    std::string module_name_;
    std::string indent_;
    const char* filename_;
  };

}

#endif

