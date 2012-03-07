#line 1 "..\\..\\..\\src\\mocha\\roaster\\consts\\consts.cc"
#line 1 "Y:\\mocha\\src\\mocha/roaster/consts/consts.h"



namespace mocha {

class Consts {
 public :
  static const char kDefaultInputCharset[];
  static const char kDefaultOutputCharset[];
  static const char kVersionAll[];
  static const char kVersionNone[];
  static const char kVersionDebug[];
};

}

#line 18 "Y:\\mocha\\src\\mocha/roaster/consts/consts.h"
#line 2 "..\\..\\..\\src\\mocha\\roaster\\consts\\consts.cc"

namespace mocha {

const char Consts::kDefaultInputCharset[] = {"UTF-8"};
const char Consts::kDefaultOutputCharset[] = {"UTF-8"};
const char Consts::kVersionAll[] = {"all"};
const char Consts::kVersionNone[] = {"none"};
const char Consts::kVersionDebug[] = {"debug"};
}
