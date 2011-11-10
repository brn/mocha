#ifndef test__h__
#define test__h__
#include <stdlib.h>
#include <string.h>
#include "scoped_list.h"
namespace mocha {
class Test {
 public :
  Test() {
    char f[] = "test";
    char* x = new char[ strlen(f) + 1 ];
    strcpy(x,f);
    handle.Retain(x);
    x_ = x;
  }
  const char* test1() {
    return x_;
  }
 private :
  char* x_;
  ScopedStrList handle;
};
}

#endif
