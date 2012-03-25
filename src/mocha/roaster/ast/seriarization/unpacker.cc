#include <stdio.h>
#include <string.h>
#include <math.h>
#include <mocha/roaster/log/logging.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/seriarization/unpacker.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/memory/pool.h>
namespace mocha {

#define PRINT(name) DEBUG_LOG(Info, "Enter "#name)

UnPacker::UnPacker(Packed* packed, memory::Pool* pool)
    : current_type_(0),
      current_(0),
      packed_(packed),
      pool_(pool){}

AstNode* UnPacker::Unpack() {
  return UnpackEachNode();
}

AstNode* UnPacker::UnpackEachNode() {
  int type = Advance();
  current_type_ = type;
  DEBUG_LOG(Info,"next type = %d", type);
  switch (type) {
    case -1 :
    case AstNode::kEmpty :
      return new(pool_) Empty();
    case AstNode::kNodeList :
      return CaseNodeList();
    case AstNode::kAstRoot :
      return CaseAstRoot();
    case AstNode::kFileRoot :
      return CaseFileRoot();
    case AstNode::kStatementList :
      return CaseStatementList();
    case AstNode::kBlockStmt :
      return CaseBlockStmt();
    case AstNode::kVersionStmt :
      return CaseVersionStmt();
    case AstNode::kVariableStmt :
      return CaseVariableStmt();
    case AstNode::kExpressionStmt :
      return CaseExpressionStmt();
    case AstNode::kIFStmt :
      return CaseIFStmt();
      
    case AstNode::kForIn :
    case AstNode::kForInWithVar :
    case AstNode::kFor :
    case AstNode::kForWithVar :
    case AstNode::kWhile :
    case AstNode::kDoWhile :
      return CaseIterationStmt();
    case AstNode::kContinueStmt :
      return CaseContinueStmt();
    case AstNode::kBreakStmt :
      return CaseBreakStmt();
    case AstNode::kReturnStmt :
      return CaseReturnStmt();
    case AstNode::kWithStmt :
      return CaseWithStmt();
    case AstNode::kLabelledStmt :
      return CaseLabelledStmt();
    case AstNode::kSwitchStmt :
      return CaseSwitchStmt();
    case AstNode::kThrowStmt :
      return CaseThrowStmt();
    case AstNode::kTryStmt :
      return CaseTryStmt();
    case AstNode::kAssertStmt :
      return CaseAssertStmt();
    case AstNode::kCase :
      return CaseCaseClause();
    case AstNode::kExpression :
      return CaseExpression();
    case AstNode::kVariableDeclarationList :
      return CaseVarDeclList();
    case AstNode::kClass :
      return CaseClass();
    case AstNode::kFunction :
      return CaseFunction();
    case AstNode::kCallExp :
      return CaseCallExp();
    case AstNode::kNewExp :
      return CaseNewExp();
    case AstNode::kPostfixExp :
      return CasePostfixExp();
    case AstNode::kUnaryExp :
      return CaseUnaryExp();
    case AstNode::kBinaryExp :
      return CaseBinaryExp();
    case AstNode::kCompareExp :
      return CaseCompareExp();
    case AstNode::kConditionalExp :
      return CaseConditionalExp();
    case AstNode::kAssignmentExp :
      return CaseAssignmentExp();
    case AstNode::kLiteral :
      return CaseLiteral();
    case AstNode::kArrayLikeLiteral :
      return CaseArray();
    case AstNode::kObjectLikeLiteral :
      return CaseObject();
    default :
      FATAL("unexpected type.");
  }
}

template <typename AstType, bool>
struct Instaniater{
  static AstType* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {}
};

template <typename AstType>
struct Instaniater<AstType, true>{
  static AstType* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return new(pool) AstType(line);
  }
};

template <typename AstType>
struct Instaniater<AstType, false>{
  static AstType* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return new(pool) AstType;
  }
};

template <>
struct Instaniater<FileRoot, true>{
  static FileRoot* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    std::string filename;
    unpacker->UnpackChar(&filename);
    bool runtime = (unpacker->Advance() == 1)? true : false;
    bool strict = (unpacker->Advance() == 1)? true : false;
    DEBUG_LOG(Log, "file %s", filename.c_str());
    FileRoot* ast = new(pool) FileRoot(filename.c_str());
    if (runtime) {
      ast->set_runtime();
    }
    if (strict) {
      ast->MarkAsStrict();
    }
    return ast;
  }
};

template <>
struct Instaniater<VersionStmt, true>{
  static VersionStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    TokenInfo* info = unpacker->UnpackToken();
    return new(pool) VersionStmt(info, line);
  }
};

