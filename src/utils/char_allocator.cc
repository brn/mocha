#include <string.h>
#include <stdlib.h>
#include <string>
#include <utils/char_allocator.h>

namespace mocha {
namespace utils {
char* CharAlloc( const char* target , size_t length ) {
  std::string tmp = target;
  char *buf = new char[ tmp.size() + 1 ];
  strcpy( buf  , target );
  return buf;
}
}
}
