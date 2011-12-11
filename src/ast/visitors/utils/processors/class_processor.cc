#include <ast/visitors/utils/processors/class_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <grammar/grammar.tab.hh>
#include <compiler/tokens/token_info.h>

#define TOKEN yy::ParserImplementation::token

namespace mocha {


MemberAttr::MemberAttr( int type , AstNode* node ) : Managed() , attr_( type ) , node_( node ){} 



inline CallExp* CreateHiddenMember( NodeList* args , long line ) {
  ValueNode* hidden = AstUtils::CreateNameNode( AstUtils::GetHiddenSymbol() , TOKEN::JS_IDENTIFIER , line );
  CallExp* mod = AstUtils::CreateRuntimeMod( hidden );
  CallExp* nrm = AstUtils::CreateNormalAccessor( mod , args );
  return nrm;
}


inline ValueNode* CreateThisNode( long line ) {
  ValueNode* this_node = AstUtils::CreateNameNode( AstUtils::GetThisSymbol() , TOKEN::JS_IDENTIFIER , line );
  return this_node;
}

inline ValueNode* CreateTypeIdNode( long line ) {
  ValueNode* this_node = AstUtils::CreateNameNode( AstUtils::GetTypeIdSymbol() , TOKEN::JS_IDENTIFIER , line );
  return this_node;
}

inline CallExp* CreateTypeIdIntializer( long line ) {
  NodeList* list = ManagedHandle::Retain<NodeList>();
  ValueNode* this_node = CreateThisNode( line );
  char buf[50];
  sprintf( buf , "'%s'" , AstUtils::GetInstanceIdSymbol() );
  ValueNode* instance_str = AstUtils::CreateNameNode( buf , TOKEN::JS_STRING_LITERAL , line );
  ValueNode* instance_sym = AstUtils::CreateNameNode( AstUtils::GetInstanceIdSymbol() , TOKEN::JS_IDENTIFIER , line );
  UnaryExp* exp = ManagedHandle::Retain( new UnaryExp( TOKEN::JS_INCREMENT ) );
  exp->Exp( instance_sym );
  list->AddChild( this_node );
  list->AddChild( instance_str );
  list->AddChild( exp );
  return CreateHiddenMember( list , line );
}


inline CallExp* CreateConstructorInitializer( long line ) {
  ValueNode* constructor_sym = AstUtils::CreateNameNode( AstUtils::GetConstructorSymbol() , TOKEN::JS_IDENTIFIER , line );
  ValueNode* apply_sym = AstUtils::CreateNameNode( AstUtils::GetApplySym() , TOKEN::JS_IDENTIFIER , line );
  NodeList *args = ManagedHandle::Retain<NodeList>();
  args->AddChild( CreateThisNode( line ) );
  args->AddChild( AstUtils::CreateNameNode( AstUtils::GetArgumentsSymbol() , TOKEN::JS_IDENTIFIER , line ) );
  CallExp* apply_call = AstUtils::CreateNormalAccessor( apply_sym , args );
  CallExp* this_accessor = AstUtils::CreateDotAccessor( CreateThisNode( line ) , constructor_sym );
  CallExp* initial_call = AstUtils::CreateDotAccessor( this_accessor , apply_call );
  return initial_call;
}


inline CallExp* CreateHiddenCall( const char* name , AstNode* val , Class* class_ ) {
  ValueNode* hidden_call_sym = AstUtils::CreateNameNode( AstUtils::GetHiddenCallSymbol() , TOKEN::JS_IDENTIFIER , class_->Line() );
  NodeList *list = ManagedHandle::Retain<NodeList>();
  char tmp[50];
  sprintf( tmp , "'%s'" , name );
  ValueNode* name_sym = AstUtils::CreateNameNode( tmp , TOKEN::JS_IDENTIFIER , class_->Line() );
  ValueNode* this_sym = CreateThisNode( class_->Line() );
  ValueNode* typeid_sym = AstUtils::CreateNameNode( AstUtils::GetTypeIdSymbol(),
                                                    TOKEN::JS_IDENTIFIER , class_->Line() );
  CallExp* accessor_node = AstUtils::CreateDotAccessor( this_sym , typeid_sym );
  list->AddChild( accessor_node );
  list->AddChild( name_sym );
  list->AddChild( val );
  CallExp* hidden_call = AstUtils::CreateNormalAccessor( hidden_call_sym , list );
  CallExp* exp = AstUtils::CreateRuntimeMod( hidden_call );
  return exp;
}


inline void Finish( const char* name , Class* class_ , AstNode* closure_ ) {
  if ( class_->Decl() ) {
    TokenInfo* info = ManagedHandle::Retain( new TokenInfo( name , TOKEN::JS_IDENTIFIER , class_->Line() ) );
    ValueNode* vars = AstUtils::CreateVarInitiliser( info , closure_->FirstChild() );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( vars );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list );
    class_->ParentNode()->ParentNode()->ReplaceChild( class_->ParentNode() , stmt );
  } else {
    class_->AddChild( closure_->FirstChild() );
  }
}


