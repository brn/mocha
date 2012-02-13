#include <ast/visitors/utils/processors/class_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/ast.h>
#include <ast/utils/ast_utils.h>
#include <utils/pool/managed_handle.h>
#include <grammar/grammar.tab.hh>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>

#define TOKEN yy::ParserImplementation::token

namespace mocha {


class ClassProcessorUtils {
 public :
  ClassProcessorUtils( ClassProcessor* processor , std::string* private_field ) :
      processor_( processor ) , private_field_( private_field ){}
  ~ClassProcessorUtils(){}
  inline CallExp* CreateHiddenMember( NodeList* args , long line ) {
    ValueNode* hidden = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateUnenumProp ),
                                                  Token::JS_IDENTIFIER , line , ValueNode::kProperty );
    CallExp* mod = AstUtils::CreateRuntimeMod( hidden );
    CallExp* nrm = AstUtils::CreateNormalAccessor( mod , args );
    return nrm;
  }


  inline ValueNode* CreatePrivateHolderName( long line ) {
    return AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                     Token::JS_IDENTIFIER , line , ValueNode::kIdentifier );
  }

  inline ValueNode* CreatePrivateField( long line ) {
    return AstUtils::CreateNameNode( private_field_->c_str(),
                                     Token::JS_IDENTIFIER , line , ValueNode::kProperty );
  }

  inline ValueNode* CreateThisNode( long line ) {
    ValueNode* this_node = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                     Token::JS_IDENTIFIER , line , ValueNode::kIdentifier );
    return this_node;
  }


  inline CallExp* CreatePrivateFieldAccessor( AstNode* name ) {
    ValueNode* private_field = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGetPrivateRecord ),
                                                         Token::JS_PROPERTY , name->Line() , ValueNode::kProperty );
    ValueNode* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                    Token::JS_IDENTIFIER , name->Line() , ValueNode::kIdentifier );
    NodeList* args = AstUtils::CreateNodeList( 1 , this_sym );
    CallExp* normal = AstUtils::CreateNormalAccessor( private_field , args );
    return AstUtils::CreateRuntimeMod( normal );
  }

  inline ValueNode* CreateTypeIdNode( long line ) {
    ValueNode* this_node = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kTypeId ),
                                                     Token::JS_IDENTIFIER , line , ValueNode::kProperty );
    return this_node;
  }

  inline CallExp* CreateRecord( long line ) {
    ValueNode* this_sym = CreateThisNode( line );
    ValueNode* create_record = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreatePrivateRecord ),
                                                         Token::JS_PROPERTY , line , ValueNode::kProperty );
    ValueNode* private_holder = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                                          Token::JS_PROPERTY , line , ValueNode::kProperty );
    NodeList* args = AstUtils::CreateNodeList( 2 , this_sym , private_holder );
    CallExp* normal = AstUtils::CreateNormalAccessor( create_record , args );
    CallExp* runtime_call = AstUtils::CreateRuntimeMod( normal );
    return runtime_call;
  }


  inline AstNode* CreateHiddenConstructor ( const char* name , long line ) {
    ValueNode* name_sym = AstUtils::CreateNameNode( name , Token::JS_IDENTIFIER , line , ValueNode::kIdentifier );
    CallExp* prototype = AstUtils::CreatePrototypeNode( name_sym );
    ValueNode* constructor_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kConstructor ),
                                                           Token::JS_IDENTIFIER , line , ValueNode::kProperty );
    std::string constructor_string_expression = "\"";
    constructor_string_expression += SymbolList::GetSymbol( SymbolList::kConstructor );
    constructor_string_expression += "\"";
    ValueNode* constructor_string = AstUtils::CreateNameNode( constructor_string_expression.c_str(),
                                                              Token::JS_IDENTIFIER , line , ValueNode::kProperty );
    NodeList* args = AstUtils::CreateNodeList( 3 , prototype , constructor_string , constructor_sym );
    AstNode* hidden_constructor = CreateHiddenMember( args , line );
    return AstUtils::CreateExpStmt( hidden_constructor );
  }

  
  inline AstNode* CreateConstructorInitializer( const char* name , long line ) {
    ValueNode* constructor_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kConstructor ),
                                                           Token::JS_IDENTIFIER , line , ValueNode::kProperty );
    ValueNode* apply_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kApply ),
                                                     Token::JS_IDENTIFIER , line , ValueNode::kProperty );
    NodeList *args = ManagedHandle::Retain<NodeList>();
    args->AddChild( CreateThisNode( line ) );
    args->AddChild( AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kArguments ),
                                              Token::JS_IDENTIFIER , line , ValueNode::kIdentifier ) );
    CallExp* apply_call = AstUtils::CreateNormalAccessor( apply_sym , args );
    CallExp* initial_call = AstUtils::CreateDotAccessor( constructor_sym , apply_call );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( initial_call );
    return exp_stmt;
  }


  inline AstNode* CreateHolderAssignment( AstNode* val,
                                          AstNode* name,
                                          Class* class_,
                                          bool is_const,
                                          bool is_instance ) {

    if ( !is_instance ) {
      CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( CreatePrivateHolderName( val->Line() ) );
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


  inline void Finish( const char* name , Class* class_ , AstNode* closure_ , ProcessorInfo* info ) {
    if ( class_->ParentNode()->NodeType() == AstNode::kExpressionStmt ||
         class_->Inner() ) {
      TokenInfo* info = ManagedHandle::Retain( new TokenInfo( name , Token::JS_IDENTIFIER , class_->Line() ) );
      ValueNode* vars = AstUtils::CreateVarInitiliser( info , closure_->FirstChild() );
      NodeList* list = ManagedHandle::Retain<NodeList>();
      list->AddChild( vars );
      VariableStmt* stmt = AstUtils::CreateVarStmt( list );
      stmt->Line( class_->Line() );
      if ( !class_->Inner() ) {
        class_->ParentNode()->ParentNode()->ReplaceChild( class_->ParentNode() , stmt );
      } else {
        class_->AddChild( stmt );
      }
    } else {
      if ( class_->ParentNode()->NodeType() == AstNode::kExportStmt ) {
        ValueNode* name_node = AstUtils::CreateNameNode( name , Token::JS_IDENTIFIER , class_->Line() , ValueNode::kProperty );
        ValueNode* local_export = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kLocalExport ),
                                                            Token::JS_IDENTIFIER , class_->Line() , ValueNode::kIdentifier );
        CallExp* dot_accessor = AstUtils::CreateDotAccessor( local_export , name_node );
        AssignmentExp* assign = AstUtils::CreateAssignment( '=' , dot_accessor , closure_->FirstChild() );
        ValueNode* var_node = AstUtils::CreateVarInitiliser( name_node->Clone()->CastToValue()->Symbol() , assign );
        VariableStmt* var_stmt = AstUtils::CreateVarStmt( var_node );
        var_stmt->Line( class_->Line() );
        class_->ParentNode()->ParentNode()->ReplaceChild( class_->ParentNode() , var_stmt );
      } else {
        closure_->FirstChild()->Line( class_->Line() );
        class_->AddChild( closure_->FirstChild() );
      }
    }
  }


  inline VariableStmt* CreatePrivateHolder( Class* class_ , ProcessorInfo* info ) {
    Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>(),
                                                 ManagedHandle::Retain<Empty>(), ManagedHandle::Retain<Empty>() );
    ValueNode* private_holder_name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                                               Token::JS_IDENTIFIER , class_->Line() , ValueNode::kIdentifier );
    ValueNode* value = AstUtils::CreateVarInitiliser( private_holder_name->Symbol() , fn );
    VariableStmt* stmt = AstUtils::CreateVarStmt( value );
    return stmt;
  }

  inline AstNode* GetSafeValue( ValueNode* value ) {
    AstNode* lhs = value->FirstChild();
    return ( lhs )? lhs : AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                    Token::JS_IDENTIFIER , value->Line() , ValueNode::kIdentifier );
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
                                                Token::JS_IDENTIFIER , val->Line() , ValueNode::kIdentifier );
    CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
    CallExp* name_accessor = AstUtils::CreateDotAccessor( prototype_accessor , name_node );
    return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , name_accessor , val ) );
  }



  inline ExpressionStmt* PrototypePublic( const char* class_name, AstNode* name_node , AstNode* val ) {
    ValueNode* name = AstUtils::CreateNameNode( class_name,
                                                Token::JS_IDENTIFIER , val->Line() , ValueNode::kIdentifier );
    CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
    CallExp* name_accessor = AstUtils::CreateDotAccessor( prototype_accessor , name_node );
    return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , name_accessor , val ) );
  }



  inline ExpressionStmt* ConstantPrototypePrivate( AstNode* name_node , AstNode* val ) {
    ValueNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPrivateHolder ),
                                                Token::JS_IDENTIFIER , val->Line() , ValueNode::kIdentifier );
    CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
    CallExp* constant_accessor = AstUtils::CreateConstantProp( prototype_accessor,
                                                               name_node , val );
    return AstUtils::CreateExpStmt( constant_accessor );
  }



  inline ExpressionStmt* ConstantPrototypePublic( const char* class_name , AstNode* name_node , AstNode* val ) {
    ValueNode* name = AstUtils::CreateNameNode( class_name,
                                                Token::JS_IDENTIFIER , val->Line() , ValueNode::kIdentifier );
    CallExp* prototype_accessor = AstUtils::CreatePrototypeNode( name );
    CallExp* constant_accessor = AstUtils::CreateConstantProp( prototype_accessor,
                                                               name_node , val );
    return AstUtils::CreateExpStmt( constant_accessor );
  }



  inline ExpressionStmt* Static( const char* class_name , AstNode* name_node , AstNode* val ) {
    ValueNode* name = AstUtils::CreateNameNode( class_name,
                                                Token::JS_IDENTIFIER , val->Line() , ValueNode::kIdentifier );
    CallExp* dot_accessor = AstUtils::CreateDotAccessor( name , name_node );
    return AstUtils::CreateExpStmt( AstUtils::CreateAssignment( '=' , dot_accessor , val ) );
  }



  inline ExpressionStmt* ConstantStatic( const char* class_name , AstNode* name_node , AstNode* val ) {
    ValueNode* name = AstUtils::CreateNameNode( class_name,
                                                Token::JS_IDENTIFIER , val->Line() , ValueNode::kIdentifier );
    CallExp* constant_accessor = AstUtils::CreateConstantProp( name , name_node , val );
    return AstUtils::CreateExpStmt( constant_accessor );
  }



