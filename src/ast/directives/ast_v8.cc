#include <third_party/v8/include/v8.h>
#include <ast/directive/ast_v8.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <utils/pool/managed_handle.h>
#include <ast/ast.h>
#include <assert.h>
using namespace v8;
namespace mocha {

typedef v8::Local<v8::Object> V8Object;
typedef v8::Handle<v8::Value> V8Value;
typedef v8::Function V8Function;
typedef v8::String V8String;

v8::Persistent<Object> GetMark() {
  static v8::Persistent<Object> mark;
  return mark;
}

v8::Persistent<Object> GetCreatorMark() {
  static v8::Persistent<Object> mark;
  return mark;
}

template <typename T>
T* GetInternal( int num , V8Object obj ) {
  assert( num > 0 );
  return static_cast<T*>( v8::Local<v8::External>::Cast( obj->GetInternalField( num ) )->Value() );
}

bool TypeCheck( int type , V8Object obj ) {
  AstNode* ast = static_cast<AstNode*>( v8::Local<v8::External>::Cast( obj->GetInternalField( num ) )->Value() );
  return ast->NodeType() == type || type == AstNode::kBase;
}

template <typename T>
T GetInternalHandle( int num , V8Object obj ) {
  return v8::Handle<T>::Cast( obj->GetInternalField( num ) )->Value();
}

#define GET_THIS(name,args) V8Object name = args.This()
#define ARGUMENTS_CHECK(num,arg)                                        \
  if ( arg.Length() != num ) {                                          \
    return v8::ThrowException( V8String::New( "arguments error" ) );   \
  }

#define ARGUMENTS_CHECK_GT(num,arg)                                     \
  if ( arg.Length() >= num ) {                                          \
    return v8::ThrowException( V8String::New( "arguments error" ) );   \
  }

#define ERROR_CHECK(obj,type)                                               \
  if ( obj->InternalFieldCount() > 0 && obj->GetInternalField( 0 )->StrictEquals( GetMark() ) && !TypeCheck( type , obj ) ) { \
    return v8::ThrowException( "arguments error" );                    \
  }

#define ERROR_CHECK_FOR_CREATOR(obj,type)                               \
  if ( obj->InternalFieldCount() > 0 && obj->GetInternalField( 0 )->StrictEquals( GetCreatorMark() ) ) { \
    return v8::ThrowException( "Illegal invocation" );                    \
  }

class JSFileRoot {
 public :
  static V8Value GetFilename( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kFileRoot );
    FileRoot* node = GetInternal<FileRoot>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    return String::New( node->FileName() , info );
  }
};

class JSVariableStmt {
 public :
  static V8Value GetVarType( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kVariableStmt );
    VariableStmt* node = GetInternal<VariableStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    return Number::New( node->VarType() , info );
  }
};

class JSIFStmt {
 public :
  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IFStmt* node = GetInternal<IFStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    return AstForV8::Init( global , node->Exp() , info );
  }

  static V8Value GetThen( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IFStmt* node = GetInternal<IFStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    return AstForV8::Init( global , node->Then() , info );
  }

  static V8Value GetElse( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IFStmt* node = GetInternal<IFStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2, this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    if ( node->Else() ) {
      return AstForV8::Init( global , node->Else() , info );
    } else {
      return Undefined();
    }
  }
};

class JSIterationStmt {
 public :
  static V8Value GetDecl( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IterationStmt* node = GetInternal<IterationStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    if ( !node->Exp()->FirstChild()->IsEmpty() ) {
      return AstForV8::Init( global , node->Exp()->FirstChild() , info );
    } else {
      return Undefined();
    }
  }

  static V8Value GetCond( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IterationStmt* node = GetInternal<IterationStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* cond = node->Exp()->FirstChild()->NextSibling();
    if ( !cond->IsEmpty() ) {
      return AstForV8::Init( global , cond , info );
    } else {
      return Undefined();
    }
  }

  static V8Value GetCounter( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IterationStmt* node = GetInternal<IterationStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* counter = node->Exp()->FirstChild()->NextSibling()->NextSibling();
    if ( !counter->IsEmpty() ) {
      return AstForV8::Init( global , counter , info );
    } else {
      return Undefined();
    }
  }

  static V8Value GetProp( const Arguments& args ) {
    return GetDecl( args );
  }

  static V8Value GetTarget( const Arguments& args ) {
    return GetCond( args );
  }

  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kIFStmt );
    IterationStmt* node = GetInternal<IterationStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* exp = node->Exp();
    if ( !exp->IsEmpty() ) {
      return AstForV8::Init( global , exp , info );
    } else {
      return Undefined();
    }
  }
};

class JSSwtichStmt {
 public :
  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kSwitchStmt );
    SwitchStmt* node = GetInternal<SwitchStmt>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* exp = node->Exp();
    if ( !exp->IsEmpty() ) {
      return AstForV8::Init( global , exp , info );
    } else {
      return Undefined();
    }
  }
};

class JSCaseClause {
 public :
  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCase );
    CaseClause* node = GetInternal<CaseClause>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 ,this_obj );
    AstNode* exp = node->Exp();
    if ( !exp->IsEmpty() ) {
      return AstForV8::Init( global , exp , info );
    } else {
      return Undefined();
    }
  }
};

class JSThorwStmt {
 public :
  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kThrowStmt );
    ThrowStmt* node = GetInternal<ThrowStmt>( 1, this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 ,this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* exp = node->Exp();
    if ( !exp->IsEmpty() ) {
      return AstForV8::Init( global , exp , info );
    } else {
      return Undefined();
    }
  }
};

class JSFunction {
 public :
  static V8Value GetName( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kFunction );
    Function* node = GetInternal<Function>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* name = node->Name();
    if ( !name->IsEmpty() ) {
      return AstForV8::Init( global , name->CastToValue()->GetToken() , info );
    } else {
      return Undefined();
    }
  }

  static V8Value GetParameterList( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kFunction );
    Function* node = GetInternal<Function>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* param = node->Argv();
    if ( !param->IsEmpty() ) {
      V8Value val = AstForV8::Init( global , param , info )->Get( String::New( "childNodes" ) );
      return Handle<V8Function>::Cast( val )->Call( global , 0 , Undefined() );
    } else {
      return Undefined();
    }
  }

  static V8Value GetParameterCount( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kFunction );
    Function* node = GetInternal<Function>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    int argc = node->Argc();
    return Number::New( argc );
  }

  static V8Value IsConst( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kFunction );
    Function* node = GetInternal<Function>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo*>( 2 , this_obj );
    return Boolean::New( node->IsConst() );
  }
};

class JSCallExp {
 public :
  static V8Value GetCallable( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCallExp );
    CallExp* node = GetInternal<CallExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    return AstForV8::Init( global , node , info );
  }

  static V8Value GetArgs( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCallExp );
    CallExp* node = GetInternal<CallExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* m_args = node->Args();
    if ( !m_args->IsEmpty() ) {
      V8Value val = AstForV8::Init( global , m_args , info )->Get( String::New( "childNodes" ) );
      return Handle<V8Function>::Cast( val )->Call( global , 0 , Undefined() );
    } else {
      Local<Object> object = Object::New();
      object->Set( String::New( "length" ) , Number::New( 0 ) , PropertyAttribute::kReadOnly | PropertyAttribute::kDontDelete );
      return object;
    }
  }

  static V8Value CallType( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCallExp );
    CallExp* node = GetInternal<CallExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    int call_type = node->CallType();
    return Number::New( call_type );
  }
};

