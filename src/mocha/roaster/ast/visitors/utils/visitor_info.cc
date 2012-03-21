#include <mocha/roaster/platform/fs/fs.h>
#include <mocha/fileinfo/fileinfo.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/dsta_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/xml/xml_setting_info.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/platform/fs/fs.h>

namespace mocha {

void CreateRelativePath(const char* base, const char* target, std::string *buffer) {
  os::fs::Path base_path_info(base);
  os::fs::Path target_path_info(target);
  std::string relative_path;
  os::fs::Path::relative_path(base_path_info.directory(), target_path_info.directory(), &relative_path);
  buffer->assign("'");
  buffer->append(relative_path.c_str());
  buffer->append(target_path_info.filename());
  buffer->append("'");
}

VisitorInfo::VisitorInfo(bool is_runtime, ScopeRegistry* scope_registry, Compiler *compiler,
                          DstaExtractedExpressions* dsta_exp, const char* main_file_path, const char* file_name) :
    tmp_index_(0), object_depth_(0), is_in_class_(0) ,is_in_module_(0),
    main_file_path_(main_file_path), file_name_(file_name),
    compile_info_(compiler->compilation_info()) ,dsta_exp_(dsta_exp),
    scope_registry_(scope_registry), compiler_(compiler), current_stmt_(0), current_fn_(0),
    builder_(AstBuilder::Local()){
  if (is_runtime){
    bit_vector_.Set(2);
  }
  CreateRelativePath(file_name, main_file_path, &relative_path_);
};

}
