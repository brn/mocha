
#ifndef PtrDeleter_h
#define PtrDeleter_h

#include <stdlib.h>
#include "static.h"

#include <stdio.h>

namespace mocha {
  
  template <typename T>
  struct PtrDeleter : private Static {
    inline static void deleter ( T* ptr  ) {
      //const char* name = typeid ( (*ptr) ).name ();
      //printf ( "n %s\n" , name );
      delete ptr;
      //printf ( "n %s\n" , name );
    };
    inline static void deleterArray ( T* ptr ) {
      //printf ( "[] %s\n" , typeid ( (*ptr) ).name () );
      delete [] ptr;
    }
    inline static void freePtr ( T* ptr ) {
      //printf ( "free %s\n" , typeid ( (*ptr) ).name () );
      free ( ptr );
    }
  };
};

#endif


