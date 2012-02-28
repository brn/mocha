#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/fileroot_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
namespace mocha {

#define TOKEN yy::ParserImplementation::token

void FileRootProcessor::ProcessNode( FileRoot* ast_node , ProcessorInfo* info ) {
  VisitorInfo *visitor_info = info->GetInfo();
  IVisitor* visitor = info->GetVisitor();
  NodeIterator iterator = ast_node->ChildNodes();
  bool is_runtime = visitor_info->IsRuntime();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( visitor );
  }
  if ( !is_runtime ) {
    Function *fn = AstUtils::CreateFunctionDecl( Empty::New(),
                                                 Empty::New() , ast_node , 1 );
    ExpressionStmt *stmt = AstUtils::CreateAnonymousFnCall( fn , Empty::New() , ast_node->line_number() );
    Literal* global_export = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalExport ),
                                                         Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kIdentifier );
    ObjectLikeLiteral* object_literal = ObjectLikeLiteral::New( ast_node->line_number() );
    Literal* key = AstUtils::CreateNameNode( visitor_info->GetRelativePath() , Token::JS_STRING_LITERAL , ast_node->line_number() , Literal::kString );
    
    CallExp* global_export_accessor = AstUtils::CreateArrayAccessor( global_export , key , ast_node->line_number() );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , global_export_accessor , object_literal , ast_node->line_number() );

    Literal* alias = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalAlias ),
                                                 Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kIdentifier );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt(
        AstUtils::CreateVarInitiliser( alias->value() , global_export_accessor->Clone() , ast_node->line_number() ) , 3 );
    ExpressionStmt* extend_global = AstUtils::CreateExpStmt( exp , 2 );
    FileRoot* root = FileRoot::New( ast_node->filename() );
    root->AddChild( stmt );
    fn->InsertBefore( var_stmt );
    fn->InsertBefore( extend_global );
    fn->set_root();
    ast_node->parent_node()->ReplaceChild( ast_node , root );
  }
}

}
