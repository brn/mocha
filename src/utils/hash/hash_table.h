#ifndef mocha_hash_table_h_
#define mocha_hash_table_h_

#include <utils/hash/entry.h>
#include <utils/hash/block.h>

namespace mocha {

template <typename Key_t , typename Value_t>
class HashTable {
 public :
  typedef Block<Key_t,Value_t> TopFixedBlock;
  typedef Block<Key_t,Value_t> Node;
  typedef Entry<Key_t,Value_t> Leaf;
  typedef std::list<const Entry<Key_t,Value_t>*> CacheList;
  
  inline HashTable();
  inline ~HashTable();
  inline void Insert( Key_t& key , Value_t& value , Hash_t& hash );
  inline const Leaf* Find( const Key_t& key , Hash_t& hash );
  inline int Size();
 private :
  Block<Key_t,Value_t>* GetBlock_( const Key_t& key , Hash_t& hash , bool is_insert );

  int size_;
  CacheList list_;
  const Leaf empty_entry_;
  TopFixedBlock fixed_[ 32 ];

  static const Hash_t lower_5bit;
  static const Hash_t lower_2bit;
  static const Hash_t shift_constatnt;
};
}

#include <utils/hash/hash_table-impl.h>

#endif
