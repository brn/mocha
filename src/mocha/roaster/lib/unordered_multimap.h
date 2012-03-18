#ifndef mocha_utils_unordered_map_h_
#define mocha_utils_unordered_map_h_
#ifdef HAVE_UNORDERED_MULTIMAP_H
#include <unordered_multimap>
namespace mocha {
namespace roastlib {
using std::unordered_map;
}
}
#else
#include <boost/unordered_multimap.hpp>
namespace mocha {
namespace roastlib {
using boost::unordered_multimap;
}
}

#endif
#endif
