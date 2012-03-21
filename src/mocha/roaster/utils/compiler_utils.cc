#include <mocha/roaster/compiler.h>
#include <mocha/roaster/utils/compiler_utils.h>
#include <mocha/roaster/platform/fs/fio.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/platform/fs/virtual_directory.h>
#include <mocha/xml/xml_setting_info.h>

#define JS_EXTENSION ".js"

inline bool CheckIsModule(const char* file) {
  return (file[ 0 ] == '.' && (file[ 1 ] == '/' || file[ 1 ] == '.'))? false : true;
}

namespace mocha{

SharedPtr<os::fs::Path> CompilerUtils::CreateJsPath(const char* filename, const char* module_path_key, const LibDirectories& dir, bool* is_runtime) {
  std::string tmp;
  if (!CheckIsModule(filename)) {
    std::string js_path = filename;
    js_path += JS_EXTENSION;
    tmp = os::fs::VirtualDirectory::GetInstance()->GetRealPath(js_path.c_str()).Get();
  } else {
    (*is_runtime) = Compiler::IsRuntime(filename);
    if ((*is_runtime)) {
      return SharedPtr<os::fs::Path>(new os::fs::Path(filename));
    }
    LibDirectories::const_iterator iterator;
    for (iterator = dir.begin(); iterator != dir.end(); ++iterator) {
      tmp = (*iterator);
      tmp += '/';
      tmp += filename;
      tmp += JS_EXTENSION;
      os::fs::Stat stat(tmp.c_str());
      if (!stat.IsExist()) {
        tmp.clear();
      } else {
        break;
      }
    }
    if (tmp.empty()) {
      tmp = filename;
    }
  }
  return SharedPtr<os::fs::Path>(new os::fs::Path(tmp.c_str()));
}

SharedPtr<os::fs::Path> CompilerUtils::ChangeDir(const char* js_path) {
  SharedPtr<os::fs::Path> path(new os::fs::Path(js_path));
  os::fs::VirtualDirectory::GetInstance()->Chdir(path->directory());
  return path;
}

}
