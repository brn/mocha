#ifndef mocha_hash_entry_h_
#define mocha_hash_entry_h_
#include <utils/bits.h>
namespace mocha {
template<typename Key,typename Value>
class HashBucket;

template <typename Key_t,typename Value_t>
class HashEntry {
  friend class HashBucket<Key_t,Value_t>;
 public :
  HashEntry() : hash_( 0 ){
    vector_.Set(0);
  }
  ~HashEntry(){}
  Value_t Value(){ return value_; }
  const Key_t& Key() const { return key_; }
  const uint64_t Hash() const { return hash_; }
  bool IsEmpty() { return vector_[0]; }
  bool IsDeleted() { return vector_[1]; }
 private :
  uint64_t hash_;
  uint32_t bucket_pos_;
  BitVector<int8_t,8> vector_;
  Key_t key_;
  Value_t value_;
};

}

#endif
