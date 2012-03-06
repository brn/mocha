#ifndef mocha_compile_result_h_
#define mocha_compile_result_h_
#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/utils/error_reporter.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
namespace mocha {

class CompilationResult {
 public :
  CompilationResult(const char* filename, SharedPtr<CodegenVisitor> visitor, ErrorMapHandle map);
  ~CompilationResult(){}
  const char* filename() { return filename_.c_str(); }
  const char* source() { return visitor_->GetCode(); }
  const ErrorMap& error_map() { return *(map_.Get()); }
 private :
  std::string filename_;
  SharedPtr<CodegenVisitor> visitor_;
  ErrorMapHandle map_;
};

}

#endif
