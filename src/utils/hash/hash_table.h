#ifndef mocha_hash_table_h_
#define mocha_hash_table_h_

#include <utils/hash/entry.h>
#include <utils/hash/block.h>

namespace mocha {

template <typename Key_t , typename Value_t>
class HashTable {
 public :
  typedef Block<Key_t,Value_t> TopFixedBlock;
  inline HashTable();
  inline ~HashTable();
  inline void Insert( Key_t key , Value_t value , uint64_t hash );
  inline const Entry<Key_t,Value_t>* Find( const Key_t& key , uint64_t hash );
  inline int Size();
 private :
  Block<Key_t,Value_t>* GetBlock_( const Key_t& key , uint64_t hash , bool is_insert );
  
  int size_;
  const Entry<Key_t,Value_t> empty_entry_;
  TopFixedBlock fixed_[ 32 ];
};
}

#include <utils/hash/hash_table-impl.h>

#endif
