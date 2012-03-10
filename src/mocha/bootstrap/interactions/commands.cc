#include <mocha/shell/shell.h>
#include <mocha/bootstrap/interactions/commands.h>
#include <mocha/bootstrap/interactions/commands_analyzer.h>
#include <mocha/bootstrap/runners/icommandline_runner.h>
#include <mocha/bootstrap/runners/observer_runner.h>
namespace mocha {
void Commands::Exec(const char* buf) {
  CommandsAnalyzer analyzer;
  SharedPtr<ICommandLineRunner> runner = analyzer.Analyze(buf);
  if (runner.IsContainValidPtr()) {
    if (runner->CastToObserver() != 0) {
      if (!is_observe_running_ && !CommandLineOptions::GetInstance()->IsStopObserving()) {
        is_observe_running_ = true;
        runner->Run();
      } else if (CommandLineOptions::GetInstance()->IsStopObserving()) {
        if (is_observe_running_) {
          runner->CastToObserver()->Exit();
          is_observe_running_ = false;
        } else {
          Shell::GetInstance()->Break(false);
          Shell::GetInstance()->Print("watch sever is not running.\n"
                                      "If you want to run watch server, try 'watch' or "
                                      "'help'.");
          Shell::GetInstance()->Break();
        }
      } else {
        Shell::GetInstance()->Break(false);
        Shell::GetInstance()->Print("watch sever is already running.\n"
                                    "If you want to run watch server again, try 'unwatch' or "
                                    "'help'.");
        Shell::GetInstance()->Break();
      }
    } else if (runner->CastToList() != 0) {
      if (is_observe_running_) {
        runner->Run();
      } else {
        Shell::GetInstance()->Break(false);
        Shell::GetInstance()->Print("observer is not running");
        Shell::GetInstance()->Break();
      }
    } else {
      runner->Run();
    }
  }
}
}
