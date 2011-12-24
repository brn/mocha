#ifndef mocha_hash_entry_h_
#define mocha_hash_entry_h_
#include <utils/int_types.h>

namespace mocha {

template<typename Key_t, typename Value_t>
class Block;

template <typename Key_t,typename Value_t>
class Entry {
  friend class Block<Key_t,Value_t>;
 public :
  Entry( Key_t& key , Value_t& value , uint64_t hash );
  Entry();
  Entry( const Entry& entry );
  ~Entry();
  uint64_t& Hash();
  Key_t& Key();
  Value_t& Value();
  bool IsEmpty() const;
 private :
  uint64_t hash_;
  Key_t key_;
  Value_t value_;
};

}

#include <utils/hash/entry-impl.h>

#endif