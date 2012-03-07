#include <mocha/roaster/file_system/file_system.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/roaster/consts/consts.h>
namespace mocha {

static const int debug = 0;
static const int compress = 1;
static const int pretty_print = 2;
static const int file = 3;

CompilationInfo::CompilationInfo(const char* str) : str_(str) {
  versions_.insert(VersionPair(Consts::kVersionAll, 1));
  versions_.insert(VersionPair(Consts::kVersionNone, 1));
  std::string base_dir = filesystem::Path::home_directory();
  base_dir += "/.mocha/";
  base_dir += "module/";
  lib_dir_.push_back(base_dir);
}

bool CompilationInfo::Debug() const {
  return flags_.At(debug);
}

void CompilationInfo::SetDebug() {
  flags_.Set(debug);
  versions_.insert(VersionPair(Consts::kVersionDebug, 1));
}

bool CompilationInfo::Compress() const {
  return flags_.At(compress);
}

void CompilationInfo::SetCompress() {
  flags_.Set(compress);
}

bool CompilationInfo::PrettyPrint() const {
  return flags_.At(pretty_print);
}

void CompilationInfo::SetPrettyPrint() {
  flags_.Set(pretty_print);
}

void CompilationInfo::SetVersion(const char* name) {
  Versions::iterator entry = versions_.find(name);
  if (entry == versions_.end()) {
    versions_.insert(VersionPair(name, 1));
  }
}

bool CompilationInfo::HasVersion(const char* name) const {
  Versions::const_iterator entry = versions_.find(name);
  if (entry == versions_.end()) {
    return false;
  } else {
    return true;
  }
}

void CompilationInfo::MarkAsFile() {
  flags_.Set(file);
}

bool CompilationInfo::IsFile() const {
  return flags_.At(file);
}

void CompilationInfo::SetCharset(const char* charset) {
  charset_ = charset;
}

void CompilationInfo::SetLibDirectory(const char* path) {
  std::string dir = path;
  lib_dir_.push_back(dir);
}

}
