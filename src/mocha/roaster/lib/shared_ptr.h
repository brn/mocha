#ifndef mocha_lib_shared_ptr_h_
#define mocha_lib_shared_ptr_h_

#if defined HAVE_SHARED_PTR_H
#include <shared_ptr>
namespace mocha {
namespace roastlib {
using std::shared_ptr;
}
}
#elif defined HAVE_BOOST_SHARED_PTR_HPP
#include <boost/shared_ptr.h>
namespace mocha {
namespace roastlib {
using std::scoped_ptr;
}
}
#endif

#endif
