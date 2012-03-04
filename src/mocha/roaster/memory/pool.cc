#include <stdlib.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace memory {

void* Allocated::operator new(size_t size, Pool* pool) {
  return pool->Alloc(size);
}
void Allocated::operator delete(void* ptr) {}
void Allocated::operator delete(void* ptr, Pool* pool){ operator delete(ptr); }

Pool::Pool() : current_(0), head_(0) {}
Pool::~Pool() {
  if (head_) {
    Allocated* block = head_;
    Allocated* next = block->next_;
    while (1) {
      block->~Allocated();
      free(block);
      if (next) {
        block = next;
        next = next->next_;
      } else {
        break;
      }
    }
  }
}
void* Pool::Alloc(size_t size) {
  Allocated* block = reinterpret_cast<Allocated*>(malloc(size));
  block->next_ = block->prev_ = 0;
  if (head_ == 0) {
    current_ = head_ = block;
  } else {
    current_->next_ = block;
    block->prev_ = current_;
    current_ = block;
  }
  return static_cast<void*>(block);
}

Pool* Pool::Local() {
  Pool* pool = reinterpret_cast<Pool*>(ThreadLocalStorage::Get(&key_));
  if (pool == NULL) {
    pool = new Pool;
    ThreadLocalStorage::Set(&key_, pool);
  }
  return pool;
}

ThreadLocalStorageKey Pool::key_;
}
}
