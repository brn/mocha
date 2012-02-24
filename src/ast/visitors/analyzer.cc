#include <ast/visitors/analyzer.h>
#include <ast/visitors/optimizer_visitor.h>
#include <ast/ast.h>
#include <compiler/scopes/scope.h>
#include <ast/visitors/utils/opt/constant_optimizer.h>

namespace mocha {

#define VISITOR_IMPL(name) JSValue* Analyzer::Analyze##name( name* ast_node )

Analyzer::Analyzer( InnerScope* scope , OptimizeVisitor* visitor ) , scope_( scope ) , visitor_( visitor ){}

VISITOR_IMPL( Expression ) {
  NodeIterator iterator = ast_node->ChildNodes();
  JSValue* last = NoStatic::New();
  while ( iterator.HasNext() ) {
    last = iterator.Next()->CastToExpression()->Analyze( this );
  }
  return last;
}

VISITOR_IMPL( AssignmentExp ){
  bool is_ident = false;
  JSValue* lvalue = ast_node->Left()->CastToExpression()->Analyze( this );
  if ( lvalue->type() == JSValue::kLiteral ) {
    JSLiteral literal = lvalue->CastToJSLiteral();
    int type = literal->value()->ValueType();
    if ( type == ValueNode::kIdentifier ) {
      is_ident = true;
    } else if ( type == ValueNode::kProperty ) {
      
    }
  }
  
  JSValue* rvalue = ast_node->Right()->CastToExpression()->Analyze( this );
  if ( is_ident && ast_node->Op() == '=' ) {
    scope_->InsertAlias( literal->value()->Symbol() , rvalue->ref() );
  }
  return lvalue;
}

VISITOR_IMPL( Function ){
  return JSFunction::New( ast_node->Name() );
}

VISITOR_IMPL( BinaryExp ){
  JSValue* lvalue = ast_node->Left()->CastToExpression()->Analyze( this );
  JSValue* rvalue = ast_node->Right()->CastToExpression()->Analyze( this );
  if ( lvalue->type() != JSValue::kNoStatic && rvalue->type() != JSValue::kNoStatic ) {
    AstNode* left = lvalue->ref();
    AstNode* right = rvalue->ref();
    int op = ast_node->Op();
    AstNode* parent = ast_node->ParentNode();
    Expression* exp = parent->CastToExpression();
    BinaryExp* binary = ( exp )? exp->CastToBinary() : 0;
    bool op_assoc = ( binary )? ConstantOptimizer::CheckOperatorAssoc( op , binary->Op() ) : true;
    if ( op_assoc && ConstantOptimizer::IsOptimizable( left , right , op ) ) {
      AstNode* ret = ConstantOptimizer::Optimize( left , right , op );
      ast_node->ParentNode()->ReplaceChild( ast_node , ret );
      return;
    }
  }
  
}

VISITOR_IMPL( UnaryExp ){
  return ast_node->Exp()->CastToExpression()->Analyze( this );
}

VISITOR_IMPL( CompareExp ) {
  ast_node->Left()->CastToExpression()->Analyze( this );
  return ast_node->Right()->CastToExpression()->Analyze( this );
}

VISITOR_IMPL( CallExp ) {
  JSValue* last = ast_node->Callable()->CastToExpression()->Analyze( this );
  if ( ast_node->CallType() == CallExp::kNormal ) {
    NodeIterator iterator = ast_node->Args()->ChildNodes();
    while ( iterator.HasNext() ) {
      last = iterator.Next()->CastToExpression()->Analyze( this );
    }
    return last;
  } else {
    return ast_node->Args()->CastToExpression()->Analyze( this );
  }
}

VISITOR_IMPL( NewExp ) {
  return ast_node->FirstChild()->CastToExpression()->Analyze( this );
}

VISITOR_IMPL( PostfixExp ) {
  return ast_node->Exp()->CastToExpression()->Analyze( this );
}

VISITOR_IMPL( ConditionalExp ){
  ast_node->Cond()->CastToExpression()->Analyze( this );
  ast_node->True()->CastToExpression()->Analyze( this );
  return ast_node->False()->CastToExpression()->Analyze( this );
}

VISITOR_IMPL( ValueNode ) {
  int type = ast_node->ValueType();
  switch ( type ) {
    case ValueNode::kArray :
      return JSArray::New();
    case ValueNode::kObject :
      return JSObject::New();
    case ValueNode::kIdentifier :
      return JSLiteral::New( ast_node );
    case ValueNode::kProperty :
      return JSLiteral::New( ast_node );
    case ValueNode::kNull :
      return JSLiteral::New( ast_node );
    case ValueNode::kNumeric :
      return JSLiteral::New( ast_node );
    case ValueNode::kString :
      return JSLiteral::New( ast_node );
    case ValueNode::kRegExp :
      return JSLiteral::New( ast_node );
    case ValueNode::kNaN :
      return JSLiteral::New( ast_node );
    case ValueNode::kThis :
      return JSLiteral::New( ast_node );
  }
}

}
