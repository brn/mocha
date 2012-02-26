#include <ast/visitors/analyzer.h>
#include <ast/visitors/optimizer_visitor.h>
#include <ast/ast.h>
#include <compiler/scopes/scope.h>
#include <ast/visitors/utils/opt/constant_optimizer.h>

namespace mocha {

#define VISITOR_IMPL(name) JSValue* Analyzer::Analyze##name( name* ast_node )

Analyzer::Analyzer( InnerScope* scope , OptimizeVisitor* visitor ) , scope_( scope ) , visitor_( visitor ){}

SymbolEntry FindAlias( TokenInfo* info , InnerScope* scope ) {
  SymbolEntry entry = scope->FindAlias( info );
  if ( entry.IsEmpty() ) {
    return scope->Find( info );
  }
  return entry;
}

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
      return ret->Analyze( this );
    }
    exp = left->CastToExpression();
    binary = ( exp )? exp->CastToBinary() : 0;
    if ( binary ) {
      int lop = binary->Op();
      if ( op_assoc && ConstantOptimizer::IsOptimizable( binary->Right() , right , op ) ) {
        AstNode* ret = ConstantOptimizer::Optimize( binary->Right() , right , op );
        binary->ReplaceChild( binary->Right() , ret );
        ast_node->ParentNode()->ReplaceChild( ast_node , binary );
        return binary->Accept( this );
      }
    }
  }
  return NoStatic::New();
}

VISITOR_IMPL( UnaryExp ){
  JSValue* value = ast_node->Exp()->CastToExpression()->Analyze( this );
  int type = value->type();
  int op = ast_node->Op();
  switch( type ) {
    case kLiteral : {
      type = value->CastToJSLiteral()->type();
      switch ( type ) {
        case ValueNode::kObject :
        case ValueNode::kArray :
          if ( op == '!' ) {
            return JSLiteral::New( ValueNode::kFalse , ast_node );
          } else if ( op == Token::JS_DELETE ) {
            ValueNode* true_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( Symbol::kTrue ) , Token::JS_TRUE,
                                                            ast_node->Line() , ValueNode::kTrue );
            ast_node->ParentNode()->ReplaceChild( ast_node , true_sym );
            return JSLiteral::New( ValueNode::kTrue , true_sym );
          } else if ( op == Token::JS_VOID ) {
            ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( Symbol::kUndefined ) , Token::JS_IDENTIFIER,
                                                             ast_node->Line() , ValueNode::kIdentifier );
            ast_node->ParentNode()->ReplaceChild( ast_node , undefined );
            return JSLiteral::New( ValueNode::kIdentifier , undefined );
          } else if ( op == Token::JS_TYPEOF ) {
            ValueNode* str = AstUtils::CreateNameNode( "\"[object Object]\"" , Token::JS_STRING_LITERAL,
                                                       ast_node->Line() , ValueNode::kString );
            ast_node->ParentNode()->ReplaceChild( ast_node , str );
            return JSLiteral( ValueNode::kString , str );
          } else if ( op == Token::JS_INCREMENT || op == Token::JS_DECREMENT || op == '+' || op == '-' ) {
            ValueNode* nan = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kNaN ) , Token::JS_STRING_LITERAL,
                                                       ast_node->Line() , ValueNode::kString );
            ast_node->ParentNode()->ReplaceChild( ast_node , nan );
            return JSLiteral( ValueNode::kNaN , nan );
          }
          break;
        case ValueNode::kIdentifier :
          if ( op == '!' ) {
            return JSLiteral::New( ValueNode::kFalse , ast_node );
          } else if ( op == Token::JS_DELETE ) {
            ValueNode* true_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( Symbol::kTrue ) , Token::JS_TRUE,
                                                            ast_node->Line() , ValueNode::kTrue );
            ast_node->ParentNode()->ReplaceChild( ast_node , true_sym );
            return JSLiteral::New( ValueNode::kTrue , true_sym );
          } else if ( op == Token::JS_VOID ) {
            ValueNode* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( Symbol::kUndefined ) , Token::JS_IDENTIFIER,
                                                             ast_node->Line() , ValueNode::kIdentifier );
            ast_node->ParentNode()->ReplaceChild( ast_node , undefined );
            return JSLiteral::New( ValueNode::kIdentifier , undefined );
          } else if ( op == Token::JS_TYPEOF ) {
            ValueNode* str = AstUtils::CreateNameNode( "\"[object Object]\"" , Token::JS_STRING_LITERAL,
                                                       ast_node->Line() , ValueNode::kString );
            ast_node->ParentNode()->ReplaceChild( ast_node , str );
            return JSLiteral( ValueNode::kString , str );
          } else if ( op == Token::JS_INCREMENT || op == Token::JS_DECREMENT || op == '+' || op == '-' ) {
            ValueNode* nan = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kNaN ) , Token::JS_STRING_LITERAL,
                                                       ast_node->Line() , ValueNode::kString );
            ast_node->ParentNode()->ReplaceChild( ast_node , nan );
            return JSLiteral( ValueNode::kNaN , nan );
          }
          break;
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
      break;
  }
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
