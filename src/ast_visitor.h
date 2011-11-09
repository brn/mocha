
#ifndef AstVisitor_h
#define AstVisitor_h

#include <string>
#include "useconfig.h"
#include "ivisitor.h"

namespace mocha{
  
class Scope;
class Codegen;
class AstState;
class ParserTracer;

#define FORWARD_DECL(name) class name
FORWARD_DECL(AstTree);
FORWARD_DECL(UnaryExp);
FORWARD_DECL(ArrayAccessor);
FORWARD_DECL(DotAccessor);
FORWARD_DECL(NewCallAccessor);
FORWARD_DECL(NewAccessor);
FORWARD_DECL(CallAccessor);
FORWARD_DECL(PostfixExp);
FORWARD_DECL(MultiplicativeExp);
FORWARD_DECL(AdditiveExp);
FORWARD_DECL(ShiftExp);
FORWARD_DECL(RelationalExp);
FORWARD_DECL(EqualityExp);
FORWARD_DECL(BitwiseANDExp);
FORWARD_DECL(BitwiseXORExp);
FORWARD_DECL(BitwiseORExp);
FORWARD_DECL(LogicalANDExp);
FORWARD_DECL(LogicalORExp);
FORWARD_DECL(ConditionalExp);
FORWARD_DECL(Assign);
FORWARD_DECL(FormalParameter);
FORWARD_DECL(Block);
FORWARD_DECL(VariableDeclaration);
FORWARD_DECL(VariableDeclarationList);
FORWARD_DECL(StmtList);
FORWARD_DECL(Expression);
FORWARD_DECL(ExpressionStmt);
FORWARD_DECL(IFStmt);
FORWARD_DECL(Continue);
FORWARD_DECL(Break);
FORWARD_DECL(Return);
FORWARD_DECL(With);
FORWARD_DECL(Label);
FORWARD_DECL(Switch);
FORWARD_DECL(Throw);
FORWARD_DECL(Try);
FORWARD_DECL(Catch);
FORWARD_DECL(Finally);
FORWARD_DECL(Function);
FORWARD_DECL(For);
FORWARD_DECL(ForIn);
FORWARD_DECL(While);
FORWARD_DECL(DoWhile);
FORWARD_DECL(CaseClause);
FORWARD_DECL(CaseClauses);
FORWARD_DECL(DefaultClause);
FORWARD_DECL(Symbol);
FORWARD_DECL(ConstantLiteral);
FORWARD_DECL(Arguments);
FORWARD_DECL(Assign);
FORWARD_DECL(ObjectLiteral);
FORWARD_DECL(ArrayLiteral);
FORWARD_DECL(ElementList);
FORWARD_DECL(ObjectMember);
FORWARD_DECL(NumberLiteral);
FORWARD_DECL(This);
FORWARD_DECL(StringLiteral);
FORWARD_DECL(NullLiteral);
FORWARD_DECL(RegExpLiteral);
FORWARD_DECL(BooleanLiteral);
FORWARD_DECL(UndefinedLiteral);
FORWARD_DECL(Identifier);
FORWARD_DECL(DestructuringAssignment);
FORWARD_DECL(DestructuringObject);
FORWARD_DECL(DestructuringObjectMember);
FORWARD_DECL(DestructuringArray);
#undef FORWARD_DECL

#define DECL_VISITOR(type) void operator () ( type* ast )

class AstVisitor : public IVisitor {
 public :
    
  AstVisitor ( Scope* scope,
               Codegen* codegen,
               const char* modulename,
               const char* filename );
  ~AstVisitor ();
  void BeginClosure ();
  void EndClosure ();
  void setScope ( Scope* scope );
  DECL_VISITOR(AstTree);
  DECL_VISITOR(UnaryExp);
  DECL_VISITOR(ArrayAccessor);
  DECL_VISITOR(DotAccessor);
  DECL_VISITOR(NewCallAccessor);
  DECL_VISITOR(NewAccessor);
  DECL_VISITOR(CallAccessor);
  DECL_VISITOR(PostfixExp);
  DECL_VISITOR(MultiplicativeExp);
  DECL_VISITOR(AdditiveExp);
  DECL_VISITOR(ShiftExp);
  DECL_VISITOR(RelationalExp);
  DECL_VISITOR(EqualityExp);
  DECL_VISITOR(BitwiseANDExp);
  DECL_VISITOR(BitwiseXORExp);
  DECL_VISITOR(BitwiseORExp);
  DECL_VISITOR(LogicalANDExp);
  DECL_VISITOR(LogicalORExp);
  DECL_VISITOR(ConditionalExp);
  DECL_VISITOR(Function);
  DECL_VISITOR(FormalParameter);
  DECL_VISITOR(VariableDeclaration);
  DECL_VISITOR(VariableDeclarationList);
  DECL_VISITOR(StmtList);
  DECL_VISITOR(ArrayLiteral);
  DECL_VISITOR(ObjectLiteral);
  DECL_VISITOR(ElementList);
  DECL_VISITOR(ObjectMember);
  DECL_VISITOR(Arguments);
  DECL_VISITOR(Assign);
  DECL_VISITOR(Block);
  DECL_VISITOR(Expression);
  DECL_VISITOR(ExpressionStmt);
  DECL_VISITOR(IFStmt);
  DECL_VISITOR(DoWhile);
  DECL_VISITOR(While);
  DECL_VISITOR(For);
  DECL_VISITOR(ForIn);
  DECL_VISITOR(Continue);
  DECL_VISITOR(Break);
  DECL_VISITOR(Return);
  DECL_VISITOR(With);
  DECL_VISITOR(Switch);
  DECL_VISITOR(CaseClause);
  DECL_VISITOR(CaseClauses);
  DECL_VISITOR(DefaultClause);
  DECL_VISITOR(Label);
  DECL_VISITOR(Throw);
  DECL_VISITOR(Try);
  DECL_VISITOR(Catch);
  DECL_VISITOR(Finally);
  DECL_VISITOR(ConstantLiteral);
  inline DECL_VISITOR(DestructuringAssignment){};
  inline DECL_VISITOR(DestructuringObject){};
  inline DECL_VISITOR(DestructuringObjectMember){};
  inline DECL_VISITOR(DestructuringArray){};
  //DECL_VISITOR(Name);
#undef DECL_VISITOR
 private:
    
  const char* symbol;
  const char* module_name_;
  const char* filename_;
  Scope* scope_;
  Scope* global_;
  Codegen* codegen_;
  AstState *state_;
  ParserTracer* tracer_;
  std::string indent_;
    
};

}

#endif

