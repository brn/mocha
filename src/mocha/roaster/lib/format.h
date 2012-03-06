#ifndef mocha_utils_formal_h_
#define mocha_utils_formal_h_
#include <useconfig.h>
#ifdef HAVE_BOOST_FORMAT_HPP
#include <boost/format.hpp>
namespace mocha {
namespace roastlib {
using boost::format;
}
}

#endif
#endif
