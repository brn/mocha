#ifndef mocha_run_v8_h_
#define mocha_run_v8_h_
#include <third_party/v8/include/v8.h>
#include <ast/ast_foward_decl.h>

namespace mocha {
class ProcessorInfo;
class RunV8 {
 public :
  RunV8( ProcessorInfo* info );
  void Init();
  ~RunV8();
  AstNode* Run();
 private :
  v8::Persistent<v8::ObjectTemplate> global_;
  v8::Persistent<v8::Object> global_object_;
  v8::Persistent<v8::Context> context_;
  v8::Persistent<v8::Script> env_;
  ProcessorInfo* info_;
};

}

#endif
