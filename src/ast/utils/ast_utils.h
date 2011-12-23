#ifndef mocha_ast_utils_h_
#define mocha_ast_utils_h_
#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>

namespace mocha {

class AstUtils : private Static {
 public :
  static Function* CreateFunctionDecl( AstNode* name , AstNode* argv , AstNode* body );
  static CallExp* CreateArrayAccessor( AstNode* callable , AstNode* args );
  static CallExp* CreateDotAccessor( AstNode* callable , AstNode* args );
  static CallExp* CreatePrototypeAccessor( AstNode* callable , AstNode* args );
  static CallExp* CreateNormalAccessor( AstNode* callable , AstNode* args );
  static ValueNode* CreateNameNode( const char* name , int type , long line , int value_type , bool is_empty = false );
  static AssignmentExp* CreateAssignment( int type , AstNode* lhs , AstNode* rhs );
  static ValueNode* CreateObjectLiteral( AstNode* body );
  static ExpressionStmt* CreateAnonymousFnCall( Function *fn , AstNode* args );
  static ExpressionStmt* CreateExpStmt( AstNode* node );
  static VariableStmt* CreateVarStmt( NodeList* list );
  static VariableStmt* CreateVarStmt( AstNode* mem );
  static ValueNode* CreateVarInitiliser( TokenInfo* lhs , AstNode* rhs );
  static ReturnStmt* CreateReturnStmt( AstNode* exp );
  static CallExp* CreateRuntimeMod( AstNode* member );
  static CallExp* CreateConstantProp( AstNode* lhs , AstNode* prop , AstNode* value );
  static CallExp* CreatePrototypeNode( AstNode* lhs );
  static CallExp* CreateGlobalExportNode( AstNode* ast_node , const char* filename );
  static const char* CreateTmpRef( char* buf , int index );
};

}

#endif