class JSNewExp {
 public :
  static V8Value GetConstructor( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCallExp );
    NewExp* node = GetInternal<NewExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* exp = node->Constructor();
    return AstForV8::Init( global , exp , info );
  }
};

class JSNewExp {
 public :
  static V8Value GetConstructor( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kNewExp );
    NewExp* node = GetInternal<NewExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* exp = node->Constructor();
    return AstForV8::Init( global , exp , info );
  }
};

class JSPostfixExp {
 public :
  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kPostfixExp );
    PostfixExp* node = GetInternal<PostfixExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* exp = node->Exp();
    return AstForV8::Init( global , exp , info );
  }
};

class JSUnaryExp {
 public :
  static V8Value GetExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kUnaryExp );
    UnaryExp* node = GetInternal<UnaryExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Obje>( 3 , this_obj );
    AstNode* exp = node->Exp();
    return AstForV8::Init( global , exp , info );
  }

  static V8Value GetOp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kUnaryExp );
    UnaryExp* node = GetInternal<UnaryExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    int op = node->Op();
    return Number::New( op );
  }
};

class JSBinaryExp {
 public :
  static V8Value GetLeftExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kBinaryExp );
    BinaryExp* node = GetInternal<BinaryExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* left = node->Left();
    return AstForV8::Init( global , left , info );
  }

  static V8Value GetRightExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kBinaryExp );
    BinaryExp* node = GetInternal<BinaryExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* right = node->Right();
    return AstForV8::Init( global , right , info );
  }
  
  static V8Value GetOp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kBinaryExp );
    BinaryExp* node = GetInternal<BinaryExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    int op = node->Op();
    return Number::New( op );
  }
};

class JSCompareExp {
 public :
  static V8Value GetLeftExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCompareExp );
    CompareExp* node = GetInternal<CompareExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* left = node->Left();
    return AstForV8::Init( global , left , info );
  }

  static V8Value GetRightExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCompareExp );
    CompareExp* node = GetInternal<CompareExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* right = node->Right();
    return AstForV8::Init( global , right , info );
  }
  
  static V8Value GetOp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kCompareExp );
    CompareExp* node = GetInternal<CompareExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    int op = node->Op();
    return Number::New( op );
  }
};

class JSAssignmentExp {
 public :
  static V8Value GetLeftExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kAssignmentExp );
    AssignmentExp* node = GetInternal<AssignmentExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* left = node->Left();
    return AstForV8::Init( global , left , info );
  }

  static V8Value GetRightExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kAssignmentExp );
    AssignmentExp* node = GetInternal<AssignmentExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* right = node->Right();
    return AstForV8::Init( global , right , info );
  }
  
  static V8Value GetOp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kAssignmentExp );
    AssignmentExp* node = GetInternal<AssignmentExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    int op = node->Op();
    return Number::New( op );
  }
};


class JSConditionalExp {
 public :
  static V8Value GetCond( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kConditionalExp );
    ConditionalExp* node = GetInternal<ConditionalExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* cond = node->Cond();
    return AstForV8::Init( global , cond , info );
  }

  static V8Value GetRightExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kConditionalExp );
    ConditionalExp* node = GetInternal<ConditionalExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* true_exp = node->True();
    return AstForV8::Init( global , true_exp , info );
  }
  
  static V8Value GetOp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kConditionalExp );
    ConditionalExp* node = GetInternal<ConditionalExp>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    AstNode* false_exp = node->False();
    return AstForV8::Init( global , false_exp , info );
  }
};

class JSValueNode {
 public :
  static V8Value GetSymbol( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kValueNode );
    ValueNode* node = GetInternal<ValueNode>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    if ( node->Symbol() ) {
      const char* symbol = node->Symbol()->GetToken();
      return String::New( symbol );
    } else {
      return Undefined();
    }
  }

  static V8Value GetNode( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kValueNode );
    ValueNode* node = GetInternal<ValueNode>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 3 , this_obj );
    if ( node->Node() ) {
      return AstForV8::Init( global , node->Node() ,  symbol );
    } else {
      return Undefined();
    }
  }

  static V8Value GetValueType( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK(0,args);
    GET_THIS( this_obj , args );
    ERROR_CHECK( this_obj , AstNode::kValueNode );
    ValueNode* node = GetInternal<ValueNode>( 1 , this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 2 , this_obj );
    return Number::New( node->ValueType() );
  }

};