ClassProcessor::ClassProcessor( ProcessorInfo* info , Class* ast_node , Statement* tmp_stmt ) :
    Managed(),
    class_id_( info->GetInfo()->GetTmpIndex() ) , info_( info ) , class_( ast_node ) , tmp_stmt_( tmp_stmt ) {
  closure_body_ = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() ,
                                           ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<StatementList>() );
  closure_ = AstUtils::CreateAnonymousFnCall( closure_body_ , ManagedHandle::Retain<Empty>() );
}



void ClassProcessor::ProcessNode() {
  AstNode* name_node = class_->Name();
  AstNode* body = class_->Body();
  if ( !name_node->IsEmpty() ) {
    name_ = name_node->CastToValue()->Symbol()->GetToken();
  } else {
    char buf[500];
    name_ = AstUtils::CreateTmpRef( buf , info_->GetInfo()->GetTmpIndex() );
  }
  
  ValueNode* name = AstUtils::CreateNameNode( name_.c_str() , TOKEN::JS_IDENTIFIER , class_->Line() );
  Function* fn = AstUtils::CreateFunctionDecl( name , ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() );
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( fn );

  ExpressionStmt* type_id_initializer = AstUtils::CreateExpStmt( CreateTypeIdIntializer( class_->Line() ) );
  fn->AddChild( type_id_initializer );
  ExpressionStmt* constructor_initializer = AstUtils::CreateExpStmt( CreateConstructorInitializer( class_->Line() ) );
  fn->AddChild( constructor_initializer );
  
  closure_body_->AddChild( stmt );
  ProcessBody_( body );
  ReturnStmt* ret = AstUtils::CreateReturnStmt( name->Clone() );
  closure_body_->AddChild( ret );
  Finish( name_.c_str() , class_ , closure_ );
}



inline void ClassProcessor::ProcessBody_( AstNode* body ) {
  if ( !body->IsEmpty() ) {
    ProcessMember_( reinterpret_cast<ClassProperties*>( body ) );
  }
}

inline void ClassProcessor::ProcessMember_( ClassProperties* body ) {
  AstNode* public_list = body->Public();
  AstNode* private_list = body->Private();
  AstNode* prototype_list = body->Prototype();
  AstNode* static_list = body->Static();
  AstNode* constructor_decl = body->Constructor();

  if ( constructor_decl ) {
    Function* constructor = reinterpret_cast<Function*>( constructor_decl->FirstChild() );
    constructor_ = constructor;
    ProcessConstructor_( constructor );
  }

  IterateMember_( public_list , true , false , false );
  IterateMember_( private_list , true , true , false );
  IterateMember_( prototype_list , true , true , false );
  IterateMember_( static_list , false , false , false );
}


inline void ClassProcessor::ProcessConstructor_( Function* constructor ) {
  ValueNode* name_node = AstUtils::CreateNameNode( name_.c_str() , TOKEN::JS_IDENTIFIER , constructor->Line() );
  ValueNode* hidden = AstUtils::CreateNameNode( AstUtils::GetHiddenSymbol() , TOKEN::JS_IDENTIFIER , constructor->Line() );
  char tmp[50];
  sprintf( tmp , "'%s'" , AstUtils::GetConstructorSymbol() );
  ValueNode* consturctor_sym = AstUtils::CreateNameNode( tmp , TOKEN::JS_IDENTIFIER , constructor->Line() );
  NodeList *list = ManagedHandle::Retain<NodeList>();
  list->AddChild( name_node );
  list->AddChild( consturctor_sym );
  list->AddChild( constructor );
  Function *backup = closure_body_;
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( CreateHiddenMember( list , constructor->Line() ) );
  
  NodeIterator iterator = constructor->ChildNodes();
  closure_body_ = constructor;
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    if ( item->NodeType() == AstNode::kClassMember ) {
      ClassMember* member = reinterpret_cast<ClassMember*>( item );
      if ( member->Attr() == ClassMember::kPrivate ) {
        ProcessEachMember_( member->FirstChild() , false , true , true );
      } else {
        ProcessEachMember_( member->FirstChild() , false , false , true );
      }
    } else {
      item->Accept( info_->GetVisitor() );
    }
  }
  closure_body_ = backup;
  closure_body_->AddChild( stmt );
}


inline void ClassProcessor::IterateMember_( AstNode *list , bool is_prototype , bool is_private , bool is_instance ) {
  NodeIterator iterator = list->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* member = iterator.Next()->FirstChild();
    ProcessEachMember_( member , is_prototype , is_private , is_instance );
  }
}

void ClassProcessor::ProcessEachMember_( AstNode* node , bool is_prototype , bool is_private , bool is_instance ) {
  IVisitor* visitor = info_->GetVisitor();
  switch ( node->NodeType() ) {

    case AstNode::kFunction : {
      ProcessFunction_( reinterpret_cast<Function*>( node ) , is_prototype , is_private );
    }
      break;
      
    case AstNode::kValueNode : {
      AstNode* child_node = node->CastToValue()->Node();
      ProcessVariable_( child_node , is_prototype , is_private , is_instance );
    }
      break;
      
    case AstNode::kNodeList : {
      ProcessVariable_( node , is_prototype , is_private , is_instance );
    }
  }
}

