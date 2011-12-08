#include <ast/visitors/utils/visitor_info.h>
namespace mocha {

VisitorInfo::VisitorInfo( Scope* scope , Compiler *compiler,
                          DstaExtractedExpressions* dsta_exp , const char* module_name , const char* file_name ) :
    tmp_index_( 0 ), is_dst_injection_( false ), module_name_( module_name ),
    file_name_( file_name ) , dsta_exp_( dsta_exp ),
    scope_( scope ) , compiler_( compiler ) , current_stmt_( 0 ){};

}
