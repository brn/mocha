#ifndef mocha_parser_h_
#define mocha_parser_h_

namespace mocha {

class Parser{
 public :
  Parser();
  ~Parser();
  AstRoot* Parse();
 private :
  AstNode* ParseProgram();
  AstNode* ParseSourceElement();
  AstNode* ParseStatement();
  AstNode* ParseFunctionDecl();
  AstNode* ParseClassDecl();
  AstNode* ParseConstDecl();
  AstNode* ParseLetDecl();
  AstNode* ParseModuleStatement();
  AstNode* ParseExportStatement();
  AstNode* ParseBlockStatement();
  AstNode* ParseVariableStatement();
  AstNode* ParseExpressionStatement();
  AstNode* ParseIFStatement();
  AstNode* ParseIterationStatement();
  AstNode* ParseContinueStatement();
  AstNode* ParseBreakStatement();
  AstNode* ParseReturnStatement();
  AstNode* ParseWithStatement();
  AstNode* ParseLabelledStatement();
  AstNode* ParseSwitchStatement();
  AstNode* ParseThrowStatement();
  AstNode* ParseTryStatement();
  AstNode* ParseImportStatement();
  AstNode* ParseVersionStatement();
  AstNode* ParseExpression();
  AstNode* ParseAssignmentExpression();
  AstNode* ParseYieldExpression();
  AstNode* ParseConditionalExpression();
  AstNode* ParseBinaryExpression();
  AstNode* ParseCompareExpression();
  AstNode* ParseUnaryExpression();
  AstNode* ParseLeftHandSideExpression();
  AstNode* ParsePostfixExpression();
  AstNode* ParseCallExpression();
  AstNode* ParseObjectLiteral();
  AstNode* ParseArrayLiteral();
  AstNode* ParsePrimary();
};

}

#endif
