#include <mocha/roaster/utils/compiler_utils.h>
#include <mocha/roaster/misc/io/file_io.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/file_system/virtual_directory.h>
#include <mocha/misc/xml/xml_setting_info.h>

#define JS_EXTENSION ".js"

inline bool CheckIsModule(const char* file) {
  return (file[ 0 ] == '.' && (file[ 1 ] == '/' || file[ 1 ] == '.'))? false : true;
}

namespace mocha{

SharedPtr<filesystem::Path> CompilerUtils::CreateJsPath(const char* filename, const char* module_path_key) {
  std::string tmp;
  if (!CheckIsModule(filename)) {
    std::string js_path = filename;
    js_path += JS_EXTENSION;
    tmp = filesystem::VirtualDirectory::GetInstance()->GetRealPath(js_path.c_str()).Get();
  } else {
    tmp = Setting::GetInstance()->GetModulePath();
    tmp += '/';
    tmp += filename;
    tmp += JS_EXTENSION;
    if (!filesystem::FileIO::IsExist(tmp.c_str())) {
      tmp = Setting::GetInstance()->GetRuntimePath();
      tmp += '/';
      tmp += filename;
      tmp += JS_EXTENSION;
      if (!filesystem::FileIO::IsExist(tmp.c_str())) {
        tmp = XMLSettingInfo::GetModuleDirPath(module_path_key);
        tmp += '/';
        tmp += filename;
        tmp += JS_EXTENSION;
      }
    }
  }
  return SharedPtr<filesystem::Path>(new filesystem::Path(tmp.c_str()));
}

SharedPtr<filesystem::Path> CompilerUtils::ChangeDir(const char* js_path) {
  SharedPtr<filesystem::Path> path(new filesystem::Path(js_path));
  filesystem::VirtualDirectory::GetInstance()->Chdir(path->directory());
  return path;
}

}
