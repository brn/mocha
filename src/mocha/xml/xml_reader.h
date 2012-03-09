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
class FileInfo;
class XMLReader {
 public :
  XMLReader (){};
  ~XMLReader();
  void Parse(const char* xmlpath, bool is_reparse = false);
  
 private :
  static bool CheckIgnoreOption(TiXmlElement *elem);
  void GetFullPath(platform::fs::Path* path);
  void ParseStart(platform::fs::Path* path);
  void SwitchProcessor(TiXmlNode* node, XMLInfo* info);
  void ProcessNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessFileNode(TiXmlElement *elem, const char* path, const char* module, XMLInfo* info);
  void ProcessSettingNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessDirNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessIncludeNode(TiXmlElement *elem, XMLInfo* info);
  void ProcessDeployOption(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo* info);
  void ProcessDeployName(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo* info);
  void ProcessCharset(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo* info);
  void ProcessCompileOption(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo* info);
  void ProcessVersion(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo* info);
  void ProcessModuleOption(const char* filename, const char* module, FileInfo* resource);
  void ProcessFilePath(const char* filename);
  ScopedStrList scoped_char_;
};
}
#undef IS_IGNORE
#endif //mocha_xml_reader_h_
