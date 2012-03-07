#ifndef mocha_xml_reader_h_
#define mocha_xml_reader_h_

#include <stdio.h>
#include <list>
#include <mocha/roaster/roaster.h>
#include <boost/unordered_map.hpp>
#include <mocha/bootstrap/bootstrap.h>
#include <mocha/roaster/smart_pointer/scope/scoped_list.h>
#include <third_party/tinyxml/tinyxml.h>

namespace mocha {
class XMLInfo;
class Resource;
class XMLReader {
 public :
  XMLReader (){};
  ~XMLReader();
  void Parse(const char* xmlpath, bool is_reparse = false);
  
 private :
  static bool CheckIgnoreOption(TiXmlElement *elem);
  void GetFullPath(filesystem::Path* path);
  void ParseStart(filesystem::Path* path);
  void SwitchProcessor(TiXmlNode* node, XMLInfo* info);
  void ProcessNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessFileNode(TiXmlElement *elem, const char* path, const char* module, XMLInfo* info);
  void ProcessSettingNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessDirNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessIncludeNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessDeployOption(TiXmlElement *elem, const char* filename, const char* dir, Resource* resource, XMLInfo* info);
  void ProcessDeployName(TiXmlElement *elem, const char* filename, const char* dir, Resource* resource, XMLInfo* info);
  void ProcessCharset(TiXmlElement *elem, const char* filename, const char* dir, Resource* resource, XMLInfo* info);
  void ProcessCompileOption(TiXmlElement *elem, const char* filename, const char* dir, Resource* resource, XMLInfo* info);
  void ProcessVersion(TiXmlElement *elem, const char* filename, const char* dir, Resource* resource, XMLInfo* info);
  void ProcessModuleOption(const char* filename, const char* module, Resource* resource);
  void ProcessFilePath(const char* filename);
  
  ScopedStrList scoped_char_;

  static const char setting_[];
  static const char file_[];
  static const char include_[];
  static const char dir_[];
  static const char path_[];
  static const char module_[];
  static const char ignore_[];
  static const char deploy_[];
  static const char deployname_[];
  static const char options_[];
  static const char version_[];
  static const char charset_[];
};
}
#undef IS_IGNORE
#endif //mocha_xml_reader_h_
