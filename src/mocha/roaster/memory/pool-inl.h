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
#ifndef mocha_memory_pool_inl_h_
#define mocha_memory_pool_inl_h_
#include <stdlib.h>
#include <mocha/roaster/assert/assert_def.h>
namespace mocha {namespace memory {

/**
 * @class
 * memory block.
 */
template <size_t size>
class Chunk : private Uncopyable {
 public :
  Chunk()
      : used_(0),
        next_(NULL){}
  ~Chunk(){}

  /**
   * @returns {Chunk<size>}
   * Get next chunk pointer.
   * By default, this method return NULL pointer,
   * if set_next is not called yet.
   */
  Chunk<size>* next() { return next_; }

  /**
   * @param {Chunk<size>}
   * Link next block.
   * Next block only allowed valid pointer.
   */
  void set_next(Chunk<size>* chunk) {
    ASSERT(true, chunk != NULL);
    ASSERT(true, chunk != 0);
    next_ = chunk;
  }

  /**
   * @param {size_t}
   * @returns {bool}
   * Check the chunk has the enough size to allocate given size.
   */
  bool HasEnoughSize(size_t need) {
    return (size - used_) >= need;
  }

  /**
   * @param {size_t}
   * @returns {void*}
   * Get memory block.
   * Must call HasEnoughSize before call this,
   * If the given size is over the block capacity,
   * this method cause the segfault.
   */
  void* GetBlock(size_t reserve) {
    ASSERT(true, HasEnoughSize(reserve));
    char* ret = (block_ + used_);
    used_ += reserve;
    used_ = Pool::Align(used_, 8);
    return ret;
  }
 private :
  char block_[size];
  size_t used_;
  Chunk<size>* next_;
};

//The special new operator.
inline void* Allocated::operator new(size_t size, Pool* pool) {
  return pool->AllocLinkedList(size);
}
inline void Allocated::operator delete(void*) {}
inline void Allocated::operator delete(void* ptr, Pool*){ operator delete(ptr); }

struct Block {
  char malloced;
  size_t size;
  Block* next;
};

static const size_t alignment = sizeof(void*);
static const size_t allocated_size = Pool::Align(sizeof(Allocated), alignment);
static const size_t block_size = Pool::Align(sizeof(Block),alignment);

//Pool constructor.
inline Pool::Pool()
    : current_(0),
      head_(0),
      head_block_(NULL),
      current_block_(NULL) {
  head_chunk_ = new Chunk<kDefaultSize>;
  current_chunk_ = head_chunk_;
}
inline Pool::~Pool() {Free();}

template <typename T>
inline T* Pool::Alloc(size_t size) {
  return reinterpret_cast<T*>(AllocateBlock(sizeof(T) * size));
}
  
inline void* Pool::AllocateBlock(size_t size) {
  if (size < block_size) {
    size = block_size;
  }
  size += block_size;
  size_t aligned = Align(size,alignment);
  void* empty = NULL;
  bool malloced = false;
  if (aligned < kDefaultSize) {
    if (!current_chunk_->HasEnoughSize(aligned)) {
      current_chunk_->set_next(new Chunk<kDefaultSize>);
      current_chunk_ = current_chunk_->next();
    }
    empty = current_chunk_->GetBlock(aligned);
  } else {
    malloced = true;
    empty = malloc(aligned);
  }
  Block* block = reinterpret_cast<Block*>(reinterpret_cast<char*>(empty) + (aligned - block_size));
  block->size = aligned - block_size;
  block->malloced = 0;
  if (malloced) {
    block->malloced |= 1;
  }
  if (head_block_ == NULL) {
    head_block_ = block;
  }
  if (current_block_ == NULL) {
    current_block_ = block;
    block->next = NULL;
  } else {
    current_block_->next = block;
    block->next = NULL;
    current_block_ = block;
  }
  return empty;
}

//Allocate chunk.
inline void* Pool::AllocLinkedList(size_t size) {
  if (!current_chunk_->HasEnoughSize(size)) {
    current_chunk_->set_next(new Chunk<kDefaultSize>);
    current_chunk_ = current_chunk_->next();
  }
  Allocated* block = NULL;
  if (size < kDefaultSize) {
    if (size < allocated_size) {
      size = allocated_size;
    }
    block = reinterpret_cast<Allocated*>(current_chunk_->GetBlock(size));
    block->allocated_ = 0;
  } else {
    block = reinterpret_cast<Allocated*>(malloc(size));
    block->allocated_ = 1;
  }
  block->next_ = block->prev_ = 0;
  if (head_ == 0) {
    current_ = head_ = block;
  } else {
    ASSERT(true, current_ != 0);
    current_->next_ = block;
    block->prev_ = current_;
    current_ = block;
  }
  return static_cast<void*>(block);
}

inline Pool* Pool::Local() {
  Pool* pool = reinterpret_cast<Pool*>(os::ThreadLocalStorage::Get(&key_));
  if (pool == NULL) {
    pool = new Pool;
    os::ThreadLocalStorage::Set(&key_, pool);
  }
  return pool;
}

}}

#endif
