#include <mocha/roaster/nexl/compilation_result/compilation_result.h>

namespace mocha {

CompilationResult::CompilationResult(const char* filename,  CodeHandle visitor, ErrorHandle reporter)
    : filename_(filename), codegen_(visitor), reporter_(reporter) {}


}
