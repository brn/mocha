#include <mocha/roaster/memory/pool.h>
namespace mocha {
namespace memory {
void Pool::Free() {
  if (head_) {
    os::ThreadLocalStorage::Set(&key_,NULL);
    Allocated* block = head_;
    Allocated* next = block->next_;
    while (1) {
      block->~Allocated();
      free(block);
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
}
os::ThreadLocalStorageKey Pool::key_;
}
}
