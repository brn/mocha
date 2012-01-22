#include <stdlib.h>
#include <string.h>
#include <compiler/scanner/source_stream.h>
#include <compiler/encoding/encoding.h>
#include <utils/pool/managed_handle.h>
#include <utils/smart_pointer/common/ptr_deleter.h>
#include <options/setting.h>
#include <utils/xml/xml_setting_info.h>
namespace mocha {

void Encode( const char* source , const char* path , std::string *buf ) {
  if ( !XMLSettingInfo::HasCharset( path ) ) {
    Handle<DetectResult> detected = ICUWrapper::GetEncode( source );
    StrHandle data = ICUWrapper::EncodeToUtf8( source , detected->charset );
    buf->assign( data.Get() );
  } else {
    StrHandle charset = XMLSettingInfo::GetCharset( path );
    StrHandle data = ICUWrapper::EncodeToUtf8( source , charset.Get() );
    buf->assign( data.Get() );
  }
}

SourceStream* SourceStream::Create( const char* source , const char* path ) {
  std::string buf;
  Encode( source , path , &buf );
  SourceStream* stream = ManagedHandle::Retain( new SourceStream() );
  stream->CreateStream_( buf.c_str() );
  return stream;
}


SourceStream::SourceStream() : cursor_( -1 ) , line_( 1 ) , size_( 0 ){};


SourceStream::~SourceStream() {
  free( stream_ );
}


void SourceStream::CreateStream_( const char* utf8_str ) {
  int size = strlen( utf8_str );
  int count = 0;
  stream_ = reinterpret_cast<uint8_t*>( malloc( sizeof( uint8_t ) * size ) );
  for ( int i = 0; i < size; i++ ) {
    if ( utf8_str[ i ] == '\n' ) line_++;
    if ( utf8_str[ i ] != '\r' ) {
      stream_[ count ] = utf8_str[ i ];
      count++;
    }
  }
  size_ = count;
  stream_[ count ] = '\0';
}


uint8_t SourceStream::At( int index ) const {
  return ( index > 0 && index < size_ )? stream_[ index ] : ( index < 0 )? Token::ILLEGAL : Token::END_OF_INPUT;
}


uint8_t SourceStream::Advance( int index ) {
  if ( index < 0 ) return Token::ILLEGAL;
  if ( cursor_ == size_ ) {
    cursor_++;
    return Token::END_OF_INPUT;
  } else {
    cursor_ += index;
    uint8_t ret = stream_[ cursor_ ];
    return ret;
  }
}


uint8_t SourceStream::Undo( int index ) {
  if ( index < 0 ) return Token::ILLEGAL;
  int i = 0;
  for ( ; i < index; i++ ) {}
  cursor_ -= i;
  return ( cursor_ > 0 && size_ > 0 )? stream_[ cursor_ ] : Token::ILLEGAL;
}


uint8_t SourceStream::Seek( int index ) const {
  int i = 0,pos = 0;
  if ( index > 0 ) {
    for ( ; i < index; i++ ) {}
  } else {
    for ( ; i > index; i-- ) {}
  }
  pos = cursor_ + i;
  if ( pos < size_ ) {
    return stream_[ pos ];
  }
  return Token::END_OF_INPUT;
}


uint8_t SourceStream::Last() const {
  return stream_[ size_ - 1 ];
}


uint8_t SourceStream::First() const {
  return stream_[ 0 ];
}


int SourceStream::Size() const { return size_; }


Handle<uint8_t> SourceStream::GetSourceFragment( int begin_col , int end_col , int row ) {
  if ( line_ >= row ) {
    int line = 1;
    int begin = 0;
    int end = 0;
    for ( int i = 0; i < size_; i++ ) {
      if ( stream_[ i ] == '\n' ) {
        end = i + 1;
        if ( line == row ) {
          int size = ( end - begin );
          uint8_t *ret = reinterpret_cast<uint8_t*>( malloc( sizeof( uint8_t ) * ( size + 1 ) ) );
          memcpy( ret , stream_ + begin , size - 1 );
          ret[ size ] = 0;
          return Handle<uint8_t>( ret , PtrDeleter<uint8_t>::Free );
        }
        begin = i + 1;
        line++;
      }
    }
  } else {
    return Handle<uint8_t>( new uint8_t[0] , PtrDeleter<uint8_t>::DeleteArray );
  }
}

}
