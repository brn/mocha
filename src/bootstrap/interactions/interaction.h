#ifndef mocha_interaction_h_
#define mocha_interaction_h_
#include <bootstrap/interactions/commands.h>
namespace mocha {
class Interaction {
 public :
  static void Begin();
 private :
  static Commands commands_;
};
}

#endif
