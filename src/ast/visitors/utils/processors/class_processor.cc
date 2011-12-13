#include <ast/visitors/utils/processors/class_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <grammar/grammar.tab.hh>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>

#define TOKEN yy::ParserImplementation::token

namespace mocha {

inline CallExp* CreateHiddenMember( NodeList* args , long line ) {
  ValueNode* hidden = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateUnenumProp ),
                                                TOKEN::JS_IDENTIFIER , line );
  CallExp* mod = AstUtils::CreateRuntimeMod( hidden );
  CallExp* nrm = AstUtils::CreateNormalAccessor( mod , args );
  return nrm;
}


inline ValueNode* CreatePrivateHolder( long line ) {
  return AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                   TOKEN::JS_IDENTIFIER , line );
}

inline ValueNode* CreatePrivateField( long line ) {
  return AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateField ),
                                   TOKEN::JS_IDENTIFIER , line );
}

inline ValueNode* CreateThisNode( long line ) {
  ValueNode* this_node = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                   TOKEN::JS_IDENTIFIER , line );
  return this_node;
}


inline CallExp* CreatePrivateFieldAccessor( AstNode* name ) {
  ValueNode* this_sym = CreateThisNode( name->Line() );
  return AstUtils::CreateDotAccessor( this_sym , CreatePrivateField( name->Line() ) );
}

inline ValueNode* CreateTypeIdNode( long line ) {
  ValueNode* this_node = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTypeId ),
                                                   TOKEN::JS_IDENTIFIER , line );
  return this_node;
}

inline CallExp* CreatePrivateInstance( long line ) {
  
  NodeList* list = ManagedHandle::Retain<NodeList>();
  char buf[50];
  sprintf( buf , "'%s'" , SymbolList::GetSymbol( SymbolList::kPrivateField ) );
  ValueNode* field = AstUtils::CreateNameNode( buf , TOKEN::JS_IDENTIFIER , line );
  ValueNode* this_sym = CreateThisNode( line );
  ValueNode* holder = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                                TOKEN::JS_IDENTIFIER , line );
  NewExp* new_exp = ManagedHandle::Retain<NewExp>();
  new_exp->Constructor( holder );
  list->AddChild( this_sym );
  list->AddChild( field );
  list->AddChild( new_exp );
  return CreateHiddenMember( list , line );
}


inline CallExp* CreateConstructorInitializer( const char* name , long line ) {
  ValueNode* constructor_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kConstructor ),
                                                         TOKEN::JS_IDENTIFIER , line );
  ValueNode* apply_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kApply ),
                                                   TOKEN::JS_IDENTIFIER , line );
  NodeList *args = ManagedHandle::Retain<NodeList>();
  args->AddChild( CreateThisNode( line ) );
  args->AddChild( AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kArguments ),
                                            TOKEN::JS_IDENTIFIER , line ) );
  CallExp* apply_call = AstUtils::CreateNormalAccessor( apply_sym , args );
  CallExp* consturctor_accessor = AstUtils::CreateDotAccessor( AstUtils::CreateNameNode( name , TOKEN::JS_IDENTIFIER , line ) , constructor_sym );
  CallExp* initial_call = AstUtils::CreateDotAccessor( consturctor_accessor , apply_call );
  return initial_call;
}