#define INSTANCE_DSTA(accessor)                                 \
  inline void Instance##accessor##Dsta( const char* class_name, \
                                        Function* closure_body, \
                                        ValueNode* val,         \
                                        bool is_const ) {       \
    if ( is_const ) {                                           \
      ExpressionStmt* stmt = ConstantInstance##accessor( val ); \
          stmt->Line( val->Line() );                            \
          closure_body->AddChild( stmt );                       \
    } else {                                                    \
      ExpressionStmt* stmt = Instance##accessor( val );         \
          stmt->Line( val->Line() );                            \
          closure_body->AddChild( stmt );                       \
    }                                                           \
  }
  INSTANCE_DSTA(Public);
  INSTANCE_DSTA(Private);


#undef INSTANCE_DSTA

#define PROTOTYPE_DSTA(accessor,args)                                   \
  inline void Prototype##accessor##Dsta( const char* class_name,        \
                                         Function* closure_body,        \
                                         ValueNode* val,                \
                                         bool is_const ) {              \
    if ( is_const ) {                                                   \
      ExpressionStmt* stmt = ConstantPrototype##accessor( args );       \
          stmt->Line( val->Line() );                                    \
          closure_body->AddChild( stmt );                               \
    } else {                                                            \
      ExpressionStmt* stmt = Prototype##accessor( args );               \
          stmt->Line( val->Line() );                                    \
          closure_body->AddChild( stmt );                               \
    }                                                                   \
  }
