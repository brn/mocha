#ifndef mocha_visitor_decl_h_
#define mocha_visitor_decl_h_

#define DECL_VISITOR(type) void Accept##type ( type* ast )
  DECL_VISITOR(AstRoot);
  DECL_VISITOR(FileRoot);
  DECL_VISITOR(Statement);
  DECL_VISITOR(StatementList);
  DECL_VISITOR(BlockStmt);
  DECL_VISITOR(ModuleStmt);
  DECL_VISITOR(ExportStmt);
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
  DECL_VISITOR(ValueNode);
#undef DECL_VISITOR

#endif