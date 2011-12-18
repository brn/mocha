#ifndef mocha_hash_bucket_h_
#define mocha_hash_bucket_h_
#include <vector>
#include <list>
#include <utils/int_types.h>
#include <utils/hash/hash_entry.h>
namespace mocha {
template <typename Key , typename Value>
class EntryContainer {
 public :
  EntryContainer();
  ~EntryContainer(){};
  void Set( HashEntry<Key,Value> *entry );
  bool IsEmpty();
  HashEntry<Key,Value>* Get();
 private :
  bool is_empty_;
  HashEntry<Key,Value> *entry_;
};

template <typename Key,typename Value>
struct EntryVector {
  EntryContainer<Key,Value> entry;
};

template <typename Key,typename Value>
class EntryNode {
 public :
  enum { kMax = 10 };
  inline EntryNode();
  inline ~EntryNode();
  inline void Next( EntryNode<Key,Value>* next );
  inline EntryNode<Key,Value>* Next();
  inline void Prev( EntryNode<Key,Value>* prev );
  inline EntryNode<Key,Value>* Prev();
  inline void Add( HashEntry<Key,Value>* );
  inline bool IsFull();
  inline int Size() { return size_; }
  inline EntryContainer<Key,Value>* Item( int i );
 private :
  int size_;
  EntryNode<Key,Value>* next_;
  EntryNode<Key,Value>* prev_;
  EntryContainer<Key,Value> entry_[ 10 ];
};

template <typename Key,typename Value>
class EntryCache {
 public :
  inline EntryCache();
  inline ~EntryCache();
  inline void Push( EntryNode<Key,Value>* node );
  inline EntryNode<Key,Value>* First();
  inline EntryNode<Key,Value>* Last();
  inline void Add( HashEntry<Key,Value>* );
 private :
  EntryNode<Key,Value>* first_;
  EntryNode<Key,Value>* last_;
};

template <typename Key , typename Value>
class HashBucket {
 public :
  inline HashBucket();
  inline ~HashBucket();
  inline void Insert( Key key , Value value , uint64_t hash );
  inline HashEntry<Key,Value>* Find( Key key , uint64_t hash );
  inline void Remove( Key key , uint64_t hash );
  inline int Size() { return entry_size_; };
 private :
  int entry_size_;
  int bucket_generation_;
  uint64_t bucket_size_;
  static HashEntry<Key,Value> empty_entry_;
  HashEntry<Key,Value>* SearchPosition_( const Key& key , uint64_t hash , bool is_insert );
  void Remap_( HashEntry<Key,Value> *old_entry , EntryVector<Key,Value> *entry_vector );
  void Rehash_();
  EntryVector<Key,Value>* entry_;
  EntryCache<Key,Value> cache_;
};

}

#include <utils/hash/hash_bucket-impl.h>

#endif