#define PUBLIC_ARGS class_name , val , val->FirstChild()
#define PRIVATE_ARGS val , val->FirstChild()
  PROTOTYPE_DSTA(Public,PUBLIC_ARGS);
  PROTOTYPE_DSTA(Private,PRIVATE_ARGS);
#undef PROTOTYPE_DSTA
#undef PUBLIC_ARGS
#undef PRIVATE_ARGS



  inline void StaticDsta( const char* class_name,
                          Function* closure_body,
                          ValueNode* exp,
                          bool is_const ) {
    if ( is_const ) {
      ExpressionStmt* stmt = ConstantStatic( class_name , exp , exp->FirstChild() );
      stmt->Line( exp->Line() );
      closure_body->AddChild( stmt );
    } else {
      ExpressionStmt* stmt = Static( class_name , exp ,  exp->FirstChild() );
      stmt->Line( exp->Line() );
      closure_body->AddChild( stmt );
    }
  }

 private :
  std::string *private_field_;
  ClassProcessor* processor_;
};




static const char table_[] = {
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$0123456789"
};


void SetRandomField( std::string *buf ) {
  int len = strlen( table_ );
  *buf += "__";
  for ( int i = 0; i < 10; i++ ) {
    fprintf( stderr,  "rand %d\n" , rand() % len );
    (*buf) += ( table_[ rand() % len ] );
  }
  *buf += "__";
}


