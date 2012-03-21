#ifndef mocha_internal_h
#define mocha_internal_h

#include <string>
#include <mocha/roaster/roaster.h>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <define.h>
namespace mocha {
namespace memory {
class Pool;
}
namespace os {
namespace fs {
class File;
}
}
class ScopeRegistry;
class Codegen;
class Ast;
class AstTransformer;
class Compiler;
class AstRoot;
class CodegenVisitor;
class PathInfo;
class ErrorReporter;
typedef SharedPtr<os::fs::File> FileHandle;
class Internal {
 public:
  typedef enum {
    kFatal,
    kNofatal
  } ErrorLevel;
  Internal (const char* path, Compiler* compiler, CodegenVisitor* codegen,
            ScopeRegistry *scope_registry, bool is_runtime,
            AstRoot* ast_root, memory::Pool* pool);
  inline ~Internal () {};
  void Parse(ErrorLevel level);
  void GetAst(ErrorLevel level);
 private :
  inline os::fs::File* file() { return file_.Get(); }
  inline bool exist() const { return file_exist_; }
  inline Compiler* compiler() const { return compiler_; }
  inline void ParseStart(bool is_ast, ErrorLevel level);
  inline void RunAction(bool is_ast, ErrorLevel level);
  inline void LoadFile();
  inline void DoParse(bool is_ast);
  inline void OpenError(const char* filename);
  bool is_runtime_;
  bool file_exist_;
  const char* path_;
  std::string error_;
  Compiler* compiler_;
  CodegenVisitor* codegen_;
  ScopeRegistry *scope_registry_;
  AstRoot *ast_root_;
  memory::Pool* pool_;
  FileHandle file_;
  ErrorHandler reporter_;
};
  
}

#endif


