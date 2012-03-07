#include <mocha/roaster/utils/compilation_result.h>

namespace mocha {

CompilationResult::CompilationResult(const char* filename, SharedPtr<CodegenVisitor> visitor, ErrorMapHandle map) :
    visitor_(visitor), map_(map) {
  filename_ = filename;
}


}
