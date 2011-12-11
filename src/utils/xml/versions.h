#ifndef mocha_versions_h_
#define mocha_versions_h_

#include <boost/unordered_map.hpp>

namespace mocha {
class Version {
 public :
  Version();
  inline ~Version(){};
  void Add( const char* ver );
  bool Get( const char* ver );
  void Debug();
 private :
  typedef boost::unordered_map<std::string,int> VersionContainer;
  VersionContainer container_;
};
}

#endif
