#ifndef mocha_scope_release_h_
#define mocha_scope_release_h_
#include <stdlib.h>
#include <stdio.h>
namespace mocha {
namespace ptr_release {
template <typename T>
inline void Release ( T* ptr ) { delete ptr; }
template <typename T>
inline void ReleaseArray ( T* ptr ) { delete[] ptr; }
template <typename T>
inline void Free ( T* ptr ) {free ( ptr ); }
};
}
#endif
