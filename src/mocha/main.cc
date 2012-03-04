#include <mocha/bootstrap/bootstrap.h>
#include <utils/file_watcher/file_watcher.h>
#include <utils/file_system/file_system.h>

int main ( int argc , char **argv ) {
  mocha::Bootstrap::Initialize( argc , argv );
  return 0;
}