ClassProcessor::ClassProcessor( ProcessorInfo* info , Class* ast_node , Statement* tmp_stmt ) :
    Managed(),
    class_id_( info->GetInfo()->GetTmpIndex() ) , info_( info ) , class_( ast_node ) , tmp_stmt_( tmp_stmt ) {
  closure_body_ = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() ,
                                           ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<StatementList>() );
  closure_ = AstUtils::CreateAnonymousFnCall( closure_body_ , ManagedHandle::Retain<Empty>() );
  closure_body_->Line( class_->Line() );
  SetRandomField( &random_field_ );
  utils_ = new ClassProcessorUtils( this , &random_field_ );
}


ClassProcessor::~ClassProcessor() {
  delete utils_;
}


void ClassProcessor::ProcessNode() {
  AstNode* name_node = class_->Name();
  AstNode* body = class_->Body();
  if ( !name_node->IsEmpty() ) {
    TokenInfo *info = name_node->CastToValue()->Symbol();
    name_ = info->GetToken();
  } else {
    char buf[500];
    name_ = AstUtils::CreateTmpRef( buf , info_->GetInfo()->GetTmpIndex() );
  }
  
  ValueNode* name = AstUtils::CreateNameNode( name_.c_str() , Token::JS_IDENTIFIER , class_->Line() , ValueNode::kIdentifier );
  Function* fn = AstUtils::CreateFunctionDecl( name , ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() );
  fn->Line( class_->Line() );
  common_constructor_ = fn;
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( fn );
  stmt->Line( class_->Line() );
  closure_body_->InsertBefore( utils_->CreatePrivateHolder( class_ , info_ ) );
  ExpressionStmt *create_record = AstUtils::CreateExpStmt( utils_->CreateRecord( class_->Line() ) );
  fn->AddChild( create_record );
  fn->AddChild( utils_->CreateConstructorInitializer( name_.c_str() , class_->Line() ) );
  closure_body_->AddChild( stmt );
  ProcessExtends_( class_->Expandar() );
  ProcessBody_( body );
  closure_body_->AddChild( utils_->CreateHiddenConstructor( name_.c_str() , class_->Line() ) );
  ReturnStmt* ret = AstUtils::CreateReturnStmt( name->Clone() );
  closure_body_->AddChild( ret );
  utils_->Finish( name_.c_str() , class_ , closure_ , info_ );
}


