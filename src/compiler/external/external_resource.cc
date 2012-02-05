#include <compiler/external/external_resource.h>
#include <compiler/consts/consts.h>
#include <compiler/utils/compile_info.h>
#include <utils/file_system/file_system.h>
namespace mocha {

Resources::Resources() : info_( new CompileInfo ){}

Resources::~Resources() {
  delete info_;
}

void Resources::SetInputCharset( const char* charset ) {
  input_charset_ = charset;
}

const char* Resources::GetInputCharset() {
  if ( input_charset_.empty() ) {
    return Consts::kDefaultInputCharset;
  } else {
    return input_charset_.c_str();
  }
}

void Resources::SetOutputCharset( const char* charset ) {
  output_charset_ = charset;
}

const char* Resources::GetOutputCharset() {
  if ( output_charset_.empty() ) {
    return Consts::kDefaultOutputCharset;
  } else {
    return output_charset_.c_str();
  }
}

void Resources::SetDeploy( const char* name ) {
  deploy_ = name;
}

const char* Resources::GetDeploy() {
  if ( deploy_.empty() ) {
    return 0;
  } else {
    return deploy_.c_str();
  }
}

void Resources::SetDeployName( const char* name ) {
  deployname_ = name;
}

StrHandle Resources::GetCmpPath_( const char* path ) {
  std::string tmp = path;
  if ( !deployname_.empty() ) {
    char *ret = new char[ deployname_.size() + 1 ];
    strcpy( ret , deployname_.c_str() );
    return StrHandle( ret );
  } else {
    int pos = tmp.find_last_of( '.' , tmp.size() - 1 );
    tmp.replace( pos , 1 , "-cmp." );
    char* result = new char[ tmp.size() + 1 ];
    strcpy( result , tmp.c_str() );
    return StrHandle( result );
  }
}

StrHandle Resources::GetDeployName( const char* filename ) {
  if ( deploy_.empty() ) {
    return GetCmpPath_( filename );
  } else {
    if ( !deployname_.empty() ) {
      const char* ret = deploy_.c_str();
      FileSystem::Mkdir( ret , 0777 );
      Handle<PathInfo> path_info = FileSystem::GetPathInfo( filename );
      char tmp[ 1000 ];
      sprintf( tmp , "%s/%s" , ret , GetCmpPath_( path_info->GetFileName().Get() ).Get() );
      char* result = new char[ strlen( tmp ) + 1 ];
      strcpy( result , tmp );
      return StrHandle( result );
    } else {
      return GetCmpPath_( filename );
    }
  }
}

void Resources::SetModule( const char* path ) {
  std::string ret = path;
  modulelist_.push_back( ret );
}


const Resources::ModuleList& Resources::GetModuleList() {
  return modulelist_;
}


CompileInfo* Resources::GetCompileInfo() {
  return info_;
}

void ExternalResource::UnsafeSet( const char* filename ) {
  Handle<Resources> handle( new Resources );
  resources_.Insert( filename , handle );
}

void ExternalResource::SafeSet( const char* filename ) {
  MutexLock lock( mutex_ );
  Handle<Resources> handle( new Resources );
  resources_.Insert( filename , handle );
}

Resources* ExternalResource::UnsafeGet( const char* filename ) {
  ResourceMap::HashEntry entry = resources_.Find( filename );
  if ( !entry.IsEmpty() ) {
    return entry.Value().Get();
  }
  return 0;
}

Resources* ExternalResource::SafeGet( const char* filename ) {
  MutexLock lock( mutex_ );
  ResourceMap::HashEntry entry = resources_.Find( filename );
  if ( !entry.IsEmpty() ) {
    return entry.Value().Get();
  }
  return 0;
}

Mutex ExternalResource::mutex_;
ExternalResource::ResourceMap ExternalResource::resources_;

}
