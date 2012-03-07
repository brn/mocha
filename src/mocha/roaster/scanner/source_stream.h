#ifndef mocha_source_stream_h_
#define mocha_source_stream_h_
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/misc/int_types.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class CompilationInfo;
class SourceStream : public memory::Allocated {
 public :
  static SourceStream* New(const char* source, const char* path, const CompilationInfo* info);
  ~SourceStream();
  int Size() const;
  uint8_t At(int index) const;
  uint8_t Advance(int index = 1);
  uint8_t Undo(int index = 0);
  uint8_t Seek(int index) const;
  uint8_t Last() const;
  uint8_t First() const;
 private :
  SourceStream();
  void CreateStream(const char* utf8_str);
  int cursor_;
  int line_;
  int size_;
  uint8_t *stream_;
};
}

#endif
