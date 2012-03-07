#ifndef mocha_int_types_h_
#define mocha_int_types_h_

#include <stdio.h>

#if defined(_MSC_VER) && (_MSC_VER < 1600) && !defined(__MINGW32__)

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;  // NOLINT
typedef unsigned short uint16_t;  // NOLINT
typedef int int32_t;
typedef unsigned int uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

#define INT8_MAX CHAR_MAX
#define INT8_MIN CHAR_MIN
#define UINT8_MAX UCHAR_MAX
#define INT16_MAX SHRT_MAX
#define INT16_MIN SHRT_MIN
#define UINT16_MAX SHORT_MAX
#define INT32_MAX INT_MAX
#define INT32_MIN INT_MIN
#define UINT32_MAX UINT_MAX
#define INT64_MAX _I64_MAX
#define INT64_MIN _I64_MIN
#define UINT64_MAX _UI64_MAX

// intptr_t and friends are defined in crtdefs.h through stdio.h.
#include <crtdefs.h>
#else


#include <stdint.h>

#endif

#endif  // mocha_int_types_h_
