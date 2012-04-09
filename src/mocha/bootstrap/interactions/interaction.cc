#include <stdio.h>
#include <stdlib.h>
#include <mocha/shell/shell.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/v8wrap/init.h>
using namespace v8;
namespace mocha {

class Interaction::RunCommand : public Action {
 public :
  bool operator()(ConsoleInput input) {
    if (input.size() > 1) {
      if (input.at(0) == '@') {
        std::string tmp = input;
        input = "mocha.callCommand('";
        input += tmp;
        input += "');";
      }
      V8Init* v8_runner = V8Init::GetInstance();
      HandleScope handle_scope;
      TryCatch try_catch;
      Handle<Value> value = v8_runner->RunInGlobalContext(input.c_str());
      if (try_catch.Exception().IsEmpty()) {
        v8_runner->Print(value);
      } else {
        V8Init::HandleException(&try_catch);
        try_catch.Reset();
      }
      V8Init::IdleNotification();
    }
    return Interaction::IsExit();
  }
};

void Interaction::Begin() {
  RunCommand command;
  V8Init* init = V8Init::GetInstance();
  const char* logpath = Setting::Get(Setting::kLogPath);
  if (logpath != NULL) {
    Logging::Initialize(logpath, "a+");
  } else {
    Logging::Initialize(stdout);
  }
  Context::Scope context_scope(init->context());
  Shell* shell = Shell::Initialize(command);
  shell->Read();
  V8Init::Destruct();
  V8Init::IdleNotification();
}

void Interaction::Exit() {
  is_exit_ = true;
}

bool Interaction::IsExit() {
  return is_exit_;
}

bool Interaction::is_exit_ = false;
}
