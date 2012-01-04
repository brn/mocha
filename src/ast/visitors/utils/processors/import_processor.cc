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
#include <grammar/grammar.tab.hh>

namespace mocha {
#define TOKEN yy::ParserImplementation::token
ImportProccessor::ImportProccessor( ImportStmt* stmt , ProcessorInfo* info ) :
    stmt_( stmt ) , info_( info ) {}

void ImportProccessor::ProcessNode() {
  IVisitor *visitor = info_->GetVisitor();
  stmt_->Exp()->Accept( visitor );
  LoadModule_();
  ValueNode *name = AstUtils::CreateNameNode( stmt_->ModKey()->GetToken(),
                                              Token::JS_STRING_LITERAL , stmt_->Line() , ValueNode::kString );
  ValueNode *global = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGlobalExport ),
                                                Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
  CallExp* exp = AstUtils::CreateArrayAccessor( global , name );
  if ( stmt_->From()->ChildLength() > 1 ) {
    NodeIterator iter = stmt_->From()->ChildNodes();
    iter.Next();
    while ( iter.HasNext() ) {
      ValueNode* item = iter.Next()->CastToValue();
      if ( !item->IsEmpty() ) {
        if ( item->ValueType() == ValueNode::kString ) {
          exp = AstUtils::CreateArrayAccessor( exp , item );
        } else {
          exp = AstUtils::CreateDotAccessor( exp , item );
        }
      }
    }
  }
  if ( stmt_->HasDsta() ) {
    ValueNode* value = AstUtils::CreateVarInitiliser( stmt_->Exp()->CastToValue()->Symbol() , exp );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    NodeList* var_list = DstaProcessor::CreateDstaExtractedVarStmt( stmt_ , info_ );
    list->AddChild( value );
    list->Append( var_list );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list );
    stmt->Line( stmt_->Line() );
    stmt_->ParentNode()->ReplaceChild( stmt_ , stmt );
  } else {
    ValueNode* value = AstUtils::CreateVarInitiliser( stmt_->Exp()->CastToValue()->Symbol() , exp );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( value );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list );
    stmt->Line( stmt_->Line() );
    stmt_->ParentNode()->ReplaceChild( stmt_ , stmt );
  }
}


void ImportProccessor::LoadModule_() {
  VisitorInfo* visitor_info = info_->GetInfo();
  AstNode* from = stmt_->From();
  AstNode* file = from->FirstChild();
  ValueNode* value = file->CastToValue();

  if ( value && value->ValueType() == ValueNode::kString ) {
    //Create path from js string literal.
    TokenInfo* info = value->Symbol();
    std::string js_path = info->GetToken();
    js_path.erase( 0 , 1 );
    //"path to file" -> path to file
    js_path.erase( js_path.size() - 1 , js_path.size() );
    
    StrHandle current_dir = VirtualDirectory::GetInstance()->GetCurrentDir();
    //Get full path of module.
    StrHandle real_path = visitor_info->GetCompiler()->Load( js_path.c_str() );

    //Set virtual dir to current context dir.
    VirtualDirectory::GetInstance()->Chdir( current_dir.Get() );

    //Get module uuid key.
    StrHandle key_str = FileSystem::GetModuleKey( real_path.Get() );
    TokenInfo* key = ManagedHandle::Retain( new TokenInfo( key_str.Get() , Token::JS_IDENTIFIER , stmt_->Line() ) );

    //Reserve module key string for later code generation.
    stmt_->ModKey( key );
  }
}

}
