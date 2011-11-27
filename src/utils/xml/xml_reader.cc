#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <utils/xml/xml_reader.h>
#include <utils/file_system/file_system.h>
#include <utils/io/file_io.h>
#include <utils/xml/xml_setting_info.h>
#include <utils/char_allocator.h>
#include <options/setting.h>
#include <options/options.h>

#define BEGIN(name) //printf( "log : %s\n" , #name )
#define END(name) //printf( "log : %s end\n" , #name )
#define IS_DEF(str) str && strlen(str) > 0
#define ITERATOR(name) begin = name.begin(),end = name.end()
#define MODULE_LIST XMLSettingInfo::module_list_
#define INCLUDE_LIST XMLSettingInfo::include_list_
#define DEPLOY_LIST XMLSettingInfo::deploy_list_
#define FILE_LIST XMLSettingInfo::file_list_
#define COMPILE_OPTION XMLSettingInfo::compile_option_
#define SETTINGS Setting::GetInstance()
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

void XMLReader::Parse( const char* path , bool is_reparse ) {
  BEGIN(Parse);
  std::string fullpath;
  //Get absolute path of xml file.
  GetFullPath_( path , fullpath );
  /*
   *If xml file is exit, start parse,
   *if not exist ignore this file and logging.
   */
  if ( FileIO::IsExist( fullpath.c_str() ) ) {
    ParseStart_( fullpath.c_str() );
  } else {
    SETTINGS->LogError( "%s no such file." , fullpath.c_str() );
  }
  END(Parse);
}

bool XMLReader::CheckIgnoreOption_( TiXmlElement *elem ) {
  const char* ignore_attr = elem->Attribute( ignore_ );
  if ( IS_IGNORE( ignore_attr ) ) {
    Setting::GetInstance()->Log( "ignore tag." );
    return true;
  }
  return false;
}

void XMLReader::GetFullPath_( const char* path , std::string& buf ) {
  /*
   *If path is default setting.xml,push include list to setting.xml path,
   *and return default path.
   *If path is not default setting.xml, get absolute path of xml path.
   */
  if ( strcmp( path , SETTINGS->GetXMLPath() ) == 0 ) {
    buf = SETTINGS->GetXMLPath();
    INCLUDE_LIST.push_back( buf );
  } else {
    return GetPath_( path , buf );
  }
}


void XMLReader::GetPath_( const char* path , std::string& buf ) {
  BEGIN(GetPath_);
  /*
   *Get full file path.
   */
  StrHandle fullpath = FileSystem::GetAbsolutePath( path );
  buf = fullpath.Get();
  INCLUDE_LIST.push_back( buf );
  END(GetPath_);
}



void XMLReader::ParseStart_( const char* path ) {
  BEGIN(ParseStart_);
  TiXmlDocument xml_document;
  xml_document.LoadFile( path );
  TiXmlElement* elem = xml_document.RootElement();
  Handle<PathInfo> path_info = FileSystem::GetPathInfo( path );
  XMLInfo info( path_info->GetDirPath().Get() );
  SwitchProcessor_( elem , &info );
  END(ParseStart_);
}



void XMLReader::SwitchProcessor_( TiXmlNode* node , XMLInfo* info ) {
  BEGIN(Read_);
  if ( node ) {
    if ( node->Type() == TiXmlNode::TINYXML_DOCUMENT ) {
      TiXmlNode *child = node->FirstChild();
      SwitchProcessor_( child , info );
    } else if ( node->Type() == TiXmlNode::TINYXML_ELEMENT ) {
      ProcessNode_( node->ToElement() , info );
    } else {
      TiXmlNode* next = node->NextSibling();
      SwitchProcessor_( next , info );
    }
  }
  END(Read_);
}



void XMLReader::ProcessNode_( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessNode_);
  if ( strcmp( elem->Value() , setting_ ) == 0 ) {
    ProcessSettingNode_( elem , info );
  } else if ( strcmp( elem->Value() , dir_ ) == 0 ) {
    ProcessDirNode_( elem , info );
  } else if ( strcmp( elem->Value() , include_ ) == 0 ) {
    ProcessIncludeNode_( elem , info );
  }
  END(ProcessNode_);
}