inline AstNode* CreateHolderAssignment( AstNode* val,
                                  AstNode* name,
                                  Class* class_,
                                  bool is_const,
                                  bool is_instance ) {

  if ( !is_instance ) {
    CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( CreatePrivateHolder( val->Line() ) );
    if ( is_const ) {
      return AstUtils::CreateConstantProp( prototype_accessor , name , val );
    } else {
      AstNode* lhs =  AstUtils::CreateDotAccessor( prototype_accessor , name );
      return AstUtils::CreateAssignment( '=' , lhs , val );
    }
  } else {
    CallExp* field_accessor = CreatePrivateFieldAccessor( name );
    if ( is_const ) {
      return AstUtils::CreateConstantProp( field_accessor , name , val );
    } else {
      AstNode* lhs = AstUtils::CreateDotAccessor( field_accessor , name );
      return AstUtils::CreateAssignment( '=' , lhs , val );
    }
  }
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


inline VariableStmt* CreatePrivateHolder( Class* class_ ) {
  Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>(),
                                               ManagedHandle::Retain<Empty>(), ManagedHandle::Retain<Empty>() );
  ValueNode* private_holder_name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                                             TOKEN::JS_IDENTIFIER , class_->Line() );
  ValueNode* value = AstUtils::CreateVarInitiliser( private_holder_name->Symbol() , fn );
  VariableStmt* stmt = AstUtils::CreateVarStmt( value );
  return stmt;
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

  closure_body_->InsertBefore( CreatePrivateHolder( class_ ) );

  ExpressionStmt *new_call = AstUtils::CreateExpStmt( CreatePrivateInstance( class_->Line() ) );
  fn->AddChild( new_call );
  ExpressionStmt* constructor_initializer = AstUtils::CreateExpStmt( CreateConstructorInitializer( name_.c_str() , class_->Line() ) );
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
  char tmp[50];
  sprintf( tmp , "'%s'" , SymbolList::GetSymbol( SymbolList::kConstructor ) );
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
  switch ( node->NodeType() ) {

    case AstNode::kFunction : {
      ProcessFunction_( reinterpret_cast<Function*>( node ) , is_prototype , is_private , is_instance );
    }
      break;
      
    case AstNode::kValueNode : {
      AstNode* child_node = node->CastToValue()->Node();
      ProcessVariable_( child_node , is_prototype , is_private , is_instance , true );
    }
      break;
      
    case AstNode::kNodeList : {
      ProcessVariable_( node , is_prototype , is_private , is_instance , false );
    }
  }
}

inline AstNode* GetSafeValue( ValueNode* value ) {
  AstNode* lhs = value->FirstChild();
  return ( lhs )? lhs : AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                 TOKEN::JS_IDENTIFIER , value->Line() );
}

inline ExpressionStmt* InstancePrivate( ValueNode* value ) {
  CallExp* private_accessor = CreatePrivateFieldAccessor( value );
  CallExp* dot_accessor = AstUtils::CreateDotAccessor( private_accessor , value );
  return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , dot_accessor , GetSafeValue( value ) ) );
}

inline ExpressionStmt* InstancePublic( ValueNode* value ) {
  ValueNode* this_node = CreateThisNode( value->Line() );
  CallExp* dot_accessor = AstUtils::CreateDotAccessor( this_node , value );
  return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , dot_accessor , GetSafeValue( value ) ) );
}

inline ExpressionStmt* ConstantInstancePrivate( ValueNode* value ) {
  CallExp* constant_accessor = AstUtils::CreateConstantProp( CreatePrivateFieldAccessor( value ),
                                                             value , GetSafeValue( value ) );
  return AstUtils::CreateExpStmt( constant_accessor );
}

inline ExpressionStmt* ConstantInstancePublic( ValueNode* value ) {
  ValueNode* this_node = CreateThisNode( value->Line() );
  CallExp* dot_accessor = AstUtils::CreateDotAccessor( this_node , value );
  CallExp* constant_accessor = AstUtils::CreateConstantProp( dot_accessor,
                                                             value , GetSafeValue( value ) );
  return AstUtils::CreateExpStmt( constant_accessor );
}

inline ExpressionStmt* PrototypePrivate( AstNode* name_node , AstNode* val ) {
  ValueNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                              TOKEN::JS_IDENTIFIER , val->Line() );
  CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
  CallExp* name_accessor = AstUtils::CreateDotAccessor( prototype_accessor , name_node );
  return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , name_accessor , val ) );
}

inline ExpressionStmt* PrototypePublic( const char* class_name, AstNode* name_node , AstNode* val ) {
  ValueNode* name = AstUtils::CreateNameNode( class_name,
                                              TOKEN::JS_IDENTIFIER , val->Line() );
  CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
  CallExp* name_accessor = AstUtils::CreateDotAccessor( prototype_accessor , name_node );
  return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , name_accessor , val ) );
}

inline ExpressionStmt* ConstantPrototypePrivate( AstNode* name_node , AstNode* val ) {
  ValueNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                              TOKEN::JS_IDENTIFIER , val->Line() );
  CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
  CallExp* constant_accessor = AstUtils::CreateConstantProp( prototype_accessor,
                                                             name_node , val );
  return AstUtils::CreateExpStmt( constant_accessor );
}

