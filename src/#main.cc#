#include "bootstrap.h"
#include "file_watcher.h"
#include "file_system.h"

class Test : public mocha::IUpdater{
  void Update( mocha::watch_traits::Modify* modify ) {
    printf( "update %s\n" , modify->filename );
  }
};

int main ( int argc , char **argv ) {
  printf("start\n");
  mocha::Bootstrap::Initialize( argc , argv );
  mocha::FileWatcher watch;
  
  return 0;
}
