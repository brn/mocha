#include <compiler/external/external_resource.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/ast.h>
#include <utils/xml/xml_setting_info.h>
#include <utils/pool/managed_handle.h>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/file_system/file_system.h>
namespace mocha {

void CreateRelativePath( const char* base , const char* target , std::string *buffer ) {
  Handle<PathInfo> base_path_info = FileSystem::GetPathInfo( base );
  Handle<PathInfo> target_path_info = FileSystem::GetPathInfo( target );
  StrHandle handle = FileSystem::GetModuleKey( base_path_info->GetDirPath().Get() , target_path_info->GetDirPath().Get() );
  buffer->assign( "'" );
  buffer->append( handle.Get() );
  buffer->append( target_path_info->GetFileName().Get() );
  buffer->append( "'" );
}

VisitorInfo::VisitorInfo( bool is_runtime , Scope* scope , Compiler *compiler,
                          DstaExtractedExpressions* dsta_exp , const char* main_file_path , const char* file_name ) :
    tmp_index_( 0 ) , object_depth_( 0 ) , is_in_class_( 0 ) ,is_in_module_( 0 ),
    main_file_path_( main_file_path ) , file_name_( file_name ),
    compile_info_( ExternalResource::SafeGet( main_file_path )->GetCompileInfo() ) ,dsta_exp_( dsta_exp ),
    scope_( scope ) , compiler_( compiler ) , current_stmt_( 0 ) , current_fn_( 0 ) {
  if ( is_runtime ){
    bit_vector_.Set( 2 );
  }
  CreateRelativePath( main_file_path , file_name , &relative_path_ );
};

}
