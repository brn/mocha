#include <stdlib.h>
#include <string.h>
#include <mocha/roaster/scanner/source_stream.h>
#include <mocha/roaster/encoding/encoding.h>
#include <mocha/roaster/smart_pointer/common/ptr_deleter.h>
#include <mocha/options/setting.h>
#include <mocha/xml/xml_setting_info.h>
namespace mocha {

SharedStr Encode(const char* source, const char* path, const CompilationInfo* info) {
  if (!info->HasCharset()) {
    SharedPtr<DetectResult> detected = ICUWrapper::GetEncode(source);
    SharedStr data = ICUWrapper::EncodeToUtf8(source, detected->charset);
    return data;
  } else {
    const char* charset = info->charset();
    SharedStr data = ICUWrapper::EncodeToUtf8(source, charset);
    return data;
  }
}

SourceStream* SourceStream::New(const char* source, const char* path, const CompilationInfo* info) {
  SharedStr str_handle = Encode(source, path, info);
  SourceStream* stream = new(memory::Pool::Local()) SourceStream();
  stream->CreateStream(str_handle.Get());
  return stream;
}


SourceStream::SourceStream() : cursor_(-1), line_(1), size_(0){};


SourceStream::~SourceStream() {
  free(stream_);
}


void SourceStream::CreateStream(const char* utf8_str) {
  int size = strlen(utf8_str);
  int count = 0;
  stream_ = reinterpret_cast<uint8_t*>(malloc(sizeof(uint8_t) * size + sizeof(uint8_t)));
  for (int i = 0; i < size; i++) {
    if (utf8_str[ i ] == '\n') line_++;
    if (utf8_str[ i ] != '\r') {
      stream_[ count ] = utf8_str[ i ];
      count++;
    }
  }
  size_ = count;
  stream_[ count ] = '\0';
}


uint8_t SourceStream::At(int index) const {
  return (index > 0 && index < size_)? stream_[ index ] : (index < 0)? Token::ILLEGAL : Token::END_OF_INPUT;
}


uint8_t SourceStream::Advance(int index) {
  if (index < 0) return Token::ILLEGAL;
  if (cursor_ == size_) {
    cursor_++;
    return Token::END_OF_INPUT;
  } else {
    cursor_ += index;
    char ret = stream_[ cursor_ ];
    return ret;
  }
}


uint8_t SourceStream::Undo(int index) {
  if (index < 0) return Token::ILLEGAL;
  int i = 0;
  for (; i < index; i++) {}
  cursor_ -= i;
  return (cursor_ > 0 && size_ > 0)? stream_[ cursor_ ] : Token::ILLEGAL;
}


uint8_t SourceStream::Seek(int index) const {
  int i = 0,pos = 0;
  if (index > 0) {
    for (; i < index; i++) {}
  } else {
    for (; i > index; i--) {}
  }
  pos = cursor_ + i;
  if (pos < size_) {
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

}