void SetUniqueProp( AstNode* ast , Handle<ObjectTemplate> object ) {
  switch( ast->NodeType() ) {
    case AstNode::kFileRoot : {
      object->Set( String::New( "getFilename" ) , FunctionTemplate::New( JSFileRoot::GetFilename ) );
    }
      break;
      
    case AstNode::kVariableStmt : {
      object->Set( String::New( "getVarType" ) , FunctionTemplate::New( JSVariableStmt::GetVarType ) );
    }
      break;

    case AstNode::kIFStmt : {
      object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSIFStmt::GetExp ) );
      object->Set( String::New( "getThen" ) , FunctionTemplate::New( JSIFStmt::GetThen ) );
      object->Set( String::New( "getElse" ) , FunctionTemplate::New( JSIFStmt::GetElse ) );
    }
      break;

    case AstNode::kIterationStmt : {
      IterationStmt* stmt = ast->CastToIteration();
      if ( stmt->NodeType() == AstNode::kFor || stmt->NodeType() == AstNode::kForWithVar ) {
        object->Set( String::New( "getDecl" ) , FunctionTemplate::New( JSIterationStmt::GetDecl ) );
        object->Set( String::New( "getCond" ) , FunctionTemplate::New( JSIterationStmt::GetCond ) );
        object->Set( String::New( "getCounter" ) , FunctionTemplate::New( JSIterationStmt::GetCounter ) );
      } else if ( stmt->NodeType() == AstNode::kForIn || stmt->NodeType() == AstNode::kForInWithVar ) {
        object->Set( String::New( "getProp" ) , FunctionTemplate::New( JSIterationStmt::GetProp ) );
        object->Set( String::New( "getTarget" ) , FunctionTemplate::New( JSIterationStmt::GetTarget ) );
      } else if ( stmt->NodeType() == AstNode::kWhile || stmt->NodeType() == AstNode::kDoWhile ) {
        object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSIterationStmt::GetExp ) );
      }
    }
      break;

    case AstNode::kSwitchStmt : {
      object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSSwtichStmt::GetExp ) );
    }
      break;

    case AstNode::kCase : {
      object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSCaseClause::GetExp ) );
    }
      break;
      
    case AstNode::kThrowStmt : {
      object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSThorwStmt::GetExp ) );
    }
      break;

    case AstNode::kFunction : {
      object->Set( String::New( "getName" ) , FunctionTemplate::New( JSFunction::GetName ) );
      object->Set( String::New( "getParameterList" ) , FunctionTemplate::New( JSFunction::GetParameterList ) );
      object->Set( String::New( "getParameterCount" ) , FunctionTemplate::New( JSFunction::GetParameterCount ) );
      object->Set( String::New( "isConst" ) , FunctionTemplate::New( JSFunction::IsConst) );
    }
      break;

    case AstNode::kCallExp : {
      object->Set( String::New( "getCallable" ) , FunctionTemplate::New( JSCallExp::GetCallable ) );
      object->Set( String::New( "getArgs" ) , FunctionTemplate::New( JSCallExp::GetArgs ) );
      object->Set( String::New( "getCallType" ) , FunctionTemplate::New( JSCallExp::GetCallType ) );
    }
      break;

    case AstNode::kNewExp : {
      object->Set( String::New( "getConstructor" ) , FunctionTemplate::New( JSNewExp::GetConstructor ) );
    }
      break;

    case AstNode::kPostfixExp : {
      object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSPostfixExp::GetExp ) );
    }
      break;

    case AstNode::kUnaryExp : {
      object->Set( String::New( "getExp" ) , FunctionTemplate::New( JSUnaryExp::GetExp ) );
      object->Set( String::New( "getOp" ) , FunctionTemplate::New( JSUnaryExp::GetOp ) );
    }
      break;

    case AstNode::kCompareExp :{
      object->Set( String::New( "getLeftExp" ) , FunctionTemplate::New( JSCompareExp::GetLeftExp ) );
      object->Set( String::New( "getRightExp" ) , FunctionTemplate::New( JSCompareExp::GetRightExp ) );
      object->Set( String::New( "getOp" ) , FunctionTemplate::New( JSCompareExp::GetOp ) );
    }
      break;
      
    case AstNode::kAssignmentExp : {
      object->Set( String::New( "getLeftExp" ) , FunctionTemplate::New( JSAssignmentExp::GetLeftExp ) );
      object->Set( String::New( "getRightExp" ) , FunctionTemplate::New( JSAssignmentExp::GetRightExp ) );
      object->Set( String::New( "getOp" ) , FunctionTemplate::New( JSAssignmentExp::GetOp ) );
    }
      break;
      
    case AstNode::kBinaryExp : {
      object->Set( String::New( "getLeftExp" ) , FunctionTemplate::New( JSBinaryExp::GetLeftExp ) );
      object->Set( String::New( "getRightExp" ) , FunctionTemplate::New( JSBinaryExp::GetRightExp ) );
      object->Set( String::New( "getOp" ) , FunctionTemplate::New( JSBinaryExp::GetOp ) );
    }
      break;

    case AstNode::kConditionalExp : {
      object->Set( String::New( "getCond" ) , FunctionTemplate::New( JSConditionalExp::GetCond ) );
      object->Set( String::New( "getTrue" ) , FunctionTemplate::New( JSConditionalExp::GetTrue ) );
      object->Set( String::New( "getFalse" ) , FunctionTemplate::New( JSConditionalExp::GetFalse ) );
    }
      break;

    case AstNode::ValueNode : {
      object->Set( String::New( "getSymbol" ) , FunctionTemplate::New( JSValueNode::GetSymbol ) );
      object->Set( String::New( "getNode" ) , FunctionTemplate::New( JSValueNode::GetNode ) );
      object->Set( String::New( "getValueType" ) , FunctionTemplate::New( JSValueNode::GetValueType ) );
    }
      break;
  }
}


class JSEnv {
 public :
  static V8Value GetFilename( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    return String::New( info->GetInfo()->GetFilename() );
  }
  static V8Value GetMainFilePath( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    return String::New( info->GetInfo()->GetMainPath() );
  }
  static V8Value HasVersion( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    String::Utf8Value str( args [ 0 ] );
    return Boolean::New( info->GetInfo()->HasVersion( *str ) );
  }
};

#define STATEMENT_EXPECT(name,node)                             \
  if ( !node->CastToStatement() && !node->IsEmpty() ){          \
    std::string tmp = "The arguments of ";                      \
    tmp += #name;                                               \
    tmp += " expect Statement";                                 \
    return v8::ThrowException( V8String::New( tmp.c_str() ) );  \
  }

#define FORBID_STATEMENT(name,node)                                     \
  if ( node->CastToStatement() && !node->IsEmpty() ){                   \
    std::string tmp = "Unexpected Statement got in the arguments of ";  \
    tmp += #name;                                                       \
    return v8::ThrowException( V8String::New( tmp.c_str() ) );          \
  }

#define FORBID_LIST(name,node)                                          \
  if ( node->NodeType() == AstNode::kNodeList || node->NodeType() == AstNode::StatementList ){ \
    std::string tmp = "Unexpected NodeList or StatementList got in the arguments of "; \
    tmp += #name;                                                       \
    return v8::ThrowException( V8String::New( tmp.c_str() ) );          \
  }

#define VALUE_EXPECT(name,node)                                         \
  if ( node->NodeType() != AstNode::kValueNode && !node->IsEmpty() ){   \
    std::string tmp = "The arguments of ";                              \
    tmp += #name;                                                       \
    tmp += " expect ValueNode";                                         \
    return v8::ThrowException( V8String::New( tmp.c_str() ) );          \
  }

