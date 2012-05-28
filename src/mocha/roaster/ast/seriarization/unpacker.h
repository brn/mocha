#ifndef mocha_ast_seriarization_unpacker_h_
#define mocha_ast_seriarization_unpacker_h_
#include <vector>
#include <string>
#include <mocha/roaster/ast/seriarization/byte.h>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class TokenInfo;
namespace memory {
class Pool;
}
template <typename AstType, bool>
class Instaniater;
typedef std::vector<int32_t> Packed;
typedef std::vector<std::string> Included;
class UnPacker {
  template<typename AstType, bool>
  friend class Instaniater;
 public :
  UnPacker(Packed* packed, ByteOrder* b_order, memory::Pool* pool);
  UnPacker(int32_t* packed, int size, ByteOrder* b_order, memory::Pool* pool);
  ~UnPacker(){}
  AstNode* Unpack();
  bool HasInclude() const {return has_include_;};
  const Included& included() const {return included_;};
 private :
  int32_t Advance(int index = 1) {
    if (current_ == max_) {
      return -1;
    }
    int32_t ret = b_order_->ToHostByteOrder(packed_[current_]);
    current_ += index;
    return ret;
  };
  int32_t Current() {
    if (current_ == max_) {
      return -1;
    }
    return b_order_->ToHostByteOrder(packed_[current_]);
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
  AstNode* CaseIncludeStmt();
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
  int max_;
  int32_t* packed_;
  bool has_include_;
  std::vector<std::string> included_;
  ByteOrder* b_order_;
  memory::Pool* pool_;
};
}

#endif
