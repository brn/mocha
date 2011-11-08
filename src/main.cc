#include "bootstrap.h"
#include "file_watcher.h"
#include "file_system.h"
#include "test.h"

void test_(){
  mocha::Test h;
  const char* x = h.test1();
  printf( "%s\n" , x );
}

int main ( int argc , char **argv ) {
  printf("start\n");
  //test_();
  mocha::Bootstrap::Initialize( argc , argv );
  mocha::FileWatcher watch;
  
  return 0;
}
