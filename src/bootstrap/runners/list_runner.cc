#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <utils/xml/xml_setting_info.h>
#include <bootstrap/runners/list_runner.h>

namespace mocha {

inline int max( int x , int y ) {
  return ( x > y )? x : y;
}

class ListData {
  friend class ListRunner;
 public :
  ListData() : xml_max_len_( 0 ) , file_max_len_( 0 ){}
  void Collect() {
    include_list_.push_back( xml_ );
    file_list_.push_back( js_ );
    XMLSettingInfo::IterateIncludeList( &ListData::SetToXMLList , this );
    XMLSettingInfo::IterateFileList( &ListData::SetToFileList , this );
    xml_max_len_ = ( xml_max_len_ > 10 )? xml_max_len_ : 10;
    file_max_len_ = ( file_max_len_ > 10 )? file_max_len_ : 10;
  }
  void SetToXMLList( const char* path ) {
    xml_max_len_ = max( xml_max_len_ , strlen( path ) );
    include_list_.push_back( path );
  }
  
  void SetToFileList( const char* path ) {
    file_max_len_ = max( file_max_len_ , strlen( path ) );
    file_list_.push_back( path );
  }

 private :
  static const char xml_[];
  static const char js_[];
  int xml_max_len_;
  int file_max_len_;
  std::vector<std::string> include_list_;
  std::vector<std::string> file_list_;
};

const char ListData::xml_[] = "xml";
const char ListData::js_[] = "javascript";


ListRunner::ListRunner( Options *options ) : ICommandLineRunner( options ) {}

void ListRunner::Run() {
  ListData data;
  data.Collect();
  int file_size = data.file_list_.size();
  int xml_size = data.include_list_.size();
  int index = max( xml_size , file_size );
  for ( int i = 0; i < data.xml_max_len_ + 6; i++ ) {
    fprintf( stderr , "-" );
  }
  for ( int i = 0; i < data.file_max_len_ + 5; i++ ) {
    fprintf( stderr , "-" );
  }
  fprintf( stderr , "\n" );
  for ( int i = 0; i < index; i++ ) {
    fprintf( stderr , "|" );
    if ( xml_size > i ) {
      int diff = data.xml_max_len_ - data.include_list_[ i ].size();
      int mod = diff % 2;
      diff = ( diff > 1 )? diff / 2 : diff;
      for ( int j = 0; j < diff ; j++ ) {
        fprintf( stderr , " " );
      }
      fprintf( stderr , "  %s  " , data.include_list_[ i ].c_str() );
      for ( int j = 0; j < diff + mod ; j++ ) {
        fprintf( stderr , " " );
      }
    } else {
      for ( int j = 0; j < data.xml_max_len_ + 4; j++ ) {
        fprintf( stderr , " " );
      }
    }
    fprintf( stderr , "|" );
    if ( file_size > i ) {
      int diff = data.file_max_len_ - data.file_list_[ i ].size();
      int mod = diff % 2;
      diff = ( diff > 1 )? diff / 2 : diff;
      for ( int j = 0; j < diff ; j++ ) {
        fprintf( stderr , " " );
      }
      fprintf( stderr , "  %s  " , data.file_list_[ i ].c_str() );
      for ( int j = 0; j < diff + mod ; j++ ) {
        fprintf( stderr , " " );
      }
      if ( i == 0 ) {
        fprintf( stderr , "|" );
        fprintf( stderr , "\n|" );
        for ( int j = 0; j < data.xml_max_len_ + 4; j++ ) {
          fprintf( stderr , "-" );
        }
        fprintf( stderr , "|" );
        for ( int j = 0; j < data.file_max_len_ + 4; j++ ) {
          fprintf( stderr , "-" );
        }
      }
    } else {
      for ( int j = 0; j < data.file_max_len_ + 4; j++ ) {
        fprintf( stderr , " " );
      }
    }
    fprintf( stderr , "|" );
    fprintf( stderr , "\n" );
  }
  for ( int i = 0; i < ( data.xml_max_len_ + data.file_max_len_ + 11 ); i++ ) {
    fprintf( stderr , "-" );
  }
  fprintf( stderr , "\n" );
}
}
