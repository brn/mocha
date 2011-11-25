#ifndef mocha_ast_foward_decl_h_
#define mocha_ast_foward_decl_h_

namespace mocha {
#define FOWARD_DECL(name) class name
FOWARD_DECL(AstNode);
FOWARD_DECL(NodeList);
FOWARD_DECL(Empty);
FOWARD_DECL(AstRoot);
FOWARD_DECL(FileRoot);
FOWARD_DECL(Statement);
FOWARD_DECL(StatementList);
FOWARD_DECL(BlockStmt);
FOWARD_DECL(ModuleStmt);
FOWARD_DECL(ExportStmt);
FOWARD_DECL(ImportStmt);
FOWARD_DECL(VariableStmt);
FOWARD_DECL(LetStmt);
FOWARD_DECL(ExpressionStmt);
FOWARD_DECL(IFStmt);
FOWARD_DECL(IterationStmt);
FOWARD_DECL(ContinueStmt);
FOWARD_DECL(BreakStmt);
FOWARD_DECL(ReturnStmt);
FOWARD_DECL(WithStmt);
FOWARD_DECL(LabelledStmt);
FOWARD_DECL(SwitchStmt);
FOWARD_DECL(ThrowStmt);
FOWARD_DECL(TryStmt);
FOWARD_DECL(CaseClause);
FOWARD_DECL(Expression);
FOWARD_DECL(Function);
FOWARD_DECL(CallExp);
FOWARD_DECL(NewExp);
FOWARD_DECL(PostfixExp);
FOWARD_DECL(UnaryExp);
FOWARD_DECL(BinaryExp);
FOWARD_DECL(CompareExp);
FOWARD_DECL(ConditionalExp);
FOWARD_DECL(AssignmentExp);
FOWARD_DECL(ValueNode);
FOWARD_DECL(TokenInfo);
#undef FOWARD_DECL
}
#endif
