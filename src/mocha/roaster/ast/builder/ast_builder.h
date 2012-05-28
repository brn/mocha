/**
 *@author Taketoshi Aono
 *@fileOverview
 *Abstract syntax tree utilities.
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#ifndef mocha_ast_utils_h_
#define mocha_ast_utils_h_
#include <assert.h>
#include <sstream>
#include <mocha/roaster/misc/class_traits/static.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/platform/thread/thread.h>

namespace mocha {
namespace memory {
class Pool;
}
#define AST_ERROR(info, message)
class TranslatorData;
class TokenInfo;
class AstBuilder : private Uncopyable {
 public :
  static AstBuilder* Local();
  AstBuilder(memory::Pool* pool)
      : pool_(pool){}
  ~AstBuilder();
  Function* CreateFunctionDecl(AstNode* name, AstNode* argv, AstNode* body, int64_t line);
  CallExp* CreateArrayAccessor(AstNode* callable, AstNode* args, int64_t line);
  CallExp* CreateDotAccessor(AstNode* callable, AstNode* args, int64_t line);
  CallExp* CreatePrototypeAccessor(AstNode* callable, AstNode* args, int64_t line);
  CallExp* CreateNormalAccessor(AstNode* callable, AstNode* args, int64_t line);
  Literal* CreateNameNode(const char* name, int type, int64_t line, int value_type, bool is_empty = false);
  Literal* CreateNameNode(const std::stringstream&, int type, int64_t line, int value_type, bool is_empty = false);
  AssignmentExp* CreateAssignment(int type, AstNode* lhs, AstNode* rhs, int64_t line);
  UnaryExp* CreateUnaryExp(int type, AstNode* exp, int64_t line);
  NodeList* CreateNodeList(int num, ...);
  ObjectLikeLiteral* CreateObjectLiteral(AstNode* body, int64_t line);
  ExpressionStmt* CreateAnonymousFnCall(Function *fn, AstNode* args, int64_t line);
  ExpressionStmt* CreateExpStmt(AstNode* node, int64_t line);
  VariableStmt* CreateVarStmt(VariableDeclarationList* list, int64_t line);
  Literal* CreateVarInitiliser(TokenInfo* lhs, AstNode* rhs, int64_t line);
  ReturnStmt* CreateReturnStmt(AstNode* exp, int64_t line);
  CallExp* CreateRuntimeMod(AstNode* member, int64_t line);
  CallExp* CreateConstantProp(AstNode* lhs, AstNode* prop, AstNode* value, int64_t line);
  CallExp* CreatePrototypeNode(AstNode* lhs, int64_t line);
  std::string CreateTmpRef(int index);
  Literal* CreateTmpNode(int index, int64_t line);
  IFStmt* CreateIFStmt(AstNode* exp, AstNode* then_stmt, AstNode* else_stmt, int64_t line);
  BlockStmt* CreateBlockStmt(int64_t line, int num, ...);
  VariableDeclarationList* CreateVarDeclList(int64_t line, int num, ...);
  void FindDirectivePrologue(AstNode* node, Function* fn);
  void FindDirectivePrologue(AstNode* node, FileRoot* fn);
  CallExp* BuildPrivateRecordAccessor(int64_t line);
  void SetAutoReturnFlag(AstNode* node);
  void ReplaceAutoReturnStatement(AstNode* stmt);
  static AstNode* IsDestructringLeftHandSide(AstNode* node);
 private :
  memory::Pool* pool() { return pool_; }
  memory::Pool* pool_;
  static os::ThreadLocalStorageKey key_;
};

}

#endif
