
#ifndef define_h
#define define_h

#include <string>

#if defined __GNUC__
#define JPM_CONST __attribute__((const))
#define JPM_PURE __attribute__ ((pure))
#define JPM_INLINE __attribute__((flatten))
#else
#define JPM_CONST
#define JPM_PURE
#define JPM_INLINE
#endif

#endif

