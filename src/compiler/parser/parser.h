#ifndef mocha_parser_h_
#define mocha_parser_h_
#include <string>
#include <ast/ast_foward_decl.h>
#include <compiler/binding/parser_connector.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/js_token.h>
namespace mocha {
class ErrorReporter;
class ParserConnector;
class Parser{
 public :
  Parser( ParserConnector* connector_ , ErrorReporter* reporter , const char* filename );
  ~Parser();
  FileRoot* Parse();
 private :
  typedef bool ( *StatementListMatcher )( int type );
  inline TokenInfo* Advance_( int len = 1 ) {
    TokenInfo* info = connector_->Advance( len );
    //printf( "advance %s\n" , static_cast<const char*>( TokenConverter(info) ) );
    return info;
  }
  inline TokenInfo* Undo_( int len = 1 ) { return connector_->Undo( len ); }
  inline TokenInfo* Seek_( int len = 1 ) {
    TokenInfo* info = connector_->Seek( len );
    //printf( "seek %s\n" , static_cast<const char*>( TokenConverter(info) ) );
    return info;
  }
  void IllegalEnd_( const char* expect , long line );
  AstNode* ParseProgram_();
  AstNode* ParseSourceElements_();
  AstNode* ParseSourceElement_();
  AstNode* ParseStatementList_( StatementListMatcher matcher );
  AstNode* ParseStatement_();
  AstNode* ParseBlockStatement_();
  AstNode* ParseModuleStatement_();
  AstNode* ParseExportStatement_();
  AstNode* ParseImportStatement_();
  AstNode* ParseImportExpression_();
  AstNode* ParseDebuggerStatement_( TokenInfo* token );
  AstNode* ParseVersionStatement_();
  AstNode* ParseVariableStatement_();
  AstNode* ParseVariableDecl_( bool is_noin );
  AstNode* ParseLetDeclOrLetStatement_(){return 0;};
  AstNode* ParseDestructuringLeftHandSide_();
  AstNode* ParseArrayPattern_();
  AstNode* ParseObjectPattern_();
  AstNode* ParseObjectPatternElement_( int type , TokenInfo* token , AstNode* list );
  AstNode* CheckLabellOrExpressionStatement_();
  AstNode* ParseIFStatement_( bool is_comprehensions );
  AstNode* ParseWhileStatement_();
  AstNode* ParseDoWhileStatement_();
  AstNode* ParseForStatement_( bool is_comprehensions );
  void ParseForStatementCondition_( NodeList* list );
  void ParseForInStatementCondition_( NodeList* list );
  AstNode* ParseContinueStatement_();
  AstNode* ParseBreakStatement_();
  AstNode* ParseReturnStatement_();
  AstNode* ParseWithStatement_();
  AstNode* ParseSwitchStatement_();
  AstNode* ParseCaseClauses_();
  AstNode* ParseLabelledStatement_();
  AstNode* ParseThrowStatement_();
  AstNode* ParseTryStatement_();
  AstNode* ParseCatchBlock_();
  AstNode* ParseFinallyBlock_();
  AstNode* ParseClassDecl_( bool is_const );
  AstNode* ParseInheritDecl_();
  AstNode* ParseClassBody_();
  ClassMember* ParseClassMember_();
  AstNode* ParseExportableDefinition_();
  AstNode* ParseExpression_( bool is_noin );
  AstNode* ParseAssignmentExpression_( bool is_noin );
  AstNode* ParseYieldExpression_( bool is_noin );
  AstNode* ParseConditional_( bool is_noin );
  AstNode* ParseBinaryExpression_( bool is_noin );
  AstNode* ParseUnaryExpression_();
  AstNode* ParsePostfixExpression_();
  AstNode* ParseLeftHandSideExpression_();
  NewExp* ParseNewExpression_();
  AstNode* ParseCallExpression_();
  AstNode* ParseArguments_();
  AstNode* ParseMemberExpression_();
  AstNode* ParseBracketMember_();
  AstNode* ParseDotMember_( bool *is_bool );
  CallExp* ParseEachMember_( int type , bool is_first , CallExp* exp );
  AstNode* ParsePrimaryExpression_();
  AstNode* ParseObjectLiteral_();
  AstNode* ParseObjectElement_( int type , TokenInfo* token , AstNode* list );
  AstNode* ParseArrayLiteral_();
  AstNode* ParseLiteral_();
  AstNode* ParseFunctionDecl_( bool is_const );
  AstNode* ParseFormalParameter_();
  AstNode* ParseArrowFunctionExpression_( AstNode* exp , int type );
  AstNode* ParseArrowFunctionExpression_( AstNode* member , AstNode* args , int type );
  AstNode* ParseArrowFunctionExpression_( int type );
  AstNode* ParseArrowFunctionBody_( Function* fn );
  AstNode* ParseArrayComprehensions_();

  const char* filename_;
  bool is_source_elements_parse_begin_;
  std::string indent_;
  ParserConnector* connector_;
  ErrorReporter* reporter_;
};

}

#endif