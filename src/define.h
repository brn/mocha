
#ifndef define_h
#define define_h

#include <string>

#if defined __GNUC__
#define JPM_CONST __attribute__((const))
#define JPM_PURE __attribute__ ((pure))
#else
#define JPM_CONST
#define JPM_PURE
#endif

namespace mocha {

  typedef std::string::const_iterator CSTIter;
  typedef std::string STR;

}

#endif

