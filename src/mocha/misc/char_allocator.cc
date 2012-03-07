#include <string.h>
#include <stdlib.h>
#include <string>
#include <mocha/misc/char_allocator.h>

namespace mocha {
namespace utils {
char* CharAlloc(const char* target, size_t length) {
  char *buf = new char[ strlen(target) + 1 ];
  strcpy(buf , target);
  return buf;
}
}
}
