#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/dsta_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/misc/xml/xml_setting_info.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/file_system/file_system.h>
namespace mocha {

void CreateRelativePath(const char* base, const char* target, std::string *buffer) {
  SharedPtr<PathInfo> base_path_info = FileSystem::GetPathInfo(base);
  SharedPtr<PathInfo> target_path_info = FileSystem::GetPathInfo(target);
  SharedStr handle = FileSystem::GetModuleKey(base_path_info->GetDirPath().Get(), target_path_info->GetDirPath().Get());
  buffer->assign("'");
  buffer->append(handle.Get());
  buffer->append(target_path_info->GetFileName().Get());
  buffer->append("'");
}

VisitorInfo::VisitorInfo(bool is_runtime, ScopeRegistry* scope_registry, Compiler *compiler,
                          DstaExtractedExpressions* dsta_exp, const char* main_file_path, const char* file_name) :
    tmp_index_(0), object_depth_(0), is_in_class_(0) ,is_in_module_(0),
    main_file_path_(main_file_path), file_name_(file_name),
    compile_info_(ExternalResource::SafeGet(main_file_path)->GetCompileInfo()) ,dsta_exp_(dsta_exp),
    scope_registry_(scope_registry), compiler_(compiler), current_stmt_(0), current_fn_(0),
    builder_(AstBuilder::Local()){
  if (is_runtime){
    bit_vector_.Set(2);
  }
  CreateRelativePath(main_file_path, file_name, &relative_path_);
};

}
