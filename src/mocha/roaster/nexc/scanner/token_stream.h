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
#ifndef mocha_scanner_token_stream_h_
#define mocha_scanner_token_stream_h_
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class TokenContainer;
class TokenInfo;
class TokenStream : public memory::Allocated {
 public :
  ~TokenStream();
  static TokenStream* New(memory::Pool* pool);
  TokenInfo* Advance(int index = 1);
  TokenInfo* Seek(int index);
  TokenInfo* Undo(int index = 0);
  void Append(const char* token, int type, int64_t line);  
  int size() const { return size_; }
  TokenInfo* last() const;
  TokenInfo* first() const;
  static TokenInfo* kEmpty;
 private :
  TokenStream();
  memory::Pool* pool() { return pool_; }
  int cursor_;
  int size_;
  TokenContainer* current_;
  TokenContainer* first_;
  TokenContainer* last_;
  memory::Pool* pool_;
};

}

#endif
