#ifndef mocha_hash_block_impl_h_
#define mocha_hash_block_impl_h_
#include <assert.h>
#include <utils/bits.h>

namespace mocha {

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>::Block() : node_( 0 ){}

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>::~Block(){}

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>* Block<Key_t,Value_t>::Node() {
  return node_;
}

template <typename Key_t , typename Value_t>
void Block<Key_t,Value_t>::Link( Block<Key_t , Value_t> *block ) {
  node_ = block;
}

template <typename Key_t , typename Value_t>
const typename Block<Key_t,Value_t>::EntryList& Block<Key_t,Value_t>::GetEntry() {
  return list_;
}

template <typename Key_t , typename Value_t>
inline void Block<Key_t,Value_t>::Set( Key_t key , Value_t value , uint64_t hash ) {
  list_.push_back( Handle<Entry<Key_t,Value_t> >( new Entry<Key_t,Value_t>( key , value , hash ) ) );
}

}

#endif
