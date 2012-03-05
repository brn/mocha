#ifndef mocha_roaster_lib_function_h_
#define mocha_roaster_lib_function_h_
#include <useconfig.h>
#if defined HAVE_FUNCTION_H
#include <function>
namespace mocha {
namespace roastlib {
using std::function;
}
}
#elif defined HAVE_BOOST_FUNCTION_HPP
#include <boost/function.hpp>
namespace mocha {
namespace roastlib {
using boost::function;
}
}
#endif
#endif
