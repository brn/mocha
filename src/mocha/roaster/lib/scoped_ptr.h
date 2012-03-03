#ifndef mocha_lib_shared_ptr_h_
#define mocha_lib_shared_ptr_h_

#if defined HAVE_BOOST_SCOPED_PTR_HPP
#include <boost/scoped_ptr.hpp>
namespace mocha {
namespace roastlib {
using boost::scoped_ptr;
}
}
#endif

#endif
