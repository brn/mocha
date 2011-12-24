#ifndef mocha_hash_table_h_
#define mocha_hash_table_h_

#include <utils/hash/entry.h>
#include <utils/hash/block.h>

namespace mocha {

template <typename Key_t , typename Value_t>
class EntryIteratorBase {
 public :
  typedef Entry<Key_t,Value_t> HashEntry;
  typedef Block<Key_t,Value_t> Node;
  inline EntryIteratorBase( Node* node );
  inline EntryIteratorBase( const EntryIteratorBase& iterator );
  inline bool HasNext();
  inline HashEntry Next();
 private :
  Node* node_;
  Node* current_;
};

template <typename Key_t , typename Value_t>
class HashTable {
 public :
  typedef Block<Key_t,Value_t> TopFixedBlock;
  typedef Block<Key_t,Value_t> Node;
  typedef Entry<Key_t,Value_t> Leaf;
  
  inline HashTable();
  inline ~HashTable();
  inline void Insert( Key_t& key , Value_t& value , Hash_t& hash );
  inline void Remove( Key_t& key , Hash_t& hash );
  inline void RemoveAll();
  inline Leaf Find( const Key_t& key , Hash_t& hash );
  inline int Size();
  inline EntryIteratorBase<Key_t,Value_t> Entries();
 private :
  Block<Key_t,Value_t>* GetBlock_( const Key_t& key , Hash_t& hash , bool is_insert );
  void AddList_( Node* node );
  
  int size_;
  const Leaf empty_entry_;
  TopFixedBlock *fixed_;
  Node* head_;
  Node* tail_;
  static const Hash_t lower_5bit;
  static const Hash_t lower_2bit;
  static const Hash_t shift_constatnt2;
  static const Hash_t shift_constatnt5;
};
}

#include <utils/hash/hash_table-impl.h>

#endif