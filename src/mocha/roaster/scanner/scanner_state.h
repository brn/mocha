#ifndef mocha_scanner_state_h_
#define mocha_scanner_state_h_
#include <mocha/misc/class_traits/uncopyable.h>
namespace mocha {

class ScannerState : private Uncopyable {
 public :
  ScannerState();
  ~ScannerState();
  void Check(int token);
  bool IsAllowExpression();
  bool IsRightHandSide();
  class State;
  State* state_;
};

}

#endif
