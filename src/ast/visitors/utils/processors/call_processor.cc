#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/call_processor.h>
#include <ast/visitors/utils/processors/class_processor.h>
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
      ValueNode* private_field = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGetPrivateRecord ),
                                                           Token::JS_PROPERTY , maybeIdent->Line() , ValueNode::kProperty );
      ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                      Token::JS_IDENTIFIER , maybeIdent->Line() , ValueNode::kIdentifier );
      NodeList* args = AstUtils::CreateNodeList( 1 , this_sym );
      CallExp* normal = AstUtils::CreateNormalAccessor( private_field , args );
      CallExp* runtime_call = AstUtils::CreateRuntimeMod( normal );
      ast_node->Callable( runtime_call );
    } else {
      ast_node->Callable( this_sym );
    }
    maybeIdent = ast_node->Args()->CastToValue();
    if ( maybeIdent && maybeIdent->ValueType() == ValueNode::kProperty ) {
      ast_node->CallType( CallExp::kDot );
    } else {
      ast_node->CallType( CallExp::kBracket );
    }
  }
}


void CallSuper ( CallExp* ast_node ) {
  AstNode* args = ast_node->Args();
  ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                  Token::JS_THIS , ast_node->Line() , ValueNode::kThis );
  ValueNode* call = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCall ),
                                              Token::JS_PROPERTY , ast_node->Line() , ValueNode::kProperty );
  ValueNode* constructor = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kConstructor ),
                                                     Token::JS_PROPERTY , ast_node->Line() , ValueNode::kProperty );
  CallExp* constructor_accessor = AstUtils::CreateDotAccessor( ast_node->Callable(), constructor );
  CallExp* normal = AstUtils::CreateDotAccessor( constructor_accessor , call );
  ast_node->Callable( normal );
  if ( !args->IsEmpty() ) {
    ast_node->Args()->InsertBefore( this_sym );
  } else {
    NodeList* args = AstUtils::CreateNodeList( 1 , this_sym );
    ast_node->Args( args );
  }
}


void CallProcessor::ProcessFnCall( CallExp* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->GetVisitor();
  AstNode* args = ast_node->Args();
  AstNode* callable = ast_node->Callable();
  if ( callable->NodeType() == AstNode::kValueNode &&
       callable->CastToValue()->ValueType() == ValueNode::kSuper ) {
    ast_node->Callable()->Accept( visitor );
    CallSuper( ast_node );
  } else {
    AstNode* tmp = ast_node->Callable();
    while ( tmp->NodeType() != AstNode::kValueNode ) {
      if ( tmp->NodeType() == AstNode::kCallExp ) {
        tmp = tmp->CastToExpression()->CastToCallExp()->Callable();
      } else {
        break;
      }
    }
    if ( tmp->NodeType() == AstNode::kValueNode ) {
      ValueNode* val = tmp->CastToValue();
      if ( val->ValueType() == ValueNode::kSuper ) {
        CallSuper( ast_node );
      }
    }
    ast_node->Callable()->Accept( visitor );
  }
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
