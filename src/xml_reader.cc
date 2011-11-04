#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "ptr_release.h"
#include "xml_reader.h"
#include "file_system.h"
#include "file_io.h"
#include "setting.h"
#include "xml_setting_info.h"

#define BEGIN(name) printf( "log : %s\n" , #name )
#define END(name) printf( "log : %s end\n" , #name )
#define IS_DEF(str) str && strlen(str) > 0
#define MODULE_LIST XMLSettingInfo::module_list_
#define INCLUDE_LIST XMLSettingInfo::include_list_
#define DEPLOY_LIST XMLSettingInfo::deploy_list_
#define FILE_LIST XMLSettingInfo::file_list_
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

XMLReader::~XMLReader() {}

void XMLReader::Parse( const char* path , bool is_reparse ) {
  BEGIN(Parse);
  //Get absolute path of xml file.
  const char* fullpath = GetFullPath_( path , is_reparse );
  /*
   *If xml file is exit, start parse,
   *if not exist ignore this file and logging.
   */
  if ( FileIO::isExist( fullpath ) ) {
    ParseStart_( fullpath );
  } else {
    SETTINGS->LogError( "%s no such file." , fullpath );
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

const char* XMLReader::GetFullPath_( const char* path , bool is_reparse ) {
  /*
   *If path is default setting.xml,push include list to setting.xml path,
   *and return default path.
   *If path is not default setting.xml, get absolute path of xml path.
   */
  if ( strcmp( path , SETTINGS->GetXMLPath() ) == 0 ) {
    INCLUDE_LIST.push_back( SETTINGS->GetXMLPath() );
    return SETTINGS->GetXMLPath();
  } else {
    return GetPath_( path , is_reparse );
  }
}


const char* XMLReader::GetPath_( const char* path , bool is_reparse ) {
  BEGIN(GetPath_);
  /*
   *If parse first time, get full file path.
   *If reparse mode, return default setting.xml path. 
   */
  if ( is_reparse ) {
    printf ( "%s\n" , path );
    INCLUDE_LIST.push_back( Setting::GetInstance()->GetXMLPath() );
    return SETTINGS->GetXMLPath();
  } else {
    printf( "relative path = %s\n" , path );
    StrHandle fullpath = FileSystem::GetAbsolutePath( path );
    printf( "full path = %s\n" ,fullpath.get() );
    char* result = new char[ ( strlen( fullpath.get() ) + 1 ) ];
    strcpy( result , fullpath.get() );
    INCLUDE_LIST.push_back( scoped_char_.Retain( result , ptr_release::ReleaseArray ) );
    return result;
  }
  END(GetPath_);
}



void XMLReader::ParseStart_( const char* path ) {
  BEGIN(ParseStart_);
  TiXmlDocument xml_document;
  xml_document.LoadFile( path );
  TiXmlElement* elem = xml_document.RootElement();
  Handle<PathInfo> path_info = FileSystem::GetPathInfo( path );
  printf( "dir path = %s\n" , path_info->GetDirPath() );
  XMLInfo info( path_info->GetDirPath() );
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
  printf ( "%s\n" , elem->Value() );
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
    printf( "watch file name = %s\n" , filename_buf );

    StrHandle handle = FileSystem::NormalizePath( filename_buf );
    const char* normalized_path = handle.get();

    //If file exist.
    if ( FileIO::isExist( normalized_path ) ) {
      if ( IS_DEF( module ) ) {
        sprintf( module_buf , "%s/%s" , info->GetPath() , module );
        //Processing <file module="..." /> attr.
        ProcessModuleOption_( normalized_path , module_buf );
      }
      //Processing <file path="..." /> attr.
      ProcessFilePath_( normalized_path );
      //Processing <file deploy="..." /> attr.
      ProcessDeployOption_( elem , normalized_path , dir , info );
    } else {
      Setting::GetInstance()->LogError( "%s no such file." , handle.get() );
    }
  }
  END(ProcessFileNode_);
}


void XMLReader::ProcessFilePath_( const char* filename ) {
  char* insertion_name = new char[ strlen( filename ) + 1 ];
  strcpy( insertion_name , filename );
  printf ( "file name = %s\n" , insertion_name );
  //Manage heaped ptr.
  scoped_char_.Retain( insertion_name , ptr_release::ReleaseArray );
  FILE_LIST.push_back( insertion_name );
}


void XMLReader::ProcessModuleOption_( const char* filename , const char* module ) {
  StrHandle module_handle = FileSystem::NormalizePath( module );
  if ( MODULE_LIST.find( filename ) == MODULE_LIST.end() ) {
    MODULE_LIST[ filename ] = module_handle.get();
  }
}


void XMLReader::ProcessDeployOption_( TiXmlElement *elem , const char* filename , const char* dir , XMLInfo *info ) {
  const char* deploy_path = elem->Attribute( deploy_ );
  if ( IS_DEF( deploy_path ) ) {
    char buf[ 1000 ];
    sprintf( buf , "%s/%s/%s" , info->GetPath() , dir , deploy_path );
    printf( "deploy path is %s\n" , buf );
    StrHandle handle = FileSystem::NormalizePath( buf );
    DEPLOY_LIST[ filename ] = handle.get();
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
  printf ( "log : include xml file = %s\n" , path_attr );
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
}
