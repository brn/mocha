#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <utility>
#include <mocha/roaster/compiler.h>
#include <mocha/roaster/utils/compilation_info.h>
#include <mocha/roaster/consts/consts.h>
#include <mocha/roaster/scopes/scope.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/external/external_resource.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/visitors/codegen_visitor.h>
#include <mocha/roaster/ast/visitors/utils/codewriter.h>
#include <mocha/roaster/file_system/file_system.h>

namespace mocha {

#define TOKEN yy::ParserImplementation::token
#define VISITOR_IMPL(type) void CodegenVisitor::Visit##type(type* ast_node)
#define ITERATOR(name) begin = name.begin(),end = name.end()

#ifdef PRINTABLE
#define PRINT_NODE_NAME printf("depth = %d name = %s\n", depth_++, ast_node->node_name())
#else
#define PRINT_NODE_NAME
#endif

#define ACCEPT(ast)                             \
  if (ast != 0)                                 \
    ast->Accept(this)


inline void line_numberBreak(AstNode* ast_node, CodeStream* stream, CodeWriter* writer) {
  AstNode* parent = ast_node->parent_node();
  bool is_root_stmt = true;
  if (parent) {
    int node_type = parent->node_type();
    if (node_type == AstNode::kIFStmt ||
        node_type == AstNode::kWhile ||
        node_type == AstNode::kFor ||
        node_type == AstNode::kForIn ||
        node_type == AstNode::kDoWhile ||
        node_type == AstNode::kWithStmt ||
        node_type == AstNode::kCallExp ||
        node_type == AstNode::kFunction ||
        node_type == AstNode::kExpression ||
        (ast_node->node_type() == AstNode::kFunction &&
         node_type != AstNode::kExpression) ||
        (parent->parent_node() &&
         parent->parent_node()->node_type() == AstNode::kBlockStmt)) {
      if (ast_node->previous_sibling() == 0) {
        is_root_stmt = false;
      }
    }
  } else {
    return;
  }
  if (is_root_stmt) {
    writer->WriteOp('\n', 0, stream);
  }
}


CodegenVisitor::CodegenVisitor(const char* filename, CompilationInfo* info, Compiler* compiler) :
    depth_(0),is_line_(info->Debug()),has_rest_(false),
    is_pretty_print_(info->PrettyPrint()),filename_(filename), scope_(0),
    compiler_(compiler),
    stream_(new CodeStream(&default_buffer_)),
    writer_(new CodeWriter(info->PrettyPrint(), info->Debug())),
    current_root_(0){}

CodegenVisitor::CodegenVisitor(const char* filename, bool is_pretty_print, bool is_debug, Compiler* compiler) :
    depth_(0),is_line_(is_debug),has_rest_(false),
    is_pretty_print_(is_pretty_print), filename_(filename), scope_(0),
    compiler_(compiler),
    stream_(new CodeStream(&default_buffer_)),
    writer_(new CodeWriter(is_pretty_print, is_debug)),
    current_root_(0){}


VISITOR_IMPL(AstRoot) {
  PRINT_NODE_NAME;
  scope_ = ast_node->scope();
  stream()->Write("!function()");
  writer()->WriteOp('{', CodeWriter::kFunctionBeginBrace, stream());
  writer()->InitializeFileName("Runtime", stream());
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  writer()->WriteOp('}', CodeWriter::kArgs, stream());
  stream()->Write("()");
  writer()->WriteOp(';', 0, stream());
}


VISITOR_IMPL(FileRoot) {
  PRINT_NODE_NAME;
  current_root_ = ast_node;
  if (ast_node->IsStrict() && !is_line_) {
    stream()->Write("\"use strict\"");
    writer()->WriteOp(';', 0, stream());
  }
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    item->Accept(this);
  }
}


VISITOR_IMPL(NodeList) {
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(BlockStmt) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
  if (ast_node->child_length() > 0) {
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
    }
  }
  writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
  if (!MatchState_(Token::JS_IF)) {
    writer()->WriteOp(';', 0, stream());
  }
}



VISITOR_IMPL(ModuleStmt) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL(ExportStmt) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL(ImportStmt) {
  PRINT_NODE_NAME;
}



