#include <stdio.h>
#include <stdlib.h>
#include <mocha/shell/shell.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/bootstrap/runners/observer_runner.h>
#include <mocha/v8wrap/init.h>
using namespace v8;
namespace mocha {

class Interaction::RunCommand : public Action {
 public :
  bool operator()(ConsoleInput input) {
    //commands_.Exec(input.c_str());
    if (strcmp(input.c_str(), "exit") == 0) {
      while (1) {
        if (is_end_) {
          if (commands_.IsObserving()) {
            commands_.Exec("unwatch");
          }
          break;
        }
      }
      return true;
    }
    HandleScope scope;
    TryCatch try_catch;
    V8Init* v8_runner = V8Init::GetInstance();
    Handle<Value> value = v8_runner->Run(input.c_str());
    if (try_catch.Exception().IsEmpty()) {
      //v8_runner->Print(value);
    }
    return false;
  }
 private :
  static Commands commands_;
};

void Interaction::Begin() {
  RunCommand command;
  Shell* shell = Shell::Initialize(command);
  shell->Read();
}

bool Interaction::is_end_ = false;
Commands Interaction::RunCommand::commands_;
}
