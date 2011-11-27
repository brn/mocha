#ifndef mocha_xml_reader_h_
#define mocha_xml_reader_h_

#include <stdio.h>
#include <list>
#include <boost/unordered_map.hpp>
#include <bootstrap/bootstrap.h>
#include <utils/smart_pointer/scope/scoped_list.h>
#include <tinyxml/tinyxml.h>

namespace mocha {
class XMLInfo;
class XMLReader {
 public :
  XMLReader (){};
  ~XMLReader();
  void Parse( const char* xmlpath , bool is_reparse = false );
  
 private :
  static bool CheckIgnoreOption_( TiXmlElement *elem );
  void GetFullPath_( const char* path , std::string& buf );
  void GetPath_( const char* path , std::string& buf );
  void ParseStart_( const char* path );
  void SwitchProcessor_( TiXmlNode* node , XMLInfo* info );
  void ProcessNode_( TiXmlElement *elem , XMLInfo* info );
  void ProcessFileNode_( TiXmlElement *elem, const char* path , const char* module , XMLInfo* info );
  void ProcessSettingNode_( TiXmlElement *elem , XMLInfo* info );
  void ProcessDirNode_( TiXmlElement *elem , XMLInfo* info );
  void ProcessIncludeNode_( TiXmlElement *elem , XMLInfo* info );
  void ProcessDeployOption_( TiXmlElement *elem , const char* filename , const char* dir , XMLInfo* info );
  void ProcessCompileOption_( TiXmlElement *elem , const char* filename , const char* dir , XMLInfo* info );
  void ProcessModuleOption_( const char* filename , const char* module );
  void ProcessFilePath_( const char* filename );
  
  ScopedStrList scoped_char_;

  static const char setting_[];
  static const char file_[];
  static const char include_[];
  static const char dir_[];
  static const char path_[];
  static const char module_[];
  static const char ignore_[];
  static const char deploy_[];
  static const char options_[];
};
}
#undef IS_IGNORE
#endif //mocha_xml_reader_h_