VISITOR_IMPL(Statement) {}

VISITOR_IMPL(VersionStmt) {
  const char* ver = ast_node->version()->token();
  if (compiler_->compilation_info()->HasVersion(ver)) {
    ast_node->first_child()->Accept(this);
  }
}

VISITOR_IMPL(AssertStmt) {
  PRINT_NODE_NAME;
  if (current_root_) {
    if (compiler_->compilation_info()->HasVersion(Consts::kVersionDebug)) {
      AstNode* first = ast_node->first_child();
      AstNode* second = first->next_sibling();
      first->Accept(this);
      if (second) {
        second->Accept(this);
      }
    }
  } else {
    AstNode* first = ast_node->first_child();
    AstNode* second = first->next_sibling();
    first->Accept(this);
    if (second) {
      second->Accept(this);
    }
  }
}

VISITOR_IMPL(StatementList) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* statement = iterator.Next();
    statement->Accept(this);
  }
}


void CodegenVisitor::VarListProcessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    if (!item->IsEmpty()) {
      item->Accept(this);
      if (iterator.HasNext()) {
        if (CurrentState_() == CodeWriter::kFor) {
          stream()->Write(',');
        } else {
          writer()->WriteOp(',', CodeWriter::kVarsComma, stream());
        }
      } else if (CurrentState_() != CodeWriter::kFunctionEndBrace) {
        if (CurrentState_() != CodeWriter::kFor) {
          writer()->WriteOp(';', CodeWriter::kVarsEnd, stream());
        }
      }
    }
  }
}



VISITOR_IMPL(VariableStmt) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(Token::JS_VAR, 0, stream());
  VarListProcessor_(ast_node->first_child());
}


VISITOR_IMPL(LetStmt) {}



VISITOR_IMPL(ExpressionStmt) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  ast_node->first_child()->Accept(this);
  writer()->WriteOp(';', 0, stream());
}


VISITOR_IMPL(IFStmt) {
  PRINT_NODE_NAME;
  if (!MatchState_(Token::JS_ELSE)) {
    line_numberBreak(ast_node, stream(), writer());
    writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  }
  writer()->WriteOp(Token::JS_IF, 0, stream());
  writer()->WriteOp('(', 0, stream());
  ast_node->condition()->Accept(this);
  writer()->WriteOp(')', 0, stream());
  AstNode* maybeBlock = ast_node->then_statement();
  AstNode* maybeElse = ast_node->else_statement();
        
  if (maybeBlock->node_type() == AstNode::kBlockStmt) {
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    NodeIterator iterator = maybeBlock->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
    if (maybeElse->IsEmpty()) {
      writer()->WriteOp(';', 0, stream());
    }
  } else {
    if (is_line_ || is_pretty_print_) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    }
    BeginState_(Token::JS_IF);
    ast_node->then_statement()->Accept(this);
    EndLastState_();
    if (is_line_ || is_pretty_print_) {
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
      if (maybeElse->IsEmpty()) {
        writer()->WriteOp(';', 0, stream());
      }
    }
  }
        
  if (!maybeElse->IsEmpty()) {
    writer()->WriteOp(Token::JS_ELSE, 0, stream());
    BeginState_(Token::JS_ELSE);
    if (maybeElse->node_type() == AstNode::kBlockStmt) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
      NodeIterator iterator = maybeElse->ChildNodes();
      while (iterator.HasNext()) {
        iterator.Next()->Accept(this);
      }
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
      writer()->WriteOp(';', 0, stream());
    } else if (maybeElse->node_type() == AstNode::kIFStmt) {
      maybeElse->Accept(this);
    } else {
      if (is_line_ || is_pretty_print_) {
        writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
      }
      maybeElse->Accept(this);
      if (is_line_ || is_pretty_print_) {
        writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
        writer()->WriteOp(';', 0, stream());
      }
    }
    EndLastState_();
  }
}


