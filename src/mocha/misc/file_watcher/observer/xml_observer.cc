#include <stdio.h>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/misc/file_watcher/observer/xml_observer.h>
#include <mocha/xml/xml_reader.h>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/options/setting.h>
#include <mocha/shell/shell.h>
#ifdef _WIN32
#define sleep(time) Sleep(time##000)
#endif

namespace mocha {

class XMLObserver::XMLUpdater : public IUpdater {
 public :
  XMLUpdater(XMLObserver* observer) : observer_(observer) {}
  ~XMLUpdater() {}
  void Update(watch_traits::Modify* traits) {
    file_watcher_.Exit(RestartXMLWatcher_, this);
  }
  void Die() {
    file_watcher_.Exit(DieXMLWatcher_, this);
  }

  FileObserver* GetObserver() { return &file_observer_; }
  FileWatcher* GetWatcher() { return &file_watcher_; }

 private :

  static void RestartXMLWatcher_(void* arg) {
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>(arg);
    updater->file_observer_.Exit(RestartFileWatcher_, arg);
  }

  static void DieXMLWatcher_(void* arg) {
    Shell::GetInstance()->Print('.');
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>(arg);
    updater->file_observer_.Exit(DieFileWatcher_, arg);
  }
  
  static void RestartFileWatcher_(void* arg) {
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>(arg);
    updater->file_watcher_.UnWatchAll();
    XMLSettingInfo::EraseData();
    updater->observer_->Restart();
  }
  
  static void DieFileWatcher_(void* arg) {
    Shell::GetInstance()->Print('.');
    XMLObserver::XMLUpdater* updater = reinterpret_cast<XMLObserver::XMLUpdater*>(arg);
    updater->file_watcher_.UnWatchAll();
    XMLSettingInfo::EraseData();
    updater->observer_->Die();
  }

  FileObserver file_observer_;
  FileWatcher file_watcher_;
  XMLObserver* observer_;
};

XMLObserver::XMLObserver() : is_end_(false) {}
XMLObserver::~XMLObserver() {}
void XMLObserver::Run() {
  is_end_ = false;
  xml_updater_ = new XMLUpdater(this);
  Initialize_(Setting::GetInstance()->GetXMLPath());
  Setting::GetInstance()->Log("new thread start.");
  platform::Thread thread;
  if (!thread.Create(XMLObserver::ThreadRunner_, xml_updater_->GetWatcher())) {
    Setting::GetInstance()->LogFatal("in XMLObserver::XMLObserver thread create fail.");
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
  Shell::GetInstance()->Print('.');
  Shell::GetInstance()->Break();
  is_end_ = true;
}

bool XMLObserver::IsEnd() { return is_end_; }

void* XMLObserver::ThreadRunner_(void* arg) {
  FileWatcher* watcher = reinterpret_cast<FileWatcher*>(arg);
  watcher->Start();
  return 0;
}

void XMLObserver::Exit() {
  Shell::GetInstance()->SafeBreak(false);
  Shell::GetInstance()->Print("stopping watch server");
  xml_updater_->Die();
  while (!is_end_) {
    sleep(1);
  }
}


void XMLObserver::RegistFile_(const char* filename) {
  xml_updater_->GetWatcher()->AddWatch(filename, xml_updater_, FileWatcher::kModify);
}

void XMLObserver::Initialize_(const char* path) {
  Shell::GetInstance()->SafeBreak(false);
  Shell::GetInstance()->Print("starting watch server");
  Setting::GetInstance()->Log("xml parse begin.");
  XMLReader reader;
  reader.Parse(path);
  Shell::GetInstance()->Print('.');
  Setting::GetInstance()->Log("xml parse end.");
  Setting::GetInstance()->Log("start file observing.");
  XMLSettingInfo::IterateIncludeList<XMLObserver>(&XMLObserver::RegistFile_, this);
  Shell::GetInstance()->Print('.');
  xml_updater_->GetObserver()->Run();
  Shell::GetInstance()->Print('.');
  Shell::GetInstance()->Break();
}

}
