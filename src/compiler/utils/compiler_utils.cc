#include <compiler/utils/compiler_utils.h>
#include <utils/file_system/file_system.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/xml/xml_setting_info.h>

#define JS_EXTENSION ".js"

inline bool CheckIsModule( const char* file ) {
  return ( file[ 0 ] == '.' && ( file[ 1 ] == '/' || file[ 1 ] == '.' ) )? false : true;
}

namespace mocha{

StrHandle CompilerUtils::CreateJsPath( const char* filename , const char* module_path_key ) {
  std::string tmp;
  if ( !CheckIsModule( filename ) ) {
    tmp += VirtualDirectory::GetInstance()->GetRealPath( filename ).Get();
    tmp += JS_EXTENSION;
  } else {
    tmp = XMLSettingInfo::GetModuleDirPath( module_path_key );
    tmp += '/';
    tmp += filename;
    tmp += JS_EXTENSION;
  }
  return FileSystem::NormalizePath( tmp.c_str() );
}

Handle<PathInfo> CompilerUtils::ChangeDir( const char* js_path ) {
  Handle<PathInfo> path_info = FileSystem::GetPathInfo( js_path );
  VirtualDirectory::GetInstance()->Chdir( path_info->GetDirPath().Get() );
  return path_info;
}

Handle<PathInfo> CompilerUtils::GetRuntimePathInfo() {
  Handle<PathInfo> path_info = FileSystem::GetPathInfo( Setting::GetRuntimePath() );
  return path_info;
}

}
