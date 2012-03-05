#ifndef mocha_internal_h
#define mocha_internal_h

#include <string>
#include <mocha/roaster/smart_pointer/ref_count/shared_ptr.h>
#include <define.h>
namespace mocha {
namespace memory {
class Pool;
}
class ScopeRegistry;
class Codegen;
class File;
class Ast;
class AstTransformer;
class Compiler;
class AstRoot;
class CodegenVisitor;
class PathInfo;
class ErrorReporter;
class Internal {
  typedef SharedPtr<File> FileHandle;
 public:
  typedef enum {
    kFatal,
    kNofatal
  } ErrorLevel;
  Internal (FileSystem::Path* path, Compiler* compiler, CodegenVisitor* codegen,
            ScopeRegistry *scope_registry, bool is_runtime,
            AstRoot* ast_root, memory::Pool* pool);
  inline ~Internal () {};
  void Parse(ErrorLevel level);
  void GetAst(ErrorLevel level, ErrorReporter* reporter);
 private :
  inline File* file() { return file_.Get(); }
  inline bool exist() const { return file_exist_; }
  inline Compiler* compiler() const { return compiler_; }
  inline void ParseStart(bool is_ast);
  inline void RunAction(bool is_ast);
  inline void LoadFile();
  inline void DoParse(bool is_ast);
  inline void OpenError();
  bool is_runtime_;
  bool file_exist_;
  FileSystem::Path* path_;
  std::string error_;
  Compiler* compiler_;
  CodegenVisitor* codegen_;
  ScopeRegistry *scope_registry_;
  AstRoot *ast_root_;
  memory::Pool* pool_;
  FileHandle file_;
};
  
}

#endif


