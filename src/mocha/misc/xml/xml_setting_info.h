#ifndef mocha_xml_utils_h_
#define mocha_xml_utils_h_

#include <list>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/misc/xml/xml_reader.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/xml/versions.h>
#include <mocha/options/options.h>

#define CALL_BACK void(T::*fn)(const char*)
#define ITERATOR(x) begin=x.begin(),end=x.end()

namespace mocha {
class XMLSettingInfo : private Static {
  friend class XMLReader;
 public :
  static void EraseData();
  template<typename T>
  inline static void IterateFileList(CALL_BACK, T* thisObject);
  template<typename T>
  inline static void IterateIncludeList(CALL_BACK, T* thisObject);
 private :
  typedef boost::unordered_map<std::string,std::string> Hash;
  typedef std::list<std::string> List;
  template<typename T>
  inline static void Iterate_(CALL_BACK, T* thisObject, const List& list);
  static List file_list_;
  static List include_list_;
  static Hash module_list_;
};
}

#include <mocha/misc/xml/xml_setting_info-inl.h>

#undef CALL_BACK
#undef ITERATOR

#endif
