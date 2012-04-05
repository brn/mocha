#ifndef mocha_interaction_h_
#define mocha_interaction_h_
namespace mocha {
class Interaction {
 public :
  static void Begin();
  static void Exit();
  static bool IsExit();
 private :
  static bool is_exit_;
  class RunCommand;
};
}

#endif
