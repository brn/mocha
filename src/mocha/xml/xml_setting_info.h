#ifndef mocha_xml_utils_h_
#define mocha_xml_utils_h_

#include <list>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/xml/xml_reader.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/xml/versions.h>
#include <mocha/options/options.h>

#define ITERATOR(x) begin=x.begin(),end=x.end()
#define FILE_LIST_CALLBACK void(T::*fn)(const char*)
namespace mocha {
class XMLSettingInfo : private Static {
  friend class XMLReader;
 public :
  static void EraseData();
  template<typename T>
  inline static void IterateFileList(FILE_LIST_CALLBACK, T* thisObject);
  template<typename T>
  inline static void IterateIncludeList(FILE_LIST_CALLBACK, T* thisObject);
 private :
  typedef boost::unordered_map<std::string,std::string> Hash;
  typedef std::list<std::string> List;
  static void set_file_list(std::string path) { file_list_.push_back(path); };
  static void set_include_list(std::string path) {include_list_.push_back(path);};
  template<typename T>
  inline static void Iterate_(FILE_LIST_CALLBACK, T* thisObject, const List& list);
  static List file_list_;
  static List include_list_;
  static Hash module_list_;
};
}

#include <mocha/xml/xml_setting_info-inl.h>

#undef CALL_BACK
#undef ITERATOR

#endif
