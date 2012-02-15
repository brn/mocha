#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/trait_processor.h>
#include <utils/pool/managed_handle.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/tokens/js_token.h>
namespace mocha {

TraitProcessor::TraitProcessor( Trait* trait , ProcessorInfo* info ) :
    trait_( trait ) , info_( info ) {}

void TraitProcessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->GetInfo();
  AstNode* name = trait_->GetName();
  name_ = ( !name->IsEmpty() )? name->CastToValue() : AstUtils::CreateTmpNode( visitor_info->GetTmpIndex() );
  ValueNode* object = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
  object->Line( trait_->Line() );
  NodeList* list = ManagedHandle::Retain<NodeList>();
  AstNode* parent = trait_->ParentNode();
  if ( trait_->IsDecl() ) {
    body_ = trait_->ParentNode();
    ValueNode* name_value = name_->Clone()->CastToValue();
    name_value->ValueType( ValueNode::kVariable );
    name_value->AddChild( object );
    VariableStmt* stmt = AstUtils::CreateVarStmt( name_value );
    parent->ReplaceChild( trait_ , stmt );
    ProcessPrivate_( list );
    ProcessPublic_( list );
    ProcessMixin_( stmt );
  } else {
    Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() );
    fn->RemoveAllChild();
    ExpressionStmt* stmt = AstUtils::CreateAnonymousFnCall( fn , ManagedHandle::Retain<Empty>() );
    body_ = stmt->FirstChild()->FirstChild();
    parent->ReplaceChild( trait_ , stmt->FirstChild() );
    ReturnStmt* ret = AstUtils::CreateReturnStmt( name_->Clone() );
    ValueNode* name_value = name_->Clone()->CastToValue();
    name_value->ValueType( ValueNode::kVariable );
    name_value->AddChild( object );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( name_value );
    fn->AddChild( var_stmt );
    ProcessPrivate_( list );
    ProcessPublic_( list );
    ProcessMixin_( var_stmt );
    fn->AddChild( ret );
  }
  object->Node( list );
  ValueNode* trait_mark = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTraitMark ),
                                                    Token::JS_PROPERTY , trait_->Line() , ValueNode::kProperty );
  ValueNode* true_value = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTrue ),
                                                    Token::JS_TRUE , trait_->Line() , ValueNode::kTrue );
  trait_mark->AddChild( true_value );
  list->AddChild( trait_mark );
}

NodeIterator GetPrivateIterator( Trait *trait ) {
  return trait->GetPrivate()->ChildNodes();
}

NodeIterator GetPublicIterator( Trait *trait ) {
  return trait->GetPublic()->ChildNodes();
}

void TraitProcessor::CommonProcessor_( NodeList* list , IteratorGetter getter , const char* type ) {
  NodeList* member_list = ManagedHandle::Retain<NodeList>();
  ValueNode* value = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
  ValueNode* member_field = AstUtils::CreateNameNode( type,
                                                      Token::JS_PROPERTY , trait_->Line() , ValueNode::kProperty );
  IVisitor* visitor = info_->GetVisitor();
  NodeIterator iterator = getter( trait_ );
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    TraitMember* member = item->CastToExpression()->CastToTraitMember();
    AstNode* property = member->GetProperty();
    property->Accept( visitor );
    Function* fn = property->CastToExpression()->CastToFunction();
    ValueNode* prop = AstUtils::CreateNameNode( fn->Name()->CastToValue()->Symbol()->GetToken(),
                                                Token::JS_PROPERTY , fn->Line() , ValueNode::kProperty );
    prop->AddChild( property );
    member_list->AddChild( prop );
  }
  value->Node( member_list );
  member_field->AddChild( value );
  list->AddChild( member_field );
}



void TraitProcessor::ProcessPrivate_( NodeList* list ) {
  CommonProcessor_( list , GetPrivateIterator , SymbolList::GetSymbol( SymbolList::kTraitPrivate ) );
}

void TraitProcessor::ProcessPublic_( NodeList* list ) {
  CommonProcessor_( list , GetPublicIterator , SymbolList::GetSymbol( SymbolList::kTraitPublic ) );
}

void TraitProcessor::ProcessMixin_( AstNode* mark ) {
  VisitorInfo* visitor_info = info_->GetInfo();
  NodeIterator iterator = trait_->GetMixinList()->ChildNodes();
  AstNode* last = mark;
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    MixinMember* member = item->CastToExpression()->CastToMixinMember();
    AstNode* name_node = member->GetName();
    AstNode* rename_list = member->GetRename();
    AstNode* removal_list = member->GetRemoval();
    name_node->Accept( info_->GetVisitor() );
    rename_list->Accept( info_->GetVisitor() );
    removal_list->Accept( info_->GetVisitor() );
    ValueNode* rename_map;
    if ( rename_list->ChildLength() > 0 ) {
      rename_map = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
      NodeIterator rename_iterator = rename_list->ChildNodes();
      while ( rename_iterator.HasNext() ) {
        
      }
    }
    ValueNode* name = name_->Clone()->CastToValue();
    ValueNode* mixin = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kMixin ),
                                               Token::JS_PROPERTY , trait_->Line() , ValueNode::kProperty );
    NodeList* args = AstUtils::CreateNodeList( 2 , name_->Clone() , name );
    CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( mixin );
    CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime_call );
    body_->InsertAfter( stmt , last );
    last = stmt;
  }
}

void TraitProcessor::ProcessRequires_( NodeList* list ) {
  
}

}
