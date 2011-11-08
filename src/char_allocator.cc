#include <string.h>
#include <stdlib.h>
#include "char_allocator.h"

namespace mocha {
namespace utils {
char* CharAlloc( const char* target , size_t length ) {
  size_t len = ( length == 0 )? strlen( target ) : length;
  char *buf = new char[ len + 1 ];
  strcpy( buf  , target );
  return buf;
}
}
}
