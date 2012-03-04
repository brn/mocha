#include <mocha/roaster/ast/visitors/utils/processors/object_processor.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/syntax_sugar_processor.h>
#include <mocha/roaster/tokens/token_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/symbol_list.h>
namespace mocha {

ObjectProccessor::ObjectProccessor(ObjectLikeLiteral* literal, ProcessorInfo* info) :
    literal_(literal), info_(info){}

void ObjectProccessor::ProcessNode() {
  VisitorInfo* visitor_info = info_->visitor_info();
  visitor_info->EnterObject();
  NodeIterator iterator = literal_->elements()->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* element = iterator.Next();
    element->first_child()->Accept(info_->visitor());
    element->Accept(info_->visitor());
  }
  visitor_info->EscapeObject();
  if (literal_->IsRecord()) {
    ProcessRecord();
  } else {
    if (!visitor_info->IsInObject()) {
      if (visitor_info->private_property_list()->size() > 0) {
        AstNode* parent = literal_->parent_node();
        while (!parent->CastToStatement()) {
          parent = parent->parent_node();
        }
        Literal* name = builder()->CreateTmpNode(visitor_info->tmp_index(), literal_->line_number());
        Literal* exp = builder()->CreateVarInitiliser(name->value(), literal_->Clone(pool()), literal_->line_number());
        VariableDeclarationList* decl_list = builder()->CreateVarDeclList(literal_->line_number(), 1, exp);
        VariableStmt* stmt = builder()->CreateVarStmt(decl_list, literal_->line_number());
        parent->parent_node()->InsertBefore(stmt, parent);
        literal_->parent_node()->ReplaceChild(literal_, name->Clone(pool()));
        ProcessPrivateProperty(name);
      }
    }
  }
}


typedef std::vector<Literal*> LiteralArray;

void CollectParentExpression(LiteralArray* expression_array, AstNode* parent, Literal* maybe_value) {
  while (1) {
    if (parent->CastToExpression() && parent->node_type() != AstNode::kObjectLikeLiteral) {
      expression_array->push_back(parent->CastToLiteral());
    }
    parent = parent->parent_node();
    if (parent->node_type() == AstNode::kObjectLikeLiteral &&
         parent->parent_node()->parent_node()->node_type() != AstNode::kObjectLikeLiteral) {
      break;
    }
  }
}

void ObjectProccessor::ProcessPrivateProperty(Literal *name) {
  VisitorInfo::PrivateNameList *list = info_->visitor_info()->private_property_list();
  VisitorInfo::PrivateNameList::reverse_iterator begin = list->rbegin(),end = list->rend();
  while (begin != end) {
    LiteralArray expression_array;
    AstNode* cur_name = (*begin).first;
    expression_array.push_back(cur_name->CastToLiteral());
    AstNode* statement = literal_->parent_node();
    while (!statement->CastToStatement()) {
      statement = statement->parent_node();
    }
    AstNode* parent = cur_name->parent_node();
    Literal* maybe_value = parent->CastToLiteral();
    CollectParentExpression(&expression_array, parent, maybe_value);
    LiteralArray::reverse_iterator expression_begin = expression_array.rbegin();
    LiteralArray::reverse_iterator expression_end = expression_array.rend();
    CallExp* exp = 0;
    while (expression_begin != expression_end) {
      Literal* val = (*expression_begin);
      if (val->value_type() == Literal::kPrivateProperty) {
        if (exp == 0) {
          exp =  builder()->CreateArrayAccessor(name->Clone(pool()), val->node()->Clone(pool()), literal_->line_number());
        } else {
          exp =  builder()->CreateArrayAccessor(exp, val->node()->Clone(pool()), literal_->line_number());
        }
      } else if (val->value_type() == Literal::kIdentifier ||
                  val->value_type() == Literal::kProperty) {
        val->set_value_type(Literal::kProperty);
        if (exp == 0) {
          exp =  builder()->CreateDotAccessor(name->Clone(pool()), val->Clone(pool()), literal_->line_number());
        } else {
          exp =  builder()->CreateDotAccessor(exp, val->Clone(pool()), literal_->line_number());
        }
      } else {
        if (exp == 0) {
          exp =  builder()->CreateArrayAccessor(name->Clone(pool()), val->Clone(pool()), literal_->line_number());
        } else {
          exp =  builder()->CreateArrayAccessor(exp, val->Clone(pool()), literal_->line_number());
        }
      }
      ++expression_begin;
    }
    Literal* unenum = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCreateUnenumProp),
                                                Token::JS_IDENTIFIER, literal_->line_number(), Literal::kProperty);
    CallExp* runtime_call = builder()->CreateRuntimeMod(unenum, literal_->line_number());
    NodeList* args = builder()->CreateNodeList(3, exp->callable(), exp->args(), (*begin).second->Clone(pool()));
    CallExp* runtime_normal_call = builder()->CreateNormalAccessor(runtime_call, args, literal_->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(runtime_normal_call, literal_->line_number());
    statement->parent_node()->InsertBefore(stmt, statement);
    ++begin;
  }
  list->clear();
}

void ObjectProccessor::ProcessRecord() {
  AstNode* parent = literal_->parent_node();
  Literal* create_record = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kCreateRecord),
                                                     Token::JS_IDENTIFIER, literal_->line_number(), Literal::kProperty);
  CallExp* runtime_accessor = builder()->CreateRuntimeMod(create_record, literal_->line_number());
  NodeList* args = builder()->CreateNodeList(1, literal_);
  CallExp* runtime_call = builder()->CreateNormalAccessor(runtime_accessor, args, literal_->line_number());
  parent->ReplaceChild(literal_, runtime_call);
}

}
