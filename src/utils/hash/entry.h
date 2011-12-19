#ifndef mocha_hash_entry_h_
#define mocha_hash_entry_h_
#include <utils/int_types.h>

namespace mocha {

template <typename Key_t,typename Value_t>
class Entry {
 public :
  Entry( Key_t key , Value_t value , uint64_t hash );
  ~Entry();
  const uint64_t& Hash() const;
  const Key_t& Key() const;
  const Value_t& Value() const;
 private :
  uint64_t hash_;
  Key_t key_;
  Value_t value_;
};

}

#endif
