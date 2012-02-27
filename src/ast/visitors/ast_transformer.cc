/**
 *@author Taketoshi Aono
 *@fileOverview
 *@license
 *Copyright (c) 2011 Taketoshi Aono
 *Licensed under the BSD.
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 *associated doc umentation files (the "Software"), to deal in the Software without restriction,
 *including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all copies or
 *substantial portions ofthe Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 *TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *DEALINGS IN THE SOFTWARE.
 */
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include <compiler/compiler.h>
#include <compiler/tokens/js_token.h>
#include <compiler/tokens/token_info.h>
#include <compiler/tokens/symbol_list.h>
#include <compiler/scopes/scope.h>
#include <ast/visitors/ast_transformer.h>
#include <ast/visitors/codegen_visitor.h>
#include <ast/ast.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/pool/managed_handle.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/iteration_processor.h>
#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/class_processor.h>
#include <ast/visitors/utils/processors/trait_processor.h>
#include <ast/visitors/utils/processors/function_processor.h>
#include <ast/visitors/utils/processors/fileroot_processor.h>
#include <ast/visitors/utils/processors/module_processor.h>
#include <ast/visitors/utils/processors/export_processor.h>
#include <ast/visitors/utils/processors/import_processor.h>
#include <ast/visitors/utils/processors/call_processor.h>
#include <ast/visitors/utils/processors/yield_processor.h>
#include <ast/visitors/utils/processors/processor_info.h>
#include <utils/xml/xml_setting_info.h>
#include <grammar/grammar.tab.hh>
#include <third_party/v8/include/v8.h>

namespace mocha {


#define VISITOR_IMPL(type) void AstTransformer::Visit##type( type* ast_node )
#define TOKEN yy::ParserImplementation::token

#ifdef PRINTABLE
#define PRINT_NODE_NAME ast_node->PrintNodeName();
#else
#define PRINT_NODE_NAME
#endif

#define REGIST(node) visitor_info_->SetCurrentStmt( node )


AstTransformer::AstTransformer( bool is_runtime , Scope* scope , Compiler* compiler,
                        const char* main_file_path , const char* filename ) :
    visitor_info_( new VisitorInfo( is_runtime,
                                    scope,
                                    compiler,
                                    ManagedHandle::Retain<DstaExtractedExpressions>() , main_file_path , filename ) ) {
  proc_info_( new ProcessorInfo( this , scope , visitor_info_.Get() ) );
}

AstTransformer::~AstTransformer () {}


VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  AstNode* root = ast_node->first_child();
  if ( root ) {
    root->Accept( this );
  }
}

VISITOR_IMPL( FileRoot ) {
  PRINT_NODE_NAME;
  FileRootProcessor::ProcessNode( ast_node , proc_info_.Get() );
}


VISITOR_IMPL( NodeList ) {
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( VersionStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* body = ast_node->first_child();
  ast_node->RemoveAllChild();
  Function *fn_node = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>(),
                                                    ManagedHandle::Retain<Empty>() , body );
  ExpressionStmt* an_stmt_node = AstUtils::CreateAnonymousFnCall( fn_node , ManagedHandle::Retain<Empty>() );
  ast_node->AddChild( an_stmt_node );
  body->Accept( this );
}


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}

VISITOR_IMPL( ModuleStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ModuleProcessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
}


VISITOR_IMPL( ExportStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ExportProcessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
}

VISITOR_IMPL( ImportStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ImportProccessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
}


VISITOR_IMPL( Statement ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
}


VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  VariableProcessor::ProcessVarList( ast_node , proc_info_.Get() );
  if ( ast_node->dsta_flag() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedVarStmt( ast_node , proc_info_.Get() );
    ast_node->Append( list );
  }
}

VISITOR_IMPL(LetStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
}


VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept( this );
  if ( ast_node->dsta_flag() ) {
    NodeIterator iterator = ast_node->dsta_node()->Refs()->ChildNodes();
    NodeList* var_list = ManagedHandle::Retain<NodeList>();
    while ( iterator.HasNext() ) {
      Literal* node = AstUtils::CreateVarInitiliser( iterator.Next()->CastToLiteral()->value() , ManagedHandle::Retain<Empty>() );
      var_list->AddChild( node );
    }
    VariableStmt *var_stmt = AstUtils::CreateVarStmt( var_list );
    ast_node->parent_node()->InsertBefore( var_stmt , ast_node );
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
    NodeIterator iter = list->ChildNodes();
    AstNode* last = 0;
    while ( iter.HasNext() ) {
      AstNode* item = iter.Next();
      ExpressionStmt* stmt = AstUtils::CreateExpStmt( item );
      if ( last ) {
        ast_node->parent_node()->InsertAfter( stmt , last );
        last = stmt;
      } else {
        ast_node->parent_node()->InsertAfter( stmt , ast_node );
        last = stmt;
      }
    }
  }
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->condition()->Accept( this );
  AstNode* then_statement = ast_node->then_statement();
  AstNode* maybe_else_statement = ast_node->else_statement();
  if ( then_statement->node_type() != AstNode::kBlockStmt ) {
    BlockStmt* block = AstUtils::CreateBlockStmt( 1 , then_statement );
    ast_node->set_then_statement( block );
    then_statement = block;
  }
  then_statement->Accept( this );
  if ( ast_node->dsta_flag() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    exp->paren();
    ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->AddChild( exp );
    maybeBlock->first_child()->InsertBefore( exp_stmt );
    AstNode* parent = ast_node;
    AstNode* first_if = ast_node;
    while ( parent->node_type() == AstNode::kIFStmt ) {
      parent = parent->parent_node();
      if ( parent->node_type() != AstNode::kIFStmt ) {
        break;
      } else {
        first_if = parent;
      }
    }
    if ( first_if->HasPrev() && first_if->previous_sibling()->node_type() == AstNode::kVariableStmt ) {
      first_if->previous_sibling()->Append( DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() ) );
    } else {
      parent->InsertBefore( DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() ), first_if );
    }
  }
  maybe_else_statement->Accept( this );
  if ( ast_node->generator() ) {
    visitor_info_->GetFunction()->set_statement_in_generator( ast_node );
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  switch ( ast_node->NodeType() ) {
    case AstNode::kFor : //Fall Through
    case AstNode::kForWithVar :
      IterationProcessor::ProcessForNode( ast_node , proc_info_.Get() );
      break;

    case AstNode::kForIn :
    case AstNode::kForInWithVar :
      IterationProcessor::ProcessForInNode( ast_node , proc_info_.Get() );
      break;
    case AstNode::kForEach :
    case AstNode::kForEachWithVar :
      IterationProcessor::ProcessForEachNode( ast_node , proc_info_.Get() );
      break;

    case AstNode::kForOf :
    case AstNode::kForOfWithVar :
      IterationProcessor::ProcessForOfNode( ast_node , proc_info_.Get() );
      break;

    case AstNode::kDoWhile :
    case AstNode::kWhile :
      IterationProcessor::ProcessWhileNode( ast_node , proc_info_.Get() );
      break;
  }
}


VISITOR_IMPL( ContinueStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept( this );
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept( this );
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept( this );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->expression();
  AstNode* body = ast_node->first_child();
  if ( body->node_type != AstNode::kBlockStmt ) {
    BlockStmt* block = AstUtils::CreateBlockStmt( 1 , body );
    ast_node->RemoveAllChild();
    ast_node->AddChild( block );
    body = block;
  }
  exp->Accept( this );
  body->Accept( this );
  if ( ast_node->dsta_flag() ) {
    VariableStmt* var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() );
    ast_node->parent_node()->InsertBefore( var_stmt , ast_node );
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    exp_stmt->AddChild( exp );
    body->first_child()->InsertBefore( exp_stmt );
  }
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->Exp();
  exp->Accept( this );
  NodeIterator iterator = ast_node->first_child()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  if ( ast_node->generator() ) {
    visitor_info_->GetFunction()->set_statement_in_generator( ast_node );
  }
}


VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  Statement* stmt_tmp = ManagedHandle::Retain<Statement>();
  REGIST(stmt_tmp);
  AstNode *parent = ast_node->parent_node();
  SwitchStmt *switch_stmt = reinterpret_cast<SwitchStmt* >( parent->parent_node() );
  ast_node->expression()->Accept( this );
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
  ExpressionStmt* case_exp_stmt = 0;
  ExpressionStmt* cond_exp_stmt = 0;
  if ( stmt_tmp->dsta_flag() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( stmt_tmp , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    case_exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    case_exp_stmt->AddChild( exp );
    if ( ast_node->ChildLength() > 0 ) {
      ast_node->InsertBefore( case_exp_stmt );
    } else {
      ast_node->AddChild( case_exp_stmt ); 
    }
  }
  if ( switch_stmt->dsta_flag() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( switch_stmt , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    exp->paren();
    cond_exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    cond_exp_stmt->AddChild( exp );
    if ( ast_node->ChildLength() > 0 ) {
      ast_node->InsertBefore( cond_exp_stmt );
    } else {
      ast_node->AddChild( cond_exp_stmt ); 
    }
  }

}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* symbol = ast_node->first_child();
  AstNode* statement = symbol->NextSibling();
  if ( statement->NodeType() != AstNode::kBlockStmt ) {
    BlockStmt* stmt = AstUtils::CreateBlockStmt( 1 , statement->Clone() );
    ast_node->ReplaceChild( statement , stmt );
  }
  symbol->Accept( this );
  statement->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* val = ast_node->Exp();
  Expression* exp = val->CastToExpression();
  if ( exp && !visitor_info_->IsRuntime() ) {
    if ( exp->ChildLength() == 1 ) {
      Literal* name = exp->first_child()->CastToLiteral();
      if ( name && name->ValueType() == Literal::kIdentifier && strcmp( name->Symbol()->GetToken() , "StopIteration" ) == 0 ) {
        Literal* undefined = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kUndefined ),
                                                         Token::JS_IDENTIFIER , ast_node->Line() , Literal::kIdentifier );
        ReturnStmt* stmt = AstUtils::CreateReturnStmt( undefined );
        ast_node->parent_node()->ReplaceChild( ast_node , stmt );
      } else {
        ast_node->Exp()->Accept( this );
      }
    } else {
      ast_node->Exp()->Accept( this );
    }
  } else {
    ast_node->Exp()->Accept( this );
  }
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->first_child()->Accept( this );
  if ( !ast_node->Catch()->IsEmpty() ) {
    ast_node->Catch()->Accept( this );
    ast_node->Catch()->first_child()->Accept( this );
  }
  ast_node->Finally()->Accept( this );
  if ( ast_node->GetYieldFlag() ) {
    visitor_info_->GetFunction()->SetTryCatch( ast_node );
  }
}


