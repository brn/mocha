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
#include <mocha/roaster/nexc/scanner/token_stream.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/misc/int_types.h>

namespace mocha {

static const int max_element = 6;

class TokenContainer : public memory::Allocated {
 public :
  TokenContainer(const char* token, int type, int64_t line, memory::Pool* pool)
      :  size(0),
         next(0),
         prev(0) {
    Push(token, type, line, pool);
  }
  
  void Push(const char* token, int type, int64_t line, memory::Pool* pool) {
    TokenInfo* info = new(pool) TokenInfo(token, type, line);
    array[ size ] = reinterpret_cast<uintptr_t>(info);
    size++;
  }

  TokenInfo* Get(int index) {
    return reinterpret_cast<TokenInfo*>(array[index]);
  }
                                
  int size;
  TokenContainer* next;
  TokenContainer* prev;

 private :
  uintptr_t array[max_element];
};


TokenStream* TokenStream::New(memory::Pool* pool) {
  return new(pool) TokenStream();
}

TokenStream::TokenStream()
    : cursor_(0),
      size_(0),
      current_(0),
      first_(0),
      last_(0),
      pool_(memory::Pool::Local()){};

TokenStream::~TokenStream() {};

TokenInfo* TokenStream::Advance(int index) {
  if (index < 1) return 0;
  int count = cursor_;
  TokenContainer* tmp = current_;
  TokenInfo* ret;
  for (int i = 0; i < index; i++) {
    if (count == current_->size) {
      current_ = current_->next;
      if (current_ == 0) {
        current_ = tmp;
        return kEmpty;
      } else {
        count = 0;
      }
    }
    ret = current_->Get(count);
    count++;
  }
  cursor_ = count;
  return ret;
}



void TokenStream::Append(const char* token, int type, int64_t line) {
  if (first_ == 0) {
    first_ = new(pool()) TokenContainer(token, type, line, pool());
    current_ = last_ = first_;
  } else {
    if (first_->size < max_element) {
      last_->Push(token, type, line, pool());
    } else {
      TokenContainer* tmp = new(pool()) TokenContainer(token, type, line, pool());
      last_->next = tmp;
      tmp->prev = last_;
      last_ = tmp;
    }
  }
  size_++;
}


TokenInfo* TokenStream::Undo(int index) {
  if (index < 0) return kEmpty;
  int count = cursor_;
  TokenContainer* tmp = current_;
  TokenInfo* ret;
  for (int i = 0; i < index; i++) {
    if (count < 0) {
      current_ = current_->prev;
      if (current_ == 0) {
        current_ = tmp;
        return kEmpty;
      } else {
        count = current_->size;
      }
    }
    count--;
    ret = current_->Get(count);
  }
  cursor_ = count;
  return ret;
}


TokenInfo* TokenStream::Seek(int index) {
  int cursor = cursor_;
  TokenContainer* tmp = current_;
  TokenInfo* info = (index > 0)? Advance(index) : Undo((-1 * index));
  current_ = tmp;
  cursor_ = cursor;
  return info;
}

TokenInfo* TokenStream::first() const {
  if (first_) {
    return first_->Get(0);
  }
  return 0;
}

TokenInfo* TokenStream::last() const {
  if (last_) {
    return last_->Get(last_->size - 1);
  }
  return 0;
}

TokenInfo* TokenStream::kEmpty = 0;

}
