#include <mocha/roaster/utils/compile_result.h>

namespace mocha {

CompilationResult::CompilationResult(const char* filename, SharedPtr<CodegenVisitor> visitor, ErrorMapHandle map) :
    visitor_(visitor), map_(map) {
  filename_ = filename;
}


}
