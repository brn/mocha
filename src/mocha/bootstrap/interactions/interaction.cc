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
    if (input.size() > 2) {
      if (input.at(0) == '-' && input.at(1) == '-') {
        std::string tmp = input;
        input = "mocha.callCommand('";
        input += tmp;
        input += "');";
      }
      V8Init* v8_runner = V8Init::GetInstance();
      HandleScope handle_scope;
      TryCatch try_catch;
      Handle<Value> value = v8_runner->RunInGlobalContext(input.c_str());
      if (v8_runner->IsExitStatus(value)) {
        return true;
      } else if (try_catch.Exception().IsEmpty()) {
        v8_runner->Print(value);
      } else {
        V8Init::HandleException(&try_catch);
        try_catch.Reset();
      }
    }
    return false;
  }
 private :
  static Commands commands_;
};

void Interaction::Begin() {
  RunCommand command;
  V8Init* init = V8Init::GetInstance();
  Context::Scope context_scope(init->context());
  Shell* shell = Shell::Initialize(command);
  shell->Read();
}

bool Interaction::is_end_ = false;
Commands Interaction::RunCommand::commands_;
}
