#include <stdio.h>
#include "thread.h"
#include "xml_observer.h"
#include "xml_reader.h"
#include "setting.h"
#include "xml_setting_info.h"
#include "bootstrap.h"


namespace mocha {

class XMLObserver::XMLUpdater : public IUpdater {
 public :
  void Update( watch_traits::Modify* traits ) {
    //exit(1);
    Bootstrap::Reboot();
  }
};

XMLObserver::XMLObserver() : xml_updater_( new XMLUpdater ) { Initialize_( Setting::GetInstance()->GetXMLPath() ); }

void XMLObserver::Run() {
  Setting::GetInstance()->Log( "new thread start." );
  Thread thread;
  if ( !thread.Create( XMLObserver::ThreadRunner_ , &file_watcher_ ) ) {
    Setting::GetInstance()->LogFatal( "in XMLObserver::XMLObserver thread create fail." );
  } else {
    thread.Join();
  }
}

void* XMLObserver::ThreadRunner_( void* arg ) {
  FileWatcher* watcher = reinterpret_cast<FileWatcher*>( arg );
  watcher->Start();
  return 0;
}

void XMLObserver::RegistFile_( const char* filename ) {
  file_watcher_.AddWatch( filename , xml_updater_.Get() , FileWatcher::kModify );
}

void XMLObserver::Initialize_( const char* path ) {
  XMLReader reader;
  reader.Parse( path );
  file_observer_.Run();
  XMLSettingInfo::IterateIncludeList<XMLObserver>( &XMLObserver::RegistFile_ , this );
}

}
