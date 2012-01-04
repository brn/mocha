#include <bootstrap/interactions/interaction.h>
#include <bootstrap/interactions/commands_analyzer.h>
#include <bootstrap/runners/icommandline_runner.h>
#include <bootstrap/runners/help_runner.h>
#include <bootstrap/runners/compile_runner.h>
#include <bootstrap/runners/observer_runner.h>
#include <bootstrap/runners/error_runner.h>
#include <bootstrap/runners/list_runner.h>

#define COMPILE "compile"
#define HELP "help"
#define EXIT "exit"
#define OBSERVE "observe"
#define UNOBSERVE "unobserve"
#define LIST "list"

namespace mocha {
Handle<ICommandLineRunner> CommandsAnalyzer::Analyze( const char* buf ) {
  int i = 0;
  Options* options = CommandLineOptions::GetInstance();
  options->Reset();
  while ( buf[ i ] ) {
    if ( buf[ i ] == ' ' ) {
      AnalyzeEachToken_( options );
      if ( state_ == kS_Error ) {
        break;
      }
    }
    buf_ += buf[ i ];
    i++;
  }
  if ( state_ == kS_Begin ) {
    AnalyzeEachToken_( options );
  }
  if ( state_ == kS_Exit ) {
    return Handle<ICommandLineRunner>();
  }
  switch ( state_ ) {
    case kS_Compile :
      {
        if ( options->IsPath() ) {
          CompileRunner* runner = new CompileRunner( options );
          return Handle<ICommandLineRunner>( runner );
        } else {
          ErrorRunner* runner = new ErrorRunner( options );
          return Handle<ICommandLineRunner>( runner );
        }
      }
    case kS_Observe :
      {
        ObserverRunner* runner = new ObserverRunner( options );
        return Handle<ICommandLineRunner>( runner );
      }
    case kS_Help :
      {
        HelpRunner* runner = new HelpRunner( options );
        return Handle<ICommandLineRunner>( runner );
      }
    case kS_Error :
      {
        ErrorRunner* runner = new ErrorRunner( options );
        return Handle<ICommandLineRunner>( runner );
      }
    case kS_List :
      {
        ListRunner* runner = new ListRunner( options );
        return Handle<ICommandLineRunner>( runner );
      }
  }
}

void CommandsAnalyzer::AnalyzeEachToken_( Options* option ) {
  const char* token = buf_.c_str();
  if ( state_ == kS_Begin && strlen( token ) > 0 ) {
    if ( strcmp( token , COMPILE ) == 0 ) {
      state_ = kS_Compile;
    } else if ( strcmp( token , EXIT ) == 0 ) {
      Interaction::End();
      state_ = kS_Exit;
    } else if ( strcmp( token , OBSERVE ) == 0 ) {
      state_ = kS_Observe;
    } else if ( strcmp( token , UNOBSERVE ) == 0 ) {
      option->StopObserve();
      state_ = kS_Observe;
    } else if ( strcmp( token , HELP ) == 0 ) {
      state_ = kS_Help;
    } else if ( strcmp( token , LIST ) == 0 ) {
      state_ = kS_List;
    } else {
      option->AnalyzeOption( token );
      state_ = kS_Error;
    }
  } else if ( state_ != kS_Error && state_ == kS_Compile ) {
    option->AnalyzeOption( token );
    if ( option->IsUnmatch() ) {
      state_ = kS_Error;
    }
  }
  buf_.clear();
}

}