class JSAst {
 public :
  static V8Value CreateBlock( const Arguments& args ) {
    HandleScope handle_scope;
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Handle>( 2 , this_obj );
    int len = args.Length();
    StatementList* list = ManagedHandle::Retain<StatementList>();
    for ( int i = 0; i < len; i++ ) {
      V8Object obj = args[ i ]->ToObject();
      ERROR_CHECK( obj , AstNode::kBase );
      AstNode* node = GetInternal<AstNode>( 1 , obj );
      if ( len == 1 && ( node->NodeType() == AstNode::kStatementList ||
                         node->NodeType() == AstNode::kNodeList ) ) {
        list->Append( node );
      } else {
        STATEMENT_EXPECT( CreateBlock , node );
        list->AddChild( node );
      }
    }
    BlockStmt* stmt = ManagedHandle::Retain<BlockStmt>();
    stmt->AddChild( list );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateEmptyNode( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 0 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    AstNode* empty = ManagedHandle::Retain<Empty>();
    return AstForV8::Init( global , empty , info );
  }
  
  static V8Value CreateVariableStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternal<V8Object>( 2 , this_obj );
    int len = args.Length();
    AstNode *list;
    for ( int i = 0; i < len; i++ ) {
      V8Object obj = args[ i ]->ToObject();
      ERROR_CHECK( obj , AstNode::kBase );
      AstNode* node = GetInternal<AstNode>( 1 , obj );
      if ( node->NodeType() == AstNode::kNodeList && len == 1 ) {
        list->Append( node );
      } else {
        VALUE_EXPECT( CreateVariableStmt , node );
        list->AddChild( node );
      }
    }
    VariableStmt* stmt = ManagedHandle::Retain<VariableStmt>();
    stmt->AddChild( list );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateExpressionStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternal<V8Object>( 2 , this_obj );
    V8Object obj = args[ i ]->ToObject();
    ERROR_CHECK( obj , AstNode::kBase );
    AstNode* node = GetInternal<AstNode>( 1 , obj );
    FORBID_STATEMENT( CreateExpressionStmt , node );
    FORBID_LIST( CreateExpressionStmt , node );
    if ( node->NodeType() != AstNode::kExpression ) {
      Expression* exp = ManagedHandle::Retain<Expression>();
      ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp->AddChild( node );
      stmt->AddChild( exp );
    } else {
      ExpressionStmt* stmt = ManagedHandle::Retain<ExpressionStmt>();
      stmt->AddChild( node );
    }
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateIFStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 3 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternal<V8Object>( 2 , this_obj );
    IFStmt* stmt = ManagedHandle::Retain<IFStmt>();
    V8Value exp_val = args[ 0 ]->ToObject();
    V8Value then_val = args[ 0 ]->ToObject();
    V8Value else_val = args[ 0 ]->ToObject();
    FORBID_STATEMENT( CreateIFStmt , exp_val );
    FORBID_LIST( CreateIFStmt , exp );
    STATEMENT_EXPECT( CreateIFStmt , then_val );
    STATEMENT_EXPECT( CreateIFStmt , else_val );
    AstNode* then_body = reinterpret_cast<AstNode*>( then_val );
    AstNode* else_body = reinterpret_cast<AstNode*>( else_val );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val ); 
    stmt->Exp( exp );
    stmt->Then( then_body );
    stmt->Else( else_body );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateForStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value is_var_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    bool is_var = is_var_val->IsTrue();
    V8Value decl_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    V8Value cond_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 2 );
    V8Value counter_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 3 );
    V8Value body_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 4 );
    AstNode* decl = reinterpret_cast<AstNode*>( decl_val );
    AstNode* cond = reinterpret_cast<AstNode*>( cond_val );
    AstNode* counter = reinterpret_cast<AstNode*>( counter_val );
    AstNode* body = reinterpret_cast<AstNode*>( body_val );
    int type = ( is_var )? IterationStmt::kForWithVar : IterationStmt::kFor;
    IterationStmt* stmt = ManagedHandle::Retain( new IterationStmt( type ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( decl );
    list->AddChild( cond );
    list->AddChild( counter );
    stmt->Exp( list );
    stmt->AddChild( body );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateForInStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value is_var_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    bool is_var = is_var_val->IsTrue();
    V8Value prop_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    V8Value target_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 2 );
    V8Value body_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 4 );
    AstNode* prop = reinterpret_cast<AstNode*>( prop_val );
    AstNode* target = reinterpret_cast<AstNode*>( target_val );
    AstNode* body = reinterpret_cast<AstNode*>( body_val );
    int type = ( is_var )? IterationStmt::kForInWithVar : IterationStmt::kForIn;
    IterationStmt* stmt = ManagedHandle::Retain( new IterationStmt( type ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    list->AddChild( prop );
    list->AddChild( target );
    stmt->Exp( list );
    stmt->AddChild( body );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateWhileStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value body_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    AstNode* body = reinterpret_cast<AstNode*>( body_val );
    IterationStmt* stmt = ManagedHandle::Retain( new IterationStmt( IterationStmt::kWhile ) );
    stmt->Exp( exp );
    stmt->AddChild( body );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateDoWhileStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value body_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    AstNode* body = reinterpret_cast<AstNode*>( body_val );
    IterationStmt* stmt = ManagedHandle::Retain( new IterationStmt( IterationStmt::kDoWhile ) );
    stmt->Exp( exp );
    stmt->AddChild( body );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateContinueStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    ContinueStmt* stmt = ManagedHandle::Retain<ContinueStmt>();
    stmt->AddChild( exp );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateBreakStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    BreakStmt* stmt = ManagedHandle::Retain<BreakStmt>();
    stmt->AddChild( exp );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateReturnStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    ReturnStmt* stmt = ManagedHandle::Retain<RetrunStmt>();
    stmt->AddChild( exp );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateWithStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value body_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    AstNode* body = reinterpret_cast<AstNode*>( body_val );
    WithStmt* stmt = ManagedHandle::Retain<WithStmt>();
    stmt->Exp( exp );
    stmt->AddChild( body );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateLabelledStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    LabelledStmt* stmt = ManagedHandle::Retain<LabelledStmt>();
    stmt->AddChild( exp );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateSwitchStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    int len = args.Length();
    NodeList* list = ManagedHandle::Retain<NodeList>();
    for ( int i = 1; i < len; i++ ) {
      V8Value case_val = V8Object::Cast( args[ i ] )->GetInternalField( 0 );
      CaseClause* case_clause = reinterpret_cast<CaseClause*>( case_val );
      list->AddChild( case_clause );
    }
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    SwitchStmt* stmt = ManagedHandle::Retain<SwitchStmt>();
    stmt->AddChild( list );
    stmt->Exp( exp );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateThrowStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    ThrowStmt* stmt = ManagedHandle::Retain<ThrowStmt>();
    stmt->Exp( exp );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateTryStmt( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value try_body = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value catch_body = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    V8Value finally_body = V8Object::Cast( args[ 0 ] )->GetInternalField( 2 );
    AstNode* try_block = reinterpret_cast<AstNode*>( try_body );
    AstNode* catch_block = reinterpret_cast<AstNode*>( catch_body );
    AstNode* finally_block = reinterpret_cast<AstNode*>( finally_body );
    TryStmt* stmt = ManagedHandle::Retain<TryStmt>();
    stmt->AddChild( try_block );
    stmt->Catch( catch_block );
    stmt->Finally( finally_block );
    return AstForV8::Init( global , stmt , info );
  }

  static V8Value CreateCaseClause( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value exp_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value case_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 1 );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    AstNode* case_body = reinterpret_cast<AstNode*>( case_val );
    CaseClause* clause = ManagedHandle::Retain<CaseClause>();
    clause->Exp( exp );
    clause->AddChild( case_body );
    return AstForV8::Init( global , clause , info );
  }

  static V8Value CreateExpression( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    int len = args.Length();
    Expression* expression = ManagedHandle::Retain<Expression>();
    for ( int i = 0; i < len; i++ ) {
      V8Value exp_val = V8Object::Cast( args[ i ] )->GetInternalField( 0 );
      AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
      expression->AddChild( exp );
    }
    return AstForV8::Init( global , expression , info );
  }

  static V8Value CreateNodeList( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    NodeList* list = ManagedHandle::Retain<NodeList>();
    int len = args.Length();
    for ( int i = 0; i < len; i++ ) {
      V8Value val = V8Object::Cast( args[ i ] )->GetInternalField( 0 );
      AstNode* node = reinterpret_cast<AstNode*>( val );
      list->AddChild( node );
    }
    return AstForV8::Init( global , list , info );
  }
  
  static V8Value CreateFunction( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    bool is_const = V8Object::Cast( args[ 0 ] )->IsTrue();
    V8Value name_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    V8Value arg_val = V8Object::Cast( args[ 2 ] )->GetInternalField( 0 );
    V8Value body_val = V8Object::Cast( args[ 3 ] )->GetInternalField( 0 );
    AstNode* name = reinterpret_cast<AstNode*>( name_val );
    AstNode* m_args = reinterpret_cast<AstNode*>( arg_val );
    AstNode* body = reinterpret_cast<AstNode*>( body_val );
    mocha::Function* fn = ManagedHandle::Retain<mocha::Function>();
    fn->Name( name );
    fn->Argv( m_args );
    fn->Append( body );
    return AstForV8::Init( global , fn , info );
  }

  static V8Value CreateCallExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value call_type_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value call_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    V8Value arg_val = V8Object::Cast( args[ 2 ] )->GetInternalField( 0 );
    int type = reinterpret_cast<int>( call_type_val );
    AstNode* call = reinterpret_cast<AstNode*>( call_val );
    AstNode* m_args = reinterpret_cast<AstNode*>( arg_val );
    CallExp* exp = ManagedHandle::Retain( new CallExp( type ) );
    exp->Callable( call );
    exp->Args( m_args );
    return AstForV8::Init( global , exp , info );
  }

  static V8Value CreateNewExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value call_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    AstNode* call = reinterpret_cast<AstNode*>( call_val );
    NewExp* exp = ManagedHandle::Retain<NewExp>();
    exp->Constructor( call );
    return AstForV8::Init( global , exp , info );
  }

  static V8Value CreatePostfixExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value post_type_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value exp_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    int type = reinterpret_cast<int>( post_type_val );
    AstNode* exp = reinterpret_cast<AstNode*>( exp_val );
    PostfixExp* post = ManagedHandle::Retain( new PostfixExp( type ) );
    post->Exp( exp );
    return AstForV8::Init( global , post , info );
  }

  static V8Value CreateBinaryExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value op_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value left_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    V8Value right_val = V8Object::Cast( args[ 2 ] )->GetInternalField( 0 );
    int type = reinterpret_cast<int>( op_val );
    AstNode* left = reinterpret_cast<AstNode*>( left_val );
    AstNode* right = reinterpret_cast<AstNode*>( right_val );
    BinaryExp* binary = ManagedHandle::Retain( new BinaryExp( type , left , right ) );
    return AstForV8::Init( global , binary , info );
  }

  static V8Value CreateCompareExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value op_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value left_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    V8Value right_val = V8Object::Cast( args[ 2 ] )->GetInternalField( 0 );
    int type = reinterpret_cast<int>( op_val );
    AstNode* left = reinterpret_cast<AstNode*>( left_val );
    AstNode* right = reinterpret_cast<AstNode*>( right_val );
    CompareExp* compare = ManagedHandle::Retain( new ComapreExp( type , left , right ) );
    return AstForV8::Init( global , compare , info );
  }

  static V8Value CreateConditionalExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value cond_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value true_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    V8Value false_val = V8Object::Cast( args[ 2 ] )->GetInternalField( 0 );
    AstNode* cond = reinterpret_cast<int>( cond_val );
    AstNode* true_exp = reinterpret_cast<AstNode*>( true_val );
    AstNode* false_exp = reinterpret_cast<AstNode*>( false_val );
    ConditionalExp* conditional = ManagedHandle::Retain( new ConditionalExp( cond , true_exp , false_exp ) );
    return AstForV8::Init( global , conditional , info );
  }

  static V8Value CreateAssignmentExp( const Arguments& args ) {
    HandleScope handle_scope;
    ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 0 ) );
    V8Object global = V8Object::Cast( args.This()->GetInternalField( 1 ) );
    V8Value op_val = V8Object::Cast( args[ 0 ] )->GetInternalField( 0 );
    V8Value left_val = V8Object::Cast( args[ 1 ] )->GetInternalField( 0 );
    V8Value right_val = V8Object::Cast( args[ 2 ] )->GetInternalField( 0 );
    int type = reinterpret_cast<int>( op_val );
    AstNode* left = reinterpret_cast<AstNode*>( left_val );
    AstNode* right = reinterpret_cast<AstNode*>( right_val );
    AssignmentExp* assign = ManagedHandle::Retain( new AssignmentExp( type , left , right ) );
    return AstForV8::Init( global , assign , info );
  }
  
  static V8Value CreateSymbol( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    if ( args[ 0 ]->IsString() ) {
      V8String::Utf8Value str( args[0] );
      const char* val = *str;
      ValueNode* value = AstUtils::CreateNameNode( val , Token::JS_IDENTIFIER , ValueNode::kIdentifier , 0 );
      return AstForV8::Init( global , value , info );
    }
    return v8::ThrowException( V8String::New( "arguments error." ) );
  }

  static V8Value CreateProperty( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    if ( args[ 0 ]->IsString() ) {
      V8String::Utf8Value str( args[0] );
      const char* val = *str;
      ValueNode* value = AstUtils::CreateNameNode( val , Token::JS_PROPERTY , ValueNode::kProperty , 0 );
      return AstForV8::Init( global , value , info );
    }
    return v8::ThrowException( V8String::New( "arguments error." ) );
  }

  static V8Value CreateThis( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 0 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    ValueNode* value = AstUtils::CreateNameNode( "this" , Token::JS_THIS , ValueNode::kThis , 0 );
    return AstForV8::Init( global , value , info );
  }

  static V8Value CreateTrue( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 0 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    ValueNode* value = AstUtils::CreateNameNode( "true" , Token::JS_TRUE , ValueNode::kTrue , 0 );
    return AstForV8::Init( global , value , info );
  }

  static V8Value CreateFalse( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 0 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    ValueNode* value = AstUtils::CreateNameNode( "false" , Token::JS_FALSE , ValueNode::kFalse , 0 );
    return AstForV8::Init( global, value , info );
  }

  static V8Value CreateNull( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 0 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    ValueNode* value = AstUtils::CreateNameNode( "null" , Token::JS_IDENTIFIER , ValueNode::kIdentifier , 0 );
    return AstForV8::Init( global , value , info );
  }

  static V8Value CreateUndefined( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 0 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    ValueNode* value = AstUtils::CreateNameNode( "undefined" , Token::JS_IDENTIFIER , ValueNode::kIdentifier , 0 );
    return AstForV8::Init( global , value , info );
  }
  
  static V8Value CreateNumber( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    if ( args[ 0 ]->IsString() ) {
      ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
      V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
      V8String::Utf8Value str( args[0] );
      const char* val = *str;
      ValueNode* value = AstUtils::CreateNameNode( val , Token::JS_NUMERIC , ValueNode::kNumeric , 0 );
      return AstForV8::Init( global , value , info );
    }
    return v8::ThrowException( V8String::New( "arguments error." ) );
  }

  static V8Value CreateString( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    if ( args[ 0 ]->IsString() ) {
      ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
      V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
      V8String::Utf8Value str( args[0] );
      std::string val = "\"";
      val += *str;
      val += '"';
      ValueNode* value = AstUtils::CreateNameNode( val.c_str() , Token::JS_STRING_LITERAL , ValueNode::kString , 0 );
      return AstForV8::Init( global , value , info );
    }
    return v8::ThrowException( V8String::New( "arguments error." ) );
  }

  static V8Value CreateRegExp( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    if ( args[ 0 ]->IsString() ) {
      ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
      V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
      V8String::Utf8Value str( args[0] );
      const char* val = *str;
      ValueNode* value = AstUtils::CreateNameNode( val , Token::JS_REGEXP , ValueNode::kRegExp , 0 );
      return AstForV8::Init( global , value , info );
    }
    return v8::ThrowException( V8String::New( "arguments error." ) );
  }

  static V8Value CreateVariableDecl( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 2 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ERROR_CHECK( args[ 0 ]->ToObject() , AstNode::kValueNode );
    ERROR_CHECK( args[ 1 ]->ToObject() , AstNode::kBase );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    AstNode* name = GetInternal<ValueNode*>( 1 , args[ 0 ]->ToObject() );
    AstNode* val = GetInternal<ValueNode*>( 2 , args[ 1 ]->ToObject() );
    ValueNode* var = AstUtils::CreateVarInitialiser( name , val );
    return AstForV8::Init( global , var , info );
  }

  static V8Value CreateObject( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ERROR_CHECK( args[ 0 ]->ToObject() , AstNode::kNodeList );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    AstNode* val = GetInternal<NodeList>( 1 , args[ 0 ]->ToObject() );
    ValueNode* object = ManagedHandle::Retain( new ValueNode( ValueNode::kObject ) );
    object->Node( val );
    return AstForV8::Init( global , object , info );
  }

  static V8Value CreateObjectElement( const Arguments& args ) {
    HandleScope handle_scope;
    NodeList* list = ManagedHandle::Retain<NodeList>();
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    for ( int i = 0,len = args.Length(); i < len; i++ ) {
      ERROR_CHECK( args[ i ]->ToObject() , AstNode::kBase );
      AstNode* val = GetInternal<AstNode>( 1 , args[ i ]->ToObject() );
      if ( val->NodeType() == AstNode::kValueNode && val->CastToValue()->ValueType() == ValueNode::kProperty ) {
        list->AddChild( val );
      } else {
        return v8::ThrowException( V8String::New( "arguments error." ) );
      }
    }
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    return AstForV8::Init( global , list , info );
  }

  static V8Value CreateArray( const Arguments& args ) {
    HandleScope handle_scope;
    ARGUMENTS_CHECK( 1 , args );
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    ERROR_CHECK( args[ 0 ]->ToObject() , AstNode::kNodeList );
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    AstNode* val = GetInternal<NodeList>( 1 , args[ 0 ]->ToObject() );
    ValueNode* array = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
    object->Node( val );
    return AstForV8::Init( global , object , info );
  }

  static V8Value CreateArrayElement( const Arguments& args ) {
    HandleScope handle_scope;
    NodeList* list = ManagedHandle::Retain<NodeList>();
    GET_THIS( this_obj , args );
    ERROR_CHECK_FOR_CREATOR( this_obj , AstNode::kBase );
    for ( int i = 0,len = args.Length(); i < len; i++ ) {
      ERROR_CHECK( args[ i ]->ToObject() , AstNode::kBase );
      AstNode* val = GetInternal<AstNode>( 1 , args[ i ]->ToObject() );
      if ( val->NodeType() == AstNode::kValueNode ||
           val->NodeType() == AstNode::kFunction ||
           val->NodeType() == AstNode::kAssignmentExp ||
           val->NodeType() == AstNode::kCompareExp ||
           val->NodeType() == AstNode::kEmpty ||
           val->NodeType() == AstNode::kUnaryExp ||
           val->NodeType() == AstNode::kConditionalExp ||
           val->NodeType() == AstNode::kCallExp ||
           val->NodeType() == AstNode::kNewExp
           val->NodeType() == AstNode::kEmpty ) {
        list->AddChild( val );
      } else {
        return v8::ThrowException( V8String::New( "arguments error." ) );
      }
    }
    ProcessorInfo* info = GetInternal<ProcessorInfo>( 1 , this_obj );
    V8Object global = GetInternalHandle<V8Object>( 2 , this_obj );
    return AstForV8::Init( global , list , info );
  }
};


