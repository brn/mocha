#ifndef mocha_internal_h
#define mocha_internal_h

#include <string>
#include "handle.h"
#include "define.h"

namespace mocha {

class Scope;
class Codegen;
class File;
class ParserTracer;
class Ast;
class AstVisitor;
class Compiler;
class AstRoot;
class CodegenVisitor;
class PathInfo;
  
class Internal {
 public:
  typedef enum {
    kFatal,
    kNofatal
  } ErrorLevel;
  Internal ( Handle<PathInfo> path_info,
             Compiler *compiler,
             Scope *scope,
             CodegenVisitor *codegen,
             AstRoot* ast_root );

  inline ~Internal () {};

  void Parse( ErrorLevel level = kFatal );
    
 private :
  inline void LoadFile_ ();
  inline void ParseStart_ ();
  bool file_exist_;
  std::string error_;
  Compiler* compiler_;
  Scope *scope_;
  AstRoot *ast_root_;
  CodegenVisitor *codegen_;
  Handle<File> file_;
  Handle<PathInfo> path_info_;
};
  
}

#endif


