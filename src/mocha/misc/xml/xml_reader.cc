#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <mocha/roaster/utils/compile_info.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/misc/xml/xml_reader.h>
#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/misc/io/file_io.h>
#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/misc/xml/versions.h>
#include <mocha/misc/char_allocator.h>
#include <mocha/options/setting.h>
#include <mocha/options/options.h>

#define BEGIN(name) //printf( "log : %s\n" , #name )
#define END(name) //printf( "log : %s end\n" , #name )
#define IS_DEF(str) str && strlen(str) > 0
#define IS_IGNORE(name) name && strlen(name) > 0 && strcmp( name , "true" ) == 0

namespace mocha {

class XMLInfo {
 public :
  inline XMLInfo( const char* path ) : path_( path ) {}
  inline ~XMLInfo(){};
  inline const char* GetPath(){ return path_; }
 private :
  const char* path_;
};

XMLReader::~XMLReader() {
  END("XMLReader");
}

void XMLReader::Parse( const char* pathname , bool is_reparse ) {
  BEGIN(Parse);
  filesystem::Path path(pathname);
  //Get absolute path of xml file.
  GetFullPath(&path);
  /*
   *If xml file is exit, start parse,
   *if not exist ignore this file and logging.
   */
  if (FileIO::IsExist(path.absolute_path())) {
    ParseStart(&path);
  } else {
    Setting::GetInstance()->GetInstance()->LogError("%s no such file." , path.absolute_path());
  }
  END(Parse);
}

bool XMLReader::CheckIgnoreOption( TiXmlElement *elem ) {
  const char* ignore_attr = elem->Attribute( ignore_ );
  if ( IS_IGNORE( ignore_attr ) ) {
    Setting::GetInstance()->Log( "ignore tag." );
    return true;
  }
  return false;
}

void XMLReader::GetFullPath(filesystem::Path* path) {
  XMLSettingInfo::include_list_.push_back(std::string(path->absolute_path()));
}


void XMLReader::ParseStart(filesystem::Path* path) {
  BEGIN(ParseStart);
  TiXmlDocument xml_document;
  xml_document.LoadFile(path->absolute_path());
  TiXmlElement* elem = xml_document.RootElement();
  XMLInfo info(path->directory());
  SwitchProcessor(elem, &info);
  END(ParseStart_);
}



void XMLReader::SwitchProcessor( TiXmlNode* node , XMLInfo* info ) {
  BEGIN(Read_);
  if ( node ) {
    if ( node->Type() == TiXmlNode::TINYXML_DOCUMENT ) {
      TiXmlNode *child = node->FirstChild();
      SwitchProcessor( child , info );
    } else if ( node->Type() == TiXmlNode::TINYXML_ELEMENT ) {
      ProcessNode( node->ToElement() , info );
    } else {
      TiXmlNode* next = node->NextSibling();
      SwitchProcessor( next , info );
    }
  }
  END(Read_);
}



void XMLReader::ProcessNode( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessNode_);
  if ( strcmp( elem->Value() , setting_ ) == 0 ) {
    ProcessSettingNode( elem , info );
  } else if ( strcmp( elem->Value() , dir_ ) == 0 ) {
    ProcessDirNode( elem , info );
  } else if ( strcmp( elem->Value() , include_ ) == 0 ) {
    ProcessIncludeNode( elem , info );
  }
  END(ProcessNode_);
}



void XMLReader::ProcessFileNode( TiXmlElement* elem , const char* dir , const char* module , XMLInfo* info ) {
  BEGIN(ProcessFileNode_);
  //Check is ignore attr is there.
  if ( CheckIgnoreOption( elem ) ) {
    return;
  }
  const char* filename = elem->Attribute( path_ );

  if ( IS_DEF( filename ) ) {
    char filename_buf[500];
    char module_buf[500];
    sprintf( filename_buf, "%s/%s/%s" , info->GetPath() , dir , filename );

    filesystem::Path path(filename_buf);
    const char* normalized_path = path.absolute_path();
    ExternalResource::UnsafeSet(normalized_path);
    Resource* resource = ExternalResource::UnsafeGet(normalized_path);
    //If file exist.
    if (FileIO::IsExist(normalized_path)) {
      if (IS_DEF(module)) {
        sprintf(module_buf, "%s/%s", info->GetPath() , module);
        //Processing <file module="..." /> attr.
        ProcessModuleOption(normalized_path , module_buf , resource );
      }
      //Processing <file path="..." /> attr.
      ProcessFilePath( normalized_path );
      //Processing <file deploy="..." /> attr.
      ProcessDeployOption( elem , normalized_path , dir , resource , info );
      ProcessDeployName( elem , normalized_path , dir , resource , info );
      ProcessCharset( elem , normalized_path , dir , resource , info );
      ProcessCompileOption( elem , normalized_path , dir , resource , info );
      ProcessVersion( elem , normalized_path , dir , resource , info );
    } else {
      Setting::GetInstance()->LogError( "%s no such file." , normalized_path );
    }
  }
  END(ProcessFileNode);
}


void XMLReader::ProcessFilePath( const char* filename ) {
  XMLSettingInfo::file_list_.push_back( filename );
  SharedPtr<Version> handle( new Version );
  XMLSettingInfo::versions_.insert( std::pair<const char*,SharedPtr<Version> >( filename , handle ) );
}


void XMLReader::ProcessModuleOption( const char* filename , const char* module , Resource* resource ) {
  std::string buffer;
  for ( int i = 0,len = strlen( module );i < len; i++ ) {
    if ( module[ i ] == ',' ) {
      filesystem::Path path(buffer.c_str());
      resource->SetModule(path.absolute_path());
      buffer.clear();
    } else if ( isalnum( module[ i ] ) || module[ i ] == '-' || module[ i ] == '_' ) {
      buffer += module[ i ];
    }
  }
  if ( !buffer.empty() ) {
    filesystem::Path path(buffer.c_str());
    resource->SetModule(path.absolute_path());
  }
}