V8Object AstForV8::Init( V8Object global_object , AstNode* ast_node , ProcessorInfo* info ) {
  HandleScope handle_scope;
  Handle<FunctionTemplate> function_template = FunctionTemplate::New();
  Handle<ObjectTemplate>   prototype_template = function_template->PrototypeTemplate();
  Handle<ObjectTemplate>   object_template = function_template->InstanceTemplate();
  prototype_template->Set( String::New( "childNodes" ) , FunctionTemplate::New( AstForV8::ChildNodes ) );
  prototype_template->Set( String::New( "firstChild" ) , FunctionTemplate::New( AstForV8::FirstChild ) );
  prototype_template->Set( String::New( "lastChild" ) , FunctionTemplate::New( AstForV8::LastChild ) );
  prototype_template->Set( String::New( "replaceChild" ) , FunctionTemplate::New( AstForV8::ReplaceChild ) );
  prototype_template->Set( String::New( "parentNode" ) , FunctionTemplate::New( AstForV8::ParentNode ) );
  prototype_template->Set( String::New( "nextSibling" ) , FunctionTemplate::New( AstForV8::NextSibling ) );
  prototype_template->Set( String::New( "previousSibling" ) , FunctionTemplate::New( AstForV8::PreviousSibling ) );
  prototype_template->Set( String::New( "nodeName" ) , FunctionTemplate::New( AstForV8::NodeName ) );
  prototype_template->Set( String::New( "nodeType" ) , FunctionTemplate::New( AstForV8::NodeType ) );
  prototype_template->Set( String::New( "addChild" ) , FunctionTemplate::New( AstForV8::AddChild ) );
  prototype_template->Set( String::New( "removeChild" ) , FunctionTemplate::New( AstForV8::RemoveChild ) );
  prototype_template->Set( String::New( "before" ) , FunctionTemplate::New( AstForV8::Before ) );
  prototype_template->Set( String::New( "after" ) , FunctionTemplate::New( AstForV8::After ) );
  prototype_template->Set( String::New( "insertAfter" ) , FunctionTemplate::New( AstForV8::InsertAfter ) );
  prototype_template->Set( String::New( "insertBefore" ) , FunctionTemplate::New( AstForV8::InsertBefore ) );
  prototype_template->Set( String::New( "setParent" ) , FunctionTemplate::New( AstForV8::SetParentNode ) );
  SetUniqueProp( ast_node , prototype_template );
  V8Object object = function_template->GetFunction()->NewInstance();
  object->SetInternalFieldCount( 4 );
  object->SetInternalField( 0 , GetMark() );
  object->SetInternalField( 1 , External::New( ast_node ) );
  object->SetInternalField( 2 , External::New( info ) );
  object->SetInternalField( 3 , global_object );
  return object;
}


