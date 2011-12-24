#include <stdio.h>
#include <stdarg.h>
#include <utils/format.h>

namespace mocha {

void Format( char* buf , const char* format , ... ) {
  va_list ap;
  va_start(ap, format);
  vsprintf(buf, format, ap);
  va_end(ap);
}

}