inline void ClassProcessor::ProcessVariable_( AstNode* node , bool is_prototype , bool is_private ,bool is_instance ) {
  NodeIterator iterator = node->Clone()->ChildNodes();
  if ( is_private && is_prototype ) {
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->Append( node );
    VariableStmt* stmt = AstUtils::CreateVarStmt( list );
    closure_body_->InsertBefore( stmt );
    stmt->Accept( info_->GetVisitor() );
  } else {
    while ( iterator.HasNext() ) {
      ValueNode* value = iterator.Next()->CastToValue();
      if ( value ) {
        if ( value->ValueType() == ValueNode::kDst && tmp_stmt_->HasDsta() ) {
          value->ValueType( ValueNode::kIdentifier );
        } else {
          if ( !is_private ) {
            ValueNode* name_node;
            if ( !is_instance ) {
              name_node = AstUtils::CreateNameNode( name_.c_str() , TOKEN::JS_IDENTIFIER , node->Line() );
            } else {
              name_node = AstUtils::CreateNameNode( AstUtils::GetThisSymbol() , TOKEN::JS_IDENTIFIER , node->Line() );
            }
            value->ValueType( ValueNode::kIdentifier );
            CallExp* exp = 0;
            if ( is_prototype ) {
              exp = AstUtils::CreatePrototypeAccessor( name_node , value );
            } else {
              exp = AstUtils::CreateDotAccessor( name_node , value );
            }
            AstNode* lhs = value->FirstChild();
            lhs = ( lhs->IsEmpty() )? AstUtils::CreateNameNode( AstUtils::GetUndefinedSymbol(),
                                                                TOKEN::JS_IDENTIFIER , node->Line() ) : lhs;
            ExpressionStmt* stmt = AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , exp , lhs ) );
            closure_body_->AddChild( stmt );
          } else {
            AstNode* accessor_node;
            const char* table = 0;
            value->ValueType( ValueNode::kIdentifier );
            if ( !is_instance ) {
              char buf[ 50 ];
              sprintf( buf , "%d" , class_id_ );
              accessor_node = AstUtils::CreateNameNode( buf , TOKEN::JS_NUMERIC_LITERAL , value->Line() );
              table = AstUtils::GetClassTableSymbol();
            }

            AstNode* lhs = value->FirstChild();
            lhs = ( lhs->IsEmpty() )? AstUtils::CreateNameNode( AstUtils::GetUndefinedSymbol(),
                                                                TOKEN::JS_IDENTIFIER , node->Line() ) : lhs;
            AstNode* result = 0;
            if ( is_instance ) {
              result = CreateHiddenCall( value->Symbol()->GetToken() , lhs , class_ );
            } else {
              ValueNode* name_node = AstUtils::CreateNameNode( table,
                                                               TOKEN::JS_IDENTIFIER , node->Line() );
              CallExp* exp = AstUtils::CreateArrayAccessor( name_node , accessor_node );
              exp = AstUtils::CreateDotAccessor( exp , value );
              result = AstUtils::CreateAssignment( '=' , exp , lhs );
            }
            
            ExpressionStmt* stmt = AstUtils::CreateExpStmt( result );
            closure_body_->AddChild( stmt );
          }
        }
      }
    }
  }
}



inline void ClassProcessor::ProcessFunction_( Function* fn , bool is_prototype , bool is_private ) {
  fn = reinterpret_cast<Function*>( fn->Clone() );
  if ( is_prototype && is_private ) {
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( fn );
    closure_body_->InsertBefore( stmt );
    fn->Accept( info_->GetVisitor() );
  } else {
    ValueNode* value = fn->Name()->CastToValue();
    if ( !is_private ) {
      ValueNode* name_node = AstUtils::CreateNameNode( name_.c_str() , TOKEN::JS_IDENTIFIER , fn->Line() );
      CallExp* exp = 0;
      if ( is_prototype ) {
        exp = AstUtils::CreatePrototypeAccessor( name_node , value );
      } else {
        exp = AstUtils::CreateDotAccessor( name_node , value );
      }
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , exp , fn ) );
      closure_body_->AddChild( stmt );
    } else {
      ValueNode* name_node = AstUtils::CreateNameNode( AstUtils::GetClassTableSymbol(),
                                                       TOKEN::JS_IDENTIFIER , fn->Line() );
      char buf[ 50 ];
      const char* accessor = AstUtils::CreateTmpRef( buf , class_id_ );
      ValueNode* accessor_node = AstUtils::CreateNameNode( accessor , TOKEN::JS_NUMERIC_LITERAL , value->Line() );
      CallExp* exp = AstUtils::CreateArrayAccessor( name_node , accessor_node );
      value->ValueType( ValueNode::kIdentifier );
      exp = AstUtils::CreateDotAccessor( exp , value );
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , exp , fn ) );
      closure_body_->AddChild( stmt );
    }
  }
}

}