template <>
struct Instaniater<IterationStmt, true> {
  static IterationStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    IterationStmt* ast = new(pool) IterationStmt(unpacker->current_type_, line);
    ast->set_expression(unpacker->UnpackEachNode());
    return ast;
  }
};

template <>
struct Instaniater<Expression, true> {
  static Expression* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    Expression* exp = new(pool) Expression(line);
    bool parenthesis = unpacker->Advance() == 1? true : false;
    if (parenthesis) {
      exp->MarkParenthesis();
    }
    return exp;
  }
};

template <>
struct Instaniater<CallExp, true> {
  static CallExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    int type = unpacker->Advance();
    bool rest = unpacker->Advance() == 1? true : false;
    CallExp* ast = new(pool) CallExp(type, line);
    ast->set_callable(unpacker->UnpackEachNode());
    ast->set_args(unpacker->UnpackEachNode());
    if (rest) {
      ast->set_rest();
    }
    return ast;
  }
};

template <typename T>
T* UnPacker::MakeUnary(int64_t line) {
  int type = Advance();
  return new(pool_) T(type, UnpackEachNode(), line);
}

template <typename T>
T* UnPacker::MakeBinary(int64_t line) {
  int type = Advance();
  return new(pool_) T(type, UnpackEachNode(), UnpackEachNode(), line);
}

template <>
struct Instaniater<PostfixExp, true> {
  static PostfixExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return unpacker->MakeUnary<PostfixExp>(line);
  }
};

template <>
struct Instaniater<UnaryExp, true> {
  static UnaryExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return unpacker->MakeUnary<UnaryExp>(line);
  }
};

template <>
struct Instaniater<BinaryExp, true> {
  static BinaryExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return unpacker->MakeBinary<BinaryExp>(line);
  }
};

template <>
struct Instaniater<AssignmentExp, true> {
  static AssignmentExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return unpacker->MakeBinary<AssignmentExp>(line);
  }
};

template <>
struct Instaniater<CompareExp, true> {
  static CompareExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return unpacker->MakeBinary<CompareExp>(line);
  }
};

template <>
struct Instaniater<ConditionalExp, true> {
  static ConditionalExp* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return new(pool) ConditionalExp(unpacker->UnpackEachNode(), unpacker->UnpackEachNode(),
                                    unpacker->UnpackEachNode(), line);
  }
};

template <>
struct Instaniater<Literal, true> {
  static Literal* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    int type = unpacker->Advance();
    Literal* ast = new(pool) Literal(type, line);
    if (unpacker->Advance() == 1) {
      ast->set_value(unpacker->UnpackToken());
      DEBUG_LOG(Info, "now unpacing token %s", ast->value()->token());
    }
    if (unpacker->Advance() == 1) {
      ast->set_node(unpacker->UnpackEachNode());
    }
    if (unpacker->Advance() == 1) {
      DEBUG_LOG(Log, "now unpacking literal child");
      ast->AddChild(unpacker->UnpackEachNode());
    }
    return ast;
  }
};

template <>
struct Instaniater<Function, true> {
  static Function* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    Function *fn = new(pool) Function(line);
    if (unpacker->Advance() == 1) {
      fn->MarkAsConstDeclaration();
    }
    if (unpacker->Advance() == 1) {
      fn->MarkAsDeclaration();
    }
    if (unpacker->Advance() == 1) {
      fn->MarkAsRoot();
    }
    if (unpacker->Advance() == 1) {
      fn->MarkAsStrict();
    }
    int argc = unpacker->Advance();
    if (argc > 0) {
      NodeList* list = new(pool) NodeList;
      for (int i = 0; i < argc; i++) {
        AstNode* ast = unpacker->UnpackEachNode();
        list->AddChild(ast);
      }
      fn->set_argv(list);
    } else {
      fn->set_argv(new(pool) Empty());
    }
    if (unpacker->Current() != AstNode::kEmpty) {
      DEBUG_LOG(Log, "has name");
      fn->set_name(unpacker->UnpackEachNode());
    } else {
      fn->set_name(new(pool) Empty);
      unpacker->Advance();
    }
    return fn;
  }
};


template <>
struct Instaniater<IFStmt, true> {
  static IFStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    IFStmt *stmt = new(pool) IFStmt(line);
    stmt->set_condition(unpacker->UnpackEachNode());
    stmt->set_then_statement(unpacker->UnpackEachNode());
    stmt->set_else_statement(unpacker->UnpackEachNode());
    return stmt;
  }
};

