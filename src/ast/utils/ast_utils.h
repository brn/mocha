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
  static ValueNode* CreateNameNode( const char* name , int type , long line , bool is_empty = false );
  static AssignmentExp* CreateAssignment( int type , AstNode* lhs , AstNode* rhs );
  static ValueNode* CreateObjectLiteral( AstNode* body );
  static ExpressionStmt* CreateAnonymousFnCall( Function *fn , AstNode* args );
  static ExpressionStmt* CreateExpStmt( AstNode* node );
  static VariableStmt* CreateVarStmt( NodeList* list );
  static VariableStmt* CreateVarStmt( AstNode* mem );
  static ValueNode* CreateVarInitiliser( TokenInfo* lhs , AstNode* rhs );
  static ReturnStmt* CreateReturnStmt( AstNode* exp );
  static CallExp* CreateRuntimeMod( AstNode* member );
  static const char* GetGloablExportSymbol();
  static const char* GetLocalExportSymbol();
  static const char* GetGlobalAliasSymbol();
  static const char* CreateTmpRef( char* buf , int index );
  static const char* GetToArraySymbol();
  static const char* GetArgumentsSymbol();
  static const char* GetUndefinedSymbol();
  static const char* GetHiddenSymbol();
  static const char* GetClassTableSymbol();
  static const char* GetHiddenCallSymbol();
  static const char* GetConstructorSymbol();
  static const char* GetThisSymbol();
  static const char* GetTypeIdSymbol();
  static const char* GetInstanceIdSymbol();
  static const char* GetApplySym();
  static CallExp* CreateGlobalExportNode( AstNode* ast_node , const char* filename );
};

}

#endif
