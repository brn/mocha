#include <stdio.h>
#include <string>
#include "useconfig.h"
#include "bootstrap.h"
#include "file_system.h"
#include "file_io.h"
#include "mocha.h"
#include "setting.h"
#include "handle.h"
#include "commandline_options.h"

#ifdef HAVE__EXECV
#include <process.h>
#define execv(path,argv) _execv(path,argv)
#endif

const char* CreateXML() {
  return
      "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>\n"
      "<settings>\n"
      "    <dir>\n"
      "    </dir>\n"
      "</settings>";
}

void BeginLog() {
  mocha::Setting::GetInstance()->SetLogFileHandle();
  mocha::Setting::GetInstance()->LogNoDate(
" __    __     ______     ______     __  __     ______    \n"
"/\\ -./  \\   /\\  __ \\   /\\  ___\\   /\\ \\_\\ \\   /\\  __ \\   \n"
"\\ \\ \\-./\\ \\  \\ \\ \\/\\ \\  \\ \\ \\____  \\ \\  __ \\  \\ \\  __ \\  \n"
" \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\ \n"
"  \\/_/  \\/_/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_/\\/_/ \n"
"  Welcome to mocha! This file has all log of mocha activity." );
}

void CreateMochaDir() {
  const char* path = mocha::Setting::GetInstance()->GetBasePath();
  if ( !mocha::FileSystem::Mkdir( path , 0777 ) ) {
    fprintf( stderr , "Can not create directory %s mocha boot failed." , path );
    exit(2);
  }
}

void CreateDir() {
  CreateMochaDir();
  const char* path = mocha::Setting::GetInstance()->GetModulePath();
  if ( !mocha::FileSystem::Mkdir( path , 0777 ) ) {
    fprintf( stderr , "Can not create directory %s mocha boot failed." , path );
    exit(2);
  }
}

void CreateSetting() {
  CreateDir();
  const char* path = mocha::Setting::GetInstance()->GetXMLPath();
  if ( !mocha::FileIO::isExist( path ) ) {
    mocha::Handle<mocha::File> file = mocha::FileIO::Open( path , "rwn" , mocha::FileIO::P_ReadWrite );
    if ( file->isSuccess() ) {
      mocha::FileSystem::Chmod( path , 0777 );
      file->write( CreateXML() );
    } else {
      fprintf( stderr , "Can not create setting file %s mocha boot failed." , path );
    }
  }
}

void CreateLog() {
  CreateSetting();
  const char* path = mocha::Setting::GetInstance()->GetLogPath();
  if ( !mocha::FileIO::isExist( path ) ) {
 CREATE :
    int ret = mocha::FileIO::CreateFile( path , 0777 );
    if ( ret != -1 ) {
      mocha::FileSystem::Chmod( path , 0777 );
      BeginLog();
    } else {
      fprintf( stderr , "Can not create setting file %s mocha boot failed." , path );
    }
  } else {
    if ( mocha::FileIO::Open( path , "r" , mocha::FileIO::P_ReadOnly )->getSize() > 524288 ) {
      char tmp[ 1000 ];
      sprintf( tmp , "%s-%s\n" , path , mocha::Setting::GetInstance()->GetTimeStr() );
      rename( path , tmp );
      goto CREATE;
    }
    mocha::Setting::GetInstance()->SetLogFileHandle();
  }
}

namespace mocha {
void Bootstrap::Initialize( int argc , char** argv ) {
  Setting::instance_ = new Setting();
  CreateLog();
  Setting::instance_->Log( "mocha initialize end." );
  argv_ = argv;
  self_path_ = FileSystem::GetAbsolutePath( argv[ 0 ] ).get();
  Options *options = CommandLineOptions::GetInstance();
  options->AnalyzeOption( argc , argv );
  Mocha mocha( options );
  mocha.Run();
}

void Bootstrap::Reboot() {
  Setting::instance_->Log( "reload mocha." );
  FileIO::CloseAll();
  execv( self_path_.c_str() , argv_ );
  exit(0);
}

char** Bootstrap::argv_;
std::string Bootstrap::self_path_;

}
