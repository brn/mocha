#ifndef mocha_pwd_h_
#define mocha_pwd_h_

#include <cstddef>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>

#define GW_BUF_SIZE 1000

namespace mocha {
#ifdef _WIN32
SharedStr ReplaceBackSlash( const char* path );
#endif
SharedStr GetCwd();
};

#endif