VISITOR_IMPL(AssertStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* name = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kAssert ),
                                            Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
  CodegenVisitor visitor( visitor_info_->GetFileName() , true , false );
  AstNode* expect = ast_node->first_child();
  AstNode* expression = expect->NextSibling();
  ast_node->RemoveAllChild();
  expect->Accept( this );
  expression->Accept( this );
  expression->Accept( &visitor );
  std::string str = "\"";
  std::string result = visitor.GetCode();
  bool is_escaped = false;
  for ( int i = 0,len = result.size(); i < len; i++ ) {
    if ( result.at( i ) == '\n' ) {
      str += "\\n";
    } else if ( result.at( i ) == '\\' && !is_escaped ) {
      str += '\\';
      is_escaped = true;
    } else if ( result.at( i ) == '"' && !is_escaped ) {
      str += '\\';
      str += '"';
    } else if ( is_escaped ) {
      str += result.at( i );
      is_escaped = false;
    } else {
      str += result.at( i );
    }
  }
  str += "\"";
  char tmp[100];
  sprintf( tmp , "%ld" , ast_node->Line() );
  Literal* line = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , ast_node->Line() , Literal::kNumeric );
  Literal* string_expression = AstUtils::CreateNameNode( str.c_str() , Token::JS_STRING_LITERAL,
                                                           ast_node->Line() , Literal::kString );
  Literal* filename = AstUtils::CreateNameNode( visitor_info_->GetRelativePath() , Token::JS_STRING_LITERAL,
                                                  ast_node->Line() , Literal::kString );
  AstNode* arg = AstUtils::CreateNodeList( 5 , expect , expression , string_expression , line , filename );
  CallExp* exp = AstUtils::CreateRuntimeMod( name );
  CallExp* call = AstUtils::CreateNormalAccessor( exp , arg );
  ExpressionStmt* stmt = AstUtils::CreateExpStmt( call );
  ast_node->AddChild( stmt );
  stmt->Line( ast_node->Line() );
  if ( ast_node->HasDsta() ) {
    AstNode* dsta_exp = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
    ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( dsta_exp );
    ast_node->AddChild( exp_stmt );
  }
}


VISITOR_IMPL( CallExp ) {
  PRINT_NODE_NAME;
  switch ( ast_node->CallType() ) {
    case CallExp::kNormal :
      CallProcessor::ProcessFnCall( ast_node , proc_info_.Get() );
      break;

    case CallExp::kDot :
    case CallExp::kBracket : {
      AstNode* args = ast_node->Args();
      if ( args->CastToLiteral() && args->CastToLiteral()->ValueType() == Literal::kObject ) {
        CallProcessor::ProcessExtendAccessor( ast_node , proc_info_.Get() );
      } else {
        ast_node->Callable()->Accept( this );
        ast_node->Args()->Accept( this );
      }
    }
      break;

    case CallExp::kPrivate :
      CallProcessor::ProcessPrivateAccessor( ast_node , proc_info_.Get() );
      break;

    case CallExp::kExtend :
      CallProcessor::ProcessExtendAccessor( ast_node , proc_info_.Get() );
  }
}


VISITOR_IMPL(NewExp) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept( this );
}


VISITOR_IMPL(YieldExp) {
  PRINT_NODE_NAME;
  YieldProcessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
}

VISITOR_IMPL(CompareExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
}



VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  ast_node->Cond()->Accept( this );
  ast_node->True()->Accept( this );
  ast_node->False()->Accept( this );
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  ast_node->Left()->Accept( this );
  ast_node->Right()->Accept( this );
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}

VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  Statement *tmp_stmt = ManagedHandle::Retain<Statement>();
  REGIST(tmp_stmt);
  ClassProcessor *cls = ManagedHandle::Retain( new ClassProcessor( proc_info_.Get() , ast_node , tmp_stmt ) );
  visitor_info_->SetClass( cls );
  cls->ProcessNode();
}

VISITOR_IMPL(Trait) {
  PRINT_NODE_NAME;
  TraitProcessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  FunctionProcessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
};


void AstTransformer::ArrayProccessor_( Literal* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->first_child();
  while ( list_child ) {
    if ( !list_child->IsEmpty() ) {
      NodeIterator iter = list_child->ChildNodes();
      while ( iter.HasNext() ) {
        AstNode* element = iter.Next();
        if ( !element->IsEmpty() ) {
          element->Accept( this );
        }
      }
      if ( list_child->HasNext() ) {
        list_child = list_child->NextSibling();
      } else {
        break;
      }
    } else {
      break;
    }
  }
}


void AstTransformer::ObjectProccessor_( Literal* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* element_list = ast_node->Node();
  if ( !element_list->IsEmpty() ) {
    NodeIterator iterator = element_list->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->first_child()->Accept( this );
      element->Accept( this );
    }
  }
}



