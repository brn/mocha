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
    //file_watcher_.Exit();
    //file_observer_.Exit();
    //XMLSettingInfo::EraseData();
    Bootstrap::Reboot();
  }
  FileObserver* GetObserver() { return &file_observer_; }
  FileWatcher* GetWatcher() { return &file_watcher_; }
 private :
  FileWatcher file_watcher_;
  FileObserver file_observer_;
};

XMLObserver::XMLObserver() : xml_updater_( new XMLUpdater ) { Initialize_( Setting::GetInstance()->GetXMLPath() ); }

void XMLObserver::Run() {
  Setting::GetInstance()->Log( "new thread start." );
  Thread thread;
  if ( !thread.Create( XMLObserver::ThreadRunner_ , xml_updater_->GetWatcher() ) ) {
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
  printf( "xml regist %s\n" ,filename );
  xml_updater_->GetWatcher()->AddWatch( filename , xml_updater_.Get() , FileWatcher::kModify );
}

void XMLObserver::Initialize_( const char* path ) {
  Setting::GetInstance()->Log( "xml parse begin." );
  XMLReader reader;
  reader.Parse( path );
  Setting::GetInstance()->Log( "xml parse end." );
  Setting::GetInstance()->Log( "start file observing." );
  XMLSettingInfo::IterateIncludeList<XMLObserver>( &XMLObserver::RegistFile_ , this );
  xml_updater_->GetObserver()->Run();
}

}
