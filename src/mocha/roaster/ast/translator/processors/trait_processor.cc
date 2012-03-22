#include <sstream>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/trait_processor.h>
#include <mocha/roaster/tokens/symbol_list.h>
#include <mocha/roaster/tokens/js_token.h>
namespace mocha {

TraitProcessor::TraitProcessor(Trait* trait, ProcessorInfo* info)
    : Processor(), trait_(trait), info_(info) {}

void TraitProcessor::ProcessNode() {
  TranslatorData* translator_data = info_->translator_data();
  AstNode* name = trait_->name();
  name_ = (!name->IsEmpty())? name->CastToLiteral() : builder()->CreateTmpNode(visitor_info->tmp_index(), trait_->line_number());
  ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(trait_->line_number());
  NodeList* list = new(pool()) NodeList;
  AstNode* parent = trait_->parent_node();
  if (trait_->IsDeclared()) {
    body_ = trait_->parent_node();
    Literal* name_value = name_->Clone(pool())->CastToLiteral();
    name_value->set_value_type(Literal::kVariable);
    name_value->AddChild(object);
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(trait_->line_number(), 1, name_value);
    VariableStmt* stmt = builder()->CreateVarStmt(decl_list, trait_->line_number());
    parent->ReplaceChild(trait_, stmt);
    ProcessPrivate(list);
    ProcessPublic(list);
    ProcessRequires(list);
    CreateMixinStmt(ProcessMixin(trait_->mixin_member(), info_ ,trait_->line_number()), stmt);
  } else {
    Function* fn = builder()->CreateFunctionDecl(new(pool()) Empty, new(pool()) Empty ,
                                                  new(pool()) Empty, trait_->line_number());
    fn->RemoveAllChild();
    ExpressionStmt* stmt = builder()->CreateAnonymousFnCall(fn, new(pool()) Empty, trait_->line_number());
    body_ = stmt->first_child()->CastToExpression()->CastToCallExp()->callable()->first_child();
    parent->ReplaceChild(trait_, stmt->first_child());
    ReturnStmt* ret = builder()->CreateReturnStmt(name_->Clone(pool()), trait_->line_number());
    Literal* name_value = name_->Clone(pool())->CastToLiteral();
    name_value->set_value_type(Literal::kVariable);
    name_value->AddChild(object);
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(trait_->line_number(), 1, name_value);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, trait_->line_number());
    fn->AddChild(var_stmt);
    ProcessPrivate(list);
    ProcessPublic(list);
    ProcessRequires(list);
    CreateMixinStmt(ProcessMixin(trait_->mixin_member(), info_, trait_->line_number()), var_stmt);
    fn->AddChild(ret);
  }
  object->elements()->Append(list);
  Literal* trait_mark = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTraitMark),
                                                  Token::JS_IDENTIFIER, trait_->line_number(), Literal::kProperty);
  Literal* true_value = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTrue),
                                                  Token::JS_TRUE, trait_->line_number(), Literal::kTrue);
  trait_mark->AddChild(true_value);
  list->AddChild(trait_mark);
}

NodeIterator GetPrivateIterator(Trait *trait) {
  return trait->private_member()->ChildNodes();
}

NodeIterator GetPublicIterator(Trait *trait) {
  return trait->public_member()->ChildNodes();
}

void TraitProcessor::CommonProcessor(NodeList* list, IteratorGetter getter, const char* type) {
  Literal* member_field = builder()->CreateNameNode(type, Token::JS_IDENTIFIER, trait_->line_number(), Literal::kProperty);
  ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(trait_->line_number());
  IVisitor* visitor = info_->visitor();
  NodeIterator iterator = getter(trait_);
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    TraitMember* member = item->CastToExpression()->CastToTraitMember();
    AstNode* property = member->property();
    property->Accept(visitor);
    Function* fn = property->CastToExpression()->CastToFunction();
    Literal* prop = builder()->CreateNameNode(fn->name()->CastToLiteral()->value()->token(),
                                              Token::JS_IDENTIFIER, fn->line_number(), Literal::kProperty);
    prop->AddChild(property);
    object->set_element(prop);
  }
  member_field->AddChild(object);
  list->AddChild(member_field);
}



void TraitProcessor::ProcessPrivate(NodeList* list) {
  CommonProcessor(list, GetPrivateIterator, SymbolList::symbol(SymbolList::kTraitPrivate));
}

