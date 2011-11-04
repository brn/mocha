#ifndef mocha_xml_utils_h_
#define mocha_xml_utils_h_

#include <list>
#include "static.h"
#include "xml_reader.h"
#include "handle.h"

#define CALL_BACK void( T::*fn )( const char* )
#define ITERATOR(x) begin=x.begin(),end=x.end()

namespace mocha {
class XMLSettingInfo : private Static {
  friend class XMLReader;
 public :
  static void EraseData();
  static const char* GetModuleDirPath( const char* filename );
  static StrHandle GetDeployPath( const char* filename );
  template<typename T>
  inline static void IterateFileList( CALL_BACK , T* thisObject );
  template<typename T>
  inline static void IterateIncludeList( CALL_BACK , T* thisObject );
 private :
  template<typename T>
  inline static void Iterate_( CALL_BACK , T* thisObject , const std::list<const char*>& list );
  static StrHandle GetCmpPath_( const char* filename );
  typedef boost::unordered_map<std::string,std::string> Hash;
  typedef std::list<const char*> List;
  static List file_list_;
  static List include_list_;
  static Hash module_list_;
  static Hash deploy_list_; 
};
}

#include "xml_setting_info-inl.h"

#undef CALL_BACK
#undef ITERATOR

#endif
