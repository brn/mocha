#ifndef mocha_visitor_base_h_
#define mocha_visitor_base_h_
#include <mocha/roaster/ast/ast_foward_decl.h>

namespace mocha {
#ifdef DEBUG
//#define PRINTABLE
#endif
#define DECL_VISITOR(type) virtual void Visit##type(type* ast) = 0

class IVisitor {
 public :
  DECL_VISITOR(AstRoot);
  DECL_VISITOR(FileRoot);
  DECL_VISITOR(Statement);
  DECL_VISITOR(NodeList);
  DECL_VISITOR(StatementList);
  DECL_VISITOR(VersionStmt);
  DECL_VISITOR(BlockStmt);
  DECL_VISITOR(ModuleStmt);
  DECL_VISITOR(ExportStmt);
  DECL_VISITOR(ImportStmt);
  DECL_VISITOR(VariableStmt);
  DECL_VISITOR(LetStmt);
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
  DECL_VISITOR(AssertStmt);
  DECL_VISITOR(SourceStmt);
  DECL_VISITOR(IncludeStmt);
  DECL_VISITOR(CaseClause);
  DECL_VISITOR(Expression);
  DECL_VISITOR(VariableDeclarationList);
  DECL_VISITOR(Trait);
  DECL_VISITOR(Class);
  DECL_VISITOR(ClassProperties);
  DECL_VISITOR(ClassExpandar);
  DECL_VISITOR(ClassMember);
  DECL_VISITOR(Function);
  DECL_VISITOR(CallExp);
  DECL_VISITOR(NewExp);
  DECL_VISITOR(YieldExp);
  DECL_VISITOR(PostfixExp);
  DECL_VISITOR(UnaryExp);
  DECL_VISITOR(BinaryExp);
  DECL_VISITOR(CompareExp);
  DECL_VISITOR(ConditionalExp);
  DECL_VISITOR(AssignmentExp);
  DECL_VISITOR(Literal);
  DECL_VISITOR(ArrayLikeLiteral);
  DECL_VISITOR(ObjectLikeLiteral);
  DECL_VISITOR(GeneratorExpression);
};

}
#undef DECL_VISITOR
#endif
