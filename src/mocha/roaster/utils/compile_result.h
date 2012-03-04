#ifndef mocha_compile_result_h_
#define mocha_compile_result_h_
#include <string>
#include <utils/smart_pointer/ref_count/shared_ptr.h>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
namespace mocha {

class CompileResult {
 public :
  CompileResult(const char* filename, SharedPtr<CodegenVisitor> visitor, ErrorMapHandle map);
  ~CompileResult(){}
  const char* GetFilename() { return filename_.c_str(); }
  const char* GetSource() { return visitor_->GetCode(); }
  const ErrorMap& GetErrorMap() { return *(map_.Get()); }
 private :
  std::string filename_;
  SharedPtr<CodegenVisitor> visitor_;
  ErrorMapHandle map_;
};

}

#endif