void XMLReader::ProcessDeployOption( TiXmlElement *elem , const char* filename , const char* dir , Resource* resource , XMLInfo *info ) {
  const char* deploy_path = elem->Attribute( deploy_ );
  if ( IS_DEF( deploy_path ) ) {
    char buf[ 1000 ];
    sprintf( buf , "%s/%s/%s" , info->GetPath() , dir , deploy_path );
    filesystem::Path path(buf);
    resource->SetDeploy(path.absolute_path());
  }
}


void XMLReader::ProcessDeployName( TiXmlElement *elem , const char* filename , const char* dir , Resource* resource , XMLInfo *info ) {
  const char* deploy_name = elem->Attribute( deployname_ );
  if ( IS_DEF( deploy_name ) ) {
    std::string tmp = deploy_name;
    size_t pos = 0;
    if ( ( pos = tmp.find( ':' , 0 ) ) != std::string::npos ) {
      std::string charset = tmp.substr( ( pos + 1 ) );
      std::string name = tmp.substr( 0 , pos );
      resource->SetOutputCharset( charset.c_str() );
      resource->SetDeployName( name.c_str() );
    } else {
      resource->SetDeployName( deploy_name );
    }
  }
}


void XMLReader::ProcessCharset( TiXmlElement *elem , const char* filename , const char* dir , Resource* resource , XMLInfo *info ) {
  const char* charset = elem->Attribute( charset_ );
  if ( IS_DEF( charset ) ) {
    resource->SetInputCharset( charset );
    printf( "charset = %s\n" , charset );
  }
}


void XMLReader::ProcessCompileOption( TiXmlElement *elem , const char* filename , const char* dir , Resource* resource , XMLInfo *info ) {
  const char* compile_option = elem->Attribute( options_ );
  if ( IS_DEF( compile_option ) ) {
    CompilationInfo* cmp_option = resource->GetCompilationInfo();
    int len = strlen( compile_option );
    std::string buf;
    ScopedStrList scoped_list;
    if ( len > 0 ) {
      Options *option = new Options();
      for ( int i = 0; i < len; ++i ) {
        buf += compile_option[ i ];
        if ( ( compile_option[ i ] == ' ' || ( i == ( len - 1 ) ) ) &&
             buf.find_first_not_of( ' ' , 0 ) != std::string::npos ) {

          if ( buf[ buf.size() - 1 ] == ' ' ) {
            buf.erase( buf.size() - 1 , buf.size() );
          }
          option->AnalyzeOption( buf.c_str() );
          buf.clear();
        }
      }
      if ( option->IsPrettyPrint() ) {
        cmp_option->SetPrettyPrint();
      }
      if ( option->IsDebug() ) {
        cmp_option->SetDebug();
      }
      if ( option->IsCompress() ) {
        cmp_option->SetCompress();
      }
    }
  }
}

void XMLReader::ProcessVersion( TiXmlElement *elem , const char* filename , const char* dir , Resource* resource , XMLInfo *info ) {
  const char* version_attr = elem->Attribute( version_ );
  if ( IS_DEF( version_attr ) ) {
    std::string tmp;
    Version* version = XMLSettingInfo::GetVersion( filename );
    if ( version ) {
      for ( int i = 0;version_attr[ i ];i++ ) {
        if ( version_attr[ i ] == ' ' && tmp.size() > 0 ) {
          version->Add( tmp.c_str() );
          tmp.clear();
        } else {
          tmp += version_attr[ i ];
        }
      }
      if ( tmp.size() > 0 ) {
        resource->GetCompilationInfo()->SetVersion( tmp.c_str() );
        version->Add( tmp.c_str() );
      }
    }
  }
}

void XMLReader::ProcessSettingNode( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessSettingNode_);
  TiXmlNode *child = 0;
  while ( ( child = elem->IterateChildren( child ) ) ) {
    SwitchProcessor( child , info );
  }
  END(ProcessSettingNode_);
}



void XMLReader::ProcessDirNode( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessDirNode_);
  const char* dir_attr = elem->Attribute( path_ );
  const char* module_attr = elem->Attribute( module_ );
  if ( CheckIgnoreOption( elem ) ) {
    return;
  }
  TiXmlNode* child = 0;
  while ( ( child = elem->IterateChildren( child ) ) ) {
    if ( child->Type() == TiXmlNode::TINYXML_ELEMENT ) {
      if ( strcmp( child->Value() , file_ ) == 0 ) {
        ProcessFileNode( child->ToElement() , dir_attr , module_attr , info );
      }
    }
  }
  END(ProcessDirNode_);
}

void XMLReader::ProcessIncludeNode( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessIncludeNode_);
  const char* path_attr = elem->Attribute( path_ );
  if ( CheckIgnoreOption( elem ) ) {
    return;
  }
  Parse( path_attr );
  END(ProcessIncludeNode_);
}


const char XMLReader::setting_[] = { "settings" };
const char XMLReader::file_[] = { "file" };
const char XMLReader::include_[] = { "include" };
const char XMLReader::dir_[] = { "dir" };
const char XMLReader::path_[] = { "path" };
const char XMLReader::module_[] = { "module" };
const char XMLReader::ignore_[] = { "ignore" };
const char XMLReader::deploy_[] = { "deploy" };
const char XMLReader::deployname_[] = { "deployname" };
const char XMLReader::options_[] = { "options" };
const char XMLReader::version_[] = { "version" };
const char XMLReader::charset_[] = { "charset" };
}
