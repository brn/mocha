#ifndef mocha_interaction_h_
#define mocha_interaction_h_
#include <mocha/bootstrap/interactions/commands.h>
namespace mocha {
class Interaction {
 public :
  static void Begin();
  inline static void End() { is_end_ = true; }
 private :
  static bool is_end_;
  class RunCommand;
};
}

#endif
