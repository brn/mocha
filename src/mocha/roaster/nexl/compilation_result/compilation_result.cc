#include <mocha/roaster/nexl/compilation_result/compilation_result.h>

namespace mocha {

CompilationResult::CompilationResult(SharedPtr<os::fs::Path> path,  CodeHandle visitor, ErrorHandle reporter, DepsListHandle handle)
    : path_(path),
      codegen_(visitor),
      reporter_(reporter),
      deps_(handle){}


}
