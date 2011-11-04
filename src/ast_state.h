
#ifndef mocha_ast_state_h
#define mocha_ast_state_h

#include <stdint.h>
#include <queue>
#include "uncopyable.h"
#include "define.h"

#define EX_VOLATILE 1
#define ED_VOLATILE 0

namespace mocha {

  class AstState : private Uncopyable {

  public :

     typedef enum {
      kGlobal,
      kFunction,
      kFunctionName,
      kIfCond,
      kIfBody,
      kForBody,
      kForCond,
      kBlock,
      kDoCond,
      kDoBody,
      kWhileCond,
      kWhileBody,
      kBreak,
      kReturn,
      kWithParent,
      kWithBody,
      kContinue,
      kLabel,
      kSwitchCond,
      kCase,
      kCaseBody,
      kDefault,
      kThrow,
      kTry,
      kCatchCond,
      kCatchBody,
      kFinally,
      kCall,
      kNew,
      kDot,
      kBracket,
      kFormalParameter,
      kDecl,
      kArrayLiteral,
      kObjectLiteral,
      kArguments,
      kAssign
    } StateType;
    
    inline explicit AstState () :
      compiler_operation_ ( 0 ),
      main_function_name_ ( 0 )
    {};
    
    inline ~AstState () {};
    
    inline JPM_PURE bool IsVolatile () const {
      return ( compiler_operation_ & 1 ) == 1;
    }
    
    inline void DeclVolatile () {
      compiler_operation_ | 1;
    }
    
    inline void EndVolatile () {
      //11111110 shift or to LSM;
      compiler_operation_ = compiler_operation_ & 0xFE;
    }
    
    inline JPM_PURE bool IsModule () const {
      return ( compiler_operation_ & 0x2 ) == 2;
    }
    
    inline void DeclModule () {
      compiler_operation_ | 0x2;
    }
    
    inline void EndModule () {
      //11111101
      compiler_operation_ = compiler_operation_ & 0xFD;
    }
    
    inline JPM_PURE bool IsInclude () const {
      return ( compiler_operation_ & 0x4 ) == 4;
    }

    inline void DeclInclude () {
      compiler_operation_ | 0x4;
    }
    
    inline void EndInclude () {
      //11111011
      compiler_operation_ = compiler_operation_ & 0xFB;
    }
    
    inline JPM_PURE bool IsMain () {
      return ( compiler_operation_ & 8 ) == 8;
    }
    
    inline void DeclMain () {
      compiler_operation_ |= 8;
    }
    
    inline void SetMainFunctionName ( const char* name ) {
      main_function_name_ = const_cast<char*> ( name );
    }
    
    inline JPM_CONST const char* GetMainFunctionName () {
      return main_function_name_;
    }
    
    inline void State ( StateType state ) {
      ast_state_stack_.push_front ( state );
    }
    
    inline StateType State () {
      if ( ast_state_stack_.size () > 0 ) {
        return ast_state_stack_.front ();
      }
      return kGlobal;
    }
    
    inline void Pop () {
      if ( ast_state_stack_.size () > 0 ) {
        ast_state_stack_.pop_front ();
      }
    }

    inline bool Match ( StateType state ) {
      StateStack::iterator begin = ast_state_stack_.begin ();
      StateStack::iterator end = ast_state_stack_.end ();
      while ( begin != end ) {
        if ( (*begin) == state ) {
          return true;
        }
        ++begin;
      }
    }

    inline bool Is ( StateType state ) { return State() == state; }
      
  private:
    typedef std::deque<StateType> StateStack;
    uint8_t compiler_operation_;
    StateStack ast_state_stack_;
    char *main_function_name_;

  };

}

#endif

