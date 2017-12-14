#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <mocha/shell/shell.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/v8wrap/init.h>
#include <mocha/roaster/misc/string_utils.h>
using namespace v8;
namespace mocha {

class Interaction::RunCommand : public Action {
 public :
  bool operator()(ConsoleInput input) {
    if (input.size() > 0) {
      std::string buf;
      if (input.at(0) == '.') {
        std::stringstream st;
        mocha::StringUtils::Escape(&st, input, '\'');
        input = st.str();
        auto command = input.substr(1);
        os::SPrintf(&buf, "mocha.callCommand('%s')", command.c_str());
      } else {
        os::SPrintf(&buf, "console.dir(do{%s})", input.c_str());
      }
      V8Init* v8_runner = V8Init::GetInstance();
      HandleScope handle_scope;
      TryCatch try_catch;
      Handle<Value> value = v8_runner->RunInGlobalContext(buf.c_str());
      if (!try_catch.Exception().IsEmpty()) {
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
  Context::Scope context_scope(init->context());
  init->RunInConfigContext("mocha.callCommand('watch')");
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