void TraitProcessor::ProcessPublic(NodeList* list) {
  CommonProcessor(list, GetPublicIterator, SymbolList::symbol(SymbolList::kTraitPublic));
}

void TraitProcessor::CreateMixinStmt(AstNode* mixin_list, AstNode* mark) {
  Literal* mixin = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kMixin),
                                             Token::JS_IDENTIFIER, mark->line_number(), Literal::kProperty);
  NodeIterator iterator = mixin_list->ChildNodes();
  AstNode* last = mark;
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    AstNode* rename = item->first_child();
    AstNode* remove = rename->next_sibling();
    AstNode* name_node = remove->next_sibling();
    NodeList* args = builder()->CreateNodeList(4, name_->Clone(pool()), name_node, rename, remove);
    CallExp* runtime_accessor = builder()->CreateRuntimeMod(mixin, rename->line_number());
    CallExp* runtime_call = builder()->CreateNormalAccessor(runtime_accessor, args, rename->line_number());
    ExpressionStmt* stmt = builder()->CreateExpStmt(runtime_call, rename->line_number());
    body_->InsertAfter(stmt, mark);
    last = stmt;
  }
}

AstNode* TraitProcessor::ProcessMixin(AstNode* mixin, ProcessorInfo* info, int64_t line) {
  NodeIterator iterator = mixin->ChildNodes();
  NodeList* ret = new(LocalPool()) NodeList;
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    MixinMember* member = item->CastToExpression()->CastToMixinMember();
    AstNode* name_node = member->name();
    AstNode* rename_list = member->rename_list();
    AstNode* removal_list = member->remove_list();
    name_node->Accept(info->visitor());
    rename_list->Accept(info->visitor());
    removal_list->Accept(info->visitor());
    ObjectLikeLiteral* rename_map = 0;
    if (rename_list->child_length() > 0) {
      rename_map = new(LocalPool()) ObjectLikeLiteral(mixin->line_number());
      NodeIterator rename_iterator = rename_list->ChildNodes();
      while (rename_iterator.HasNext()) {
        AstNode* item = rename_iterator.Next();
        Literal* before = item->first_child()->CastToLiteral();
        Literal* after = item->first_child()->next_sibling()->CastToLiteral();
        std::stringstream sst;
        sst << "\"" << after->value()->token() << "\"";
        TokenInfo* str = new(LocalPool()) TokenInfo(sst.str().c_str(), Token::JS_STRING_LITERAL, line);
        after->set_value(str);
        before->AddChild(after);
        rename_map->set_element(before);
      }
    }
    ObjectLikeLiteral* remove_map = 0;
    if (removal_list->child_length() > 0) {
      remove_map = new(LocalPool()) ObjectLikeLiteral(mixin->line_number());
      NodeIterator removal_iterator = removal_list->ChildNodes();
      while (removal_iterator.HasNext()) {
        AstNode* item = removal_iterator.Next();
        Literal* true_val = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kTrue),
                                                      Token::JS_TRUE, line, Literal::kProperty);
        item->AddChild(true_val);
        remove_map->set_element(item);
      }
    }
    if (rename_map == 0) {
      rename_map = new(LocalPool()) ObjectLikeLiteral(mixin->line_number());
    }
    if (remove_map == 0) {
      remove_map = new(LocalPool()) ObjectLikeLiteral(mixin->line_number());
    }
    ret->AddChild(LocalBuilder()->CreateNodeList(3, rename_map, remove_map, name_node));
  }
  return ret;
}

void TraitProcessor::ProcessRequires(NodeList* list) {
  ObjectLikeLiteral* object = new(pool()) ObjectLikeLiteral(trait_->line_number());
  Literal* prop = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kRequires),
                                            Token::JS_IDENTIFIER, trait_->line_number(), Literal::kProperty);
  NodeList* requires = trait_->require_member();
  NodeIterator iterator = requires->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* item = iterator.Next();
    Literal* name = item->CastToLiteral();
    Literal* true_val = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kTrue),
                                                  Token::JS_TRUE, trait_->line_number(), Literal::kTrue);
    name->AddChild(true_val);
    object->set_element(name);
  }
  prop->AddChild(object);
  list->AddChild(prop);
}

}
