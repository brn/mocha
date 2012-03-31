#include <stdio.h>
#include <mocha/v8wrap/init.h>
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
using namespace v8;
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

XMLObserver::XMLObserver() : is_end_(true) {}
XMLObserver::~XMLObserver() {}
void XMLObserver::Run() {
  is_end_ = false;
  xml_updater_ = new XMLUpdater(this);
  if (Initialize_(Setting::GetInstance()->GetConfigPath())) {
    os::Thread thread;
    if (!thread.Create(XMLObserver::ThreadRunner_, xml_updater_->GetWatcher())) {
    } else {
      thread.Detach();
    }
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

bool XMLObserver::Initialize_(const char* path) {
  std::string buf;
  os::SPrintf(&buf, "mocha.import('%s');", path);
  V8Init* v8_runner = V8Init::GetInstance();
  Handle<Value> value = v8_runner->RunInConfigContext(buf.c_str());
  if (!v8_runner->IsInvalidValue(value)) {
    os::Printf("\n");
    Shell::GetInstance()->Print("starting watch server");
    Shell::GetInstance()->Print('.');
    XMLSettingInfo::IterateIncludeList<XMLObserver>(&XMLObserver::RegistFile_, this);
    Shell::GetInstance()->Print('.');
    xml_updater_->GetObserver()->Run();
    Shell::GetInstance()->Print('.');
    Shell::GetInstance()->Break();
    return true;
  } else {
    is_end_ = true;
    delete xml_updater_;
    return false;
  }
}

}
