#ifndef mocha_platform_fs_directory_h_
#define mocha_platform_fs_directory_h_
#include <mocha/roaster/platform/fs/directory/directory.h>
namespace mocha {
namespace os {
namespace fs {
Directory::const_iterator::const_iterator(const DirEntry* entry) : entry_(entry){}
Directory::const_iterator::const_iterator() : entry_(0){}
Directory::const_iterator::~const_iterator() {}

Directory::const_iterator::const_iterator(const Directory::const_iterator& iterator) {
  entry_ = iterator.entry_;
}

const Directory::const_iterator& Directory::const_iterator::operator = (const Directory::const_iterator& iterator) {
  entry_ = iterator.entry_;
  return (*this);
}

const DirEntry* Directory::const_iterator::operator*() const {
  return entry_;
}

Directory::const_iterator& Directory::const_iterator::operator++() {
  entry_ = entry_->next_;
  return (*this);
}

bool Directory::const_iterator::operator != (const Directory::const_iterator& iter) const {
  return entry_ != iter.entry_;
}
}
}}
#endif
