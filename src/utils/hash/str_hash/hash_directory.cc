#include <assert.h>
#include <utils/hash/str_hash/hash_directory.h>

namespace mocha {

HashDirectory::HashDirectory() :
    used_bit_category_( 1 ), list_( new DirEntryList ){}

HashDirectory::~HashDirectory(){}

void HashDirectory::Extend() {
  list_->Extend();
}

void HashDirectory::Inesert( void* entry , uint32_t hash ) {
  list_->Insert( entry , hash );
}

void* HashDirectory::Find( uint32_t hash ) {
  return list_->Find( hash )
}

int HashDirectory::Size() {
  return list_->Size();
}

int HashDirectory::BitCategory() {
  return used_bit_category_;
}

void HashDirectory::Increase() {
  used_bit_category_++;
}

DirEntry* HashDirectory::At( int num ) {
  return entries_[ num ];
}

}