inline void ClassProcessor::ProcessExtends_( AstNode* node ) {
  if ( !node->IsEmpty() ) {
    ClassExpandar* expandar = reinterpret_cast<ClassExpandar*>( node );
    const char* extend_fn = ( expandar->Type() == ClassExpandar::kExtends )?
        SymbolList::GetSymbol( SymbolList::kExtendClass ) :
        SymbolList::GetSymbol( SymbolList::kExtendPrototype );
    ValueNode* tmp_node = AstUtils::CreateTmpNode( info_->GetInfo()->GetTmpIndex() );
    ValueNode* tmp_init = AstUtils::CreateVarInitiliser( tmp_node->Symbol() , node->FirstChild() );
    VariableStmt* var_stmt = AstUtils::CreateVarStmt( tmp_init );
    closure_body_->AddChild( var_stmt );
    
    ValueNode* extend = AstUtils::CreateNameNode( extend_fn,
                                                  Token::JS_IDENTIFIER , class_->Line() , ValueNode::kProperty );
    CallExp* runtime_prop = AstUtils::CreateRuntimeMod( extend );
    NodeList* arg = ManagedHandle::Retain<NodeList>();
    ValueNode* class_name = AstUtils::CreateNameNode( name_.c_str(),
                                                  Token::JS_IDENTIFIER , class_->Line() , ValueNode::kIdentifier );
    arg->AddChild( class_name );
    arg->AddChild( tmp_node->Clone() );
    CallExp* normal_fn_call = AstUtils::CreateNormalAccessor( runtime_prop , arg );
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( normal_fn_call );
    stmt->Line( node->Line() );
    closure_body_->AddChild( stmt );
    ValueNode* super_obj = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kSuper ),
                                                     Token::JS_IDENTIFIER , node->Line() , ValueNode::kIdentifier );
    ValueNode* create_super = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kGetSuper ),
                                                        Token::JS_PROPERTY , node->Line() , ValueNode::kProperty );
    NodeList* super_args = AstUtils::CreateNodeList( 1 , tmp_node->Clone() );
    CallExp* create_super_call = AstUtils::CreateNormalAccessor( create_super , super_args );
    CallExp* runtime_exp = AstUtils::CreateRuntimeMod( create_super_call );
    ValueNode* var_init = AstUtils::CreateVarInitiliser( super_obj->Symbol() , runtime_exp );
    VariableStmt* runtime_super_stmt = AstUtils::CreateVarStmt( var_init );
    closure_body_->AddChild( runtime_super_stmt );
  }
}


inline void ClassProcessor::ProcessBody_( AstNode* body ) {
  if ( !body->IsEmpty() ) {
    ProcessMember_( reinterpret_cast<ClassProperties*>( body ) );
  } else {
    CreateEmptyConstructor_();
  }
}



inline void ClassProcessor::ProcessMember_( ClassProperties* body ) {
  AstNode* public_list = body->Public();
  AstNode* private_list = body->Private();
  AstNode* prototype_list = body->Prototype();
  AstNode* static_list = body->Static();
  AstNode* constructor_decl = body->Constructor();

  if ( constructor_decl ) {
    Function* constructor = constructor_decl->FirstChild()->CastToExpression()->CastToFunction();
    constructor_ = constructor;
    constructor->Line( constructor_decl->FirstChild()->Line() );
    ProcessConstructor_( constructor );
  } else {
    CreateEmptyConstructor_();
  }

  IterateMember_( public_list , true , false , false );
  IterateMember_( private_list , true , true , false );
  IterateMember_( prototype_list , true , true , false );
  IterateMember_( static_list , false , false , false );
}



inline void ClassProcessor::ProcessConstructor_( Function* constructor ) {
  IVisitor* visitor = info_->GetVisitor();
  closure_body_->AddChild( constructor );
  Function *backup = closure_body_;
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
    }
  }
  constructor->Accept( visitor );
  closure_body_ = backup;
}


inline void ClassProcessor::CreateEmptyConstructor_() {
  ValueNode* constructor = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kConstructor ),
                                                     Token::JS_IDENTIFIER , class_->Line() , ValueNode::kIdentifier );
  Function* fn = AstUtils::CreateFunctionDecl( constructor , ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() );
  fn->Line( class_->Line() );
  closure_body_->AddChild( fn );
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
      break;

    case AstNode::kClass : {
      Statement* tmp_stmt = ManagedHandle::Retain<Statement>();
      info_->GetInfo()->SetCurrentStmt( tmp_stmt );
      Class* class_node = reinterpret_cast<Class*>( node );
      class_node->Inner( true );
      ClassProcessor *cls = ManagedHandle::Retain( new ClassProcessor( info_ , class_node , tmp_stmt ) );
      cls->ProcessNode();
      ProcessVariable_( class_node->FirstChild() , is_prototype , is_private , is_instance , class_node->Const() );
    }
  }
}







