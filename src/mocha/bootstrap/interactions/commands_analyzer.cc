#include <assert.h>
#include <mocha/bootstrap/interactions/interaction.h>
#include <mocha/bootstrap/interactions/commands_analyzer.h>
#include <mocha/bootstrap/runners/icommandline_runner.h>
#include <mocha/bootstrap/runners/help_runner.h>
#include <mocha/bootstrap/runners/compile_runner.h>
#include <mocha/bootstrap/runners/observer_runner.h>
#include <mocha/bootstrap/runners/error_runner.h>
#include <mocha/bootstrap/runners/list_runner.h>

#define COMPILE "compile"
#define HELP "help"
#define EXIT "exit"
#define OBSERVE "watch"
#define UNOBSERVE "unwatch"
#define LIST "list"

namespace mocha {
SharedPtr<ICommandLineRunner> CommandsAnalyzer::Analyze(const char* buf) {
  int i = 0;
  Options* options = CommandLineOptions::GetInstance();
  options->Reset();
  while (buf[ i ]) {
    if (buf[ i ] == ' ') {
      AnalyzeEachToken_(options);
      if (state_ == kS_Error) {
        break;
      }
    } else {
      buf_ += buf[ i ];
    }
    i++;
  }
  if ((state_ == kS_Begin || state_ == kS_Compile) && !buf_.empty()) {
    AnalyzeEachToken_(options);
  }
  if (state_ == kS_Exit) {
    return SharedPtr<ICommandLineRunner>();
  }
  switch (state_) {
    case kS_Compile :
      {
        if (options->IsPath()) {
          CompileRunner* runner = new CompileRunner(options);
          return SharedPtr<ICommandLineRunner>(runner);
        } else {
          ErrorRunner* runner = new ErrorRunner(options);
          return SharedPtr<ICommandLineRunner>(runner);
        }
      }
    case kS_Observe :
      {
        ObserverRunner* runner = new ObserverRunner(options);
        return SharedPtr<ICommandLineRunner>(runner);
      }
    case kS_Help :
      {
        HelpRunner* runner = new HelpRunner(options);
        return SharedPtr<ICommandLineRunner>(runner);
      }
    case kS_Error :
      {
        ErrorRunner* runner = new ErrorRunner(options);
        return SharedPtr<ICommandLineRunner>(runner);
      }
    case kS_List :
      {
        ListRunner* runner = new ListRunner(options);
        return SharedPtr<ICommandLineRunner>(runner);
      }

    default :
      ErrorRunner* runner = new ErrorRunner(options);
      return SharedPtr<ICommandLineRunner>(runner);
  }
}

void CommandsAnalyzer::AnalyzeEachToken_(Options* option) {
  const char* token = buf_.c_str();
  if (state_ == kS_Begin && strlen(token) > 0) {
    if (strcmp(token, COMPILE) == 0) {
      state_ = kS_Compile;
      option->AnalyzeOption(token);
    } else if (strcmp(token, EXIT) == 0) {
      Interaction::End();
      state_ = kS_Exit;
    } else if (strcmp(token, OBSERVE) == 0) {
      state_ = kS_Observe;
    } else if (strcmp(token, UNOBSERVE) == 0) {
      option->StopObserve();
      state_ = kS_Observe;
    } else if (strcmp(token, HELP) == 0) {
      state_ = kS_Help;
    } else if (strcmp(token, LIST) == 0) {
      state_ = kS_List;
    } else {
      option->AnalyzeOption(token);
      state_ = kS_Error;
    }
  } else if (state_ != kS_Error && state_ == kS_Compile) {
    option->AnalyzeOption(token);
    if (option->IsUnmatch()) {
      state_ = kS_Error;
    }
  }
  buf_.clear();
}

}
