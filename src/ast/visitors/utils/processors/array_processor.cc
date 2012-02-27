#include <ast/visitors/utils/processors/array_processor.h>
namespace mocha {

void ArrayProccessor::ProcessNode( ArrayLikeLiteral* literal , ProcessorInfo* info ) {
  IVisitor* visitor = info->GetVisitor();
  if ( ast_node->comprehensions() ) {
    SyntaxSugarProcessor::ProcessArrayComprehensions( ast_node , proc_info_.Get() );
  } else if ( ast_node->tuple() ) {
    ProcessTuple( literal , info );
  } else {
    NodeIterator iterator = ast_node->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->Accept( visitor );
    }
  }
}

void ArrayProccessor::ProcessTuple( ArrayLikeLiteral* literal , ProcessorInfo* info ) {
  IVisitor* visitor = info->GetVisitor();
  ObjectLikeLiteral* object = ObjectLikeLiteral::New( literal->line_number() );
  NodeList* list = NodeList::New();
  NodeIterator iterator = ast_node->ChildNodes();
  int count = 0;
  while ( iterator.HasNext() ) {
    char tmp[500];
    sprintf( tmp , "%d" , count );
    Literal* num = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , ast_node->Line() , Literal::kNumeric );
    AstNode* item = iterator.Next();
    item->Accept( visitor );
    num->AddChild( item );
    list->AddChild( num );
    count++;
  }
  char tmp[500];
  sprintf( tmp , "%d" , count );
  Literal* num = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , ast_node->Line() , Literal::kNumeric );
  object->Append( list );
  Literal* create_tuple = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateTuple ),
                                                    Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
  CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( create_tuple );
  NodeList* args = AstUtils::CreateNodeList( 2 , object , num );
  CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args );
  ast_node->parent_node()->ReplaceChild( ast_node , runtime_call );
}

}
