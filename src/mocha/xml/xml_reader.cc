#include <string.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <mocha/consts/consts.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/xml/xml_reader.h>
#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/xml/versions.h>
#include <mocha/misc/char_allocator.h>
#include <mocha/options/setting.h>
#include <mocha/options/options.h>

#define BEGIN(name) //printf("log : %s\n", #name)
#define END(name) //printf("log : %s end\n", #name)
#define IS_DEF(str) str && strlen(str) > 0

namespace mocha {

class XMLInfo {
 public :
  inline XMLInfo(const char* path) : path_(path) {}
  inline ~XMLInfo(){};
  inline const char* GetPath(){ return path_; }
 private :
  const char* path_;
};

XMLReader::~XMLReader() {
  END("XMLReader");
}

void XMLReader::Parse(const char* pathname, bool is_reparse) {
  BEGIN(Parse);
  os::fs::Path path(pathname);
  //Get absolute path of xml file.
  GetFullPath(&path);
  /*
   *If xml file is exit, start parse,
   *if not exist ignore this file and logging.
   */
  os::fs::Stat stat(path.absolute_path());
  if (stat.IsExist()) {
    ParseStart(&path);
  } else {
  }
  END(Parse);
}

bool XMLReader::CheckIgnoreOption(TiXmlElement *elem) {
  const char* ignore_attr = elem->Attribute(consts::xml_attributes::kIgnore);
  if (ignore_attr && strlen(ignore_attr) > 0 && strcmp(ignore_attr, "true") == 0) {
    return true;
  }
  return false;
}

void XMLReader::GetFullPath(os::fs::Path* path) {
  XMLSettingInfo::set_include_list(std::string(path->absolute_path()));
}


void XMLReader::ParseStart(os::fs::Path* path) {
  BEGIN(ParseStart);
  TiXmlDocument xml_document;
  xml_document.LoadFile(path->absolute_path());
  TiXmlElement* elem = xml_document.RootElement();
  XMLInfo info(path->directory());
  SwitchProcessor(elem, &info);
  END(ParseStart_);
}



void XMLReader::SwitchProcessor(TiXmlNode* node, XMLInfo* info) {
  BEGIN(Read_);
  if (node) {
    if (node->Type() == TiXmlNode::TINYXML_DOCUMENT) {
      TiXmlNode *child = node->FirstChild();
      SwitchProcessor(child, info);
    } else if (node->Type() == TiXmlNode::TINYXML_ELEMENT) {
      ProcessNode(node->ToElement(), info);
    } else {
      TiXmlNode* next = node->NextSibling();
      SwitchProcessor(next, info);
    }
  }
  END(Read_);
}



void XMLReader::ProcessNode(TiXmlElement *elem, XMLInfo* info) {
  BEGIN(ProcessNode_);
  if (strcmp(elem->Value(), consts::xml_attributes::kSettings) == 0) {
    ProcessSettingNode(elem, info);
  } else if (strcmp(elem->Value(), consts::xml_attributes::kDir) == 0) {
    ProcessDirNode(elem, info);
  } else if (strcmp(elem->Value(), consts::xml_attributes::kInclude) == 0) {
    ProcessIncludeNode(elem, info);
  }
  END(ProcessNode_);
}



void XMLReader::ProcessFileNode(TiXmlElement* elem, const char* dir, const char* module, XMLInfo* info) {
  BEGIN(ProcessFileNode_);
  //Check is ignore attr is there.
  if (CheckIgnoreOption(elem)) {
    return;
  }
  const char* filename = elem->Attribute(consts::xml_attributes::kPath);

  if (IS_DEF(filename)) {
    std::stringstream st;
    st << info->GetPath() << '/' << dir << '/' << filename;
    std::string combined_path = st.str();
    os::fs::Path path(combined_path.c_str());
    const char* normalized_path = path.absolute_path();
    FileInfoMap::UnsafeSet(normalized_path);
    FileInfo* resource = FileInfoMap::UnsafeGet(normalized_path);
    //If file exist.
    os::fs::Stat stat(normalized_path);
    if (stat.IsExist()) {
      if (IS_DEF(module)) {
        std::stringstream st;
        st << info->GetPath() << '/' << module;
        std::string module_path = st.str();
        //Processing <file module="..." /> attr.
        ProcessModuleOption(normalized_path, module_path.c_str(), resource);
      }
      //Processing <file path="..." /> attr.
      ProcessFilePath(normalized_path);
      //Processing <file deploy="..." /> attr.
      ProcessDeployOption(elem, normalized_path, dir, resource, info);
      ProcessDeployName(elem, normalized_path, dir, resource, info);
      ProcessCharset(elem, normalized_path, dir, resource, info);
      ProcessCompileOption(elem, normalized_path, dir, resource, info);
      ProcessVersion(elem, normalized_path, dir, resource, info);
    } else {
    }
  }
  END(ProcessFileNode);
}


void XMLReader::ProcessFilePath(const char* filename) {
  XMLSettingInfo::set_file_list(std::string(filename));
}


void XMLReader::ProcessModuleOption(const char* filename, const char* module, FileInfo* resource) {
  std::string buffer;
  for (int i = 0,len = strlen(module);i < len; i++) {
    if (module[ i ] == ',') {
      os::fs::Path path(buffer.c_str());
      resource->compilation_info()->SetLibDirectory(path.absolute_path());
      buffer.clear();
    } else if (isalnum(module[ i ]) || module[ i ] == '-' || module[ i ] == '_') {
      buffer += module[ i ];
    }
  }
  if (!buffer.empty()) {
    os::fs::Path path(buffer.c_str());
    resource->compilation_info()->SetLibDirectory(path.absolute_path());
  }
}


void XMLReader::ProcessDeployOption(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo *info) {
  const char* deploy_path = elem->Attribute(consts::xml_attributes::kDeploy);
  if (IS_DEF(deploy_path)) {
    std::stringstream st;
    st << info->GetPath() << '/' << dir << '/' << deploy_path;
    os::fs::Path path(st.str().c_str());
    resource->SetDeploy(path.absolute_path());
  }
}


void XMLReader::ProcessDeployName(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo *info) {
  const char* deploy_name = elem->Attribute(consts::xml_attributes::kDeployname);
  if (IS_DEF(deploy_name)) {
    std::string tmp = deploy_name;
    size_t pos = 0;
    if ((pos = tmp.find(':', 0)) != std::string::npos) {
      std::string charset = tmp.substr((pos + 1));
      std::string name = tmp.substr(0, pos);
      resource->SetOutputCharset(charset.c_str());
      resource->SetDeployName(name.c_str());
    } else {
      resource->SetDeployName(deploy_name);
    }
  }
}


void XMLReader::ProcessCharset(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo *info) {
  const char* charset = elem->Attribute(consts::xml_attributes::kCharset);
  if (IS_DEF(charset)) {
    resource->compilation_info()->SetCharset(charset);
  }
}


void XMLReader::ProcessCompileOption(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo *info) {
  const char* compile_option = elem->Attribute(consts::xml_attributes::kOptions);
  if (IS_DEF(compile_option)) {
    CompilationInfoHandle cmp_option = resource->compilation_info();
    int len = strlen(compile_option);
    std::string buf;
    ScopedStrList scoped_list;
    if (len > 0) {
      Options *option = new Options();
      for (int i = 0; i < len; ++i) {
        buf += compile_option[ i ];
        if ((compile_option[ i ] == ' ' || (i == (len - 1))) &&
             buf.find_first_not_of(' ', 0) != std::string::npos) {

          if (buf[ buf.size() - 1 ] == ' ') {
            buf.erase(buf.size() - 1, buf.size());
          }
          option->AnalyzeOption(buf.c_str());
          buf.clear();
        }
      }
      if (option->IsPrettyPrint()) {
        cmp_option->SetPrettyPrint();
      }
      if (option->IsDebug()) {
        cmp_option->SetDebug();
      }
      if (option->IsCompress()) {
        cmp_option->SetCompress();
      }
    }
  }
}

void XMLReader::ProcessVersion(TiXmlElement *elem, const char* filename, const char* dir, FileInfo* resource, XMLInfo *info) {
  const char* version_attr = elem->Attribute(consts::xml_attributes::kVersions);
  if (IS_DEF(version_attr)) {
    std::string tmp;
    for (int i = 0;version_attr[ i ];i++) {
      if (version_attr[ i ] == ' ' && tmp.size() > 0) {
        resource->compilation_info()->SetVersion(tmp.c_str());
        tmp.clear();
      } else {
        tmp += version_attr[ i ];
      }
    }
    if (tmp.size() > 0) {
      resource->compilation_info()->SetVersion(tmp.c_str());
    }
  }
}

void XMLReader::ProcessSettingNode(TiXmlElement *elem, XMLInfo* info) {
  BEGIN(ProcessSettingNode_);
  TiXmlNode *child = 0;
  while ((child = elem->IterateChildren(child))) {
    SwitchProcessor(child, info);
  }
  END(ProcessSettingNode_);
}



void XMLReader::ProcessDirNode(TiXmlElement *elem, XMLInfo* info) {
  BEGIN(ProcessDirNode_);
  const char* dir_attr = elem->Attribute(consts::xml_attributes::kPath);
  const char* module_attr = elem->Attribute(consts::xml_attributes::kModule);
  if (CheckIgnoreOption(elem)) {
    return;
  }
  TiXmlNode* child = 0;
  while ((child = elem->IterateChildren(child))) {
    if (child->Type() == TiXmlNode::TINYXML_ELEMENT) {
      if (strcmp(child->Value(), consts::xml_attributes::kFile) == 0) {
        ProcessFileNode(child->ToElement(), dir_attr, module_attr, info);
      }
    }
  }
  END(ProcessDirNode_);
}

void XMLReader::ProcessIncludeNode(TiXmlElement *elem, XMLInfo* info) {
  BEGIN(ProcessIncludeNode_);
  const char* path_attr = elem->Attribute(consts::xml_attributes::kPath);
  if (CheckIgnoreOption(elem)) {
    return;
  }
  Parse(path_attr);
  END(ProcessIncludeNode_);
}

}
