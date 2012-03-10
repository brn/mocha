#ifndef mocha_shell_h_
#define mocha_shell_h_
#include <string>
#include <deque>
#include <mocha/roaster/misc/atomic.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
namespace mocha {
typedef std::string ConsoleInput;
typedef std::deque<std::string> ConsoleHistory;

class Action {
 public :
  virtual bool operator()(ConsoleInput input){return true;}
};

class Shell {
 public :
  ~Shell();
  static Shell* Initialize(Action& action);
  static Shell* GetInstance();
  void Read();
  void Print(const char* str);
  void SafePrint(const char* str);
  void Print(char str);
  void SafePrint(char str);
  void Break(bool initial = true);
  void SafeBreak(bool initial = true);
 private :
  Shell(Action& action);
  void AddHistory();
  bool CallAction();
  bool CheckInput(int ch);
  void SwitchShellAction(int ch);
  void History();
  void PrevHistory();
  void NextHistory();
  void MoveLeft();
  void MoveRight();
  void BackSpace();
  void Delete();
  void EndOfBuffer();
  void BeginingOfBuffer();
  int history_cursor_;
  Action& action_;
  ConsoleInput input_buffer_;
  ConsoleHistory input_history_;
  static platform::Mutex mutex_;
  static ScopedPtr<Shell> shell_;
  static AtomicWord init_;
};
}

#endif
