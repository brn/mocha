#include <mocha/roaster/utils/compile_info.h>
#include <mocha/roaster/consts/consts.h>
namespace mocha {

static const int debug = 0;
static const int compress = 1;
static const int pretty_print = 2;

CompileInfo::CompileInfo() {
  versions_.insert(VersionPair(Consts::kVersionAll, 1));
  versions_.insert(VersionPair(Consts::kVersionNone, 1));
}

bool CompileInfo::Debug() {
  return flags_.At(debug);
}

void CompileInfo::SetDebug() {
  flags_.Set(debug);
  versions_.insert(VersionPair(Consts::kVersionDebug, 1));
}

bool CompileInfo::Compress() {
  return flags_.At(compress);
}

void CompileInfo::SetCompress() {
  flags_.Set(compress);
}

bool CompileInfo::PrettyPrint() {
  return flags_.At(pretty_print);
}

void CompileInfo::SetPrettyPrint() {
  flags_.Set(pretty_print);
}

void CompileInfo::SetVersion(const char* name) {
  Versions::iterator entry = versions_.find(name);
  if (entry == versions_.end()) {
    versions_.insert(VersionPair(name, 1));
  }
}

bool CompileInfo::HasVersion(const char* name) {
  Versions::iterator entry = versions_.find(name);
  if (entry == versions_.end()) {
    return false;
  } else {
    return true;
  }
}

}
