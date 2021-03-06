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
#ifndef mocha_memory_pool_h_
#define mocha_memory_pool_h_

#include <stdio.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
#include <mocha/roaster/platform/thread/thread.h>
namespace mocha {
namespace memory {
class Pool;
/**
 * @class
 * The base of the lifetime managed pointer.
 * To allocate from the pool,
 * must inherit this class as public.
 */
class Allocated {
  friend class Pool;
 public :
  Allocated(){}
  virtual ~Allocated(){}
  //The placement new for the pool allocation.
  void* operator new(size_t size, Pool* pool);
  void operator delete(void* ptr);
  void operator delete(void* ptr, Pool* pool);
 private :
  char allocated_;
  Allocated* prev_;
  Allocated* next_;
};

template <size_t>
class Chunk;

struct Block;

/**
 * @class
 * The pointer lifetime managable allocator.
 * This memory space is allocation only,
 * it can not free an each space, to free memory block,
 * destroy Pool class.
 */
class Pool : private Uncopyable {
  friend class Allocated;
 public :
  Pool();
  ~Pool();
  /**
   * @public
   * free memory space.
   */
  void Free();
  /**
   * @public
   * allocate to tls space.
   */
  static Pool* Local();
  static size_t Align(size_t offset, size_t alignment);
  template <typename T>
  T* Alloc(size_t size = 1);
 private :
  void* AllocateBlock(size_t size);
  ///Default memory block size.
  static const size_t kDefaultSize = 3072;
  /**
   * @private
   * Allocate the memory and add used block list,
   * if the Pool class is destroyed,
   * all allocated memory is destoryed too.
   * Allocatable size is kDefaultSize.
   */
  void* AllocLinkedList(size_t size);
  Allocated* current_;
  Allocated* head_;
  Chunk<kDefaultSize>* head_chunk_;
  Chunk<kDefaultSize>* current_chunk_;
  Block* head_block_;
  Block* current_block_;
  static os::ThreadLocalStorageKey key_;
};

}
}

#include <mocha/roaster/memory/pool-inl.h>
#endif
