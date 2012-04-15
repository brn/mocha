#ifndef mocha_memory_pool_inl_h_
#define mocha_memory_pool_inl_h_
#include <assert.h>
#include <stdlib.h>
namespace mocha {
namespace memory {
template <size_t size>
class Chunk {
 public :
  Chunk()
      : used_(0),
        next_(0){}
  ~Chunk(){}
  Chunk<size>* next() {return next_;}
  void set_next(Chunk<size>* chunk) {next_ = chunk;}
  bool HasEnoughSize(size_t need) {
    return (size - used_) >= need;
  }
  void* GetBlock(size_t reserve) {
    char* ret = (block + used_);
    used_ += reserve;
    used_ = Pool::Align(used_, 8);
    return ret;
  }
 private :
  char block[size];
  size_t used_;
  Chunk<size>* next_;
};

inline void* Allocated::operator new(size_t size, Pool* pool) {
  return pool->AllocLinkedList(size);
}
inline void Allocated::operator delete(void*) {}
inline void Allocated::operator delete(void* ptr, Pool*){ operator delete(ptr); }

inline Pool::Pool()
  : current_(0),
    head_(0) {
  head_chunk_ = new Chunk<kDefaultSize>;
  current_chunk_ = head_chunk_;
}
inline Pool::~Pool() {
  Free();
}

inline void* Pool::AllocLinkedList(size_t size) {
  if (!current_chunk_->HasEnoughSize(size)) {
    current_chunk_->set_next(new Chunk<kDefaultSize>);
    current_chunk_ = current_chunk_->next();
  }
  Allocated* block = reinterpret_cast<Allocated*>(current_chunk_->GetBlock(size));
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