inline void ClassProcessor::ProcessDsta_( ValueNode *value,
                                          bool is_const,
                                          DstaCallback callback ) {
  Statement* tmp_stmt = ManagedHandle::Retain<Statement>();
  info_->GetInfo()->SetCurrentStmt( tmp_stmt );
  value->Node()->Accept( info_->GetVisitor() );
  if ( tmp_stmt->HasDsta() ) {
    value->ValueType( ValueNode::kVariable );
    value->Symbol( value->Node()->CastToValue()->Symbol() );
    VariableStmt* stmt = AstUtils::CreateVarStmt( value );
    stmt->Line( value->Line() );
    closure_body_->AddChild( stmt );
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( tmp_stmt , info_ );
    NodeIterator iterator = list->ChildNodes();
    while ( iterator.HasNext() ) {
      ValueNode* dsta_value = iterator.Next()->CastToValue();
      dsta_value->Line( value->Line() );
      dsta_value->ValueType( ValueNode::kIdentifier );
      ( utils_->*callback )( name_.c_str() , closure_body_ , dsta_value , is_const );
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
        ProcessDsta_( value , is_const , &ClassProcessorUtils::PrototypePrivateDsta );
      } else {
        value->ValueType( ValueNode::kProperty );
        ExpressionStmt* result = 0;
        if ( is_const ) {
          result = utils_->ConstantPrototypePrivate( value , utils_->GetSafeValue( value ) );
        } else {
          result = utils_->PrototypePrivate( value , utils_->GetSafeValue( value ) );
        }
        result->Line( value->Line() );
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
          ProcessDsta_( value , is_const , &ClassProcessorUtils::StaticDsta );
        } else if ( is_prototype ) {
          ProcessDsta_( value , is_const , &ClassProcessorUtils::PrototypePublicDsta );
        } else if ( is_private ){
          ProcessDsta_( value , is_const , &ClassProcessorUtils::InstancePrivateDsta );
        } else {
          ProcessDsta_( value , is_const , &ClassProcessorUtils::InstancePublicDsta );
        }
      } else {
        ExpressionStmt* result = 0;
        value->ValueType( ValueNode::kProperty );
        AstNode* safe_val = utils_->GetSafeValue( value );
        if ( !is_instance && !is_prototype ) {
          if ( is_const ) {
            result = utils_->ConstantStatic( class_name , value , safe_val );
          } else {
            result = utils_->Static( class_name , value , safe_val );
          }
        } else if ( is_prototype ) {
          if ( is_const ) {
            result = utils_->ConstantPrototypePublic( class_name , value , safe_val );
          } else {
            result = utils_->PrototypePublic( class_name , value , safe_val );
          }
        } else if ( is_private ) {
          if ( is_const ) {
            result = utils_->ConstantInstancePrivate( value );
          } else {
            result = utils_->InstancePrivate( value );
          }
        } else {
          if ( is_const ) {
            result = utils_->ConstantInstancePublic( value );
          } else {
            result = utils_->InstancePublic( value );
          }
        }
        result->Line( value->Line() );
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
  value->ValueType( ValueNode::kProperty );
  if ( !is_instance && !is_prototype ) {
    fn->Accept( info_->GetVisitor() );
    ExpressionStmt* stmt = utils_->Static( class_name , value , fn );
    stmt->Line( fn->Line() );
    closure_body_->AddChild( stmt );
  } else if ( is_prototype ) {
    if ( is_private ) {
      info_->GetInfo()->EnterPrivate();
      fn->Accept( info_->GetVisitor() );
      info_->GetInfo()->EscapePrivate();
      ExpressionStmt* stmt = utils_->PrototypePrivate( value , fn );
      stmt->Line( fn->Line() );
      closure_body_->AddChild( stmt );
    } else {
      fn->Accept( info_->GetVisitor() );
      ExpressionStmt* stmt = utils_->PrototypePublic( class_name , value , fn );
      stmt->Line( fn->Line() );
      closure_body_->AddChild( stmt );
    }
  } else {
    if ( is_private ) {
      info_->GetInfo()->EnterPrivate();
      fn->Accept( info_->GetVisitor() );
      info_->GetInfo()->EscapePrivate();
      ExpressionStmt* stmt = utils_->PrototypePrivate( value , fn );
      stmt->Line( fn->Line() );
      closure_body_->AddChild( stmt );
    } else {
      fn->Accept( info_->GetVisitor() );
      ExpressionStmt* stmt = utils_->PrototypePublic( class_name , value , fn );
      stmt->Line( fn->Line() );
      closure_body_->AddChild( stmt );
    }
  }
}

}

