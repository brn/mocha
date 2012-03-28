/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#include <stdlib.h>
#include <string.h>
#include <mocha/roaster/smart_pointer/common/ptr_deleter.h>
#include <mocha/roaster/nexc/scanner/source_stream.h>
#include <mocha/roaster/nexc/scanner/encoding/encoding.h>
namespace mocha {

SharedStr Encode(const char* source, const char* charset) {
  if (charset == NULL) {
    SharedPtr<DetectResult> detected = ICUWrapper::GetEncode(source);
    SharedStr data = ICUWrapper::EncodeToUtf8(source, detected->charset);
    return data;
  } else {
    SharedStr data = ICUWrapper::EncodeToUtf8(source, charset);
    return data;
  }
}

SourceStream* SourceStream::New(const char* source, const char* path, const char* charset, memory::Pool* pool) {
  SharedStr str_handle = Encode(source, charset);
  SourceStream* stream = new(pool) SourceStream();
  stream->CreateStream(str_handle.Get());
  return stream;
}


SourceStream::SourceStream()
  : cursor_(-1),
    line_(1),
    size_(0){};


SourceStream::~SourceStream() {
  free(stream_);
}


void SourceStream::CreateStream(const char* utf8_str) {
  int size = strlen(utf8_str);
  int count = 0;
  stream_ = reinterpret_cast<int*>(malloc(sizeof(int) * size + sizeof(int)));
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


int SourceStream::At(int index) const {
  return (index > 0 && index < size_)? stream_[ index ] : (index < 0)? Token::ILLEGAL : Token::END_OF_INPUT;
}


int SourceStream::Advance(int index) {
  if (index < 0) return Token::ILLEGAL;
  if (cursor_ >= size_) {
    cursor_++;
    return Token::END_OF_INPUT;
  } else {
    cursor_ += index;
    int ret = stream_[ cursor_ ];
    return ret;
  }
}


int SourceStream::Undo(int index) {
  if (index < 0) return Token::ILLEGAL;
  int i = 0;
  for (; i < index; i++) {}
  cursor_ -= i;
  return (cursor_ > 0 && size_ > 0)? stream_[ cursor_ ] : Token::ILLEGAL;
}


int SourceStream::Seek(int index) const {
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


int SourceStream::Last() const {
  return stream_[ size_ - 1 ];
}


int SourceStream::First() const {
  return stream_[ 0 ];
}


int SourceStream::Size() const { return size_; }

}
