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
#ifndef mocha_roaster_nexc_scanner_source_stream_h_
#define mocha_roaster_nexc_scanner_source_stream_h_
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
namespace mocha {
class CompilationInfo;
class SourceStream : public memory::Allocated {
 public :
  static SourceStream* New(const char* source, const char* path, const char* charset, memory::Pool* pool);
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