VISITOR_IMPL(IterationStmt) {
  PRINT_NODE_NAME;
  switch (ast_node->node_type()) {
    case AstNode::kFor : //Fall Through
    case AstNode::kForWithVar :
      ForProccessor_(ast_node);
      break;

    case AstNode::kForIn :
    case AstNode::kForInWithVar :
    case AstNode::kForEach :
    case AstNode::kForEachWithVar :
    case AstNode::kForOf :
    case AstNode::kForOfWithVar :
      ForInProccessor_(ast_node);
      break;

    case AstNode::kDoWhile :
      DoWhileProccessor_(ast_node);
      break;

    case AstNode::kWhile :
      WhileProccessor_(ast_node);
      break;
  }
}


void CodegenVisitor::ForProccessor_(IterationStmt* ast_node) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  AstNode* exp = ast_node->expression();
  writer()->WriteOp(Token::JS_FOR, 0, stream());
  writer()->WriteOp('(', 0, stream());
  if (ast_node->node_type() == AstNode::kForWithVar) {
    BeginState_(CodeWriter::kFor);
    writer()->WriteOp(Token::JS_VAR, CodeWriter::kFor, stream());
  }
        
  AstNode* index_exp = exp->first_child();
  AstNode* cond_exp = (index_exp)? index_exp->next_sibling() : 0;
  AstNode* incr_exp = (cond_exp)? cond_exp->next_sibling() : 0;

  if (ast_node->node_type() == AstNode::kForWithVar) {
    VarListProcessor_(index_exp);
    EndLastState_();
  } else {
    index_exp->Accept(this);
  }
  stream()->Write(';');
  if (cond_exp) {
    cond_exp->Accept(this);
  }
  stream()->Write(';');
  if (incr_exp) {
    incr_exp->Accept(this);
  }
  writer()->WriteOp(')', 0, stream());

  AstNode* maybeBlock = ast_node->first_child();
  if (maybeBlock->node_type() == AstNode::kBlockStmt) {
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    NodeIterator iterator = maybeBlock->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
    if (!MatchState_(Token::JS_IF)) {
      writer()->WriteOp(';', 0, stream());
    }
  } else {
    if (is_line_) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    }
    ast_node->first_child()->Accept(this);
    if (is_line_) {
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
      if (!MatchState_(Token::JS_IF)) {
        writer()->WriteOp(';', 0, stream());
      }
    }
  }
}

void CodegenVisitor::ForInProccessor_(IterationStmt* ast_node) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  int for_in_type = ast_node->node_type();
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  AstNode* exp = ast_node->expression();
  writer()->WriteOp(Token::JS_FOR, 0, stream());
  writer()->WriteOp('(', 0, stream());
  if (for_in_type == AstNode::kForInWithVar || for_in_type == AstNode::kForEachWithVar) {
    writer()->WriteOp(Token::JS_VAR, CodeWriter::kFor, stream());
  }
  AstNode* index_exp = exp->first_child();
  AstNode* target_exp = index_exp->next_sibling();
        
  if (for_in_type == AstNode::kForInWithVar || for_in_type == AstNode::kForEachWithVar) {
    Literal* var = index_exp->CastToLiteral();
    if (var) {
      VarInitialiserProccessor_(index_exp->CastToLiteral());
    }
  } else {
    index_exp->Accept(this);
  }
        
  writer()->WriteOp(Token::JS_IN, 0, stream());
  target_exp->Accept(this);
        
  writer()->WriteOp(')', 0, stream());
  AstNode* maybeBlock = ast_node->first_child();
  if (maybeBlock->node_type() == AstNode::kBlockStmt) {
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    NodeIterator iterator = maybeBlock->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
    if (!MatchState_(Token::JS_IF)) {
      writer()->WriteOp(';', 0, stream());
    }
  } else {
    if (is_line_) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    }
    ast_node->first_child()->Accept(this);
    if (is_line_) {
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
      if (!MatchState_(Token::JS_IF)) {
        writer()->WriteOp(';', 0, stream());
      }
    }
  }
}