void XMLReader::ProcessFileNode_( TiXmlElement* elem , const char* dir , const char* module , XMLInfo* info ) {
  BEGIN(ProcessFileNode_);
  //Check is ignore attr is there.
  if ( CheckIgnoreOption_( elem ) ) {
    return;
  }
  const char* filename = elem->Attribute( path_ );

  if ( IS_DEF( filename ) ) {
    char filename_buf[500];
    char module_buf[500];
    sprintf( filename_buf, "%s/%s/%s" , info->GetPath() , dir , filename );

    StrHandle handle = FileSystem::NormalizePath( filename_buf );
    const char* normalized_path = handle.Get();

    //If file exist.
    if ( FileIO::IsExist( normalized_path ) ) {
      if ( IS_DEF( module ) ) {
        sprintf( module_buf , "%s/%s" , info->GetPath() , module );
        //Processing <file module="..." /> attr.
        ProcessModuleOption_( normalized_path , module_buf );
      }
      //Processing <file path="..." /> attr.
      ProcessFilePath_( normalized_path );
      //Processing <file deploy="..." /> attr.
      ProcessDeployOption_( elem , normalized_path , dir , info );
      ProcessCompileOption_( elem , normalized_path , dir , info );
    } else {
      Setting::GetInstance()->LogError( "%s no such file." , handle.Get() );
    }
  }
  END(ProcessFileNode_);
}


void XMLReader::ProcessFilePath_( const char* filename ) {
  FILE_LIST.push_back( filename );
}


void XMLReader::ProcessModuleOption_( const char* filename , const char* module ) {
  StrHandle module_handle = FileSystem::NormalizePath( module );
  if ( MODULE_LIST.find( filename ) == MODULE_LIST.end() ) {
    MODULE_LIST[ filename ] = module_handle.Get();
  }
}


void XMLReader::ProcessDeployOption_( TiXmlElement *elem , const char* filename , const char* dir , XMLInfo *info ) {
  const char* deploy_path = elem->Attribute( deploy_ );
  if ( IS_DEF( deploy_path ) ) {
    char buf[ 1000 ];
    sprintf( buf , "%s/%s/%s" , info->GetPath() , dir , deploy_path );
    StrHandle handle = FileSystem::NormalizePath( buf );
    DEPLOY_LIST[ filename ] = handle.Get();
  }
}


void XMLReader::ProcessCompileOption_( TiXmlElement *elem , const char* filename , const char* dir , XMLInfo *info ) {
  const char* compile_option = elem->Attribute( options_ );
  if ( IS_DEF( compile_option ) ) {
    std::vector<char*> array;
    array.push_back( 0 );
    int len = strlen( compile_option );
    int raw = 1;
    std::string buf;
    ScopedStrList scoped_list;
    for ( int i = 0; i < len; ++i ) {
      buf += compile_option[ i ];
      if ( ( compile_option[ i ] == ' ' || ( i == ( len - 1 ) ) ) &&
           buf.find_first_not_of( ' ' , 0 ) != std::string::npos ) {

        if ( buf[ buf.size() - 1 ] == ' ' ) {
          buf.erase( buf.size() - 1 , buf.size() );
        }
        char* ret = new char[ buf.size() + 1 ];
        strcpy( ret , buf.c_str() );
        scoped_list.Retain( ret );
        array.push_back( ret );
        buf.clear();
        raw++;
      }
    }
    if ( raw > 1 ) {
      Options *option = new Options();
      option->AnalyzeOption( raw , array );
      COMPILE_OPTION[ filename ] = Handle<Options>( option );
    }
  }
}


void XMLReader::ProcessSettingNode_( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessSettingNode_);
  TiXmlNode *child = 0;
  while ( ( child = elem->IterateChildren( child ) ) ) {
    SwitchProcessor_( child , info );
  }
  END(ProcessSettingNode_);
}



void XMLReader::ProcessDirNode_( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessDirNode_);
  const char* dir_attr = elem->Attribute( path_ );
  const char* module_attr = elem->Attribute( module_ );
  if ( CheckIgnoreOption_( elem ) ) {
    return;
  }
  TiXmlNode* child = 0;
  while ( ( child = elem->IterateChildren( child ) ) ) {
    if ( child->Type() == TiXmlNode::TINYXML_ELEMENT ) {
      if ( strcmp( child->Value() , file_ ) == 0 ) {
        ProcessFileNode_( child->ToElement() , dir_attr , module_attr , info );
      }
    }
  }
  END(ProcessDirNode_);
}

void XMLReader::ProcessIncludeNode_( TiXmlElement *elem , XMLInfo* info ) {
  BEGIN(ProcessIncludeNode_);
  const char* path_attr = elem->Attribute( path_ );
  if ( CheckIgnoreOption_( elem ) ) {
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
const char XMLReader::options_[] = { "options" };
}
