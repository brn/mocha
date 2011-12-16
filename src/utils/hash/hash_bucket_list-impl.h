#ifndef mocha_hash_bucket_list_impl_h_
#define mocha_hash_bucket_list_impl_h_

namespace mocha {

template <typename Key,typename Value>
inline HashBucketList::HashBucketList() : bucket_length_( 0 ) {
  Grow();
}

#define ITERATOR(name) begin = name.begin,end = name.end()
#define RITERATOR(name) begin = name.rbegin,end = name.rend()
template <typename Key,typename Value>
inline HashBucketList::~HashBucketList() {
  std::list<HashBucket<Key,Value>*>::iterator ITERATOR(bucket_);
  while ( begin != end ) {
    delete begin;
    ++begin;
  }
}

template <typename Key,typename Value>
inline void HashBucketList::Grow() {
  bucket_length_++;
  bucket_.push_back( new HashBucket<Key,Value> );
}

template <typename Key,typename Value>
inline void HashBucketList::Insert( Key key , Value value , uint32_t hash ) {
  bucket_.back()->Insert( key , value , hash );
  if ( bucket_.Size() > ( 0.8 * HashBucket::BUCKET_SIZE ) ) {
    Grow();
  }
}

template<typename Key,typename Value>
inline HashEntry<Key,Value>* HashBucketList::Find( Key key , uint32_t hash ) {
  return FindOf_( key , hash );
}

template<typename Key,typename Value>
inline HashEntry<Key,Value> HashBucketList::FindOf_( Key key , uint32_t hash ) {
  HashEntry<Key,Value> *entry = bucket_.back()->Find( key , hash );
  if ( entry->IsEmpty() ) {
    std::list<HashBucket<T>*>::reverse_iterator RITERATOR(bucket_);
    begin++;
    while ( begin != end ) {
      entry = (*begin)->Find( key , hash );
      if ( !entry->IsEmpty() ) { return entry; }
      ++begin;
    }
  }
  return entry;
}

}

#endif
