#ifndef mocha_setting_h_
#define mocha_setting_h_

#include <string>
#include "scoped_ptr.h"
#include "bootstrap.h"

namespace mocha {
class File;
class Setting {
  friend class Bootstrap;
 public :
  static Setting* GetInstance();
  const char* GetBasePath();
  const char* GetXMLPath();
  const char* GetModulePath();
  const char* GetLogPath();
  void Close();
  void LogNoDate( const char* str , ... );
  void Log( const char* str , ... );
  void LogError( const char* str , ... );
  void LogFatal( const char* str , ... );
  void SetLogFileHandle();
 private :
  Setting();
  ~Setting();
  class PtrImpl;
  ScopedPtr<PtrImpl> implementation_;
  static Setting* instance_;
};
}

#endif
