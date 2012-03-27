#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/translator/processors/export_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>
#include <mocha/roaster/nexc/tokens/token_info.h>

namespace mocha {

ExportProcessor::ExportProcessor(ExportStmt* stmt, ProcessorInfo* info) :
    stmt_(stmt), info_(info){}

void ExportProcessor::ProcessNode() {
  IVisitor *visitor = info_->visitor();
  AstNode* node = stmt_->first_child();
  node->Accept(visitor);
  if (node->node_type() == AstNode::kFunction) {
    ProcessFunction(node);
  } else if (node->node_type() == AstNode::kVariableDeclarationList) {
    ProcessNodeList(node);
  }
}


void ExportProcessor::ProcessFunction(AstNode* node) {
  Function* fn = node->CastToExpression()->CastToFunction();
  info_->translator_data()->set_function(fn);
  Literal* name = fn->name()->CastToLiteral();
  Literal* local = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                             Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
  Literal* property_name = name->Clone(pool())->CastToLiteral();
  property_name->set_value_type(Literal::kProperty);
  CallExp *export_prop = builder()->CreateDotAccessor(local, property_name, node->line_number());
  AssignmentExp* assign = builder()->CreateAssignment('=', export_prop, name->Clone(pool()), node->line_number());
  fn->MarkAsDeclaration();
  ExpressionStmt* exp_stmt = builder()->CreateExpStmt(assign, node->line_number());
  AstNode* parent = stmt_->parent_node();
  parent->ReplaceChild(stmt_, fn);
  parent->InsertAfter(exp_stmt, fn);
}



void ExportProcessor::ProcessNodeList(AstNode* node) {
  AstNode* stmt = CreateAssignment(node);
  stmt_->parent_node()->ReplaceChild(stmt_, stmt);
}


AstNode* ExportProcessor::CreateAssignment(AstNode* node) {
  NodeIterator iterator = node->ChildNodes();
  VariableDeclarationList* list = node->CastToExpression()->CastToVariableDeclarationList();
  bool is_const = list->IsDeclaredAsConst();
  while (iterator.HasNext()) {
    AstNode *item = iterator.Next();
    TokenInfo *name_info = item->CastToLiteral()->value();
    Literal *name = builder()->CreateNameNode(name_info->token(), Token::JS_IDENTIFIER,
                                              stmt_->line_number(), Literal::kProperty);
    Literal *local = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kLocalExport),
                                               Token::JS_IDENTIFIER, stmt_->line_number(), Literal::kIdentifier);
    CallExp *export_prop = builder()->CreateDotAccessor(local, name, node->line_number());
    if (is_const) {
      if (!item->first_child()->IsEmpty()) {
        CallExp* constant_prop = builder()->CreateConstantProp(local, name, item->first_child(), node->line_number());
        return builder()->CreateExpStmt(constant_prop, node->line_number());
      } else {
        AstNode* target = name->Clone(pool());
        if (target->CastToLiteral()) {
          Literal* target_name = target->CastToLiteral();
          target_name->set_value_type(Literal::kIdentifier);
        }
        CallExp* constant_prop = builder()->CreateConstantProp(local, name, target, node->line_number());
        return builder()->CreateExpStmt(constant_prop, node->line_number());
      }
    } else {
      AssignmentExp* assign;
      if (!item->first_child()->IsEmpty()) {
        assign = builder()->CreateAssignment('=', export_prop, item->first_child(), node->line_number());
        Literal *val = builder()->CreateVarInitiliser(name->value(), assign, node->line_number());
        VariableDeclarationList* list = builder()->CreateVarDeclList(node->line_number(), 1, val);
        VariableStmt* var_stmt = builder()->CreateVarStmt(list, node->line_number());
        return var_stmt;
      } else {
        AstNode* target = name->Clone(pool());
        if (target->CastToLiteral()) {
          Literal* target_name = target->CastToLiteral();
          target_name->set_value_type(Literal::kIdentifier);
        }
        assign = builder()->CreateAssignment('=', export_prop, target, node->line_number());
        return builder()->CreateExpStmt(assign, node->line_number());
      }
    }
  }
  return new(pool()) Empty;
}
}
