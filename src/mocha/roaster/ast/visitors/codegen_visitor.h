#ifndef mocha_codegen_visitor_h_
#define mocha_codegen_visitor_h_

#include <string>
#include <vector>
#include <mocha/roaster/lib/unordered_map.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/ast/visitors/utils/codegenerator_utils.h>

namespace mocha {
namespace memory {
class Pool;
}
class Compiler;
class CodeWriter;
class NodeIterator;
class Scope;
class CompilationInfo;
class AstBuilder;
class CodegenVisitor : public IVisitor {
  typedef std::pair<const char*, bool> IncludePair;
  typedef roastlib::unordered_map<std::string, bool> IncludeGuard;
 public :
  CodegenVisitor(CompilationInfo* info);
  CodegenVisitor(bool is_pretty_print, bool is_debug, CompilationInfo* info);
  ~CodegenVisitor(){};
#include <mocha/roaster/ast/visitors/visitor_decl.h>
  inline void Write(const char* code) { stream_->Write(code); }
  inline const char* GetCode() { return stream_->Get()->GetData(); }
 private :
  void ForProccessor_(IterationStmt* iter);
  void ForInProccessor_(IterationStmt* iter);
  void DoWhileProccessor_(IterationStmt* iter);
  void WhileProccessor_(IterationStmt* iter);
  void VarListProcessor_(AstNode* ast_node);
  void JumpStmt_(AstNode* ast_node, int type);
  void ArrayAccessorProccessor_(CallExp* exp);
  void DotAccessorProccessor_(CallExp* exp);
  void NormalFunctionCall_(CallExp* exp);
  void ArrayProccessor_(AstNode* ast_node);
  void ObjectProccessor_(NodeList* ast_node);
  void VarInitialiserProccessor_(Literal* ast_node);
  void BeginState_(int state);
  void EndLastState_();
  int CurrentState_();
  bool MatchState_(int state);
  CodeWriter* writer() { return writer_.Get(); }
  CodeStream* stream() { return stream_.Get(); }
  int depth_;
  bool is_line_;
  bool has_rest_;
  bool is_pretty_print_;
  const char* filename_;
  std::vector<int> state_;
  Scope* scope_;
  CompilationInfo* info_;
  CodeBuffer default_buffer_;
  ScopedPtr<CodeStream> stream_;
  ScopedPtr<CodeWriter> writer_;
  FileRoot* current_root_;
  IncludeGuard include_guard_;
};
}

#endif
