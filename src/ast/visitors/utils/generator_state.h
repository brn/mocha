#ifndef mocha_generator_state_h_
#define mocha_generator_state_h_

#include <vector>

namespace mocha {

class GeneratorState {
 public :
  typedef enum {
    kNone = 0,
    kFunctionBeginBrace,
    kFunctionEndBrace,
    kSwitchEndBrace,
    kBlockBeginBrace,
    kBlockEndBrace,
    kArgs,
    kFor,
    kVarsComma,
    kVarsEnd,
    kParenExp,
    kCase,
    kNewNoArgsBegin,
    kNewNoArgsEnd,
    kElseBlockEnd,
    kNamedModule,
    kAnonymousModule,
    kExpSp
  } GenState;

  enum { kStackSize = 1000 };
  
  inline GeneratorState() : index_( 0 ) , has_dst_exp_( false ), has_rest_exp_( false ) {
    stack_[ 0 ] = kNone;
  };

  inline ~GeneratorState() {};

  inline void SetDstExp() { has_dst_exp_ = true; }
  inline void UnsetDstExp() { has_dst_exp_ = false; }
  inline bool IsDstExp() { return has_dst_exp_; }

  inline void SetRestExp() { has_rest_exp_ = true; }
  inline void UnsetRestExp() { has_rest_exp_ = false; }
  inline bool IsRestExp() { return has_rest_exp_; }
  
  inline void Push( GenState state ) {
    if ( index_ < kStackSize ) {
      stack_[ index_ ] = state;
      index_++;
      stack_[ index_ ] = kNone;
    }
  }

  inline void Pop() {
    if ( index_ > 0 ) {
      index_--;
      stack_[index_] = kNone;
    }
  }

  inline GenState State() {
    return stack_[ ( ( index_ > 0 )? ( index_ - 1 ) : 0 ) ];
  }

  inline bool MatchState( GenState state ) {
    int i = 0;
    while ( stack_[ i ] != kNone ) {
      if ( state == stack_[ i ] ) {
        return true;
      }
      i++;
    }
  }
  
 private :
  int index_;
  bool has_dst_exp_;
  bool has_rest_exp_;
  GenState stack_[kStackSize]
};
}

#endif
