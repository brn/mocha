#ifndef mocha_pwd_h_
#define mocha_pwd_h_

#include <cstddef>
#include <utils/smart_pointer/ref_count/handle.h>

#define GW_BUF_SIZE 1000

namespace mocha {
#ifdef _WIN32
StrHandle ReplaceBackSlash( const char* path );
#endif
StrHandle GetCwd();
};

#endif

