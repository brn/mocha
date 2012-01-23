#ifndef mocha_parser_h_
#define mocha_parser_h_

namespace mocha {

class Parser{
 public :
  Parser( ParserConnector* connector_ , ErrorReporter* reporter );
  ~Parser();
  AstRoot* Parse();
 private :
  inline TokenInfo* Advance_( int len = 1 ) { return connector_->Advance( len ); }
  inline TokenInfo* Undo_( int len = 1 ) { return connector_->Undo( len ); }
  inline TokenInfo* Seek_( int len = 1 ) { return connector_->Seek( len ); }
  AstNode* ParseProgram_();
  AstNode* ParseSourceElements_();
  AstNode* ParseSourceElement_();
  AstNode* ParseStatementList_();
  AstNode* ParseStatement_();
  AstNode* ParseModuleStatement_();
  AstNode* ParseExportStatement_();
  AstNode* ParseImportStatement_();
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

  ParserConnector* connector_;
  ErrorReporter* reporter_;
};

}

#endif
