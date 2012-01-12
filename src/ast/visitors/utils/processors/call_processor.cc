#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/call_processor.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/js_token.h>
namespace mocha {

void CallProcessor::ProcessPrivateAccessor( CallExp* ast_node , ProcessorInfo* info ) {
  VisitorInfo* visitor_info = info->GetInfo();
  ValueNode* maybeIdent = ast_node->Callable()->CastToValue();
  if ( maybeIdent ) {
    ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , maybeIdent->Line() , ValueNode::kIdentifier );
    if ( !visitor_info->IsInPrivate() ) {
      ValueNode* private_field = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateField ),
                                                           Token::JS_IDENTIFIER , maybeIdent->Line() , ValueNode::kProperty );
      CallExp* dot_accessor = AstUtils::CreateDotAccessor( this_sym , private_field );
      ast_node->Callable( dot_accessor );
    } else {
      ast_node->Callable( this_sym );
    }
    if ( maybeIdent && maybeIdent->ValueType() == ValueNode::kIdentifier ) {
      ast_node->CallType( CallExp::kDot );
    } else {
      ast_node->CallType( CallExp::kBracket );
    }
  }
}


void CallProcessor::ProcessFnCall( CallExp* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->GetVisitor();
  AstNode* args = ast_node->Args();
  ast_node->Callable()->Accept( visitor );
  if ( !args->IsEmpty() ) {
    NodeIterator iterator = ast_node->Args()->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( visitor );
    }
  }
}

void CallProcessor::ProcessExtendAccessor( CallExp* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->GetVisitor();
  ast_node->Callable()->Accept( visitor );
  ast_node->Args()->Accept( visitor );
  CallExp* clone = ast_node->Clone()->CastToExpression()->CastToCallExp();
  ValueNode* extend = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kExtend ),
                                                Token::JS_PROPERTY , ast_node->Line() , ValueNode::kProperty );
  NodeList* args = AstUtils::CreateNodeList( 2 , clone->Callable() , ast_node->Args() );
  CallExp* extend_call = AstUtils::CreateNormalAccessor( extend , args );
  CallExp* extend_acessor = AstUtils::CreateRuntimeMod( extend_call );
  ast_node->ParentNode()->ReplaceChild( ast_node , extend_acessor );
}

}
