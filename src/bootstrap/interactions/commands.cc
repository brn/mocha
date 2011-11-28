#include <bootstrap/interactions/commands.h>
#include <bootstrap/interactions/commands_analyzer.h>
#include <bootstrap/runners/icommandline_runner.h>
#include <bootstrap/runners/observer_runner.h>
namespace mocha {
void Commands::Exec( const char* buf ) {
  CommandsAnalyzer analyzer;
  Handle<ICommandLineRunner> runner = analyzer.Analyze( buf );
  if ( runner->CastToObserver() != 0 ) {
    if ( !is_observe_running_ ) {
      is_observe_running_ = true;
      runner->Run();
    } else {
      if ( CommandLineOptions::GetInstance()->IsStopObserving() ) {
        runner->CastToObserver()->Exit();
        is_observe_running_ = false;
      } else {
        fprintf( stderr , "observer is now running.\n" );
      }
    }
  } else if ( runner->CastToList() != 0 ) {
    if ( is_observe_running_ ) {
      runner->Run();
    } else {
      fprintf( stderr , "observer is not running.\n" );
    }
  } else {
    runner->Run();
  }
}
}
