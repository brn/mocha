#include <string>
#include <utils/smart_pointer/ref_count/handle.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/file_system/file_system.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/import_processor.h>

namespace mocha {

ImportProccessor::ImportProccessor( ImportStmt* stmt , ProcessorInfo* info ) :
    stmt_( stmt ) , info_( info ) {}

void ImportProccessor::ProcessNode() {
  IVisitor *visitor = info_->visitor();
  if ( stmt_->expression_type() == ImportStmt::kDst ) {
    DstaProcessor::ProcessNode( stmt_->expression() , info_ );
  } else {
    stmt_->expression()->Accept( visitor );
  }
  AstNode* exp = 0;//init after;
  if ( stmt_->module_type() == ImportStmt::kFile ) {
    LoadModule_();
    AstNode *name = AstUtils::CreateNameNode( stmt_->module_key()->token(),
                                              Token::JS_STRING_LITERAL , stmt_->line_number() , Literal::kString );
    Literal *global = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalExport ),
                                                  Token::JS_IDENTIFIER , stmt_->line_number() , Literal::kIdentifier );
    exp = AstUtils::CreateArrayAccessor( global , name , stmt_->line_number() );
  } else {
    if ( !stmt_->IsContainDestructuring() ) {
      Literal *global = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGlobalAlias ),
                                                    Token::JS_IDENTIFIER , stmt_->line_number() , Literal::kIdentifier );
      CallExp* dot = AstUtils::CreateDotAccessor( stmt_->from() , stmt_->expression() , stmt_->line_number() );
      exp = AstUtils::CreateDotAccessor( global , dot , stmt_->line_number() );
    } else {
      exp = stmt_->from();
    }
  }
  if ( stmt_->from()->child_length() > 1 && stmt_->module_type() == ImportStmt::kFile ) {
    NodeIterator iter = stmt_->from()->ChildNodes();
    iter.Next();
    while ( iter.HasNext() ) {
      Literal* item = iter.Next()->CastToLiteral();
      if ( !item->IsEmpty() ) {
        if ( item->value_type() == Literal::kString ) {
          exp = AstUtils::CreateArrayAccessor( exp , item , stmt_->line_number() );
        } else {
          item->set_value_type( Literal::kProperty );
          exp = AstUtils::CreateDotAccessor( exp , item , stmt_->line_number() );
        }
      }
    }
  }
  VariableDeclarationList* list = VariableDeclarationList::New( stmt_->line_number() );
  if ( stmt_->IsContainDestructuring() ) {
    Literal* value = AstUtils::CreateVarInitiliser( stmt_->expression()->CastToLiteral()->value() , exp , stmt_->line_number() );
    NodeList* var_list = DstaProcessor::CreateDstaExtractedVarStmt( stmt_ , info_ );
    list->AddChild( value );
    list->Append( var_list );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list , stmt_->line_number() );
    stmt_->parent_node()->ReplaceChild( stmt_ , stmt );
  } else {
    Literal* value = AstUtils::CreateVarInitiliser( stmt_->expression()->CastToLiteral()->value() , exp , stmt_->line_number() );
    list->AddChild( value );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list , stmt_->line_number() );
    stmt_->parent_node()->ReplaceChild( stmt_ , stmt );
  }
}


void ImportProccessor::LoadModule_() {
  VisitorInfo* visitor_info = info_->visitor_info();
  AstNode* from = stmt_->from();
  AstNode* file = from->first_child();
  Literal* value = file->CastToLiteral();

  if ( value && value->value_type() == Literal::kString ) {
    //Create path from js string literal.
    TokenInfo* info = value->value();
    std::string js_path = info->token();
    js_path.erase( 0 , 1 );
    //"path to file" -> path to file
    js_path.erase( js_path.size() - 1 , js_path.size() );
    
    StrHandle current_dir = VirtualDirectory::GetInstance()->GetCurrentDir();
    //Get full path of module.
    StrHandle real_path = visitor_info->compiler()->Load( js_path.c_str() );

    //Set virtual dir to current context dir.
    VirtualDirectory::GetInstance()->Chdir( current_dir.Get() );

    //Get module uuid key.
    Handle<PathInfo> base_path_info = FileSystem::GetPathInfo( visitor_info->main_file_path() );
    Handle<PathInfo> target_path_info = FileSystem::GetPathInfo( real_path.Get() );
    StrHandle handle = FileSystem::GetModuleKey( base_path_info->GetDirPath().Get() , target_path_info->GetDirPath().Get() );
    std::string modkey = "'";
    modkey += handle.Get();
    modkey += target_path_info->GetFileName().Get();
    modkey += "'";
    TokenInfo* key = TokenInfo::New( modkey.c_str() , Token::JS_IDENTIFIER , stmt_->line_number() );

    //Reserve module key string for later code generation.
    stmt_->set_module_key( key );
  }
}

}
