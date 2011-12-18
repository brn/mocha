#include <utils/hash/str_hash/hash_directory.h>

namespace mocha {

HashDirectory::HashDirectory() :
    used_bit_category_( 1 ), list_( new DirEntryList ){}

HashDirectory::~HashDirectory(){}

void HashDirectory::Extend() {
  list_->Extend();
}



}
