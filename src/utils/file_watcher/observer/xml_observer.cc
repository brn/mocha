#include <stdio.h>
#include <bootstrap/bootstrap.h>
#include <utils/thread/thread.h>
#include <utils/file_watcher/observer/xml_observer.h>
#include <utils/xml/xml_reader.h>
#include <utils/xml/xml_setting_info.h>
#include <options/setting.h>


namespace mocha {

class XMLObserver::XMLUpdater : public IUpdater {
 public :
  XMLUpdater( XMLObserver* observer ) : observer_( observer ) {}
  ~XMLUpdater() {}
  void Update( watch_traits::Modify* traits ) {
    file_watcher_.Exit( RestartXMLWatcher_ , this );
  }
  void Die() {
    file_watcher_.Exit( DieXMLWatcher_ , this );
  }

  FileObserver* GetObserver() { return &file_observer_; }
  FileWatcher* GetWatcher() { return &file_watcher_; }

 private :

  static void RestartXMLWatcher_( void* arg ) {
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>( arg );
    updater->file_observer_.Exit( RestartFileWatcher_ , arg );
  }

  static void DieXMLWatcher_( void* arg ) {
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>( arg );
    updater->file_observer_.Exit( DieFileWatcher_ , arg );
  }
  
  static void RestartFileWatcher_( void* arg ) {
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>( arg );
    updater->file_watcher_.UnWatchAll();
    XMLSettingInfo::EraseData();
    updater->observer_->Restart();
  }
  
  static void DieFileWatcher_( void* arg ) {
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>( arg );
    updater->file_watcher_.UnWatchAll();
    XMLSettingInfo::EraseData();
    updater->observer_->Die();
  }

  FileObserver file_observer_;
  FileWatcher file_watcher_;
  XMLObserver* observer_;
};

XMLObserver::XMLObserver() {}
XMLObserver::~XMLObserver() {}
void XMLObserver::Run() {
  xml_updater_ = new XMLUpdater( this );
  Initialize_( Setting::GetInstance()->GetXMLPath() );
  Setting::GetInstance()->Log( "new thread start." );
  Thread thread;
  if ( !thread.Create( XMLObserver::ThreadRunner_ , xml_updater_->GetWatcher() ) ) {
    Setting::GetInstance()->LogFatal( "in XMLObserver::XMLObserver thread create fail." );
  } else {
    //thread.Exit();
    thread.Detach();
  }
}

void XMLObserver::Restart() {
  delete xml_updater_;
  Run();
}

void XMLObserver::Die() {
  delete xml_updater_;
}

void* XMLObserver::ThreadRunner_( void* arg ) {
  FileWatcher* watcher = reinterpret_cast<FileWatcher*>( arg );
  watcher->Start();
  return 0;
}

void XMLObserver::Exit() {
  xml_updater_->Die();
}


void XMLObserver::RegistFile_( const char* filename ) {
  xml_updater_->GetWatcher()->AddWatch( filename , xml_updater_ , FileWatcher::kModify );
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
