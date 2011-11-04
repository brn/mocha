#include <string.h>
#include "thread.h"
#include "observer.h"
#include "file_io.h"
namespace mocha {

void* Observer::Run_( void* arg ) {
  fprintf(stderr, "file o = %ld\n" , pthread_self() );
  ArgsHolder *holder = (reinterpret_cast<ArgsHolder*>( arg ) );
  List &list = holder->GetList();
  holder->GetObserver()->is_stop_ = false;
  while ( 1 && holder->GetObserver()->is_stop_ == false ) {
    List::iterator begin = list.begin();
    List::iterator end = list.end();
    while ( begin != end && !holder->GetObserver()->is_stop_ ) {
      Handle<File> file = FileIO::Open( begin->first.c_str() , "r" );
      printf( "%d %s %s %s\n" , file->getSize(),file->getFileName() , file->getDate( File::kUpdate ).get() , begin->second.get() );
      if ( !holder->GetObserver()->is_stop_ && strcmp( file->getDate( File::kUpdate ).get() , begin->second.get() ) != 0 ) {
        holder->GetObserver()->Update_( file );
        file->close();
      }
      ++begin;
    }
    sleep( 1 );
  }
  delete holder;
}

}
