#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/options/setting.h>
#include <mocha/roaster/file_system/file_system.h>

#define SETTINGS Setting::GetInstance()

namespace mocha {

static const char utf8[] = { "UTF-8" };

void XMLSettingInfo::EraseData() {
  file_list_.clear();
  include_list_.clear();
  module_list_.clear();
  deploy_list_.clear();
  compile_option_.clear();
  versions_.clear();
  charset_list_.clear();
  deploy_name_list_.clear();
  deploy_charset_list_.clear();
}

const char* XMLSettingInfo::GetModuleDirPath( const char* filename ) {
  if ( module_list_.size() == 0 ) {
    return SETTINGS->GetModulePath();
  } else {
    Hash::iterator find = module_list_.find( filename );
    return ( find != module_list_.end() )? find->second.c_str() : SETTINGS->GetModulePath();
  }
}

SharedStr XMLSettingInfo::GetDeployPath( const char* filename ) {
  if ( deploy_list_.size() == 0 ) {
    return GetCmpPath_( filename );
  } else {
    Hash::iterator find = deploy_list_.find( filename );
    if ( find != deploy_list_.end() ) {
      const char* ret = find->second.c_str();
      FileSystem::Mkdir( ret , 0777 );
      SharedPtr<PathInfo> path_info = FileSystem::GetPathInfo( filename );
      char tmp[ 1000 ];
      sprintf( tmp , "%s/%s" , ret , GetCmpPath_( path_info->GetFileName().Get() ).Get() );
      char* result = new char[ strlen( tmp ) + 1 ];
      strcpy( result , tmp );
      SharedStr handle( result );
      return handle;
    } else {
      return GetCmpPath_( filename );
    }
  }
}

Options* XMLSettingInfo::GetCompileOption( const char* path ) {
  OptionHash::iterator begin = compile_option_.find( path );
  if ( begin != compile_option_.end() ) {
    return (*begin).second.Get();
  } else {
    return &empty_option_;
  }
}

SharedStr XMLSettingInfo::GetCmpPath_( const char* path ) {
  std::string tmp = path;
  Hash::iterator find = deploy_name_list_.find( path );
  if ( find != deploy_name_list_.end() ) {
    char *ret = new char[ find->second.size() + 1 ];
    strcpy( ret , find->second.c_str() );
    return SharedStr( ret );
  } else {
    int pos = tmp.find_last_of( '.' , tmp.size() - 1 );
    tmp.replace( pos , 1 , "-cmp." );
    char* result = new char[ tmp.size() + 1 ];
    strcpy( result , tmp.c_str() );
    return SharedStr( result );
  }
}

Version* XMLSettingInfo::GetVersion( const char* filename ) {
  VersionHash::iterator begin = versions_.find( filename );
  if ( begin == versions_.end() ) {
    return 0;
  } else {
    return begin->second.Get();
  }
}

bool XMLSettingInfo::HasCharset( const char* filename ) {
  Hash::iterator begin = charset_list_.find( filename );
  return begin != charset_list_.end();
}

SharedStr XMLSettingInfo::GetCharset( const char* filename ) {
  Hash::iterator begin = charset_list_.find( filename );
  if ( begin != charset_list_.end() ) {
    char* ret = new char[ begin->second.size() + 1 ];
    strcpy( ret , begin->second.c_str() );
    return SharedStr( ret );
  } else {
    char* ret = new char[ strlen( utf8 ) + 1 ];
    strcpy( ret , utf8 );
    return SharedStr( ret );
  }
}

SharedStr XMLSettingInfo::GetDeployCharset( const char* filename ) {
  Hash::iterator begin = deploy_charset_list_.find( filename );
  if ( begin != deploy_charset_list_.end() ) {
    char* ret = new char[ begin->second.size() + 1 ];
    strcpy( ret , begin->second.c_str() );
    return SharedStr( ret );
  } else {
    char* ret = new char[ strlen( utf8 ) + 1 ];
    strcpy( ret , utf8 );
    return SharedStr( ret );
  }
}

XMLSettingInfo::List XMLSettingInfo::file_list_;   
XMLSettingInfo::List XMLSettingInfo::include_list_;
XMLSettingInfo::Hash XMLSettingInfo::module_list_;
XMLSettingInfo::Hash XMLSettingInfo::charset_list_;
XMLSettingInfo::Hash XMLSettingInfo::deploy_list_;
XMLSettingInfo::Hash XMLSettingInfo::deploy_name_list_;
XMLSettingInfo::Hash XMLSettingInfo::deploy_charset_list_;
XMLSettingInfo::OptionHash XMLSettingInfo::compile_option_;
XMLSettingInfo::VersionHash XMLSettingInfo::versions_;
Options XMLSettingInfo::empty_option_;


}
