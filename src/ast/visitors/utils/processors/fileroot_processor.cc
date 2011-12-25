#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/fileroot_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/symbol_list.h>
#include <grammar/grammar.tab.hh>
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
    Function *fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>(),
                                                 ManagedHandle::Retain<Empty>() , ast_node );
    fn->Line( 1 );
    ExpressionStmt *stmt = AstUtils::CreateAnonymousFnCall( fn , ManagedHandle::Retain<Empty>() );
    ValueNode* global_export = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGlobalExport ),
                                                         TOKEN::JS_IDENTIFIER , ast_node->Line() , ValueNode::kIdentifier );
    ValueNode* object_literal = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
    object_literal->Node( ManagedHandle::Retain<Empty>() );
    StrHandle handle = FileSystem::GetModuleKey( ast_node->FileName() );
    ValueNode* key = AstUtils::CreateNameNode( handle.Get() , TOKEN::JS_STRING_LITERAL , ast_node->Line() , ValueNode::kString );
    
    CallExp* global_export_accessor = AstUtils::CreateArrayAccessor( global_export , key );
    AssignmentExp* exp = AstUtils::CreateAssignment( '=' , global_export_accessor , object_literal );

    ValueNode* alias = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGlobalAlias ),
                                                 TOKEN::JS_IDENTIFIER , ast_node->Line() , ValueNode::kIdentifier );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt(
        AstUtils::CreateVarInitiliser( alias->Symbol() , global_export_accessor->Clone() ) );
    ExpressionStmt* extend_global = AstUtils::CreateExpStmt( exp );
    FileRoot* root = ManagedHandle::Retain<FileRoot>();
    root->FileName( ast_node->FileName() );
    root->AddChild( stmt );
    extend_global->Line( 2 );
    var_stmt->Line( 3 );
    fn->InsertBefore( var_stmt );
    fn->InsertBefore( extend_global );
    fn->Root( true );
    ast_node->ParentNode()->ReplaceChild( ast_node , root );
  }
}

}