VISITOR_IMPL( Literal ) {
  PRINT_NODE_NAME;
  switch ( ast_node->ValueType() ) {
    case Literal::kArray :
      ArrayProccessor_( ast_node );
      break;

    case Literal::kArrayComp : {
      Literal* call_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCall ),
                                                      Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
      Literal* tmp = AstUtils::CreateTmpNode( visitor_info_->GetTmpIndex() );
      Literal* array = ManagedHandle::Retain( new Literal( Literal::kArray ) );
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarInitiliser( tmp->Symbol() , array ) );
      NodeIterator iterator = ast_node->first_child()->ChildNodes();
      bool is_first = true;
      AstNode* first;
      AstNode* current;
      while ( iterator.HasNext() ) {
        if ( is_first ) {
          current = first = iterator.Next();
          is_first = false;
        } else {
          AstNode* item = iterator.Next();
          current->AddChild( item );
          current = item;
        }
      }
      Literal* push = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPush ),
                                                  Token::JS_PROPERTY , 0 , Literal::kProperty );
      NodeList* list = ManagedHandle::Retain<NodeList>();
      list->AddChild( ast_node->Node()->Clone() );
      CallExp* push_accessor = AstUtils::CreateDotAccessor( tmp->Clone() , push );
      CallExp* push_call = AstUtils::CreateNormalAccessor( push_accessor , list );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( push_call );
      if ( current->NodeType() == AstNode::kIFStmt ) {
        IFStmt* if_stmt = current->CastToStatement()->CastToIFStmt();
        if_stmt->Then( exp_stmt );
        if_stmt->Else( ManagedHandle::Retain<Empty>() );
      } else {
        current->AddChild( exp_stmt );
      }
      ReturnStmt* stmt = AstUtils::CreateReturnStmt( tmp->Clone() );
      NodeList* body = AstUtils::CreateNodeList( 3 , var_stmt , first , stmt );
      Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() , body );
      fn->Accept( this );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->AddChild( fn );
      exp->Paren();
      Literal* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                      Token::JS_THIS , ast_node->Line() , Literal::kThis );
      NodeList* arg = AstUtils::CreateNodeList( 1 , this_sym );
      CallExp* dot = AstUtils::CreateDotAccessor( exp , call_sym );
      CallExp* this_call = AstUtils::CreateNormalAccessor( dot , arg );
      ast_node->parent_node()->ReplaceChild( ast_node , this_call );
    }
      break;

    case Literal::kGenerator : {
      Literal* call_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCall ),
                                                      Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
      NodeIterator iterator = ast_node->first_child()->ChildNodes();
      bool is_first = true;
      AstNode* first;
      AstNode* current;
      while ( iterator.HasNext() ) {
        if ( is_first ) {
          current = first = iterator.Next();
          is_first = false;
        } else {
          AstNode* item = iterator.Next();
          current->AddChild( item );
          current = item;
        }
      }
      YieldExp* yield_exp = ManagedHandle::Retain<YieldExp>();
      yield_exp->AddChild( ast_node->Node()->Clone() );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( yield_exp );
      if ( current->NodeType() == AstNode::kIFStmt ) {
        IFStmt* if_stmt = current->CastToStatement()->CastToIFStmt();
        if_stmt->Then( exp_stmt );
        if_stmt->Else( ManagedHandle::Retain<Empty>() );
      } else {
        current->AddChild( exp_stmt );
      }
      NodeList* body = AstUtils::CreateNodeList( 1 , first );
      Function* fn = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>() , ManagedHandle::Retain<Empty>() , body );
      fn->Accept( this );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->AddChild( fn );
      exp->Paren();
      Literal* this_sym = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kThis ),
                                                      Token::JS_THIS , ast_node->Line() , Literal::kThis );
      NodeList* arg = AstUtils::CreateNodeList( 1 , this_sym );
      CallExp* dot = AstUtils::CreateDotAccessor( exp , call_sym );
      CallExp* this_call = AstUtils::CreateNormalAccessor( dot , arg );
      ast_node->parent_node()->ReplaceChild( ast_node , this_call );
    }
      break;

    case Literal::kTuple : {
      Literal* object = ManagedHandle::Retain( new Literal( Literal::kObject ) );
      NodeList* list = ManagedHandle::Retain<NodeList>();
      NodeIterator iterator = ast_node->first_child()->ChildNodes();
      int count = 0;
      while ( iterator.HasNext() ) {
        char tmp[500];
        sprintf( tmp , "%d" , count );
        Literal* num = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , ast_node->Line() , Literal::kNumeric );
        AstNode* item = iterator.Next();
        item->Accept( this );
        num->AddChild( item );
        list->AddChild( num );
        count++;
      }
      char tmp[500];
      sprintf( tmp , "%d" , count );
      Literal* num = AstUtils::CreateNameNode( tmp , Token::JS_NUMERIC_LITERAL , ast_node->Line() , Literal::kNumeric );
      object->Node( list );
      Literal* create_tuple = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateTuple ),
                                                          Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
      CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( create_tuple );
      NodeList* args = AstUtils::CreateNodeList( 2 , object , num );
      CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args );
      ast_node->parent_node()->ReplaceChild( ast_node , runtime_call );
    }
      break;

    case Literal::kRecord : {
      visitor_info_->EnterObject();
      ObjectProccessor_( ast_node );
      visitor_info_->EscapeObject();
      ast_node->ValueType( Literal::kObject );
      AstNode* parent = ast_node->parent_node();
      Literal* create_record = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateRecord ),
                                                          Token::JS_PROPERTY , ast_node->Line() , Literal::kProperty );
      CallExp* runtime_accessor = AstUtils::CreateRuntimeMod( create_record );
      NodeList* args = AstUtils::CreateNodeList( 1 , ast_node );
      CallExp* runtime_call = AstUtils::CreateNormalAccessor( runtime_accessor , args );
      parent->ReplaceChild( ast_node , runtime_call );
    }
      break;
      
    case Literal::kObject : {
      visitor_info_->EnterObject();
      ObjectProccessor_( ast_node );
      visitor_info_->EscapeObject();
      
      if ( !visitor_info_->IsInObject() ) {
        if ( visitor_info_->GetObjectPrivateList().size() > 0 ) {
          AstNode* parent = ast_node->parent_node();
          while ( !parent->CastToStatement() ) {
            parent = parent->parent_node();
          }
          Literal* name = AstUtils::CreateTmpNode( visitor_info_->GetTmpIndex() );
          Literal* exp = AstUtils::CreateVarInitiliser( name->Symbol() , ast_node->Clone() );
          VariableStmt* stmt = AstUtils::CreateVarStmt( exp );
          parent->parent_node()->InsertBefore( stmt , parent );
          ast_node->Symbol( name->Symbol() );
          ast_node->ValueType( Literal::kIdentifier );
          ast_node->RemoveAllChild();
          ast_node->AddChild( name->Clone() );
          VisitorInfo::PrivateNameList &list = visitor_info_->GetObjectPrivateList();
          VisitorInfo::PrivateNameList::reverse_iterator begin = list.rbegin(),end = list.rend();
          while ( begin != end ) {
            std::list<Literal*> exp_list;
            AstNode* cur_name = (*begin).first;
            exp_list.push_back( cur_name->CastToLiteral() );
            //CallExp* exp =  AstUtils::CreateArrayAccessor( name->Clone() , cur_name->CastToLiteral()->Node()->Clone() );
            AstNode* name_parent = cur_name->parent_node();
            Literal* maybeValue = name_parent->CastToLiteral();
            while ( name_parent && ( ( name_parent->NodeType() == AstNode::kNodeList ) ||
                                     ( maybeValue && ( maybeValue->ValueType() == Literal::kPrivateProperty ||
                                                       maybeValue->ValueType() == Literal::kProperty ||
                                                       maybeValue->ValueType() == Literal::kString ||
                                                       maybeValue->ValueType() == Literal::kNumeric ||
                                                       maybeValue->ValueType() == Literal::kObject ) ) ) ) {
              Literal* val = name_parent->CastToLiteral();
              if ( val && val->ValueType() != Literal::kObject ) {
                exp_list.push_back( val );
              }
              name_parent = name_parent->parent_node();
              maybeValue = name_parent->CastToLiteral();
            }
            std::list<Literal*>::reverse_iterator exp_begin = exp_list.rbegin(),exp_end = exp_list.rend();
            CallExp* exp = 0;
            while ( exp_begin != exp_end ) {
              Literal* val = (*exp_begin);
              if ( val->ValueType() == Literal::kPrivateProperty ) {
                if ( exp == 0 ) {
                  exp =  AstUtils::CreateArrayAccessor( name->Clone() , (*exp_begin)->Node()->Clone() );
                } else {
                  exp =  AstUtils::CreateArrayAccessor( exp , (*exp_begin)->Node()->Clone() );
                }
              } else if ( val->ValueType() == Literal::kIdentifier || val->ValueType() == Literal::kProperty ) {
                val->ValueType( Literal::kProperty );
                if ( exp == 0 ) {
                  exp =  AstUtils::CreateDotAccessor( name->Clone() , (*exp_begin)->Clone() );
                } else {
                  exp =  AstUtils::CreateDotAccessor( exp , (*exp_begin)->Clone() );
                }
              } else {
                if ( exp == 0 ) {
                  exp =  AstUtils::CreateArrayAccessor( name->Clone() , (*exp_begin)->Clone() );
                } else {
                  exp =  AstUtils::CreateArrayAccessor( exp , (*exp_begin)->Clone() );
                }
              }
              ++exp_begin;
            }
            Literal* unenum = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kCreateUnenumProp ),
                                                          Token::JS_PROPERTY , 0 , Literal::kProperty );
            CallExp* runtime_call = AstUtils::CreateRuntimeMod( unenum );
            NodeList* args = AstUtils::CreateNodeList( 3 , exp->Callable() , exp->Args() , (*begin).second->Clone() );
            CallExp* runtime_normal_call = AstUtils::CreateNormalAccessor( runtime_call , args );
            ExpressionStmt* stmt = AstUtils::CreateExpStmt( runtime_normal_call );
            parent->parent_node()->InsertBefore( stmt , parent );
            ++begin;
          }
          list.clear();
        }
      }
    }
      break;

    case Literal::kPrivateProperty : {
      AstNode* node = ast_node->first_child();
      Literal* maybeObject = node->CastToLiteral();
      visitor_info_->SetObjectPrivate( VisitorInfo::AstPair( ast_node , ast_node->first_child() ) );
    }
      break;
      
    case Literal::kVariable :
      VariableProcessor::ProcessVarInitialiser( ast_node , proc_info_.Get() );
      break;

    case Literal::kDst :
    case Literal::kDstArray :
      DstaProcessor::ProcessNode( ast_node , proc_info_.Get() );
      break;

    case Literal::kRest : {
      visitor_info_->SetRestInjection( true );
      ast_node->ValueType( Literal::kIdentifier );
      ast_node->parent_node()->RemoveChild( ast_node );
      visitor_info_->SetRestExp( ast_node->Symbol() );
    }
      break;

    case Literal::kThis : {
      Function* fn = visitor_info_->GetFunction();
      if ( fn && fn->GetReplacedThis() ) {
        ast_node->Symbol( fn->GetReplacedThis()->Symbol() );
      }
    }
      break;

    case Literal::kSuper : {
      TokenInfo* info = ManagedHandle::Retain( new TokenInfo( SymbolList::GetSymbol( SymbolList::kSuper ) , Token::JS_IDENTIFIER , ast_node->Line() ) );
      ast_node->Symbol( info );
      ast_node->ValueType( Literal::kIdentifier );
    }
      break;
  }
}
}

