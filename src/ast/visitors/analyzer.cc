#include <ast/visitors/analyzer.h>
#include <ast/ast.h>
namespace mocha {

#define VISITOR_IMPL(name) JSValue* Analyzer::Analyze##name( name* ast_node )

Analyzer::Analyzer(){}

VISITOR_IMPL( Expression ) {
  NodeIterator iterator = ast_node->ChildNodes();
  JSValue* last = NoStatic::New();
  while ( iterator.HasNext() ) {
    last = iterator.Next()->CastToExpression()->Analyze( this );
  }
  return last;
}

VISITOR_IMPL( AssignmentExp ){
  JSValue* lvalue = ast_node->Left()->CastToExpression()->Analyze( this );
  JSValue* rvalue = ast_node->Right()->CastToExpression()->Analyze( this );
  return lvalue;
}

VISITOR_IMPL( Function ){
  return JSFunction::New( ast_node->Name() );
}

VISITOR_IMPL( BinaryExp ){
  ast_node->Left()->CastToExpression()->Analyze( this );
  return ast_node->Right()->CastToExpression()->Analyze( this );
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
