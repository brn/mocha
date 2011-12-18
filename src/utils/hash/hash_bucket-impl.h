#ifndef mocha_hash_bucket_impl_h_
#define mocha_hash_bucket_impl_h_
#include <assert.h>
#include <utils/hash/hash_fn.h>
#include <utils/profiler.h>
namespace mocha {

namespace hash {
//primes from ruby's st.c
static uint32_t primes[] = {
  8 + 3,
  16 + 3,
  32 + 5,
  64 + 3,
  128 + 3,
  256 + 27,
  512 + 9,
  1024 + 9,
  2048 + 5,
  4096 + 3,
  8192 + 27,
  16384 + 43,
  32768 + 3,
  65536 + 45,
  131072 + 29,
  262144 + 3,
  524288 + 21,
  1048576 + 7,
  2097152 + 17,
  4194304 + 15,
  8388608 + 9,
  16777216 + 43,
  33554432 + 35,
  67108864 + 15,
  134217728 + 29,
  268435456 + 3,
  536870912 + 11,
  1073741824 + 85
};

static int primes_size = sizeof( primes ) / sizeof( primes[ 0 ] );

static inline uint32_t GetSize( int generation , uint32_t current_size ) {
  return ( primes_size < generation )? current_size * 2 : primes[ generation ];
}

}

template<typename Key,typename Value>
inline EntryContainer<Key,Value>::EntryContainer() : is_empty_( true ) , entry_( 0 ){}

template<typename Key,typename Value>
inline void EntryContainer<Key,Value>::Set( HashEntry<Key,Value> *entry ) {
  assert( entry );
  entry_ = entry;
  is_empty_ = false;
}

template<typename Key,typename Value>
inline bool EntryContainer<Key,Value>::IsEmpty() { return is_empty_; }

template<typename Key,typename Value>
inline HashEntry<Key,Value>* EntryContainer<Key,Value>::Get() {return entry_;}


template<typename Key,typename Value>
inline EntryNode<Key,Value>::EntryNode() : size_( 0 ) , next_( 0 ) , prev_( 0 ) {}

template<typename Key,typename Value>
inline EntryNode<Key,Value>::~EntryNode(){}

template<typename Key,typename Value>
inline void EntryNode<Key,Value>::Next( EntryNode<Key,Value> *node ) {
  assert( node );
  node->next_ = next_;
  if ( next_ ) {
    next_->prev_ = node;
  }
  next_ = node;
  node->prev_ = this;
}

template<typename Key,typename Value>
inline EntryNode<Key,Value>* EntryNode<Key,Value>::Next() {
  return next_;
}

template<typename Key,typename Value>
inline void EntryNode<Key,Value>::Prev( EntryNode<Key,Value> *node ) {
  node->prev_ = prev_;
  if ( prev_ ) {
    prev_->next_ = node;
  }
  prev_ = node;
  node->next_ = this;
}


template<typename Key,typename Value>
inline EntryNode<Key,Value>* EntryNode<Key,Value>::Prev() {
  return prev_;
}

template<typename Key,typename Value>
inline void EntryNode<Key,Value>::Add( HashEntry<Key,Value>* ent ) {
  entry_[ size_ ].Set( ent );
  size_++;
}


template <typename Key, typename Value>
inline bool EntryNode<Key,Value>::IsFull() {
  return size_ == kMax;
}

template <typename Key, typename Value>
inline EntryContainer<Key,Value>* EntryNode<Key,Value>::Item( int i ) {
  assert( i < kMax );
  return &entry_[ i ];
}


template<typename Key,typename Value>
inline EntryCache<Key,Value>::EntryCache() : first_( 0 ) , last_( 0 ){}

template<typename Key,typename Value>
inline EntryCache<Key,Value>::~EntryCache() {
  EntryNode<Key,Value> *tmp = first_;
  if ( first_ ) {
    while ( tmp ) {
      EntryNode<Key,Value> *next = tmp->Next();
      delete tmp;
      tmp = next;
    }
  }
}

template<typename Key,typename Value>
inline void EntryCache<Key,Value>::Push( EntryNode<Key,Value> *node ) {
  assert( node );
  if ( first_ == 0 ) {
    first_ = node;
    last_ = node;
  } else {
    last_->Next( node );
    node->Prev( last_ );
    last_ = node;
  }
}


template<typename Key,typename Value>
inline EntryNode<Key,Value>* EntryCache<Key,Value>::First() {
  return first_;
}

template<typename Key,typename Value>
inline EntryNode<Key,Value>* EntryCache<Key,Value>::Last() {
  return last_;
}

template<typename Key,typename Value>
inline void EntryCache<Key,Value>::Add( HashEntry<Key,Value> *ent ) {
  assert( ent && last_ );
  if ( last_->IsFull() ) {
    Push( new EntryNode<Key,Value> );
  }
  last_->Add( ent );
}


template <typename Key , typename Value>
inline HashBucket<Key,Value>::HashBucket() : entry_size_( 0 ) , bucket_generation_( 17 ),
                                             bucket_size_( hash::primes[bucket_size_] ) {
  entry_ = new EntryVector<Key,Value>[bucket_size_];
  cache_.Push( new EntryNode<Key,Value> );
}

template <typename Key , typename Value>
inline HashBucket<Key,Value>::~HashBucket(){
  for ( int i = 0;i < entry_size_;i++ ) {
    if ( !entry_[ i ].entry.IsEmpty() ) {
      delete entry_[ i ].entry.Get();
    }
  }
  delete[] entry_;
}

template <typename Key , typename Value>
inline void HashBucket<Key,Value>::Insert( Key key , Value value , uint64_t hash ) {
  HashEntry<Key,Value> *entry = SearchPosition_( key , hash , true );
  entry->key_ = key;
  entry->value_ = value;
  entry->hash_ = hash;
  entry->vector_.UnSet( 0 );
  cache_.Add( entry );
  entry_size_++;
  if ( entry_size_ > ( bucket_size_ * 0.8 ) ) {
    Rehash_();
  }
}

template <typename Key , typename Value>
inline HashEntry<Key,Value>* HashBucket<Key,Value>::Find( Key key , uint64_t hash ) {
  return SearchPosition_( key , hash , false );
}

template <typename Key , typename Value>
inline void HashBucket<Key,Value>::Remove( Key key , uint64_t hash ) {
  HashEntry<Key,Value> *entry = SearchPosition_( key , hash , false );
  if ( entry != ( &empty_entry_ ) ) {
    entry->vector_.Set( 1 );
    entry_size_--;
  }
}

template<typename Key,typename Value>
inline HashEntry<Key,Value>* HashBucket<Key,Value>::SearchPosition_( const Key& key , uint64_t hash , bool is_insert ) {
  uint32_t tmp_hash = hash % bucket_size_;
  EntryContainer<Key,Value> *entry = &(entry_[tmp_hash].entry);
  HashEntry<Key,Value> *ret = entry->Get();
  if ( entry->IsEmpty() ) {
    if ( is_insert ){
      ret = new HashEntry<Key,Value>;
      ret->bucket_pos_ = tmp_hash;
      entry->Set( ret );
      return ret;
    } else {
      return &empty_entry_;
    }
  } else if ( ret && ret->hash_ == hash && ret->key_ == key ) {
    return ( !is_insert && ret->vector_[1] )? &empty_entry_ : ret;
  } else {
    while ( 1 ) {
      tmp_hash = ( ( tmp_hash + 1 ) < bucket_size_ )? tmp_hash + 1 : 0;
      entry = &( entry_[tmp_hash].entry );
      ret = entry->Get();
      if ( entry->IsEmpty() || !ret ) {
        if ( is_insert ){
          ret = new HashEntry<Key,Value>;
          ret->bucket_pos_ = tmp_hash;
          entry->Set( ret );
          return ret;
        } else {
          return &empty_entry_;
        }
      } else if ( ret && ret->hash_ == hash && ret->key_ == key ) {
        return ( !is_insert && ret->vector_[1] )? &empty_entry_ : ret;
      }
    }
  }
}


template<typename Key,typename Value>
inline void HashBucket<Key,Value>::Remap_( HashEntry<Key,Value> *old_entry , EntryVector<Key,Value> *new_entry_list ) {
  uint64_t hash = old_entry->hash_;
  Key key = old_entry->key_;
  uint32_t tmp_hash = hash % bucket_size_;
  EntryContainer<Key,Value> *entry = &( new_entry_list[tmp_hash].entry );
  if ( entry->IsEmpty() ) {
    entry->Set( old_entry );
  } else {
    while ( 1 ) {
      tmp_hash = ( ( tmp_hash + 1 ) < bucket_size_ )? tmp_hash + 1 : 0;
      entry = &( new_entry_list[tmp_hash].entry );
      if ( entry->IsEmpty() ) {
        entry->Set( old_entry );
        break;
      }
    }
  }
}

template <typename Key,typename Value>
inline void HashBucket<Key,Value>::Rehash_() {
  bucket_size_ = hash::GetSize( ( bucket_generation_++ ) , bucket_size_ );
  EntryVector<Key,Value> *new_entry_list = new EntryVector<Key,Value>[ bucket_size_ ];
  EntryNode<Key,Value> *ent_node = cache_.First();
  Profiler profiler( stderr , "StrHash::Remap" );
  profiler.Begin();
  while ( ent_node ) {
    for ( int i = 0,len = ent_node->Size();i < len; i++ ) {
      HashEntry<Key,Value>* cache = ent_node->Item( i )->Get();
      assert( cache != 0 );
      Remap_( cache , new_entry_list );
    }
    ent_node = ent_node->Next();
  }
  profiler.End();
  delete[] entry_;
  entry_ = new_entry_list;
}

template <typename Key, typename Value>
HashEntry<Key,Value> HashBucket<Key,Value>::empty_entry_;
};

#endif
