#ifndef mocha_source_stream_h_
#define mocha_source_stream_h_
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/pool/managed.h>
#include <utils/int_types.h>
#include <mocha/roaster/tokens/js_token.h>
namespace mocha {

class SourceStream : public Managed {
 public :
  static SourceStream* New( const char* source , const char* path );
  ~SourceStream();
  StrHandle GetSourceFragment( int begin_col , int end_col , int row );
  int Size() const;
  uint8_t At( int index ) const;
  uint8_t Advance( int index = 1 );
  uint8_t Undo( int index = 0 );
  uint8_t Seek( int index ) const;
  uint8_t Last() const;
  uint8_t First() const;
 private :
  SourceStream();
  void CreateStream( const char* utf8_str );
  int cursor_;
  int line_;
  int size_;
  uint8_t *stream_;
};
}

#endif