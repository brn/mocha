#include <stdio.h>
#include <string>
#include <useconfig.h>
#include <bootstrap/bootstrap.h>
#include <utils/file_system/file_system.h>
#include <utils/io/file_io.h>
#include <mch/mocha.h>
#include <options/setting.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <options/commandline/commandline_options.h>
#include <bootstrap/interactions/interaction.h>

#ifdef HAVE__EXECV
#include <process.h>
#define execv(path,argv) _execv(path,argv)
#endif

static char data[] = {32,95,95,32,32,32,32,95,95,32,32,32,32,32,95,95,95,95,95,95,32,32,32,32,32,95,95,95,95,95,95,32,32,32,32,32,95,95,32,32,95,95,32,32,32,32,32,95,95,95,95,95,95,32,32,32,32,10,32,47,92,32,45,46,47,32,32,92,32,32,32,47,92,32,32,95,95,32,92,32,32,32,47,92,32,32,95,95,95,92,32,32,32,47,92,32,92,95,92,32,92,32,32,32,47,92,32,32,95,95,32,92,32,32,32,10,32,92,32,92,32,92,45,46,47,92,32,92,32,32,92,32,92,32,92,47,92,32,92,32,32,92,32,92,32,92,95,95,95,95,32,32,92,32,92,32,32,95,95,32,92,32,32,92,32,92,32,32,95,95,32,92,32,32,10,32,32,92,32,92,95,92,32,92,32,92,95,92,32,32,92,32,92,95,95,95,95,95,92,32,32,92,32,92,95,95,95,95,95,92,32,32,92,32,92,95,92,32,92,95,92,32,32,92,32,92,95,92,32,92,95,92,32,10,32,32,32,92,47,95,47,32,32,92,47,95,47,32,32,32,92,47,95,95,95,95,95,47,32,32,32,92,47,95,95,95,95,95,47,32,32,32,92,47,95,47,92,47,95,47,32,32,32,92,47,95,47,92,47,95,47,32,10,32,32,87,101,108,99,111,109,101,32,116,111,32,109,111,99,104,97,33,32,84,104,105,115,32,102,105,108,101,32,104,97,115,32,97,108,108,32,108,111,103,32,111,102,32,109,111,99,104,97,32,97,99,116,105,118,105,116,121,4};

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
  mocha::Setting::GetInstance()->LogNoDate( data );
}

void LoadSetting() {
  const char* path = mocha::Setting::GetInstance()->GetXMLPath();
  if ( !mocha::FileIO::IsExist( path ) ) {
    mocha::Handle<mocha::File> file = mocha::FileIO::Open( path , "rw" , mocha::FileIO::P_ReadWrite );
    if ( file->IsSuccess() ) {
      mocha::FileSystem::Chmod( path , 0777 );
      file->Write( CreateXML() );
    } else {
      fprintf( stderr , "Error can not find watch.xml. Run install.js first.\n" );
      exit(1);
    }
  }
}

void LoadLog() {
  LoadSetting();
  const char* path = mocha::Setting::GetInstance()->GetLogPath();
  if ( !mocha::FileIO::IsExist( path ) ) {
    fprintf( stderr , "Error can not find mocha.log. Run install.js first." );
    exit(1);
 CREATE :
    int ret = mocha::FileIO::CreateFile( path , 0777 );
    if ( ret != -1 ) {
      mocha::FileSystem::Chmod( path , 0777 );
      BeginLog();
    } else {
      fprintf( stderr , "Can not create setting file %s mocha boot failed." , path );
    }
  } else {
    if ( mocha::FileIO::Open( path , "r" , mocha::FileIO::P_ReadOnly )->GetSize() > 524288 ) {
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
  LoadLog();
  Setting::instance_->Log( "mocha initialize end." );
  argv_ = argv;
  self_path_ = FileSystem::GetAbsolutePath( argv[ 0 ] ).Get();
  Interaction::Begin();
  delete Setting::instance_;
}

void Bootstrap::Reboot() {
  Setting::instance_->Log( "reload mocha." );
  FileIO::CloseAll();
  execv( self_path_.c_str() , argv_ );
}

char** Bootstrap::argv_;
std::string Bootstrap::self_path_;

}
