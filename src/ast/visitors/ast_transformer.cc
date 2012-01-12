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
#include <ast/ast.h>
#include <utils/file_system/virtual_directory.h>
#include <utils/pool/managed_handle.h>
#include <ast/utils/ast_utils.h>
#include <ast/visitors/utils/visitor_info.h>
#include <ast/visitors/utils/processors/dsta_processor.h>
#include <ast/visitors/utils/processors/iteration_processor.h>
#include <ast/visitors/utils/processors/variable_processor.h>
#include <ast/visitors/utils/processors/class_processor.h>
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
                                    compiler ,
                                    ManagedHandle::Retain<DstaExtractedExpressions>() , main_file_path , filename ) ) {
  proc_info_( new ProcessorInfo( this , scope , visitor_info_.Get() ) );
}

AstTransformer::~AstTransformer () {}


VISITOR_IMPL( AstRoot ) {
  PRINT_NODE_NAME;
  AstNode* root = ast_node->FirstChild();
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
  const char* ver = ast_node->Ver()->GetToken();
  ast_node->FirstChild()->Accept( this );
  if ( visitor_info_->HasVersion( ver ) ) {
    Function *fn_node = AstUtils::CreateFunctionDecl( ManagedHandle::Retain<Empty>(),
                                                      ManagedHandle::Retain<Empty>() , ast_node->FirstChild() );
    ExpressionStmt* an_stmt_node = AstUtils::CreateAnonymousFnCall( fn_node , ManagedHandle::Retain<Empty>() );
    ast_node->ParentNode()->ReplaceChild( ast_node , an_stmt_node );
  } else {
    ast_node->ParentNode()->RemoveChild( ast_node );
  }
}


VISITOR_IMPL( PragmaStmt ) {
  AstNode* body = ast_node->FirstChild();
  int type = CompileInfo::GetType( ast_node->Op() );
  if ( body->NodeType() == AstNode::kBlockStmt ) {
    NodeIterator iter = body->FirstChild()->ChildNodes();
    while ( iter.HasNext() ) {
      AstNode* item = iter.Next();
      CompileInfo* info = ManagedHandle::Retain<CompileInfo>();
      if ( ast_node->GetInfo() ) {
        info->Type( ast_node->GetInfo()->Type() );
      }
      info->Type( type );
      item->SetInfo( info );
      item->Accept( this );
    }
  } else {
    CompileInfo* info = ManagedHandle::Retain<CompileInfo>();
    if ( ast_node->GetInfo() ) {
      info->Type( ast_node->GetInfo()->Type() );
    }
    info->Type( type );
    body->SetInfo( info );
    body->Accept( this );
  }
}


