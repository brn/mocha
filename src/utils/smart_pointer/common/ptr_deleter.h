
#ifndef mocha_ptr_deleter_h_
#define mocha_ptr_deleter_h_

#include <stdio.h>
#include <stdlib.h>
#include <utils/class_traits/static.h>

namespace mocha {
  
  template <typename T>
  struct PtrDeleter : private Static {
    inline static void Delete ( T* ptr  ) {
      delete ptr;
    };
    inline static void DeleteArray ( T* ptr ) {
      delete [] ptr;
    }
    inline static void Free ( T* ptr ) {
      free ( ptr );
    }
  };
};

#endif