inline ExpressionStmt* ConstantPrototypePublic( const char* class_name , AstNode* name_node , AstNode* val ) {
  ValueNode* name = AstUtils::CreateNameNode( class_name,
                                              TOKEN::JS_IDENTIFIER , val->Line() );
  CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
  CallExp* constant_accessor = AstUtils::CreateConstantProp( prototype_accessor,
                                                             name_node , val );
  return AstUtils::CreateExpStmt( constant_accessor );
}

inline ExpressionStmt* Static( const char* class_name , AstNode* name_node , AstNode* val ) {
  ValueNode* name = AstUtils::CreateNameNode( class_name,
                                              TOKEN::JS_IDENTIFIER , val->Line() );
  CallExp* dot_accessor = AstUtils::CreateDotAccessor( name , name_node );
  return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , dot_accessor , val ) );
}

inline ExpressionStmt* ConstantStatic( const char* class_name , AstNode* name_node , AstNode* val ) {
  ValueNode* name = AstUtils::CreateNameNode( class_name,
                                              TOKEN::JS_IDENTIFIER , val->Line() );
  CallExp* constant_accessor = AstUtils::CreateConstantProp( name , name_node , val );
  return AstUtils::CreateExpStmt( constant_accessor );
}



#define INSTANCE_DSTA(accessor)                                         \
  inline void Instance##accessor##Dsta( const char* class_name,         \
                                        Function* closure_body,         \
                                        AssignmentExp* exp,             \
                                        bool is_const ) {               \
    ValueNode* ident = exp->Left()->CastToValue();                      \
    if ( ident ) {                                                      \
      ident->RemoveAllChild();                                          \
      ident->AddChild( exp->Right() );                                  \
      if ( is_const ) {                                                 \
        closure_body->AddChild( ConstantInstance##accessor( ident ) );  \
      } else {                                                          \
        closure_body->AddChild( Instance##accessor( ident ) );          \
      }                                                                 \
    }                                                                   \
  }
INSTANCE_DSTA(Public);
INSTANCE_DSTA(Private);


#undef INSTANCE_DSTA

#define PROTOTYPE_DSTA(accessor,args)                                       \
  inline void Prototype##accessor##Dsta( const char* class_name,\
                                         Function* closure_body,        \
                                         AssignmentExp* exp,\
                                         bool is_const ) {              \
    if ( is_const ) {                                                   \
      closure_body->AddChild( ConstantPrototype##accessor( args ) ); \
    } else {                                                            \
      closure_body->AddChild( Prototype##accessor( args ) ); \
    }                                                                   \
  }
#define PUBLIC_ARGS class_name , exp->Left() , exp->Right()
#define PRIVATE_ARGS exp->Left() , exp->Right()
PROTOTYPE_DSTA(Public,PUBLIC_ARGS);
PROTOTYPE_DSTA(Private,PRIVATE_ARGS);
#undef PROTOTYPE_DSTA
#undef PUBLIC_ARGS
#undef PRIVATE_ARGS


inline void StaticDsta( const char* class_name,
                        Function* closure_body,
                        AssignmentExp* exp,
                        bool is_const ) {
  if ( is_const ) {
    closure_body->AddChild( ConstantStatic( class_name , closure_body , exp ) );
  } else {
    closure_body->AddChild( Static( class_name , closure_body , exp ) );
  }
}

inline void ClassProcessor::ProcessDsta_( ValueNode *value,
                                          bool is_const,
                                          DstaCallback callback ) {
  value->Accept( info_->GetVisitor() );
  if ( tmp_stmt_->HasDsta() ) {
    value->ValueType( ValueNode::kVariable );
    VariableStmt* stmt = AstUtils::CreateVarStmt( value );
    closure_body_->AddChild( stmt );
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( tmp_stmt_ , info_ );
    NodeIterator iterator = list->ChildNodes();
    while ( iterator.HasNext() ) {
      AssignmentExp* exp = reinterpret_cast<AssignmentExp*>( iterator.Next() );
      callback( name_.c_str() , closure_body_ , exp , is_const );
    }
  }
}

inline void ClassProcessor::SimpleVariables_( AstNode* node , bool is_const ) {
  NodeIterator iterator = node->ChildNodes();
  while ( iterator.HasNext() ) {
    AstNode* item = iterator.Next();
    ValueNode* value = item->CastToValue();
    if ( value ) {
      if ( value->ValueType() == ValueNode::kDst ) {
        ProcessDsta_( value , is_const , PrototypePrivateDsta );
      } else {
        value->ValueType( ValueNode::kIdentifier );
        ExpressionStmt* result = 0;
        if ( is_const ) {
          result = ConstantPrototypePrivate( value , GetSafeValue( value ) );
        } else {
          result = PrototypePrivate( value , GetSafeValue( value ) );
        }
        closure_body_->AddChild( result );
      }
    }
  }
}

inline void ClassProcessor::NoSimpleVariables_( AstNode* node,
                                                bool is_prototype,
                                                bool is_private,
                                                bool is_instance,
                                                bool is_const ) {

  const char* class_name = name_.c_str();
  NodeIterator iterator = node->ChildNodes();
  while ( iterator.HasNext() ) {
    ValueNode* value = iterator.Next()->CastToValue();
    if ( value ) {
      if ( value->ValueType() == ValueNode::kDst ) {
        if ( !is_instance && !is_prototype ) {
          ProcessDsta_( value , is_const , StaticDsta );
        } else if ( is_prototype ) {
          ProcessDsta_( value , is_const , PrototypePublicDsta );
        } else if ( is_private ){
          ProcessDsta_( value , is_const , InstancePrivateDsta );
        } else {
          ProcessDsta_( value , is_const , InstancePublicDsta );
        }
      } else {
        ExpressionStmt* result = 0;
        value->ValueType( ValueNode::kIdentifier );
        AstNode* safe_val = GetSafeValue( value );
        if ( !is_instance && !is_prototype ) {
          if ( is_const ) {
            result = ConstantStatic( class_name , value , safe_val );
          } else {
            result = Static( class_name , value , safe_val );
          }
        } else if ( is_prototype ) {
          if ( is_const ) {
            result = ConstantPrototypePublic( class_name , value , safe_val );
          } else {
            result = PrototypePublic( class_name , value , safe_val );
          }
        } else if ( is_private ) {
          if ( is_const ) {
            result = ConstantInstancePrivate( value );
          } else {
            result = InstancePrivate( value );
          }
        } else {
          if ( is_const ) {
            result = ConstantInstancePublic( value );
          } else {
            result = InstancePublic( value );
          }
        }
        closure_body_->AddChild( result );
      }
    }
  }
}


inline void ClassProcessor::ProcessVariable_( AstNode* node,
                                              bool is_prototype,
                                              bool is_private,
                                              bool is_instance,
                                              bool is_const ) {
  if ( is_private && is_prototype ) {
    SimpleVariables_( node->Clone() , is_const );
  } else {
    NoSimpleVariables_( node->Clone() , is_prototype , is_private , is_instance , is_const );
  }
}



inline void ClassProcessor::ProcessFunction_( Function* fn , bool is_prototype , bool is_private , bool is_instance ) {
  fn = reinterpret_cast<Function*>( fn->Clone() );
  ValueNode* value = fn->Name()->CastToValue();
  const char* class_name = name_.c_str();
  if ( !is_instance && !is_prototype ) {
    fn->Accept( info_->GetVisitor() );
    closure_body_->AddChild( Static( class_name , value , fn ) );
  } else if ( is_prototype ) {
    if ( is_private ) {
      info_->GetInfo()->EnterPrivate();
      fn->Accept( info_->GetVisitor() );
      info_->GetInfo()->EscapePrivate();
      closure_body_->AddChild( PrototypePrivate( value , fn ) );
    } else {
      fn->Accept( info_->GetVisitor() );
      closure_body_->AddChild( PrototypePublic( class_name , value , fn ) );
    }
  } else {
    if ( is_private ) {
      info_->GetInfo()->EnterPrivate();
      fn->Accept( info_->GetVisitor() );
      info_->GetInfo()->EscapePrivate();
      closure_body_->AddChild( PrototypePrivate( value , fn ) );
    } else {
      fn->Accept( info_->GetVisitor() );
      closure_body_->AddChild( PrototypePublic( class_name , value , fn ) );
    }
  }
}

}
