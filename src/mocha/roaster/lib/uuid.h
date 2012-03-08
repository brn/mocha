#ifndef mocha_lib_uuid_h_
#define mocha_lib_uuid_h_
#include <useconfig.h>
#if defined HAVE_BOOST_UUID_UUID_HPP
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
namespace mocha {
namespace roastlib {
using boost::uuids::basic_random_generator;
using boost::mt19937;
using boost::uuids::uuid;
}
}
#endif

#endif