VISITOR_IMPL( BlockStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
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
  if ( ast_node->HasDsta() ) {
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
  ast_node->FirstChild()->Accept( this );
  if ( ast_node->HasDsta() ) {
    NodeIterator iterator = ast_node->GetDsta()->Refs()->ChildNodes();
    NodeList* var_list = ManagedHandle::Retain<NodeList>();
    while ( iterator.HasNext() ) {
      ValueNode* node = AstUtils::CreateVarInitiliser( iterator.Next()->CastToValue()->Symbol() , ManagedHandle::Retain<Empty>() );
      var_list->AddChild( node );
    }
    VariableStmt *var_stmt = AstUtils::CreateVarStmt( var_list );
    ast_node->ParentNode()->InsertBefore( var_stmt , ast_node );
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    exp->Paren();
    ExpressionStmt* stmt = AstUtils::CreateExpStmt( exp );
    ast_node->ParentNode()->InsertAfter( stmt , ast_node );
  }
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->Exp()->Accept( this );
  AstNode* maybeBlock = ast_node->Then();
  AstNode* maybeElse = ast_node->Else();
  ast_node->Then()->Accept( this );
  if ( ast_node->HasDsta() ) {
    if ( maybeBlock->NodeType() == AstNode::kBlockStmt ) {
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      maybeBlock->FirstChild()->InsertBefore( exp_stmt );
    } else {
      BlockStmt *block = ManagedHandle::Retain<BlockStmt>();
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      StatementList* stmt_list = ManagedHandle::Retain<StatementList>();
      stmt_list->AddChild( exp_stmt );
      stmt_list->AddChild( maybeBlock->Clone() );
      block->AddChild( stmt_list );
      ast_node->Then()->RemoveAllChild();
      ast_node->Then( block );
    }
    AstNode* parent = ast_node;
    AstNode* first_if = ast_node;
    while ( parent->NodeType() == AstNode::kIFStmt ) {
      parent = parent->ParentNode();
      if ( parent->NodeType() != AstNode::kIFStmt ) {
        break;
      } else {
        first_if = parent;
      }
    }
    if ( first_if->HasPrev() && first_if->PreviousSibling()->NodeType() == AstNode::kVariableStmt ) {
      first_if->PreviousSibling()->Append( DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() ) );
    } else {
      parent->InsertBefore( DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() ), first_if );
    }
  }
  if ( !maybeElse->IsEmpty() ) {
    maybeElse->Accept( this );
  }
  if ( ast_node->GetYieldFlag() ) {
    visitor_info_->GetFunction()->SetStmtWithYield( ast_node );
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
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( BreakStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
}

VISITOR_IMPL( ReturnStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
}


VISITOR_IMPL( WithStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->Exp();
  AstNode* body = ast_node->FirstChild();
  exp->Accept( this );
  body->Accept( this );
  if ( ast_node->HasDsta() ) {
    VariableStmt* var_stmt = DstaProcessor::CreateTmpVarDecl( ast_node , proc_info_.Get() );
    ast_node->ParentNode()->InsertBefore( var_stmt , ast_node );
    if ( body->NodeType() == AstNode::kBlockStmt ) {
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      body->FirstChild()->InsertBefore( exp_stmt );
    } else {
      BlockStmt* block = ManagedHandle::Retain<BlockStmt>();
      StatementList* stmt_list = ManagedHandle::Retain<StatementList>();
      NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( ast_node , proc_info_.Get() );
      Expression* exp = ManagedHandle::Retain<Expression>();
      exp->Append( list );
      exp->Paren();
      ExpressionStmt* exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
      exp_stmt->AddChild( exp );
      stmt_list->AddChild( exp_stmt );
      stmt_list->AddChild( body->Clone() );
      block->AddChild( stmt_list );
      ast_node->RemoveAllChild();
      ast_node->AddChild( block );
    }
  }
}

VISITOR_IMPL( SwitchStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* exp = ast_node->Exp();
  exp->Accept( this );
  NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
  while ( iterator.HasNext() ) {
    iterator.Next()->Accept( this );
  }
}


VISITOR_IMPL( CaseClause ) {
  PRINT_NODE_NAME;
  Statement* stmt_tmp = ManagedHandle::Retain<Statement>();
  REGIST(stmt_tmp);
  AstNode *parent = ast_node->ParentNode();
  SwitchStmt *switch_stmt = reinterpret_cast<SwitchStmt* >( parent->ParentNode() );
  ast_node->Exp()->Accept( this );
  AstNode *node = ast_node->FirstChild();
  node->Accept( this );
  ExpressionStmt* case_exp_stmt = 0;
  ExpressionStmt* cond_exp_stmt = 0;
  if ( stmt_tmp->HasDsta() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( stmt_tmp , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    exp->Paren();
    case_exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    case_exp_stmt->AddChild( exp );
    if ( !node->IsEmpty() ) {
      node->InsertBefore( case_exp_stmt );
    } else {
      StatementList* list = ManagedHandle::Retain<StatementList>();
      list->AddChild( case_exp_stmt );
      ast_node->RemoveAllChild();
      ast_node->AddChild( list );
      node = list;
    }
  }
  if ( switch_stmt->HasDsta() ) {
    NodeList* list = DstaProcessor::CreateDstaExtractedAssignment( switch_stmt , proc_info_.Get() );
    Expression* exp = ManagedHandle::Retain<Expression>();
    exp->Append( list );
    exp->Paren();
    cond_exp_stmt = ManagedHandle::Retain<ExpressionStmt>();
    cond_exp_stmt->AddChild( exp );
    if ( !node->IsEmpty() ) {
      node->InsertBefore( cond_exp_stmt );
    } else {
      StatementList* list = ManagedHandle::Retain<StatementList>();
      list->AddChild( case_exp_stmt );
      node->RemoveAllChild();
      node->AddChild( list );
    }
  }

}


VISITOR_IMPL( LabelledStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  AstNode* symbol = ast_node->FirstChild();
  AstNode* statement = symbol->NextSibling();
  symbol->Accept( this );
  statement->Accept( this );
}


VISITOR_IMPL( ThrowStmt ) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->Exp()->Accept( this );
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  REGIST(ast_node);
  ast_node->FirstChild()->Accept( this );
  ast_node->Catch()->Accept( this );
  ast_node->Finally()->Accept( this );
  if ( ast_node->GetYieldFlag() ) {
    visitor_info_->GetFunction()->SetTryCatch( ast_node );
  }
}


VISITOR_IMPL( CallExp ) {
  PRINT_NODE_NAME;
  switch ( ast_node->CallType() ) {
    case CallExp::kNormal :
    case CallExp::kNew :
      CallProcessor::ProcessFnCall( ast_node , proc_info_.Get() );
      break;

    case CallExp::kDot :
    case CallExp::kBracket : {
      AstNode* args = ast_node->Args();
      if ( args->CastToValue() && args->CastToValue()->ValueType() == ValueNode::kObject ) {
        CallProcessor::ProcessExtendAccessor( ast_node , proc_info_.Get() );
      } else {
        ast_node->Callable()->Accept( this );
        args->Accept( this );
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
  ast_node->Constructor()->Accept( this );
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
  cls->ProcessNode();
}

VISITOR_IMPL(ClassProperties) {}

VISITOR_IMPL(ClassExpandar) {}

VISITOR_IMPL(ClassMember) {}

VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  FunctionProcessor processor( ast_node , proc_info_.Get() );
  processor.ProcessNode();
};


void AstTransformer::ArrayProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* list_child = ast_node->FirstChild();
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


void AstTransformer::ObjectProccessor_( ValueNode* ast_node ) {
  PRINT_NODE_NAME;
  AstNode* element_list = ast_node->Node();
  if ( !element_list->IsEmpty() ) {
    NodeIterator iterator = element_list->ChildNodes();
    while ( iterator.HasNext() ) {
      AstNode* element = iterator.Next();
      element->FirstChild()->Accept( this );
      element->Accept( this );
    }
  }
}



VISITOR_IMPL( ValueNode ) {
  PRINT_NODE_NAME;
  switch ( ast_node->ValueType() ) {
    case ValueNode::kArray :
      ArrayProccessor_( ast_node );
      break;

    case ValueNode::kArrayComp : {
      ValueNode* tmp = AstUtils::CreateTmpNode( visitor_info_->GetTmpIndex() );
      ValueNode* array = ManagedHandle::Retain( new ValueNode( ValueNode::kArray ) );
      VariableStmt* var_stmt = AstUtils::CreateVarStmt( AstUtils::CreateVarInitiliser( tmp->Symbol() , array ) );
      NodeIterator iterator = ast_node->FirstChild()->ChildNodes();
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
      ValueNode* push = AstUtils::CreateNameNode( SymbolList::GetSymbol( SymbolList::kPush ),
                                                  Token::JS_PROPERTY , 0 , ValueNode::kProperty );
      NodeList* list = ManagedHandle::Retain<NodeList>();
      list->AddChild( ast_node->Node()->Clone() );
      CallExp* push_call = AstUtils::CreateNormalAccessor( push , list );
      CallExp* push_accessor = AstUtils::CreateDotAccessor( tmp->Clone() , push_call );
      ExpressionStmt* exp_stmt = AstUtils::CreateExpStmt( push_accessor );
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
      ExpressionStmt* result = AstUtils::CreateAnonymousFnCall( fn , ManagedHandle::Retain<Empty>() );
      ast_node->ParentNode()->ReplaceChild( ast_node , result );
    }
      break;
      
    case ValueNode::kObject : {
      visitor_info_->EnterObject();
      ObjectProccessor_( ast_node );
      visitor_info_->EscapeObject();
      
      if ( !visitor_info_->IsInObject() ) {
        if ( visitor_info_->GetObjectPrivateList().size() > 0 ) {
          AstNode* parent = ast_node->ParentNode();
          while ( !parent->CastToStatement() ) {
            parent = parent->ParentNode();
          }
          ValueNode* name = AstUtils::CreateTmpNode( visitor_info_->GetTmpIndex() );
          ValueNode* exp = AstUtils::CreateVarInitiliser( name->Symbol() , ast_node->Clone() );
          VariableStmt* stmt = AstUtils::CreateVarStmt( exp );
          parent->ParentNode()->InsertBefore( stmt , parent );
          ast_node->Symbol( name->Symbol() );
          ast_node->ValueType( ValueNode::kIdentifier );
          ast_node->RemoveAllChild();
          ast_node->AddChild( name->Clone() );
          VisitorInfo::PrivateNameList &list = visitor_info_->GetObjectPrivateList();
          VisitorInfo::PrivateNameList::reverse_iterator begin = list.rbegin(),end = list.rend();
          while ( begin != end ) {
            std::list<ValueNode*> exp_list;
            AstNode* cur_name = (*begin).first;
            exp_list.push_back( cur_name->CastToValue() );
            //CallExp* exp =  AstUtils::CreateArrayAccessor( name->Clone() , cur_name->CastToValue()->Node()->Clone() );
            AstNode* name_parent = cur_name->ParentNode();
            ValueNode* maybeValue = name_parent->CastToValue();
            while ( name_parent && ( ( name_parent->NodeType() == AstNode::kNodeList ) ||
                                     ( maybeValue && ( maybeValue->ValueType() == ValueNode::kPrivateProperty ||
                                                       maybeValue->ValueType() == ValueNode::kProperty ||
                                                       maybeValue->ValueType() == ValueNode::kString ||
                                                       maybeValue->ValueType() == ValueNode::kNumeric ||
                                                       maybeValue->ValueType() == ValueNode::kObject ) ) ) ) {
              ValueNode* val = name_parent->CastToValue();
              if ( val && val->ValueType() != ValueNode::kObject ) {
                exp_list.push_back( val );
              }
              name_parent = name_parent->ParentNode();
              maybeValue = name_parent->CastToValue();
            }
            std::list<ValueNode*>::reverse_iterator exp_begin = exp_list.rbegin(),exp_end = exp_list.rend();
            CallExp* exp = 0;
            while ( exp_begin != exp_end ) {
              ValueNode* val = (*exp_begin);
              if ( val->ValueType() == ValueNode::kPrivateProperty ) {
                if ( exp == 0 ) {
                  exp =  AstUtils::CreateArrayAccessor( name->Clone() , (*exp_begin)->Node()->Clone() );
                } else {
                  exp =  AstUtils::CreateArrayAccessor( exp , (*exp_begin)->Node()->Clone() );
                }
              } else if ( val->ValueType() == ValueNode::kIdentifier || val->ValueType() == ValueNode::kProperty ) {
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
            AssignmentExp* assign = AstUtils::CreateAssignment( '=' , exp , (*begin).second->Clone() );
            ExpressionStmt* stmt = AstUtils::CreateExpStmt( assign );
            parent->ParentNode()->InsertBefore( stmt , parent );
            ++begin;
          }
          list.clear();
        }
      }
    }
      break;

    case ValueNode::kPrivateProperty : {
      AstNode* node = ast_node->FirstChild();
      ValueNode* maybeObject = node->CastToValue();
      visitor_info_->SetObjectPrivate( VisitorInfo::AstPair( ast_node , ast_node->FirstChild() ) );
    }
      break;
      
    case ValueNode::kVariable :
      VariableProcessor::ProcessVarInitialiser( ast_node , proc_info_.Get() );
      break;

    case ValueNode::kDst :
    case ValueNode::kDstArray :
      DstaProcessor::ProcessNode( ast_node , proc_info_.Get() );
      break;

    case ValueNode::kRest : {
      visitor_info_->SetRestInjection( true );
      ast_node->ValueType( ValueNode::kIdentifier );
      ast_node->ParentNode()->RemoveChild( ast_node );
      visitor_info_->SetRestExp( ast_node->Symbol() );
    }
      break;
  }
}
}

