
#ifndef PtrDeleter_h
#define PtrDeleter_h

#include <stdio.h>
#include <stdlib.h>
#include "static.h"

namespace mocha {
  
  template <typename T>
  struct PtrDeleter : private Static {
    inline static void Delete ( T* ptr  ) {
      //const char* name = typeid ( (*ptr) ).name ();
      //printf ( "n %s\n" , name );
      delete ptr;
      //printf ( "n %s\n" , name );
    };
    inline static void DeleteArray ( T* ptr ) {
      //printf ( "[] %s\n" , typeid ( (*ptr) ).name () );
      delete [] ptr;
    }
    inline static void Free ( T* ptr ) {
      //printf ( "free %s\n" , typeid ( (*ptr) ).name () );
      free ( ptr );
    }
  };
};

#endif


