#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/ast.h>
#include <utils/xml/xml_setting_info.h>
#include <utils/pool/managed_handle.h>
namespace mocha {

VisitorInfo::VisitorInfo( bool is_runtime , Scope* scope , Compiler *compiler,
                          DstaExtractedExpressions* dsta_exp , const char* main_file_path , const char* file_name ) :
    tmp_index_( 0 ) , is_dst_injection_( false ), is_rest_injection_( false ) , is_runtime_( is_runtime ),
    is_in_class_( false ) ,is_in_module_( 1 ), main_file_path_( main_file_path ),file_name_( file_name ),
    version_( XMLSettingInfo::GetVersion( main_file_path ) ) ,dsta_exp_( dsta_exp ),
    scope_( scope ) , compiler_( compiler ) , current_stmt_( 0 ) {};

}
