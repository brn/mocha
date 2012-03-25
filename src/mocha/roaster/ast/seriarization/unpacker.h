#ifndef mocha_ast_seriarization_unpacker_h_
#define mocha_ast_seriarization_unpacker_h_
#include <vector>
#include <string>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class TokenInfo;
namespace memory {
class Pool;
}
template <typename AstType, bool>
struct Instaniater;
typedef std::vector<int> Packed;
class UnPacker {
  template<typename AstType, bool>
  friend class Instaniater;
 public :
  UnPacker(Packed* packed, memory::Pool* pool);
  ~UnPacker(){}
  AstNode* Unpack();
 private :
  int Advance(int index = 1) {
    if (current_ == packed_->size()) {
      return -1;
    }
    int ret = packed_->at(current_);
    current_ += index;
    return ret;
  };
  int Current() {
    if (current_ == packed_->size()) {
      return -1;
    }
    return packed_->at(current_);
  }
  template <typename AstType, bool>
  AstNode* MakeBaseAst();
  template <typename T>
  void ProcessNode(T* node);
  template <typename T>
  T* MakeUnary(int64_t line);
  template <typename T>
  T* MakeBinary(int64_t line);
  void UnpackChar(std::string* buf);
  TokenInfo* UnpackToken();
  AstNode* UnpackEachNode();
  AstNode* CaseNodeList();
  AstNode* CaseEmpty();
  AstNode* CaseAstRoot();
  AstNode* CaseFileRoot();
  AstNode* CaseStatementList();
  AstNode* CaseBlockStmt();
  AstNode* CaseVersionStmt();
  AstNode* CaseVariableStmt();
  AstNode* CaseExpressionStmt();
  AstNode* CaseIFStmt();
  AstNode* CaseIterationStmt();
  AstNode* CaseContinueStmt();
  AstNode* CaseBreakStmt();
  AstNode* CaseReturnStmt();
  AstNode* CaseWithStmt();
  AstNode* CaseLabelledStmt();
  AstNode* CaseSwitchStmt();
  AstNode* CaseThrowStmt();
  AstNode* CaseTryStmt();
  AstNode* CaseAssertStmt();
  AstNode* CaseCaseClause();
  AstNode* CaseExpression();
  AstNode* CaseVarDeclList();
  AstNode* CaseClass();
  AstNode* CaseFunction();
  AstNode* CaseCallExp();
  AstNode* CaseNewExp();
  AstNode* CasePostfixExp();
  AstNode* CaseUnaryExp();
  AstNode* CaseBinaryExp();
  AstNode* CaseCompareExp();
  AstNode* CaseConditionalExp();
  AstNode* CaseAssignmentExp();
  AstNode* CaseLiteral();
  AstNode* CaseArray();
  AstNode* CaseObject();
  int current_type_;
  int current_;
  Packed* packed_;
  memory::Pool* pool_;
};
}

#endif
