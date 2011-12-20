#ifndef mocha_hash_block_h_
#define mocha_hash_block_h_
#include <list>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/hash/entry.h>
namespace mocha {

template <typename Key_t , typename Value_t>
class Block {
 public :
  typedef std::list<Handle<Entry<Key_t,Value_t> > > EntryList;
  inline Block();
  inline ~Block();
  inline Block<Key_t,Value_t>* Node();
  inline void Link( Block<Key_t,Value_t>* block );
  inline const EntryList& GetEntry();
  inline void Set( Key_t key , Value_t value , uint64_t hash );
 private :
  Block<Key_t,Value_t> *node_;
  EntryList list_;
};

}

#include <utils/hash/block-impl.h>

#endif
