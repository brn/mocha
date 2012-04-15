#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace memory {
size_t Pool::Align(size_t siz, size_t alignment) {
  return (siz + (alignment - 1)) & ~(alignment - 1);
}


void Pool::Free() {
  if (head_) {
    Allocated* block = head_;
    Allocated* next = block->next_;
    while (1) {
      block->~Allocated();
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
