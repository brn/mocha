#ifndef mocha_roaster_ast_analyzer_h_
#define mocha_roaster_ast_analyzer_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {
class JSValue;
class CompilationInfo;
class Analyzer {
public :
  Analyzer(CompilationInfo* info);
  ~Analyzer(){}
#define DECL_VISITOR(type) JSValue* Visit##type (type* ast)
  DECL_VISITOR(AstRoot);
  DECL_VISITOR(FileRoot);
  DECL_VISITOR(Statement);
  DECL_VISITOR(NodeList);
  DECL_VISITOR(StatementList);
  DECL_VISITOR(VersionStmt);
  DECL_VISITOR(BlockStmt);
  DECL_VISITOR(VariableStmt);
  DECL_VISITOR(ExpressionStmt);
  DECL_VISITOR(IFStmt);
  DECL_VISITOR(IterationStmt);
  DECL_VISITOR(ContinueStmt);
  DECL_VISITOR(BreakStmt);
  DECL_VISITOR(ReturnStmt);
  DECL_VISITOR(WithStmt);
  DECL_VISITOR(LabelledStmt);
  DECL_VISITOR(SwitchStmt);
  DECL_VISITOR(ThrowStmt);
  DECL_VISITOR(TryStmt);
  DECL_VISITOR(CaseClause);
  DECL_VISITOR(Expression);
  DECL_VISITOR(Function);
  DECL_VISITOR(CallExp);
  DECL_VISITOR(NewExp);
  DECL_VISITOR(PostfixExp);
  DECL_VISITOR(UnaryExp);
  DECL_VISITOR(BinaryExp);
  DECL_VISITOR(CompareExp);
  DECL_VISITOR(ConditionalExp);
  DECL_VISITOR(AssignmentExp);
  DECL_VISITOR(Literal);
  DECL_VISITOR(ArrayLikeLiteral);
  DECL_VISITOR(ObjectLikeLiteral);
  DECL_VISITOR(VariableDeclarationList);
#undef DECL_VISITOR
 private :
  JSValue* ArrayAccessorProccessor_(CallExp* exp);
  JSValue* DotAccessorProccessor_(CallExp* exp);
  JSValue* NewCallProccessor_(CallExp* exp);
  JSValue* NormalFunctionCall_(CallExp* exp);
  JSValue* ArrayProccessor_(AstNode* ast_node);
  JSValue* ObjectProccessor_(AstNode* ast_node);
  CompilationInfo* info_;
  memory::Pool pool_;
  Scope* scope_;
};
}

#endif
