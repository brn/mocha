#include <mocha/roaster/utils/compiler_utils.h>
#include <mocha/roaster/misc/io/file_io.h>
#include <mocha/misc/file_system/file_system.h>
#include <mocha/misc/file_system/virtual_directory.h>
#include <mocha/misc/xml/xml_setting_info.h>

#define JS_EXTENSION ".js"

inline bool CheckIsModule(const char* file) {
  return (file[ 0 ] == '.' && (file[ 1 ] == '/' || file[ 1 ] == '.'))? false : true;
}

namespace mocha{

SharedStr CompilerUtils::CreateJsPath(const char* filename, const char* module_path_key) {
  std::string tmp;
  if (!CheckIsModule(filename)) {
    tmp += VirtualDirectory::GetInstance()->GetRealPath(filename).Get();
    tmp += JS_EXTENSION;
  } else {
    tmp = Setting::GetInstance()->GetModulePath();
    tmp += '/';
    tmp += filename;
    tmp += JS_EXTENSION;
    if (!FileIO::IsExist(tmp.c_str())) {
      tmp = Setting::GetInstance()->GetRuntimePath();
      tmp += '/';
      tmp += filename;
      tmp += JS_EXTENSION;
      if (!FileIO::IsExist(tmp.c_str())) {
        tmp = XMLSettingInfo::GetModuleDirPath(module_path_key);
        tmp += '/';
        tmp += filename;
        tmp += JS_EXTENSION;
      }
    }
  }
  return FileSystem::NormalizePath(tmp.c_str());
}

SharedPtr<PathInfo> CompilerUtils::ChangeDir(const char* js_path) {
  SharedPtr<PathInfo> path_info = FileSystem::GetPathInfo(js_path);
  VirtualDirectory::GetInstance()->Chdir(path_info->GetDirPath().Get());
  return path_info;
}

SharedPtr<PathInfo> CompilerUtils::GetRuntimePathInfo() {
  SharedPtr<PathInfo> path_info = FileSystem::GetPathInfo(Setting::GetInstance()->GetRuntimeFile());
  return path_info;
}

}
