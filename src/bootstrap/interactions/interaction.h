#ifndef mocha_interaction_h_
#define mocha_interaction_h_
#include <bootstrap/interactions/commands.h>
namespace mocha {
class Interaction {
 public :
  static void Begin();
  inline static bool End() { is_end_ = true; }
 private :
  static bool is_end_;
  static Commands commands_;
};
}

#endif
