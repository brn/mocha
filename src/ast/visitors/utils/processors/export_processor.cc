#include <ast/ast.h>
#include <ast/visitors/utils/processors/export_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/token_info.h>
#include <utils/pool/managed_handle.h>
#include <grammar/grammar.tab.hh>

namespace mocha {

#define TOKEN yy::ParserImplementation::token

ExportProcessor::ExportProcessor( ExportStmt* stmt , ProcessorInfo* info ) :
    stmt_( stmt ) , info_( info ){}

void ExportProcessor::ProcessNode() {
  IVisitor *visitor = info_->GetVisitor();
  AstNode* node = stmt_->FirstChild();
  ValueNode* name_node = node->CastToValue();
  if ( name_node && name_node->ValueType() == ValueNode::kConstant ) {
    node = name_node->Node();
  }
  node->Accept( visitor );
  if ( node->NodeType() == AstNode::kFunction ) {
    ProcessFunction_( node );
  } else if ( node->NodeType() == AstNode::kNodeList ) {
    ProcessNodeList_( node );
  }
}


void ExportProcessor::ProcessFunction_( AstNode* node ) {
  Function* fn = reinterpret_cast<Function*>( node );
  ValueNode* name = fn->Name()->CastToValue();
  ValueNode* local = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLocalExport ),
                                               Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
  ValueNode* property_name = name->Clone()->CastToValue();
  property_name->ValueType( ValueNode::kProperty );
  CallExp *export_prop = AstUtils::CreateDotAccessor( local , property_name );
  AssignmentExp* assign = AstUtils::CreateAssignment( '=' , export_prop , fn );
  ExpressionStmt* exp_stmt_node = AstUtils::CreateExpStmt( assign );
  stmt_->ParentNode()->ReplaceChild( stmt_ , exp_stmt_node );
}



void ExportProcessor::ProcessNodeList_( AstNode* node ) {
  VariableStmt* var_stmt = ManagedHandle::Retain<VariableStmt>();
  Expression* exp = ManagedHandle::Retain<Expression>();
  var_stmt->Line( stmt_->Line() );
  exp->Paren();
  CreateAssignment_( exp , var_stmt , node );
  if ( var_stmt->ChildLength() > 0 ) {
    stmt_->ParentNode()->ReplaceChild( stmt_ , var_stmt );
  }
  if ( exp->ChildLength() > 0 ) {
    ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
    stmt->AddChild( exp );
    if ( var_stmt->ChildLength() > 0 ) {
      stmt_->ParentNode()->InsertBefore( stmt , var_stmt );
    } else {
      stmt_->ParentNode()->ReplaceChild( stmt_ , stmt );
    }
  }
}


void ExportProcessor::CreateAssignment_( Expression* exp , VariableStmt* var_stmt , AstNode* node ) {
  NodeIterator iterator = node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode *item = iterator.Next();
    TokenInfo *name_info = item->CastToValue()->Symbol();
    ValueNode *name = AstUtils::CreateNameNode( name_info->GetToken() , Token::JS_IDENTIFIER , stmt_->Line() , true );
    ValueNode *local = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLocalExport ),
                                                 Token::JS_IDENTIFIER , stmt_->Line() , ValueNode::kIdentifier );
    CallExp *export_prop = AstUtils::CreateDotAccessor( local , name );
    AssignmentExp* assign;
    if ( !item->FirstChild()->IsEmpty() ) {
      assign = AstUtils::CreateAssignment( '=' , export_prop , item->FirstChild() );
      ValueNode *val = AstUtils::CreateVarInitiliser( name->Symbol() , assign );
      var_stmt->AddChild( val);
    } else {
      assign = AstUtils::CreateAssignment( '=' , export_prop , name );
      exp->AddChild( assign );
    }
  }
}
}
