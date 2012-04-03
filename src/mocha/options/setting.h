#ifndef mocha_setting_h_
#define mocha_setting_h_

#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class Setting {
  friend class Bootstrap;
 public :
  static Setting* GetInstance();
  const char* GetBasePath();
  const char* GetXMLPath();
  const char* GetConfigPath();
  const char* GetModulePath();
  const char* GetRuntimePath();
  const char* GetRuntimeFile();
  const char* GetLogPath();
  const char* GetTimeStr();
  const char* GetTmpFile();
 private :
  Setting();
  ~Setting();
  class PtrImpl;
  ScopedPtr<PtrImpl> implementation_;
  static Setting* instance_;
};
}

#endif