template <typename T>
T* MakeExpressionOnlyAst(memory::Pool* pool, AstNode* node, int64_t line) {
  T* ast = new(pool) T(line);
  ast->set_expression(node);
  return ast;
}

template <>
struct Instaniater<WithStmt, true> {
  static WithStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return MakeExpressionOnlyAst<WithStmt>(pool, unpacker->UnpackEachNode(), line);
  }
};

template <>
struct Instaniater<SwitchStmt, true> {
  static SwitchStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return MakeExpressionOnlyAst<SwitchStmt>(pool, unpacker->UnpackEachNode(), line);
  }
};

template <>
struct Instaniater<CaseClause, true> {
  static CaseClause* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return MakeExpressionOnlyAst<CaseClause>(pool, unpacker->UnpackEachNode(), line);
  }
};

template <>
struct Instaniater<ThrowStmt, true> {
  static ThrowStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return MakeExpressionOnlyAst<ThrowStmt>(pool, unpacker->UnpackEachNode(), line);
  }
};

template <>
struct Instaniater<TryStmt, true> {
  static TryStmt* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    TryStmt* stmt = new(pool) TryStmt(line);
    stmt->set_catch_block(unpacker->UnpackEachNode());
    stmt->set_finally_block(unpacker->UnpackEachNode());
    return stmt;
  }
};

template <>
struct Instaniater<VariableDeclarationList, true> {
  static VariableDeclarationList* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    VariableDeclarationList* list = new(pool) VariableDeclarationList(line);
    if (unpacker->Advance() == 1) {
      list->MarkAsConstDeclaration();
    }
    if (unpacker->Advance() == 1) {
      list->MarkAsLetDeclaration();
    }
    return list;
  }
};

struct MaterializedLiteralTag{};

template <>
struct Instaniater<MaterializedLiteralTag, true> {
  template <typename T>
  static T* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    T* literal = new(pool) T(line);
    int size = unpacker->Advance();
    DEBUG_LOG(Info, "materiarized literal size %d", size);
    for (int i = 0; i < size; i++) {
      literal->set_element(unpacker->UnpackEachNode());
    }
    return literal;
  }
};

template <>
struct Instaniater<ArrayLikeLiteral, true> {
  static ArrayLikeLiteral* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return Instaniater<MaterializedLiteralTag, true>::Make<ArrayLikeLiteral>(unpacker, pool, line);
  }
};

template <>
struct Instaniater<ObjectLikeLiteral, true> {
  static ObjectLikeLiteral* Make(UnPacker* unpacker, memory::Pool* pool, int64_t line) {
    return Instaniater<MaterializedLiteralTag, true>::Make<ObjectLikeLiteral>(unpacker, pool, line);
  }
};

template <typename AstType, bool line>
AstNode* UnPacker::MakeBaseAst() {
  int line1 = Advance();
  int line2 = Advance();
  int child_length = Advance();
  AstType* ast = Instaniater<AstType,line>::Make(this, pool_, (line1 + line2));
  DEBUG_LOG(Log, "%s child length %d", ast->node_name(), child_length);
  if (child_length > 0) {
    for (int i = 0; i < child_length; i++) {
      DEBUG_LOG(Log, "now unpacking children");
      AstNode* node = UnpackEachNode();
      ast->AddChild(node);
    }
  }
  DEBUG_LOG(Log ,"End %s", ast->node_name());
  return ast;
}

void UnPacker::UnpackChar(std::string* buf) {
  int size = Advance();
  DEBUG_LOG(Log, "size = %d", size);
  std::stringstream st;
  while (size) {
    st << static_cast<char>(Advance());
    size--;
  }
  buf->assign(st.str());
}

TokenInfo* UnPacker::UnpackToken() {
  int type = Advance();
  bool const_decl = Advance() == 1? true : false;
  std::string token;
  UnpackChar(&token);
  int line1 = Advance();
  int line2 = Advance();
  TokenInfo* info = new(pool_) TokenInfo(token.c_str(), type, (line1 + line2));
  if (const_decl) {
    info->set_const_declaration();
  }
  return info;
}

AstNode* UnPacker::CaseAstRoot() {
  PRINT(AstRoot);
  return MakeBaseAst<AstRoot,false>();
}

AstNode* UnPacker::CaseFileRoot() {
  PRINT(FileRoot);
  return MakeBaseAst<FileRoot,true>();
}


AstNode* UnPacker::CaseNodeList() {
  PRINT(NodeList);
  return MakeBaseAst<NodeList,false>();
}


AstNode* UnPacker::CaseBlockStmt() {
  PRINT(BlockStmt);
  return MakeBaseAst<BlockStmt,true>();
}

