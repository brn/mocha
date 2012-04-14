#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <string>
#include <mocha/options/setting.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/platform/fs/stat/stat.h>

const char watch_file_template[] = {
  "config.set('compileSettingPath', './compile_setting.js');\n"
  "config.set('logFilePath', './mocha.log');\n"
};

namespace mocha {
void Setting::Initialize() {
  std::stringstream base;
  base << os::fs::Path::home_directory() << "/.mocha/";
  tmp_file_ = base.str();
  tmp_file_ += "watch.tmp";
  moduledir_ = base.str();
  moduledir_ += "module";
  FILE* fp = os::FOpen(tmp_file_.c_str(), "w+b");
  if (fp != NULL) {
    os::FClose(fp);
  } else {
    FATAL("can not create tmp file.");
  }
  os::fs::Directory::chmod(tmp_file_.c_str(), 0600);
  config_path_ = base.str();
  config_path_ += "config.js";
  base_ = base.str();
  std::string test_dirver = base.str();
  test_dirver += "test_driver.js";
  Set("testDriver", test_dirver.c_str());
}

void Setting::Destruct() {
  os::fs::rm(tmp_file_.c_str());
}

const char* Setting::base() { return base_.c_str();};
const char* Setting::tmp_path() { return tmp_file_.c_str();};
const char* Setting::config_path() {return config_path_.c_str();}
const char* Setting::moduledir() {return moduledir_.c_str();}

const char* Setting::Get(const char* key) {
  if (strlen(key) > 0) {
    SettingMap::iterator it = setting_map_.find(key);
    if (it != setting_map_.end()) {
      return it->second.c_str();
    } else {
      return NULL;
    }
  } else {
    return NULL;
  }
}

void Setting::Set(const char* key, const char* val) {
  if (strlen(key) > 0 && strlen(val) > 0) {
    SettingMap::iterator it = setting_map_.find(key);
    if (it == setting_map_.end()) {
      setting_map_.insert(SettingPair(key, val));
    }
  }
}

bool Setting::Has(const char* key) {
  return (strlen(key) > 0)? setting_map_.find(key) != setting_map_.end() : NULL;
}

const char* Setting::WatchFileTemplate() {
  return watch_file_template;
}

const char Setting::kCompileSettingPath[] = {"compileSettingPath"};
const char Setting::kPhantomPath[] = {"phantomInstallDir"};
const char Setting::kLogPath[] = {"logFilePath"};
const char Setting::kTestRunner[] = {"testRunner"};
Setting::SettingMap Setting::setting_map_;
std::string Setting::base_;
std::string Setting::tmp_file_;
std::string Setting::config_path_;
std::string Setting::moduledir_;
}
