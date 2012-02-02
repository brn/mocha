#ifndef mocha_atomic_h_
#define mocha_atomic_h_

#if !defined _WIN32
#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
#include <ext/atomicity.h>
#else
#include <bits/atomicity.h>
#endif
#define EXCHANGE_INC( val , i ) __gnu_cxx::__exchange_and_add( val , i )
#define EXCHANGE_DEC( val , i ) __gnu_cxx::__exchange_and_add( val , -i )
typedef _Atomic_word AtomicWord;
#elif defined _WIN32 || defined __MINGW32__
#include <windows.h>
#define EXCHANGE_INC( val , i ) ::InterlockedExchangeAdd( val , i )
#define EXCHANGE_DEC( val , i ) ::InterlockedExchangeAdd( val , -i )
typedef LPLONG AtomicWord;
#endif

#include <utils/class_traits/static.h>

namespace mocha {

class Atomic : private Static {
public :
  inline static AtomicWord Increment( AtomicWord *count , int inc = 1 ) {
    return EXCHANGE_INC( count , inc ) + 1;
  }

  inline static AtomicWord Decrement( AtomicWord *count , int dec = 1 ) {
    return EXCHANGE_DEC( count, dec ) - 1;
  }
};
}

#endif
