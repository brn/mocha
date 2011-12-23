#ifndef mocha_str_hash_h_
#define mocha_str_hash_h_
#include <string.h>
#include <string>
#include <utils/int_types.h>
#include <utils/hash/hash_table.h>

namespace mocha {
template <typename Key,typename Value>
class HashMap {
  public :
  typedef EntryIteratorBase<Key,Value> EntryIterator;
  typedef Entry<Key,Value> HashEntry;
  inline HashMap();
  inline ~HashMap();
  inline void Insert( const Key& key , Value value );
  inline void Remove( const Key& key );
  inline void RemoveAll();
  inline HashEntry Find( const Key& key );
  inline int Size();
  inline EntryIterator Entries();
 private :
  HashTable<Key,Value> table_;
};

template <typename Value>
class HashMap<const char*,Value> {
 public :
  typedef EntryIteratorBase<std::string,Value> EntryIterator;
  typedef Entry<std::string,Value> HashEntry;
  inline HashMap();
  inline ~HashMap();
  inline void Insert( const char* key , Value value );
  inline void Insert( const std::string& key , Value value );
  inline void Remove( const char* key );
  inline void Remove( const std::string& key );
  inline void RemoveAll();
  inline HashEntry Find( const char* key );
  inline HashEntry Find( const std::string& key );
  inline int Size();
  inline EntryIterator Entries();
 private :
  HashTable<std::string,Value> table_;
};


template <typename Value>
class HashMap<int,Value> {
 public :
  typedef EntryIteratorBase<int,Value> EntryIterator;
  typedef Entry<int,Value> HashEntry;
  inline HashMap();
  inline ~HashMap();
  inline void Insert( int key , Value value );
  inline void Remove( int key );
  inline void RemoveAll();
  inline HashEntry Find( int key );
  inline int Size();
  inline EntryIterator Entries();
 private :
  HashTable<int,Value> table_;
};

}

#include <utils/hash/hash_map/hash_map-impl.h>

#endif
