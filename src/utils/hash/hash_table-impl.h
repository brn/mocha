#ifndef mocha_hash_table_impl_h_
#define mocha_hash_table_impl_h_
#include <utils/hash/entry.h>
#include <utils/profiler.h>
namespace mocha {

static uint64_t mask5 = 0x000000000000001FULL;
static uint64_t mask2 = 0x0000000000000003ULL;
static uint64_t mask1 = 0x0000000000000001ULL;

template <typename Key_t , typename Value_t>
inline HashTable<Key_t,Value_t>::HashTable() : size_( 0 ) {}

template <typename Key_t , typename Value_t>
inline HashTable<Key_t,Value_t>::~HashTable() {}

template <typename Key_t , typename Value_t>
inline void HashTable<Key_t,Value_t>::Insert( Key_t key , Value_t value , uint64_t hash ) {
  GetBlock_( key , hash , true )->Set( key , value , hash );
  size_++;
}

template <typename Key_t , typename Value_t>
inline const Entry<Key_t,Value_t>* HashTable<Key_t,Value_t>::Find( const Key_t& key , uint64_t hash ) {
  Block<Key_t,Value_t>* ret = GetBlock_( key , hash , false );
  if ( ret == 0 ) {
    return &empty_entry_;
  } else {
    const typename Block<Key_t,Value_t>::EntryList& list = ret->GetEntry();
    if ( list.size() > 1 ) {
      typename Block<Key_t,Value_t>::EntryList::const_iterator begin = list.begin(),end = list.end();
      while ( begin != end ) {
        if ( (*begin)->Key() == key && (*begin)->Hash() == hash ) {
          return (*begin).Get();
        }
        ++begin;
      }
      return &empty_entry_;
    } else {
      const Entry<Key_t,Value_t> *entry = list.back().Get();
      return ( entry->Key() == key && entry->Hash() == hash )? entry : &empty_entry_;
    }
  }
}

template <typename Key_t , typename Value_t>
inline int HashTable<Key_t,Value_t>::Size() {
  return size_;
}

template <typename Key_t , typename Value_t>
inline Block<Key_t,Value_t>* HashTable<Key_t,Value_t>::GetBlock_( const Key_t& , uint64_t hash , bool is_insert ) {
  //Profiler profiler( stderr , "hash-GetBlock" );
  //profiler.Begin();
  int first = hash & mask5;
  Block<Key_t,Value_t>* next = &( fixed_[ first ] );
  uint64_t tmp = hash >> 31;
  while ( tmp ) {
    int next_hash = tmp & mask2;
    tmp >>= 1;
    //printf( "%p %p %d %d , %llud %llud\n",next , next->Node() , next_hash , is_insert , tmp , hash );
    if ( next->Node() == 0 ) {
      if ( is_insert ) {
        next->Link( new Block<Key_t,Value_t>[ 4 ] );
      } else {
        return 0;
      }
    }
    next = &( next->Node()[ next_hash ] );
  }
  //profiler.End();
  return next;
}

}

#endif