void CodegenVisitor::WhileProccessor_(IterationStmt* ast_node) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  AstNode* exp = ast_node->expression();
  writer()->WriteOp(Token::JS_WHILE, 0, stream());
  writer()->WriteOp('(', 0, stream());
  BeginState_(CodeWriter::kExpSp);
  exp->Accept(this);
  EndLastState_();
  writer()->WriteOp(')', 0, stream());

  AstNode* maybeBlock = ast_node->first_child();
        
  if (maybeBlock->node_type() == AstNode::kBlockStmt) {
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    NodeIterator iterator = maybeBlock->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
    if (!MatchState_(Token::JS_IF)) {
      writer()->WriteOp(';', 0, stream());
    }
  } else {
    if (is_line_) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    }
    ast_node->first_child()->Accept(this);
    if (is_line_) {
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
      if (!MatchState_(Token::JS_IF)) {
        writer()->WriteOp(';', 0, stream());
      }
    }
  }
}


void CodegenVisitor::DoWhileProccessor_(IterationStmt* ast_node) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  AstNode* exp = ast_node->expression()->first_child();
  AstNode* maybeBlock = ast_node->first_child();


  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(Token::JS_DO, 0, stream());
  if (maybeBlock->node_type() == AstNode::kBlockStmt) {
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    if (maybeBlock->node_type() == AstNode::kBlockStmt) {
      NodeIterator iterator = maybeBlock->ChildNodes();
      while (iterator.HasNext()) {
        iterator.Next()->Accept(this);
      }
    } else {
      ast_node->first_child()->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
  } else {
    if (is_line_) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    }
    ast_node->first_child()->Accept(this);
    if (is_line_) {
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
    }
  }

  writer()->WriteOp(Token::JS_WHILE, 0, stream());
  writer()->WriteOp('(', 0, stream());
  exp->Accept(this);
  writer()->WriteOp(')', 0, stream());
  writer()->WriteOp(';', 0, stream());
}


void CodegenVisitor::JumpStmt_(AstNode* ast_node, int type) {
  PRINT_NODE_NAME;
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(type, 0, stream());
  AstNode* identifer = ast_node->first_child();
  if (!identifer->IsEmpty()) {
    writer()->Write(" ", stream());
    Literal* value = identifer->CastToLiteral();
    writer()->Write(value->value()->token(), stream());
  }
  writer()->WriteOp(';', 0, stream());
}


VISITOR_IMPL(ContinueStmt) {
  PRINT_NODE_NAME;
  JumpStmt_(ast_node, Token::JS_CONTINUE);
}

VISITOR_IMPL(BreakStmt) {
  PRINT_NODE_NAME;
  JumpStmt_(ast_node, Token::JS_BREAK);
}

VISITOR_IMPL(ReturnStmt) {
  PRINT_NODE_NAME;
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(Token::JS_RETURN, 0, stream());
  AstNode* identifer = ast_node->first_child();
  identifer->Accept(this);
  writer()->WriteOp(';', 0, stream());
}


VISITOR_IMPL(WithStmt) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(Token::JS_WITH, 0, stream());
  writer()->WriteOp('(', 0, stream());
  ast_node->expression()->Accept(this);
  writer()->WriteOp(')', 0, stream());

  AstNode* maybeBlock = ast_node->first_child();
  if (maybeBlock->node_type() == AstNode::kBlockStmt) {
    ast_node->first_child()->Accept(this);
  } else {
    if (is_line_) {
      writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    }
    ast_node->first_child()->Accept(this);
    if (is_line_) {
      writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
      writer()->WriteOp(';', 0, stream());
    }
  }
}

VISITOR_IMPL(SwitchStmt) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(Token::JS_SWITCH, 0, stream());
  writer()->WriteOp('(', 0, stream());
  ast_node->expression()->Accept(this);
  writer()->WriteOp(')', 0, stream());
  writer()->WriteOp('{', CodeWriter::kFunctionBeginBrace, stream());
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
  writer()->WriteOp('}', CodeWriter::kSwitchEndBrace, stream());
  writer()->WriteOp(';', 0, stream());
}

VISITOR_IMPL(CaseClause) {
  PRINT_NODE_NAME;
  AstNode* exp = ast_node->expression();
  if (!exp->IsEmpty()) {
    writer()->WriteOp(Token::JS_CASE, 0, stream());
    exp->Accept(this);
  } else {
    writer()->WriteOp(Token::JS_DEFAULT, 0, stream());
  }
  writer()->WriteOp(':', CodeWriter::kCase, stream());
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
  }
}


