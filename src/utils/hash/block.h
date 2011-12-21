#ifndef mocha_hash_block_h_
#define mocha_hash_block_h_
#include <list>
#include <utils/smart_pointer/scope/scoped_ptr.h>
#include <utils/hash/entry.h>
namespace mocha {

template <typename Key,typename Value>
struct BlockContainer;

typedef uint64_t Hash_t;

template <typename Key_t , typename Value_t>
class Block {
 public :
  typedef std::list<Entry<Key_t,Value_t>*> EntryList;
  inline Block();
  inline ~Block();
  inline Block<Key_t,Value_t>* Node();
  inline void Alloc();
  inline Entry<Key_t,Value_t>* GetEntry();
  inline void Set( Key_t& key , Value_t& value , Hash_t hash );
  inline Hash_t& Hash();
  inline Key_t& Key();
 private :
  BlockContainer<Key_t,Value_t>* node_;
  Entry<Key_t,Value_t>* entry_;
  //EntryList list_;
};

template <typename Key_t ,typename Value_t>
struct BlockContainer {
  Block<Key_t,Value_t> block[ 4 ];
};

}

#include <utils/hash/block-impl.h>

#endif
