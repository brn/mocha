#include "xml_setting_info.h"
#include "setting.h"
#include "file_system.h"

#define SETTINGS Setting::GetInstance()

namespace mocha {

void XMLSettingInfo::EraseData() {
  file_list_.clear();
  include_list_.clear();
  module_list_.clear();
  deploy_list_.clear();
}

const char* XMLSettingInfo::GetModuleDirPath( const char* filename ) {
  if ( module_list_.size() == 0 ) {
    return SETTINGS->GetModulePath();
  } else {
    Hash::iterator find = module_list_.find( filename );
    return ( find != module_list_.end() )? find->second.c_str() : SETTINGS->GetModulePath();
  }
}

StrHandle XMLSettingInfo::GetDeployPath( const char* filename ) {
  if ( deploy_list_.size() == 0 ) {
    return GetCmpPath_( filename );
  } else {
    Hash::iterator find = deploy_list_.find( filename );
    if ( find != deploy_list_.end() ) {
      const char* ret = find->second.c_str();
      FileSystem::Mkdir( ret , 0777 );
      Handle<PathInfo> path_info = FileSystem::GetPathInfo( filename );
      char tmp[ 1000 ];
      sprintf( tmp , "%s/%s" , ret , GetCmpPath_( path_info->GetFileName() ).get() );
      char* result = new char[ strlen( tmp ) + 1 ];
      strcpy( result , tmp );
      StrHandle handle( result );
      return handle;
    } else {
      return GetCmpPath_( filename );
    }
  }
}

StrHandle XMLSettingInfo::GetCmpPath_( const char* path ) {
  std::string tmp = path;
  int pos = tmp.find_last_of( '.' , tmp.size() - 1 );
  tmp.replace( pos , 1 , "-cmp." );
  char* result = new char[ tmp.size() + 1 ];
  strcpy( result , tmp.c_str() );
  StrHandle handle( result );
  return handle;
}

XMLSettingInfo::List XMLSettingInfo::file_list_;   
XMLSettingInfo::List XMLSettingInfo::include_list_;
XMLSettingInfo::Hash XMLSettingInfo::module_list_; 
XMLSettingInfo::Hash XMLSettingInfo::deploy_list_;

}
