#ifndef mocha_xml_options_h_
#define mocha_xml_options_h_

#include <mocha/options/options.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>

namespace mocha {
class XMLOptions {
 public :
  XMLOptions() :
      options_ ( new Options ){}
  inline Options* operator -> () { return options_.Get(); }
 private :
  ScopedPtr<Options> options_;
};
}

#endif //mocha_xml_options_h_
