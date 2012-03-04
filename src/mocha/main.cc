#include <mocha/bootstrap/bootstrap.h>
#include <mocha/misc/file_watcher/file_watcher.h>
#include <mocha/misc/file_system/file_system.h>

int main ( int argc , char **argv ) {
  mocha::Bootstrap::Initialize( argc , argv );
  return 0;
}
