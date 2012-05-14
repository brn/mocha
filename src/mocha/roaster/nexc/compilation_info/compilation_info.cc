#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/roaster/consts/consts.h>
#include <mocha/roaster/nexc/compilation_info/compilation_info.h>
namespace mocha {

static const int debug = 0;
static const int compress = 1;
static const int pretty_print = 2;
static const int file = 3;
static const int org_name = 3;
static const int file_scope = 4;
static const int global_scope = 5;
static const int prototype = 6;

CompilationInfo::CompilationInfo() {
  versions_.insert(VersionPair(Consts::kVersionAll, 1));
  versions_.insert(VersionPair(Consts::kVersionNone, 1));
  versions_.insert(VersionPair(Consts::kVersionCompat, 1));
  flags_.Set(file_scope);
  flags_.Set(global_scope);
  SetPrototypeExtensions();
}

bool CompilationInfo::Debug() const {
  return flags_.At(debug);
}

void CompilationInfo::SetDebug() {
  flags_.Set(debug);
  versions_.insert(VersionPair(Consts::kVersionDebug, 1));
}

void CompilationInfo::UnsetDebug() {
  flags_.UnSet(debug);
  versions_.erase(Consts::kVersionDebug);
}

bool CompilationInfo::Compress() const {
  return flags_.At(compress);
}

void CompilationInfo::SetCompress() {
  flags_.Set(compress);
}

void CompilationInfo::UnsetCompress() {
  flags_.UnSet(compress);
}

bool CompilationInfo::PrettyPrint() const {
  return flags_.At(pretty_print);
}

void CompilationInfo::SetPrettyPrint() {
  flags_.Set(pretty_print);
}

void CompilationInfo::UnsetPrettyPrint() {
  flags_.UnSet(pretty_print);
}

bool CompilationInfo::FileScope() const {
  return flags_.At(file_scope);
}

void CompilationInfo::SetFileScope() {
  flags_.Set(file_scope);
}

void CompilationInfo::UnsetFileScope() {
  flags_.UnSet(file_scope);
}

bool CompilationInfo::GlobalScope() const {
  return flags_.At(global_scope);
}
void CompilationInfo::SetGlobalScope() {
  flags_.Set(global_scope);
}

void CompilationInfo::UnsetGlobalScope() {
  flags_.UnSet(global_scope);
}


void CompilationInfo::SetVersion(const char* name) {
  Versions::iterator entry = versions_.find(name);
  if (entry == versions_.end()) {
    versions_.insert(VersionPair(name, 1));
  }
}

void CompilationInfo::UnsetVersion(const char* name) {
  Versions::iterator entry = versions_.find(name);
  if (entry != versions_.end()) {
    versions_.erase(entry);
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

bool CompilationInfo::PrototypeExtensions() const {
  return flags_.At(prototype);
}

void CompilationInfo::SetPrototypeExtensions() {
  flags_.Set(prototype);
}

void CompilationInfo::UnsetPrototypeExtensions() {
  flags_.UnSet(prototype);
}

bool CompilationInfo::ShowOrgName() const {
  return flags_.At(org_name);
}

void CompilationInfo::SetOrgName() {
  flags_.Set(org_name);
}

void CompilationInfo::SetCharset(const char* charset) {
  charset_ = charset;
}

void CompilationInfo::SetLibDirectory(const char* path) {
  std::string dir = path;
  lib_dir_.push_back(dir);
}

void CompilationInfo::SetLibs(const char* path) {
  std::string dir = path;
  libs_.push_back(dir);
}

}
