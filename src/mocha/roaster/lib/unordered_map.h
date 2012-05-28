#ifndef mocha_utils_unordered_map_h_
#define mocha_utils_unordered_map_h_
#ifdef HAVE_UNORDERED_MAP_H
#include <unordered_map>
namespace mocha {
namespace roastlib {
using std::unordered_map;
using std::unordered_multimap;
}
}
#else
#include <boost/unordered_map.hpp>
namespace mocha {
namespace roastlib {
using boost::unordered_map;
using boost::unordered_multimap;
}
}

#endif
#endif
