#ifndef mocha_setting_h_
#define mocha_setting_h_

#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class File;
class ExternalAst;
class Setting {
  friend class Bootstrap;
 public :
  static Setting* GetInstance();
  const char* GetBasePath();
  const char* GetXMLPath();
  const char* GetModulePath();
  const char* GetRuntimePath();
  const char* GetRuntimeFile();
  const char* GetLogPath();
  const char* GetTimeStr();
  FileRoot* GetRuntime(memory::Pool* pool);
  void Close();
  void LogNoDate( const char* str , ... );
  void Log( const char* str , ... );
  void LogError( const char* str , ... );
  void LogFatal( const char* str , ... );
  void SetLogFileHandle();
 private :
  Setting();
  ~Setting(){};
  class PtrImpl;
  ScopedPtr<PtrImpl> implementation_;
  static SharedPtr<ExternalAst> runtime_ast_;
  static Setting* instance_;
};
}

#endif
