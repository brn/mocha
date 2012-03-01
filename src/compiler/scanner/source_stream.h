#ifndef mocha_source_stream_h_
#define mocha_source_stream_h_
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/pool/managed.h>
#include <utils/int_types.h>
#include <compiler/tokens/js_token.h>
namespace mocha {

class SourceStream : public Managed {
 public :
  static SourceStream* New( const char* source , const char* path );
  ~SourceStream();
  StrHandle GetSourceFragment( int begin_col , int end_col , int row );
  int Size() const;
  char At( int index ) const;
  char Advance( int index = 1 );
  char Undo( int index = 0 );
  char Seek( int index ) const;
  char Last() const;
  char First() const;
 private :
  SourceStream();
  void CreateStream( const char* utf8_str );
  int cursor_;
  int line_;
  int size_;
  char *stream_;
};
}

#endif
