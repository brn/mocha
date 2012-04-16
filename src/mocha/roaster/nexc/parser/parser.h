/**
 *@author Taketoshi Aono
 *@fileOverview
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
#ifndef mocha_nexc_parser_parser_h_
#define mocha_nexc_parser_parser_h_
#include <string.h>
#include <string>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/memory/pool.h>
#include <mocha/roaster/smart_pointer/scope/scoped_ptr.h>
#include <mocha/roaster/nexc/binding/parser_connector.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
namespace mocha {
class ErrorReporter;
class ParserConnector;
class AstBuilder;
class CompilationEvent;
class Parser{
 public :
  Parser(ParserConnector* connector_, ErrorReporter* reporter, const char* filename);
  ~Parser();
  FileRoot* Parse();
  class ParseEventListener {
   public :
    void operator()(CompilationEvent* event);
  };
 private :
  typedef bool (*StatementListMatcher)(int type);
  memory::Pool* pool() { return pool_; }
  AstBuilder* builder() { return builder_; }
  TokenInfo* Advance(int len = 1) {
    TokenInfo* info = connector_->Advance(len);
    return info;
  }
  TokenInfo* Undo(int len = 1) { return connector_->Undo(len); }
  TokenInfo* Seek(int len = 1) {
    TokenInfo* info = connector_->Seek(len);
    return info;
  }
  void IllegalEnd(const char* expect, int64_t line);
  template <typename T>
  bool IsValidNamedDeclaration(T* fn);
  void ParseTerminator();
  NodeList* FormalParameterConvertor(AstNode *args);
  AstNode* ParseProgram();
  AstNode* ParseSourceElements();
  AstNode* ParseSourceElement();
  AstNode* ParseStatementList(StatementListMatcher matcher, const char* expect);
  AstNode* ParseStatement();
  AstNode* ParseBlockStatement();
  AstNode* ParseModuleStatement();
  AstNode* ParseExportStatement();
  AstNode* ParseImportStatement();
  AstNode* ParseImportExpression();
  AstNode* ParseDebuggerStatement(TokenInfo* token);
  AstNode* ParseVersionStatement();
  AstNode* ParseAssertStatement();
  AstNode* ParseIncludeStatement();
  AstNode* ParseVariableStatement();
  AstNode* ParseVariableDecl(bool is_noin);
  AstNode* ParseLetExpressionOrLetStatement();
  AstNode* ParseLetExpressionExp();
  AstNode* ParseDestructuringLeftHandSide();
  AstNode* ParseArrayPattern();
  AstNode* ParseObjectPattern();
  AstNode* ParseObjectPatternElement(int type, TokenInfo* token, ObjectLikeLiteral* list);
  AstNode* CheckLabellOrExpressionStatement();
  AstNode* ParseIFStatement(bool is_comprehensions);
  AstNode* ParseWhileStatement();
  AstNode* ParseDoWhileStatement(bool is_exp);
  AstNode* ParseForStatement(bool is_comprehensions);
  void ParseForStatementCondition(NodeList* list, bool has_paren);
  void ParseForInStatementCondition(NodeList* list, bool has_paren);
  AstNode* ParseContinueStatement();
  AstNode* ParseBreakStatement();
  AstNode* ParseReturnStatement();
  AstNode* ParseWithStatement();
  AstNode* ParseSwitchStatement();
  AstNode* ParseCaseClauses();
  AstNode* ParseLabelledStatement();
  AstNode* ParseThrowStatement();
  AstNode* ParseTryStatement();
  AstNode* ParseCatchBlock();
  AstNode* ParseFinallyBlock();
  AstNode* ParseTrait();
  void ParseTraitBody(Trait* trait);
  AstNode* ParseMixin();
  AstNode* ParseClassDecl(bool is_const);
  AstNode* ParseInheritDecl();
  AstNode* ParseClassBody();
  AstNode* ParseClassMemberStatement();
  ClassMember* ParseClassMember();
  AstNode* ParseExportableDefinition();
  AstNode* ParseExpression(bool is_noin);
  AstNode* ParseAssignmentExpression(bool is_noin);
  AstNode* ParseYieldExpression(bool is_noin);
  AstNode* ParseConditional(bool is_noin);
  AstNode* ParseBinaryExpression(bool is_noin);
  AstNode* ParseUnaryExpression();
  AstNode* ParsePostfixExpression();
  AstNode* ParseLeftHandSideExpression();
  NewExp* ParseNewExpression();
  AstNode* ParseCallExpression();
  AstNode* ParseArguments(bool* has_spread);
  AstNode* ParseMemberExpression();
  AstNode* ParseBracketMember();
  AstNode* ParseDotMember(bool *is_bool);
  CallExp* ParseEachMember(int type, bool is_first, CallExp* exp);
  AstNode* ParsePrimaryExpression();
  AstNode* ParseGeneratorExpression(AstNode* exp);
  AstNode* ParseObjectLiteral();
  AstNode* ParseObjectElement(int type, TokenInfo* token, ObjectLikeLiteral* object);
  AstNode* ParseArrayLiteral();
  AstNode* ParseLiteral(bool);
  AstNode* ParseFunctionDecl();
  AstNode* ParseFormalParameter();
  AstNode* ParseArrowFunctionExpression(AstNode* exp, int type);
  AstNode* ParseArrowFunctionExpression(AstNode* member, AstNode* args, int type);
  AstNode* ParseArrowFunctionExpression(int type);
  AstNode* ParseArrowFunctionBody(Function* fn);
  AstNode* ParseArrayComprehensions();

  const char* filename_;
  std::string indent_;
  class StateStack;
  int depth_;
  memory::Pool* pool_;
  AstBuilder* builder_;
  BitVector8 bits_;
  ParserConnector* connector_;
  ErrorReporter* reporter_;
  ScopedPtr<StateStack> state_stack_;
};

}

#endif