VISITOR_IMPL(LabelledStmt) {
  PRINT_NODE_NAME;
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  AstNode* symbol = ast_node->first_child();
  AstNode* statement = symbol->next_sibling();
  writer()->Write(symbol->CastToLiteral()->value()->token(), stream());
  writer()->WriteOp(':', 0, stream());
  if (is_line_ && statement->node_type() != AstNode::kBlockStmt) {
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
  }
  statement->Accept(this);
  if (is_line_ && statement->node_type() != AstNode::kBlockStmt) {
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
  }
}


VISITOR_IMPL(ThrowStmt) {
  PRINT_NODE_NAME;
  writer()->SetLine(ast_node->line_number(), stream(), current_root_);
  writer()->WriteOp(Token::JS_THROW, 0, stream());
  ast_node->expression()->Accept(this);
  writer()->WriteOp(';', 0, stream());
}


VISITOR_IMPL(TryStmt) {
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->WriteOp(Token::JS_TRY, 0, stream());
  AstNode* try_block = ast_node->first_child();
  writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
  NodeIterator try_iterator = try_block->ChildNodes();
  while (try_iterator.HasNext()) {
    AstNode* item = try_iterator.Next();
    item->Accept(this);
  }
  writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
        
  AstNode* catch_block = ast_node->catch_block();
  AstNode* finally_block = ast_node->finally_block();

  if (!catch_block->IsEmpty()) {
    writer()->WriteOp(Token::JS_CATCH, 0, stream());
    writer()->WriteOp('(', 0, stream());
    writer()->Write(catch_block->CastToLiteral()->value()->token(), stream());
    writer()->WriteOp(')',      0, stream());
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    NodeIterator iterator = catch_block->first_child()->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* item = iterator.Next();
      item->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
  }

  if (!finally_block->IsEmpty()) {
    writer()->WriteOp(Token::JS_FINALLY, 0, stream());
    writer()->WriteOp('{', CodeWriter::kBlockBeginBrace, stream());
    NodeIterator iterator = finally_block->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* item = iterator.Next();
      item->Accept(this);
    }
    writer()->WriteOp('}', CodeWriter::kBlockEndBrace, stream());
  }

  writer()->WriteOp(';', 0, stream());
}


void CodegenVisitor::ArrayAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  writer()->WriteOp('[', 0, stream());
  BeginState_(CodeWriter::kArgs);
  exp->args()->Accept(this);
  EndLastState_();
  writer()->WriteOp(']', 0, stream());
}


void CodegenVisitor::DotAccessorProccessor_(CallExp* exp) {
  exp->callable()->Accept(this);
  writer()->WriteOp('.', 0, stream());
  exp->args()->Accept(this);
}

void CodegenVisitor::NewCallProccessor_(CallExp* exp) {
}

void CodegenVisitor::NormalFunctionCall_(CallExp* exp) {
  AstNode* args = exp->args();
  exp->callable()->Accept(this);
  if (args->IsEmpty()) {
    writer()->Write("()", stream());
  } else {
    BeginState_(CodeWriter::kArgs);
    writer()->WriteOp('(', 0, stream());
    NodeIterator iterator = args->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
      if (iterator.HasNext()) {
        stream()->Write(',');
      }
    }
    EndLastState_();
    writer()->WriteOp(')', 0, stream());
  }
}


VISITOR_IMPL(CallExp) {
  PRINT_NODE_NAME;
  switch (ast_node->call_type()) {
    case CallExp::kNormal :
      NormalFunctionCall_(ast_node);
      break;

    case CallExp::kDot :
      DotAccessorProccessor_(ast_node);
      break;

    case CallExp::kBracket :
      ArrayAccessorProccessor_(ast_node);
      break;
  }
}


VISITOR_IMPL(NewExp) {
  PRINT_NODE_NAME;
  writer()->WriteOp(Token::JS_NEW, 0, stream());
  ast_node->first_child()->Accept(this);
}


VISITOR_IMPL(YieldExp) {}


VISITOR_IMPL(PostfixExp) {
  PRINT_NODE_NAME;
  ast_node->expression()->Accept(this);
  writer()->WriteOp(ast_node->operand(), 0, stream());
}


