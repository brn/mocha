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
          fprintf(stderr, "observer is not running.\n");
        }
      }
    } else if (runner->CastToList() != 0) {
      if (is_observe_running_) {
        runner->Run();
      } else {
        fprintf(stderr, "observer is not running.\n");
      }
    } else {
      runner->Run();
    }
  }
}
}
