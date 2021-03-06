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
FOWARD_DECL(VersionStmt);
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
FOWARD_DECL(AssertStmt);
FOWARD_DECL(SourceStmt);
FOWARD_DECL(IncludeStmt);
FOWARD_DECL(CaseClause);
FOWARD_DECL(Expression);
FOWARD_DECL(VariableDeclarationList);
FOWARD_DECL(Trait);
FOWARD_DECL(MixinMember);
FOWARD_DECL(TraitMember);
FOWARD_DECL(Class);
FOWARD_DECL(ClassProperties);
FOWARD_DECL(ClassExpandar);
FOWARD_DECL(ClassMember);
FOWARD_DECL(Function);
FOWARD_DECL(Property);
FOWARD_DECL(CallExp);
FOWARD_DECL(NewExp);
FOWARD_DECL(YieldExp);
FOWARD_DECL(YieldMark);
FOWARD_DECL(ExYieldStateNode);
FOWARD_DECL(PostfixExp);
FOWARD_DECL(UnaryExp);
FOWARD_DECL(BinaryExp);
FOWARD_DECL(CompareExp);
FOWARD_DECL(ConditionalExp);
FOWARD_DECL(AssignmentExp);
FOWARD_DECL(Literal);
FOWARD_DECL(ArrayLikeLiteral);
FOWARD_DECL(ObjectLikeLiteral);
FOWARD_DECL(GeneratorExpression);
FOWARD_DECL(DstaTree);
FOWARD_DECL(DstaExtractedExpressions);
#undef FOWARD_DECL
}
#endif
