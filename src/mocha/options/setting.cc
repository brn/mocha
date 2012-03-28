#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string>
#include <mocha/options/setting.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/thread/thread.h>
#include <mocha/roaster/platform/fs/stat/stat.h>


namespace mocha {

class Setting::PtrImpl {
 public :
  /*void Log(const char* str, const char* type, bool is_date) {
    os::ScopedLock lock(mutex);
    std::string tmp;
    SetTime_();
    if (is_date) {
      tmp = ::asctime(date);
      tmp.erase(tmp.size() - 1, tmp.size());
      tmp += " ";
      tmp += type;
      tmp += " : ";
    }
    tmp += str;
    tmp += "\n";
    file_handle->Write(tmp.c_str());
  }

  const char* GetTimeStr() {
    SetTime_();
    char tmp[ 500 ];
    sprintf(tmp, "%d%d%d%d", date->tm_year + 1900, date->tm_mon, date->tm_mday, date->tm_hour);
    time_str_ = tmp;
    return time_str_.c_str();
    }*/
	
  time_t timer;
  tm* date;
  std::string base_dir;
  std::string xml_path;
  std::string module_path;
  std::string runtime_path;
  std::string runtime_file;
  std::string log_path;
	
  static const char info[];
  static const char error[];
  static const char fatal[];
  static os::Mutex mutex;

 private :
  void SetTime_() {
    ::time(&timer);
    date = ::localtime(&timer);
  }
  std::string time_str_;
};

const char Setting::PtrImpl::info[] = { "info" };
const char Setting::PtrImpl::error[] = { "error" };
const char Setting::PtrImpl::fatal[] = { "fatal" };
os::Mutex Setting::PtrImpl::mutex;

Setting* Setting::GetInstance() {
  if (instance_ == 0) {
    fprintf(stderr, "class Setting not initialized.");
    abort();
  }
  return instance_;
}


const char* Setting::GetBasePath() { return implementation_->base_dir.c_str(); }
const char* Setting::GetXMLPath() { return implementation_->xml_path.c_str(); }
const char* Setting::GetModulePath() { return implementation_->module_path.c_str(); }
const char* Setting::GetRuntimePath() { return implementation_->runtime_path.c_str(); }
const char* Setting::GetRuntimeFile() { return implementation_->runtime_file.c_str(); }
const char* Setting::GetLogPath() { return implementation_->log_path.c_str(); }

Setting::Setting() {
  implementation_(new PtrImpl());
  implementation_->base_dir = os::fs::Path::home_directory();
  implementation_->base_dir += "/.mocha/";
  implementation_->xml_path = implementation_->base_dir;
  implementation_->xml_path += "watch.xml";
  implementation_->module_path = implementation_->base_dir;
  implementation_->module_path += "module/";
}

Setting* Setting::instance_ = 0;
}