Handle<ObjectTemplate> AstForV8::InitEnv( V8Object , ProcessorInfo* info ) {
  HandleScope handle_scope;
  Handle<ObjectTemplate> object = ObjectTemplate::New();
  object->SetInternalFieldCount( 2 );
  object->SetInternalField( 0 , info );
  object->SetInternalField( 1 , global );
  object->Set( String::New( "getFilename" ) , Function::New( JSEnv::GetFileName ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "getMainfilePath" ) , Function::New( JSEnv::GetMainFilePath ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "hasVersion" ) , Function::New( JSEnv::HasVersion ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  return handle_scope.Close( object );
}

Handle<ObjectTemplate> AstForV8::InitCreator( V8Object global , ProcessorInfo* info ) {
  HandleScope handle_scope;
  Handle<ObjectTemplate> object = ObjectTemplate::New();
  object->SetInternalFieldCount( 2 );
  object->SetInternalField( 0 , GetCreatorMark() );
  object->SetInternalField( 1 , info );
  object->SetInternalField( 2 , global );
  object->Set( String::New( "createBlockStmt" ) , Function::New( CreateBlock ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createEmptyNode" ) , Function::New( CreateEmptyNode ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createVariableStmt" ) , Function::New( CreateVariableStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createExpressionStmt" ) , Function::New( CreateExpressionStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createIFStmt" ) , Function::New( CreateIFStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createForStmt" ) , Function::New( CreateForStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createForInStmt" ) , Function::New( CreateForInStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createWhileStmt" ) , Function::New( CreateWhileStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createDoWhileStmt" ) , Function::New( CreateDoWhileStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createContinueStmt" ) , Function::New( CreateContinueStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createBreakStmt" ) , Function::New( CreateBreakStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createReturnStmt" ) , Function::New( CreateReturnStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createWithStmt" ) , Function::New( CreateWithStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createLabelledStmt" ) , Function::New( CreateLabelledStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createSwtichStmt" ) , Function::New( CreateSwtichStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createThrowStmt" ) , Function::New( CreateThrowStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createTryStmt" ) , Function::New( CreateTryStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createCaseClause" ) , Function::New( CreateCaseClause ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createExpression" ) , Function::New( CreateExpression ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createNodeList" ) , Function::New( CreateNodeList ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createFunction" ) , Function::New( CreateFunction ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createCallExp" ) , Function::New( CreateCallExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createNewExp" ) , Function::New( CreateNewExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createPostfixExp" ) , Function::New( CreatePostfixExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createBinaryExp" ) , Function::New( CreateBinaryExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createCompareExp" ) , Function::New( CreateComapreExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createConditionalExp" ) , Function::New( CreateConditionalExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createSymbol" ) , Function::New( CreateSymbol ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createProperty" ) , Function::New( CreateProperty ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createThis" ) , Function::New( CreateThis ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createTrue" ) , Function::New( CreateTrue ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createFalse" ) , Function::New( CreateFalse ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createNull" ) , Function::New( CreateNull ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createUndefined" ) , Function::New( CreateUndefined ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createRegExp" ) , Function::New( CreateRegExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createObject" ) , Function::New( CreateObject ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createObjectElement" ) , Function::New( CreateObjectElement ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createArray" ) , Function::New( CreateArray ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "createArrayElement" ) , Function::New( CreateArrayElement ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  
  V8Object ast_type = SetTypes();
  object->Set( String::New( "astType" ) , ast_type,
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  V8Object var_type = SetVarTypes();
  object->Set( String::New( "varType" ) , var_type,
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  V8Object call_type = SetCallTypes();
  object->Set( String::New( "callType" ) , call_type,
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  V8Object value_type = SetValueTypes();
  object->Set( String::New( "valueType" ) , value_type,
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  return handle_scope.Close( object );
}

V8Object AstForV8::SetTypes() {
  HandleScope handle_scope;
  V8Object object = Object::New();
  object->Set( String::New( "EMPTY" ) , Number::New( AstNode::kEmpty ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "AST_ROOT" ) , Number::New( AstNode::kAstRoot ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FILE_ROOT" ) , Number::New( AstNode::kFileRoot ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "STATEMENT" ) , Number::New( AstNode::kStatement ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "STATEMENTLIST" ) , Number::New( AstNode::kStatementList ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "EXPRESSION" ) , Number::New( AstNode::kExpression ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "VALUENODE" ) , Number::New( AstNode::kValueNode ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "CASE_CLAUSE" ) , Number::New( AstNode::kCase ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "NODE_LIST" ) , Number::New( AstNode::kAstRoot ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "BLOCK_STMT" ) , Number::New( AstNode::kBlockStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "VARIABLE_STMT" ) , Number::New( AstNode::kVariableStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "EXPRESSION_STMT" ) , Number::New( AstNode::kExpressionStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "IF_STMT" ) , Number::New( AstNode::kIFStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "ITERATION_STMT" ) , Number::New( AstNode::kIterationStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "CONTINUE_STMT" ) , Number::New( AstNode::kContinueStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "RETURN_STMT" ) , Number::New( AstNode::kReturnStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "BREAK_STMT" ) , Number::New( AstNode::kBreakStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "WITH_STMT" ) , Number::New( AstNode::kWithStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "LABELLED_STMT" ) , Number::New( AstNode::kLabelledStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "SWTICH_STMT" ) , Number::New( AstNode::kSwitchStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "THROW_STMT" ) , Number::New( AstNode::kThrowStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "TRY_STMT" ) , Number::New( AstNode::kTryStmt ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FOR_STMT" ) , Number::New( AstNode::kFor ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FOR_WITH_VAR_STMT" ) , Number::New( AstNode::kForWithVar ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FORIN_STMT" ) , Number::New( AstNode::kForIn ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FORIN_WITH_VAR_STMT" ) , Number::New( AstNode::kForInWithVar ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "WHILE_STMT" ) , Number::New( AstNode::kWhile ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "DO_WHILE_STMT" ) , Number::New( AstNode::kDoWhile ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FUNCTION" ) , Number::New( AstNode::kFunction ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "CALL_EXP" ) , Number::New( AstNode::kCallExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "NEW_EXP" ) , Number::New( AstNode::kNewExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "POSTFIX_EXP" ) , Number::New( AstNode::kPostfixExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "UNARY_EXP" ) , Number::New( AstNode::kUnaryExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "BINARY_EXP" ) , Number::New( AstNode::kBinaryExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "COMPARE_EXP" ) , Number::New( AstNode::kCompareExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "CONDITIONAL_EXP" ) , Number::New( AstNode::kConditionalExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "ASSIGNMENT_EXP" ) , Number::New( AstNode::kAssignmentExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  return handle_scope.Close( object );
}


V8Object AstForV8::SetVarTypes() {
  HandleScope handle_scope;
  V8Object object = Object::New();
  object->Set( String::New( "NORMAL" ) , Number::New( VariableStmt::kNormal ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "CONST" ) , Number::New( VariableStmt::kConst ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "LET" ) , Number::New( VariableStmt::kLet ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  return handle_scope.Close( object );
}

V8Object AstForV8::SetCallTypes() {
  HandleScope handle_scope;
  V8Object object = Object::New();
  object->Set( String::New( "NORMAL" ) , Number::New( CallExp::kNormal ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "ARRAY" ) , Number::New( CallExp::kBracket ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "DOT" ) , Number::New( CallExp::kDot ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "NEW" ) , Number::New( CallExp::kNew ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  return handle_scope.Close( object );
}

V8Object AstForV8::SetValueTypes() {
  HandleScope handle_scope;
  V8Object object = Object::New();
  object->Set( String::New( "NULL" ) , Number::New( ValueNode::kNull ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "TRUE" ) , Number::New( ValueNode::kTrue ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "FALSE" ) , Number::New( ValueNode::kFalse ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "NUMERIC" ) , Number::New( ValueNode::kNumeric ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "STRING" ) , Number::New( ValueNode::kString ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "REGEXP" ) , Number::New( ValueNode::kRegExp ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "THIS" ) , Number::New( ValueNode::kThis ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "IDENTIFIER" ) , Number::New( ValueNode::kIdentifier ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "PROPERTY_NAME" ) , Number::New( ValueNode::kPropertyName ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "VARIABLE" ) , Number::New( ValueNode::kVariable ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "ARRAY" ) , Number::New( ValueNode::kArray ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "OBJECT" ) , Number::New( ValueNode::kObject ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  object->Set( String::New( "PROPERTY" ) , Number::New( ValueNode::kProperty ),
               PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
  return handle_scope.Close( object );
}


V8Value AstForV8::ChildNodes( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* child = node->FirstChild();
  Local<Object> object = Object::New();
  if ( !child->IsEmpty() ) {
    NodeIterator iterator = node->ChildNodes();
    int count = 0;
    while ( iterator.HasNext() ) {
      AstNode* item = iterator.Next();
      if ( !item->IsEmpty() ) {
        object->Set( Number::New( count ) , AstForV8::Init( item , info ) , PropertyAttribute::kDontDelete );
        count++;
      }
    }
    object->Set( String::New( "length" ) , Number::New( count ),
                 PropertyAttribute::kDontDelete | PropertyAttribute::kReadOnly );
    return handle_scope.Close( object );
  } else {
    return handle_scope.Close( object );
  }
}


V8Value AstForV8::FirstChild( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* child = node->FirstChild();
  if ( !child->IsEmpty() ) {
    return AstForV8::Init( child , info );
  } else {
    return Undefined();
  }
}

V8Value AstForV8::LastChild( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* child = node->LastChild();
  if ( !child->IsEmpty() ) {
    return AstForV8::Init( child , info );
  } else {
    return Undefined();
  }
}

V8Value AstForV8::FirstChild( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* child = node->FirstChild();
  if ( !child->IsEmpty() ) {
    return AstForV8::Init( child , info );
  } else {
    return Undefined();
  }
}

V8Value AstForV8::ParentNode( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* parent = node->ParentNode();
  if ( parent ) {
    return AstForV8::Init( parent , info );
  } else {
    return Undefined();
  }
}

V8Value AstForV8::NextSibling( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* next = node->NextSibling();
  if ( next && !next->IsEmpty() ) {
    return AstForV8::Init( next , info );
  } else {
    return Undefined();
  }
}

V8Value AstForV8::PreviousSibling( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  ProcessorInfo* info = reinterpret_cast<ProcessorInfo*>( args.Thils()->GetInternalField( 1 ) );
  AstNode* prev = node->PreviousSibling();
  if ( prev && !prev->IsEmpty() ) {
    return AstForV8::Init( prev , info );
  } else {
    return Undefined();
  }
}

V8Value AstForV8::NodeName( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  const char* name = node->GetName();
  return String::New( name );
}

V8Value AstForV8::NodeType( const Arguments& args ) {
  HandleScope handle_scope;
  AstNode* node = reinterpret_cast<AstNode*>( args.This()->GetInternalField( 0 ) );
  return Number::New( node->NodeType() );
}

V8Value AstForV8::AddChild( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 1 , args );
  V8Handle<V8Object> child_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( child_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* child = GetInternal<AstNode>( 1 , child_arg );
  node->AddChild( child );
  return V8Undefined();
}

V8Value AstForV8::SetParentNode( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 1 , args );
  V8Handle<V8Object> parent_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( parent_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* parent = GetInternal<AstNode>( 1 , parent_arg );
  node->ParentNode( parent );
  return V8Undefined();
}

V8Value AstForV8::After( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 1 , args );
  V8Handle<V8Object> next_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( next_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* next = GetInternal<AstNode>( 1 , next_arg );
  node->After( next );
  return V8Undefined();
}

V8Value AstForV8::Before( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 1 , args );
  V8Handle<V8Object> prev_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( prev_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* prev = GetInternal<AstNode>( 1 , prev_arg );
  node->Before( prev );
  return V8Undefined();
}

V8Value AstForV8::RemoveChild( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 1 , args );
  V8Handle<V8Object> target_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( target_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* prev = GetInternal<AstNode>( 1 , target_arg );
  node->RemoveChild( prev );
  return V8Undefined();
}

V8Value AstForV8::ReplaceChild( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 2 , args );
  V8Handle<V8Object> old_node_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  V8Handle<V8Object> new_node_arg = V8Handle<V8Object>::Cast( args[ 1 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( old_node_arg , AstNode::kBase );
  ERROR_CHECK( new_node_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* old_node = GetInternal<AstNode>( 1 , old_node_arg );
  AstNode* new_node = GetInternal<AstNode>( 1 , new_node_arg );
  node->ReplaceChild( old_node , new_node );
  return V8Undefined();
}

V8Value AstForV8::InsertAfter( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 2 , args );
  V8Handle<V8Object> before_node_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  V8Handle<V8Object> after_node_arg = V8Handle<V8Object>::Cast( args[ 1 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( before_node_arg , AstNode::kBase );
  ERROR_CHECK( after_node_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* before_node = GetInternal<AstNode>( 1 , before_node_arg );
  AstNode* after_node = GetInternal<AstNode>( 1 , after_node_arg );
  node->InsertAfter( after_node , before_node );
  return V8Undefined();
}

V8Value AstForV8::InsertBefore( const Arguments& args ) {
  HandleScope handle_scope;
  ARGUMENTS_CHECK( 2 , args );
  V8Handle<V8Object> after_node_arg = V8Handle<V8Object>::Cast( args[ 0 ] );
  V8Handle<V8Object> before_node_arg = V8Handle<V8Object>::Cast( args[ 1 ] );
  GET_THIS( this_obj , args );
  ERROR_CHECK( this_obj , AstNode::kBase );
  ERROR_CHECK( after_node_arg , AstNode::kBase );
  ERROR_CHECK( before_node_arg , AstNode::kBase );
  AstNode* node = GetInternal<AstNode>( 1 , this_obj );
  AstNode* before_node = GetInternal<AstNode>( 1 , after_node_arg );
  AstNode* after_node = GetInternal<AstNode>( 1 , before_node_arg );
  node->InsertAfter( before_node , after_node );
  return V8Undefined();
}

}
