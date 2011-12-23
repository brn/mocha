#ifndef mocha_hash_block_impl_h_
#define mocha_hash_block_impl_h_
#include <assert.h>
#include <utils/bits.h>

namespace mocha {

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>::Block() : next_( 0 ) , prev_( 0 ) , node_( 0 ) , entry_( 0 ){}

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>::~Block(){
  if ( node_ != 0 ) {
    delete node_;
  }
  if ( entry_ != 0 ) {
    delete entry_;
  }
}

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>* Block<Key_t,Value_t>::Node() {
  return ( node_ )? node_->block : 0;
}

template <typename Key_t , typename Value_t>
void Block<Key_t,Value_t>::Alloc() {
  node_ = new BlockContainer<Key_t,Value_t>;
}


template <typename Key_t , typename Value_t>
Entry<Key_t,Value_t>* Block<Key_t,Value_t>::GetEntry() {
  return entry_;
}

template <typename Key_t , typename Value_t>
inline void Block<Key_t,Value_t>::Set( Key_t& key , Value_t& value , uint64_t hash ) {
  //if ( list_.size() > 1 ) printf( "conflict %zd\n" , list_.size() );
  if ( entry_ == 0 ) {
    entry_ = new Entry<Key_t,Value_t>( key , value , hash );
  } else {
    entry_->key_ = key;
    entry_->value_ = value;
    entry_->hash_ = hash;
  }
}

template <typename Key_t , typename Value_t>
uint64_t& Block<Key_t,Value_t>::Hash() {
  return entry_->hash_;
}

template <typename Key_t , typename Value_t>
Key_t& Block<Key_t,Value_t>::Key() {
  return entry_->key_;
}

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>* Block<Key_t,Value_t>::Next() {
  return next_;
}

template <typename Key_t , typename Value_t>
Block<Key_t,Value_t>* Block<Key_t,Value_t>::Prev() {
  return prev_;
}

}

#endif
