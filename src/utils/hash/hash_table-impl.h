#ifndef mocha_hash_table_impl_h_
#define mocha_hash_table_impl_h_
#include <utils/hash/entry.h>
#include <utils/profiler.h>
namespace mocha {

template <typename Key_t,typename Value_t>
const Hash_t HashTable<Key_t,Value_t>::lower_5bit = 0x000000000000001FULL;

template <typename Key_t,typename Value_t>
const Hash_t HashTable<Key_t,Value_t>::lower_2bit = 0x0000000000000003ULL;

template <typename Key_t,typename Value_t>
const Hash_t HashTable<Key_t,Value_t>::shift_constatnt = 2;


template <typename Key_t , typename Value_t>
inline EntryIteratorBase<Key_t,Value_t>::EntryIteratorBase( EntryIteratorBase<Key_t,Value_t>::Node* node ) :
    node_( node ) , current_( node ) {}


template <typename Key_t , typename Value_t>
inline EntryIteratorBase<Key_t,Value_t>::EntryIteratorBase( const EntryIteratorBase& iterator ) :
    node_( iterator.node_ ) , current_( iterator.current_ ){}


template <typename Key_t , typename Value_t>
inline bool EntryIteratorBase<Key_t,Value_t>::HasNext() {
  return ( current_ != 0 )? true : false;
}


template <typename Key_t , typename Value_t>
inline typename EntryIteratorBase<Key_t,Value_t>::HashEntry EntryIteratorBase<Key_t,Value_t>::Next() {
  HashEntry ret = current_->GetEntry();
  current_ = current_->Next();
  while ( current_ && current_->GetEntry() && current_->GetEntry()->IsEmpty() ) {
    current_ = current_->Next();
  }
  return ret;
}


template <typename Key_t , typename Value_t>
inline HashTable<Key_t,Value_t>::HashTable() : size_( 0 ) , head_( 0 ) , tail_( 0 ){}



template <typename Key_t , typename Value_t>
inline HashTable<Key_t,Value_t>::~HashTable() {}



template <typename Key_t , typename Value_t>
inline void HashTable<Key_t,Value_t>::Insert( Key_t& key , Value_t& value , Hash_t& hash ) {
  Node *block = GetBlock_( key , hash , true );
  block->Set( key , value , hash );
  size_++;
}



template <typename Key_t , typename Value_t>
inline void HashTable<Key_t,Value_t>::Remove( Key_t& key , Hash_t& hash ) {
  Node *block = GetBlock_( key , hash , false );
  if ( block->entry_ != 0 ) {
    if ( block->next_ ) {
      block->next_->prev_ = block->prev_;
    }
    if ( block->prev_ ) {
      block->prev_->next_ = block->next_;
    }
    delete block->entry_;
    block->entry_ = 0;
    size_--;
  }
}



template <typename Key_t , typename Value_t>
inline const Entry<Key_t,Value_t>* HashTable<Key_t,Value_t>::Find( const Key_t& key,
                                                                   Hash_t& hash ) {
  Node* ret = GetBlock_( key , hash , false );
  if ( ret == 0 ) {
    return &empty_entry_;
  } else {
    return ret->GetEntry();
  }
}



template <typename Key_t , typename Value_t>
inline int HashTable<Key_t,Value_t>::Size() {
  return size_;
}


template <typename Key_t , typename Value_t>
inline EntryIteratorBase<Key_t,Value_t> HashTable<Key_t,Value_t>::Entries() {
  return EntryIteratorBase<Key_t,Value_t>( head_ );
}


template <typename Key_t , typename Value_t>
inline Block<Key_t,Value_t>* HashTable<Key_t,Value_t>::GetBlock_( const Key_t& key,
                                                                  Hash_t& hash,
                                                                  bool is_insert ) {
  int first = hash & lower_5bit;
  Hash_t tmp = hash >> shift_constatnt;
  Node* next = fixed_ + first;
  while ( tmp ) {
    int next_hash = tmp & lower_2bit;
    tmp >>= shift_constatnt;
    Node *next_node = next->Node();
    if ( next_node == 0 ) {
      if ( is_insert ) {
        next->Alloc();
        next = next->Node() + next_hash;
        AddList_( next );
        return next;
      } else {
        return 0;
      }
    } else {
      next = next_node + next_hash;
      if ( next->entry_ && next->Hash() == hash && next->Key() == key ) {
        return next;
      }
    }
  }
  return next;
}

template <typename Key_t , typename Value_t>
inline void HashTable<Key_t,Value_t>::AddList_( HashTable<Key_t,Value_t>::Node* node ) {
  if ( head_ == 0 ) {
    head_ = node;
    tail_ = node;
  } else if ( head_ == tail_ ) {
    head_->next_ = node;
    node->prev_ = head_;
    tail_ = node;
    tail_->next_ = 0;
  } else {
    tail_->next_ = node;
    node->prev_ = tail_;
    node->next_ = 0;
    tail_ = node;
  }
}

}

#endif
