#ifndef mocha_xml_setting_info_h_
#define mocha_xml_setting_info_h_

namespace mocha {

template<typename T>
inline void XMLSettingInfo::IterateFileList( CALL_BACK , T* thisObject ) {
  Iterate_<T>( fn , thisObject , XMLSettingInfo::file_list_ );
};
  
template<typename T>
inline void XMLSettingInfo::IterateIncludeList( CALL_BACK , T* thisObject ) {
  Iterate_<T>( fn , thisObject , XMLSettingInfo::include_list_ );
};

template<typename T>
inline void XMLSettingInfo::Iterate_( CALL_BACK , T* thisObject , const XMLSettingInfo::List& list ) {
  List::const_iterator ITERATOR(list);
  while ( begin != end ) {
    (thisObject->*fn)( (*begin).c_str() );
    ++begin;
  }
}

}

#endif
