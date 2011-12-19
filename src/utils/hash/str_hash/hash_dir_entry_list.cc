#include <utils/hash/hash_dir_entry_list.h>

namespace mocha {

typedef EntryAllocator<DirEntry*> Allocator;

uint64_t GetHash( const uint64_t& hash , int used_bit_category ) {
  return hash >> static_cast<uint64_t>( ( 58 - used_bit_category ) - 1 );
}

struct DirEntryList::DirEntry {
  Bucket* bucket_ptr;
};

DirEntryList::DirEntryList() : used_bit_category_( 1 ) , size_( 2 ) {
  entries_ = Allocator::Allocate( size_ );
  entries_[ 0 ].bucket_ptr = 0;
  entries_[ 1 ].bucket_ptr = 0;
}

DirEntryList::~DirEntryList(){}

void DirEntryList::Extend( int bucket_bit_category ) {
  int cache = size_;
  size_ << 1;
  used_bit_category_++;
  entries_ = Allocator::ReAllocate( entries_ , size_ );
  while ( int i = size_; i > cache; i-- ) {
    entries_[ i ].bucket_ptr = 0;
  }
}

void DirEntryList::Insert( void* entry , uint64_t hash ) {
  uint64_t hash = GetHash( hash , used_bit_category_ );
  Bucket* bucket = entries_[ hash ].bucket_ptr;
  if ( bucket != 0 && !bucket->IsEmpty() ) {
    bucket->Increase();
    if ( bucket->BitCategory() >= used_bit_category_ ) {
      Extend( bucket->BitCategory() );
      uint64_t next = GetHash( bucket->GetHash() , used_bit_category_ );
    } else {
      entries_[ hash ].bucket_ptr = new Bucket( entry , hash );
    }
  } else {
    entries_[ hash ].bucket_ptr = new Bucket( entry , hash );
  }
}

}
