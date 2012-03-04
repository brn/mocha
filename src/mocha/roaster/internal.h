#ifndef mocha_internal_h
#define mocha_internal_h

#include <string>
#include <utils/smart_pointer/ref_count/shared_ptr.h>
#include <define.h>
namespace mocha {
namespace memory {
class Pool;
}
class ScopeRegistry;
class Codegen;
class File;
class ParserTracer;
class Ast;
class AstTransformer;
class Compiler;
class AstRoot;
class CodegenVisitor;
class PathInfo;
class ErrorReporter;
class Internal {
 public:
  typedef enum {
    kFatal,
    kNofatal
  } ErrorLevel;
  Internal (const char* main_file_path,
             bool is_runtime,
             SharedPtr<PathInfo> path_info,
             Compiler *compiler,
             ScopeRegistry *scope_registry,
             CodegenVisitor *codegen,
             AstRoot* ast_root,
             memory::Pool* pool);

  inline ~Internal () {};

  void Parse(ErrorLevel level);
  void GetAst(ErrorLevel level, ErrorReporter* reporter);
 private :
  inline void LoadFile_ ();
  inline void ParseStart_ ();
  inline void OpenError_();
  inline void SyntaxError_(const ParserTracer&);
  inline void GetAst_(ErrorReporter* reporter);

  const char* main_file_path_;
  bool is_runtime_;
  bool file_exist_;
  std::string error_;
  Compiler* compiler_;
  ScopeRegistry *scope_registry_;
  AstRoot *ast_root_;
  CodegenVisitor *codegen_;
  SharedPtr<File> file_;
  SharedPtr<PathInfo> path_info_;
  memory::Pool* pool_;
};
  
}

#endif