AstNode* UnPacker::CaseVersionStmt() {
  PRINT(VersionStmt);
  return MakeBaseAst<VersionStmt, true>();
}

AstNode* UnPacker::CaseAssertStmt() {
  PRINT(AssertStmt);
  return MakeBaseAst<AssertStmt, true>();
}


AstNode* UnPacker::CaseStatementList() {
  PRINT(StatementList);
  return MakeBaseAst<StatementList, false>();
}


AstNode* UnPacker::CaseVariableStmt() {
  PRINT(VariableStmt);
  return MakeBaseAst<VariableStmt, true>();
}


AstNode* UnPacker::CaseExpressionStmt() {
  PRINT(ExpressionStmt);
  return MakeBaseAst<ExpressionStmt, true>();
}


AstNode* UnPacker::CaseIFStmt() {
  PRINT(IFStmt);
  return MakeBaseAst<IFStmt, true>();
}


AstNode* UnPacker::CaseIterationStmt() {
  PRINT(IterationStmt);
  return MakeBaseAst<IterationStmt, true>();
}


AstNode* UnPacker::CaseContinueStmt() {
  PRINT(ContinueStmt);
  return MakeBaseAst<ContinueStmt, true>();
}


AstNode* UnPacker::CaseBreakStmt() {
  PRINT(BreakStmt);
  return MakeBaseAst<BreakStmt, true>();
}


AstNode* UnPacker::CaseReturnStmt() {
  PRINT(ReturnStmt);
  return MakeBaseAst<ReturnStmt, true>();
}


AstNode* UnPacker::CaseWithStmt() {
  PRINT(WithStmt);
  return MakeBaseAst<WithStmt, true>();
}

AstNode* UnPacker::CaseSwitchStmt() {
  PRINT(SwitchStmt);
  return MakeBaseAst<SwitchStmt, true>();
}


AstNode* UnPacker::CaseCaseClause() {
  PRINT(CaseClause);
  return MakeBaseAst<CaseClause, true>();
}


AstNode* UnPacker::CaseLabelledStmt() {
  PRINT(LabelledStmt);
  return MakeBaseAst<LabelledStmt, true>();
}


AstNode* UnPacker::CaseThrowStmt() {
  PRINT(ThrowStmt);
  return MakeBaseAst<ThrowStmt, true>();
}


AstNode* UnPacker::CaseTryStmt() {
  PRINT(TryStmt);
  return MakeBaseAst<TryStmt, true>();
}


AstNode* UnPacker::CaseCallExp() {
  PRINT(CallExp);
  return MakeBaseAst<CallExp, true>();
}


AstNode* UnPacker::CaseNewExp() {
  PRINT(NewExp);
  return MakeBaseAst<NewExp, true>();
}

AstNode* UnPacker::CasePostfixExp() {
  PRINT(PostfixExp);
  return MakeBaseAst<PostfixExp, true>();
}


AstNode* UnPacker::CaseUnaryExp() {
  PRINT(UnaryExp);
  return MakeBaseAst<UnaryExp, true>();
}


AstNode* UnPacker::CaseBinaryExp() {
  PRINT(BinaryExp);
  return MakeBaseAst<BinaryExp, true>();
}


AstNode* UnPacker::CaseCompareExp() {
  PRINT(CompareExp);
  return MakeBaseAst<CompareExp, true>();
}


AstNode* UnPacker::CaseConditionalExp() {
  PRINT(ConditionalExp);
  return MakeBaseAst<ConditionalExp, true>();
}


AstNode* UnPacker::CaseAssignmentExp() {
  PRINT(AssignmentExp);
  return MakeBaseAst<AssignmentExp, true>();
}


AstNode* UnPacker::CaseExpression() {
  PRINT(Expression);
  return MakeBaseAst<Expression, true>();
}

AstNode* UnPacker::CaseClass() {
  PRINT(Class);
  return MakeBaseAst<Class, true>();
}


AstNode* UnPacker::CaseFunction(){
  PRINT(Function);
  return MakeBaseAst<Function, true>();
};


AstNode* UnPacker::CaseLiteral() {
  PRINT(Literal);
  return MakeBaseAst<Literal, true>();
}

AstNode* UnPacker::CaseVarDeclList() {
  PRINT(VarDeclList);
  return MakeBaseAst<VariableDeclarationList, true>();
}

AstNode* UnPacker::CaseArray() {
  PRINT(Array);
  return MakeBaseAst<ArrayLikeLiteral, true>();
}

AstNode* UnPacker::CaseObject() {
  PRINT(Object);
  return MakeBaseAst<ObjectLikeLiteral, true>();
}

}
