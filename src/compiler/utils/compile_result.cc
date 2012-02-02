#include <compiler/utils/compile_result.h>

namespace mocha {

CompileResult::CompileResult( const char* filename , Handle<CodegenVisitor> visitor , ErrorMapHandle map ) :
    filename_( filename ) , visitor_( visitor ) , map_( map ) {}


}
