#ifndef mocha_memory_pool_inl_h_
#define mocha_memory_pool_inl_h_
#include <assert.h>
#include <stdlib.h>
namespace mocha {
namespace memory {

inline void* Allocated::operator new(size_t size, Pool* pool) {
  return pool->AllocLinkedList(size);
}
inline void Allocated::operator delete(void*) {}
inline void Allocated::operator delete(void* ptr, Pool*){ operator delete(ptr); }

inline Pool::Pool() : current_(0), head_(0) {}
inline Pool::~Pool() {
  Free();
}

inline void* Pool::AllocLinkedList(size_t size) {
  Allocated* block = reinterpret_cast<Allocated*>(malloc(size));
  block->next_ = block->prev_ = 0;
  if (head_ == 0) {
    current_ = head_ = block;
  } else {
    assert(current_ != 0);
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

}
}

#endif
