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
#include <compiler/compiler.h>
#include <utils/class_traits/static.h>
#include <utils/format.h>
#include <ast/ast_foward_decl.h>

namespace mocha {

#define AST_ERROR( info , message )                                     \
  char buf[ 1000 ];                                                     \
  Format( buf , "%s at %d\n" , message , __LINE__ );                    \
  info->GetCompiler()->CatchException( ExceptionHandler::CreateException( buf ) )

class AstUtils : private Static {
 public :
  static Function* CreateFunctionDecl( AstNode* name , AstNode* argv , AstNode* body );
  static CallExp* CreateArrayAccessor( AstNode* callable , AstNode* args );
  static CallExp* CreateDotAccessor( AstNode* callable , AstNode* args );
  static CallExp* CreatePrototypeAccessor( AstNode* callable , AstNode* args );
  static CallExp* CreateNormalAccessor( AstNode* callable , AstNode* args );
  static ValueNode* CreateNameNode( const char* name , int type , long line , int value_type , bool is_empty = false );
  static AssignmentExp* CreateAssignment( int type , AstNode* lhs , AstNode* rhs );
  static UnaryExp* CreateUnaryExp( int type , AstNode* exp );
  static NodeList* CreateNodeList( int num , ... );
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
  static ValueNode* CreateTmpNode( int index );
  static IFStmt* CreateIFStmt( AstNode* exp , AstNode* then_stmt , AstNode* else_stmt );
  static BlockStmt* CreateBlockStmt( int num , ... );
};

}

#endif
