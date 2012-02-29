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
  VisitorInfo* visitor_info = info->visitor_info();
  Literal* maybe_ident = ast_node->callable()->CastToLiteral();
  if ( maybe_ident ) {
    Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                    Token::JS_THIS , maybe_ident->line_number() , Literal::kThis );
    Literal* private_field = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kGetPrivateRecord ),
                                                         Token::JS_IDENTIFIER , maybe_ident->line_number() , Literal::kProperty );
    NodeList* args = AstUtils::CreateNodeList( 1 , this_sym->Clone() );
    CallExp* normal = AstUtils::CreateNormalAccessor( private_field , args , ast_node->line_number() );
    CallExp* runtime_call = AstUtils::CreateRuntimeMod( normal , ast_node->line_number() );
    ast_node->set_callable( runtime_call );
    maybe_ident = ast_node->args()->CastToLiteral();
    if ( maybe_ident && maybe_ident->value_type() == Literal::kProperty ) {
      ast_node->set_call_type( CallExp::kDot );
    } else {
      ast_node->set_call_type( CallExp::kBracket );
    }
  }
}


void CallSuper ( CallExp* ast_node ) {
  AstNode* args = ast_node->args();
  Literal* this_sym = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kThis ),
                                                Token::JS_THIS , ast_node->line_number() , Literal::kThis );
  Literal* call = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCall ),
                                            Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kProperty );
  Literal* constructor = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kConstructor ),
                                                   Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kProperty );
  CallExp* constructor_accessor = AstUtils::CreateDotAccessor( ast_node->callable(), constructor , ast_node->line_number() );
  CallExp* normal = AstUtils::CreateDotAccessor( constructor_accessor , call , ast_node->line_number() );
  ast_node->set_callable( normal );
  if ( !args->IsEmpty() ) {
    ast_node->args()->InsertBefore( this_sym );
  } else {
    NodeList* args = AstUtils::CreateNodeList( 1 , this_sym );
    ast_node->set_args( args );
  }
}


void CallProcessor::ProcessFnCall( CallExp* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->visitor();
  AstNode* args = ast_node->args();
  AstNode* callable = ast_node->callable();
  if ( callable->node_type() == AstNode::kLiteral &&
       callable->CastToLiteral()->value_type() == Literal::kSuper ) {
    ast_node->callable()->Accept( visitor );
    CallSuper( ast_node );
  } else {
    AstNode* tmp = ast_node->callable();
    while ( tmp->node_type() != AstNode::kLiteral ) {
      if ( tmp->node_type() == AstNode::kCallExp ) {
        tmp = tmp->CastToExpression()->CastToCallExp()->callable();
      } else {
        break;
      }
    }
    if ( tmp->node_type() == AstNode::kLiteral ) {
      Literal* val = tmp->CastToLiteral();
      if ( val->value_type() == Literal::kSuper ) {
        CallSuper( ast_node );
      }
    }
    ast_node->callable()->Accept( visitor );
  }
  if ( !args->IsEmpty() ) {
    NodeIterator iterator = ast_node->args()->ChildNodes();
    while ( iterator.HasNext() ) {
      iterator.Next()->Accept( visitor );
    }
  }
}

void CallProcessor::ProcessExtendAccessor( CallExp* ast_node , ProcessorInfo* info ) {
  IVisitor *visitor = info->visitor();
  ast_node->callable()->Accept( visitor );
  ast_node->args()->Accept( visitor );
  CallExp* clone = ast_node->Clone()->CastToExpression()->CastToCallExp();
  Literal* extend = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kExtend ),
                                                Token::JS_IDENTIFIER , ast_node->line_number() , Literal::kProperty );
  NodeList* args = AstUtils::CreateNodeList( 2 , clone->callable() , ast_node->args() );
  CallExp* extend_call = AstUtils::CreateNormalAccessor( extend , args , ast_node->line_number() );
  CallExp* extend_acessor = AstUtils::CreateRuntimeMod( extend_call , ast_node->line_number() );
  ast_node->parent_node()->ReplaceChild( ast_node , extend_acessor );
}

}