VISITOR_IMPL(UnaryExp) {
  PRINT_NODE_NAME;
  writer()->WriteOp(ast_node->operand(), 0, stream());
  ast_node->expression()->Accept(this);
}


VISITOR_IMPL(BinaryExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  writer()->WriteOp(ast_node->operand(), 0, stream());
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(CompareExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  writer()->WriteOp(ast_node->operand(), 0, stream());
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(ConditionalExp) {
  PRINT_NODE_NAME;
  ast_node->condition()->Accept(this);
  writer()->WriteOp('?', 0, stream());
  ast_node->case_true()->Accept(this);
  writer()->WriteOp(':', 0, stream());
  ast_node->case_false()->Accept(this);
}


VISITOR_IMPL(AssignmentExp) {
  PRINT_NODE_NAME;
  ast_node->left_value()->Accept(this);
  writer()->WriteOp(ast_node->operand(), 0, stream());
  ast_node->right_value()->Accept(this);
}


VISITOR_IMPL(Expression) {
  PRINT_NODE_NAME;
  if (ast_node->IsParenthesis()) {
    BeginState_(CodeWriter::kParenExp);
    writer()->WriteOp('(', 0, stream());
  }
  NodeIterator iterator = ast_node->ChildNodes();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(this);
    if (iterator.HasNext()) {
      writer()->WriteOp(',', 0, stream());
    }
  }
  if (ast_node->IsParenthesis()) {
    writer()->WriteOp(')', 0, stream());
    EndLastState_();
  }
}


void CodegenVisitor::PrototypeMemberProccessor(NodeIterator& iterator, AstNode* name, bool is_private) {
}


void CodegenVisitor::StaticMemberProccessor(NodeIterator& iterator, AstNode* name) {
}

VISITOR_IMPL(Trait) {
}

VISITOR_IMPL(Class) {
  PRINT_NODE_NAME;
  ast_node->first_child()->Accept(this);
}

VISITOR_IMPL(ClassProperties) {
        
}

VISITOR_IMPL(ClassExpandar) {
  PRINT_NODE_NAME;
}

VISITOR_IMPL(ClassMember) {
  PRINT_NODE_NAME;
}


VISITOR_IMPL(Function){
  PRINT_NODE_NAME;
  line_numberBreak(ast_node, stream(), writer());
  writer()->WriteOp(Token::JS_FUNCTION, 0, stream());
  ast_node->name()->Accept(this);
  scope_ = ast_node->scope();
  if (ast_node->argv()->IsEmpty()) {
    stream()->Write("()");
  } else {
    writer()->WriteOp('(', 0, stream());
    NodeIterator iterator = ast_node->argv()->ChildNodes();
    while (iterator.HasNext()) {
      iterator.Next()->Accept(this);
      if (iterator.HasNext()) {
        stream()->Write(',');
      }
    }
    writer()->WriteOp(')', 0, stream());
  }
  if (ast_node->child_length() == 0) {
    stream()->Write("{}");
  } else {
    writer()->WriteOp('{', CodeWriter::kFunctionBeginBrace, stream());
    if (ast_node->IsStrict() && !is_line_) {
      stream()->Write("\"use strict\"");
      writer()->WriteOp(';', 0, stream());
    }
    if (current_root_ && !current_root_->runtime()) {
      writer()->DebugBlockBegin(stream());
    }
    if (current_root_ && ast_node->IsRoot()) {
      writer()->InitializeFileName(current_root_->filename(), stream());
    }
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* node = iterator.Next();
      if (!node->IsEmpty()) {
        node->Accept(this);
      }
    }
    int state = CurrentState_();
    state = (state == CodeWriter::kArgs)? state :
        (MatchState_(CodeWriter::kParenExp))? CodeWriter::kArgs : CodeWriter::kFunctionEndBrace;
    if (current_root_ && !current_root_->runtime()) {
      writer()->DebugBlockEnd(stream(), scope_);
    }
    writer()->WriteOp('}', state, stream());
  }
  if (scope_) {
    scope_ = scope_->parent();
  }
};


