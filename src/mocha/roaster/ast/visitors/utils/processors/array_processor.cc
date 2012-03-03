#include <mocha/roaster/ast/visitors/utils/processors/array_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/utils/ast_utils.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/syntax_sugar_processor.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/symbol_list.h>
namespace mocha {

void ArrayProcessor::ProcessNode( ArrayLikeLiteral* literal , ProcessorInfo* info ) {
  IVisitor* visitor = info->visitor();
  if ( literal->IsComprehensions() ) {
    SyntaxSugarProcessor::ProcessArrayComprehensions( literal , info );
  } else if ( literal->IsTuple() ) {
    ProcessTuple( literal , info );
  } else {
    NodeIterator iterator = literal->elements()->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->Accept( visitor );
    }
  }
}

void ArrayProcessor::ProcessTuple( ArrayLikeLiteral* literal , ProcessorInfo* info ) {
  IVisitor* visitor = info->visitor();
  ObjectLikeLiteral* object = ObjectLikeLiteral::New( literal->line_number() );
  NodeList* list = NodeList::New();
  NodeIterator iterator = literal->elements()->ChildNodes();
  int count = 0;
  while ( iterator.HasNext() ) {
    char tmp[500];
    sprintf( tmp , "%d" , count );
    Literal* num = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , literal->line_number() , Literal::kNumeric );
    AstNode* item = iterator.Next();
    item->Accept( visitor );
    num->AddChild( item );
    list->AddChild( num );
    count++;
  }
  char tmp[500];
  sprintf( tmp , "%d" , count );
  Literal* num = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , literal->line_number() , Literal::kNumeric );
  object->Append( list );
  Literal* create_tuple = AstUtils::CreateNameNode( SymbolList::symbol( SymbolList::kCreateTuple ),
                                                    Token::JS_IDENTIFIER , literal->line_number() , Literal::kProperty );
  CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( create_tuple , literal->line_number() );
  NodeList* args = AstUtils::CreateNodeList( 2 , object , num );
  CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args , literal->line_number() );
  literal->parent_node()->ReplaceChild( literal , runtime_call );
}

}
