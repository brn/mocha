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
#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace memory {
//Check alignment.
size_t Pool::Align(size_t siz, size_t alignment) {
  return (siz + (alignment - 1)) & ~(alignment - 1);
}

//Free all allocated block.
void Pool::Free() {
  //Call Allocated destructor.
  //Not free.
  if (head_) {
    Allocated* block = head_;
    Allocated* next = block->next_;
    while (1) {
      //Call virtual destructor.
      block->~Allocated();
      if (block->allocated_ == 1) {
        free(block);
      }
      if (next) {
        block = next;
        next->prev_ = 0;
        next = next->next_;
      } else {
        break;
      }
    }
    head_ = current_ = 0;
  }
  if (head_block_ != NULL) {
    Block* tmp = head_block_;
    while (tmp != NULL) {
      Block* next = tmp->next;
      if (tmp->malloced & (1 == 1)) {
        tmp = reinterpret_cast<Block*>(reinterpret_cast<char*>(tmp) - tmp->size);
        free(tmp);
      }
      tmp = next;
    }
  }
  //Free all chunk.
  if (head_chunk_) {
    while (1) {
      Chunk<kDefaultSize>* next = head_chunk_->next();
      delete head_chunk_;
      head_chunk_ = next;
      if (!head_chunk_) {
        break;
      }
    }
  }
}
os::ThreadLocalStorageKey Pool::key_;
}
}