void CodegenVisitor::ArrayProccessor_(AstNode* ast_node) {
  PRINT_NODE_NAME;
  writer()->WriteOp('[', 0, stream());
  NodeIterator iter = ast_node->ChildNodes();
  while (iter.HasNext()) {
    AstNode* element = iter.Next();
    if (!element->IsEmpty()) {
      element->Accept(this);
    }
    if (iter.HasNext()) {
      stream()->Write(',');
    }
  }
  writer()->WriteOp(']', 0, stream());
}


void CodegenVisitor::ObjectProccessor_(NodeList* ast_node) {
  PRINT_NODE_NAME;
  if (ast_node->child_length() == 0) {
    stream()->Write("{}");
  } else {
    writer()->WriteOp('{', CodeWriter::kArgs, stream());
    NodeIterator iterator = ast_node->ChildNodes();
    while (iterator.HasNext()) {
      AstNode* element = iterator.Next();
      Literal* val = element->CastToLiteral();
      if ((val && element->CastToLiteral()->value_type() != Literal::kPrivateProperty) || !val) {
        element->Accept(this);
        writer()->WriteOp(':', 0, stream());
        element->first_child()->Accept(this);
        if (iterator.HasNext()) {
          writer()->WriteOp(',', CodeWriter::kVarsComma, stream());
        }
      }
    }
    writer()->WriteOp('}', CodeWriter::kArgs, stream());
  }
}


void CodegenVisitor::VarInitialiserProccessor_(Literal* ast_node) {
  PRINT_NODE_NAME;
  if (ast_node->value_type() == Literal::kVariable) {
    ast_node->set_value_type(Literal::kIdentifier);
    ast_node->Accept(this);
  }
  AstNode* initialiser = ast_node->first_child();
  if (!initialiser->IsEmpty()) {
    writer()->WriteOp('=', 0, stream());
    initialiser->Accept(this);
  }
}


VISITOR_IMPL(Literal) {
  switch (ast_node->value_type()) {
    case Literal::kVariable :
      VarInitialiserProccessor_(ast_node);
      break;

    case Literal::kProperty :
      stream()->Write(ast_node->value()->token());
      break;
                        
    case Literal::kIdentifier : {
      const char* symbol = ast_node->value()->token();
      if (symbol[ 0 ] == '@') {
        std::string tmp = symbol;
        if (strlen(symbol) > 1) {
          stream()->Write("this.");
          tmp.erase(0, 1);
        } else {
          stream()->Write("this");
        }
        stream()->Write(tmp.c_str());
      } else {
        if (scope_) {
          SymbolEntry entry = scope_->Find(ast_node->value());
          if (entry.first != 0) {
            TokenInfo *info = entry.first;
            stream()->Write(info->compressed_name());
            //stream()->Write("/*");
            //stream()->Write(symbol);
            //stream()->Write("*/");
          } else {
            stream()->Write(symbol);
          }
        } else {
          stream()->Write(symbol);
        }
      }
    }
      break;
                        
    case Literal::kRest :
    case Literal::kPrivateProperty :
      return;
      break;

    default :
      stream()->Write(ast_node->value()->token());
  }
}

VISITOR_IMPL(ArrayLikeLiteral) {
  PRINT_NODE_NAME;
  ArrayProccessor_(ast_node->elements());
}

VISITOR_IMPL(ObjectLikeLiteral) {
  PRINT_NODE_NAME;
  ObjectProccessor_(ast_node->elements());
}

VISITOR_IMPL(VariableDeclarationList) {
  VarListProcessor_(ast_node);
}

VISITOR_IMPL(GeneratorExpression) {
  PRINT_NODE_NAME;
}


void CodegenVisitor::BeginState_(int state) {
  state_.push_back(state);
}

void CodegenVisitor::EndLastState_() {
  state_.pop_back();
}

int CodegenVisitor::CurrentState_() {
  return (state_.size() > 0)? state_.back() : 0;
}

bool CodegenVisitor::MatchState_(int state) {
  std::vector<int>::iterator begin = state_.begin(),end = state_.end();
  while (begin != end) {
    if ((*begin) == state) {
      return true;
    }
    ++begin;
  }
  return false;
}


}

