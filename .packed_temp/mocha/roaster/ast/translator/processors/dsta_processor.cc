/**
 *@author Taketoshi Aono
 *@fileOverview
 *Implementation of destructuring assignment processor.
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
#include <mocha/roaster/assert/assert_def.h>
#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/translator/processors/dsta_processor.h>
#include <mocha/roaster/ast/translator/processors/processor_info.h>
#include <mocha/roaster/ast/translator/translator_data/translator_data.h>
#include <mocha/roaster/nexc/tokens/js_token.h>
#include <mocha/roaster/nexc/tokens/token_info.h>
#include <mocha/roaster/nexc/tokens/symbol_list.h>

namespace mocha {
/**
 * We express destructuring assingment as dsta.
 * Let's begin transform of abstract syntax tree!
 * Buf before that, describe target tree structure overview on following.
 *
 * Statement<Current active statement>
 *                  |
 *                  DstaExtractedExpression -----Refs
 *                  |                              |-----
 *                  NodeList--------               |    |
 *                  |    |    |    |               Ref1 Ref2 ...
 *                  Tree Tree Tree Tree
 *                  |
 *                  CallExp<Result of processing>
 *
 * The DstaExtractedExpression could has multiple Tree class,
 * but appling this case will be only in case that dsta appear in the formal_parameter_list.
 * Now mocha implements dsta as the conditional expression or simple property accessor.
 * This implementation not throw error, except if lhs is null or undefined,
 * this based on firefox implemetation, not harmony.
 */



#define UPDATE_TREE                             \
  if (depth == 0) {                           \
    tree = new(pool()) DstaTree;                \
  } else {                                      \
    tree = tree->Clone(pool())->CastToDstaTree();     \
    tree->RemoveChild(tree->last_child());    \
  }

//prototypes.
void ProcessObject(ObjectLikeLiteral* ast_node, DstaTree* tree, int depth, ProcessorInfo* info);
void ProcessArray(ArrayLikeLiteral* ast_node, DstaTree* tree, int depth, ProcessorInfo* info);

/**
 * Process the Object pattern's property member.
 * Create an accessor for conditional_expression, like _mochaLocalTmp.x[0].y
 */
void DstaProcessor::ProcessMember(Literal* ast_node, DstaTree* tree) {
  TranslatorData *translator_data = info()->translator_data();
  TokenInfo* info = ast_node->value();
  switch(info->type()) {
    //In case of { Identifier : ... } or { Identifier }
    case Token::JS_IDENTIFIER : {
      if (tree->child_length() > 0) {
        /*
         * If the Tree has the one or more children,
         * connect new identifier accessor to the tree last accessor expressions.
         */
        CallExp* dot_accessor = builder()->CreateDotAccessor(tree->last_child(), ast_node, ast_node->line_number());
        tree->AddChild(dot_accessor);
      } else {
        /*
         * If the Tree hasn't children,
         * add first identifier accessor to tree.
         */
        AstNode* node = translator_data->current_statement()->destructuring_node()->refs()->last_child()->Clone(pool());
        CallExp* dot_accessor = builder()->CreateDotAccessor(node, ast_node, ast_node->line_number());
        tree->AddChild(dot_accessor);
      }
    }
      break;
      //In case of { "string" : ... } or { 0 : ... }
    case Token::JS_NUMERIC_LITERAL :
    case Token::JS_STRING_LITERAL : {
      if (tree->child_length() > 0) {
        //As stated above, connect node.
        CallExp* arr_accessor = builder()->CreateArrayAccessor(tree->last_child(), ast_node, ast_node->line_number());
        tree->AddChild(arr_accessor);
      } else {
        //Same as above.
        AstNode* node = translator_data->current_statement()->destructuring_node()->refs()->last_child();
        CallExp* arr_accessor = builder()->CreateArrayAccessor(node, ast_node, ast_node->line_number());
        tree->AddChild(arr_accessor);
      }
    }
      break;                                                            
  }
}


/**
 * Process { x : <...> } or { <...> }
 */
DstaTree* DstaProcessor::ProcessPropertyMember(Literal* value, DstaTree* tree, int depth) {
  TranslatorData* translator_data = info()->translator_data();
  if (value->child_length() > 0) {
    ProcessMember(value, tree);
    AstNode* child_node = value->first_child();
    Literal* prop = child_node->CastToLiteral();
    ObjectLikeLiteral* object = child_node->CastToExpression()->CastToObjectLikeLiteral();
    ArrayLikeLiteral* array = child_node->CastToExpression()->CastToArrayLikeLiteral();
    if (prop || object || array) {
      if (object) {
        ProcessObject(object, tree, (depth + 1));
        UPDATE_TREE;
      } else if (array) {
        ProcessArray(array, tree, (depth + 1));
        UPDATE_TREE;
      } else {
        prop->set_value_type(Literal::kProperty);
        tree->set_symbol(prop);
        translator_data->current_statement()->destructuring_node()->last_child()->AddChild(tree);
        UPDATE_TREE;
      }
    }
  } else {
    value->set_value_type(Literal::kProperty);
    tree->set_symbol(value);
    ProcessMember(value, tree);
    translator_data->current_statement()->destructuring_node()->last_child()->AddChild(tree);
    UPDATE_TREE;
  }
  return tree;
}



/**
 * Iterate Object pattern like
 * var { x, y, z : { x } } = {...}
 */
void DstaProcessor::ProcessObject(ObjectLikeLiteral* ast_node, DstaTree* tree, int depth) {
  NodeIterator iterator = ast_node->elements()->ChildNodes();
  //Iterate member.
  while (iterator.HasNext()) {
    AstNode* node = iterator.Next();
    Literal* value = node->CastToLiteral();
    if (value) {
      switch (value->value_type()) {
        case Literal::kNumeric :
        case Literal::kString :
        case Literal::kProperty :
        case Literal::kIdentifier : {
          tree = ProcessPropertyMember(value, tree, depth);
        }
          break;
        default :
          FATAL("unknown type");
      }
    }
  }
}



void DstaProcessor::ArrayHelper(ArrayLikeLiteral* ast_node,
                                 DstaTree* tree,
                                 int index,
                                 Literal* symbol,
                                 bool is_rest) {
  TranslatorData* translator_data = info()->translator_data();
  std::stringstream st;
  st << index;
  TokenInfo* info = new(pool()) TokenInfo(st, Token::JS_NUMERIC_LITERAL, ast_node->line_number());
  CallExp* exp;
  if (is_rest) {
    NodeList* list = new(pool()) NodeList;
    std::stringstream st;
    st << index;
    Literal* arg = builder()->CreateNameNode(st, Token::JS_NUMERIC_LITERAL, ast_node->line_number(), Literal::kNumeric);
    Literal* to_array = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kToArray),
                                                  Token::JS_IDENTIFIER, ast_node->line_number(), Literal::kProperty);
    if (tree->child_length() > 0) {
      list->AddChild(tree->last_child()->Clone(pool()));
    } else {
      list->AddChild(translator_data->current_statement()->destructuring_node()->refs()->last_child()->Clone(pool()));
    }
    list->AddChild(arg);
    CallExp* nrm = builder()->CreateNormalAccessor(to_array, list, ast_node->line_number());
    CallExp* std_to_array = builder()->CreateRuntimeMod(nrm, ast_node->line_number());
    std_to_array->set_rest();
    exp = std_to_array;
  } else {                      
    Literal* accessor_index = new(pool()) Literal(Literal::kNumeric, ast_node->line_number());
    accessor_index->set_value(info);
    if (tree->child_length() > 0) {
      exp = builder()->CreateArrayAccessor(tree->last_child(), accessor_index, ast_node->line_number());
    } else {
      exp = builder()->CreateArrayAccessor(translator_data->current_statement()->destructuring_node()->refs()->last_child(),
                                           accessor_index, ast_node->line_number());
    }
  }
  if (symbol) {
    symbol->set_value_type(Literal::kIdentifier);
    tree->set_symbol(symbol);
  }
  tree->AddChild(exp);
}


/**
 * Process each member of array pattern.
 */
DstaTree* DstaProcessor::ProcessArrayElement(ArrayLikeLiteral* ast_node,
                                              AstNode* element,
                                              DstaTree* tree,
                                              int depth,
                                              int index) {
  TranslatorData* translator_data = info()->translator_data();
  if (!element->IsEmpty()) {
    Literal* elem = element->CastToLiteral();
    ObjectLikeLiteral* object = element->CastToExpression()->CastToObjectLikeLiteral();
    ArrayLikeLiteral* array = element->CastToExpression()->CastToArrayLikeLiteral();
    if (elem) {
      switch(elem->value_type()) {
        //In case of [ x, y ]
        case Literal::kIdentifier : //fall through
        case Literal::kProperty : {
          ArrayHelper(ast_node, tree, index, elem, false);
          translator_data->current_statement()->destructuring_node()->last_child()->AddChild(tree);
          UPDATE_TREE;
        }
          break;
          //In case of [ x ,y ,...rest ]
        case Literal::kRest : {
          ArrayHelper(ast_node, tree, index, elem, true);
          translator_data->current_statement()->destructuring_node()->last_child()->AddChild(tree);
          UPDATE_TREE;
        }
          break;
      }
    } else if (object) {
      //In case of [ {x,y} ]
      ArrayHelper(ast_node, tree, index, 0, false);
      ProcessObject(object, tree, (depth + 1));
      UPDATE_TREE;
    } else if (array) {
      //In case of [ [x,y] ]
      ArrayHelper(ast_node, tree, index, 0, false);
      ProcessArray(array, tree, (depth + 1));
      UPDATE_TREE;
    }

  }
  return tree;
}


/**
 * Process Array pattern.
 * Array pattern is this,
 * [ x, y, z ],
 * [ x, {x,y,z} ],
 * [ x, [ x,y ] ],
 * [ x, y, ...rest ]
 */
void DstaProcessor::ProcessArray(ArrayLikeLiteral* ast_node, DstaTree* tree, int depth) {
  int index = 0;
  NodeIterator iterator = ast_node->elements()->ChildNodes();
  while (iterator.HasNext()) {
    AstNode* element = iterator.Next();
    if (!element->IsEmpty()) {
      tree = ProcessArrayElement(ast_node, element, tree, depth, index);
      if (iterator.HasNext()) {
        index++;
      }
    }
  }
}


//Create a conditional expression that dsta converted result.
inline AstNode* DstaProcessor::CreateConditional(AstNode* last_exp, AstNode* first, ProcessorInfo *info, bool is_assign) {
  Literal* undefined = LocalBuilder()->CreateNameNode(SymbolList::symbol(SymbolList::kUndefined),
                                                 Token::JS_IDENTIFIER, last_exp->line_number(), Literal::kIdentifier);
  ConditionalExp* cond = new(LocalPool()) ConditionalExp(last_exp, first->last_child(), undefined, last_exp->line_number());
  DstaTree* tree = 0;//init after.
  ASSERT(true, first->node_type() == AstNode::kDstaTree);
  tree = first->CastToDstaTree();
  if (!is_assign) {
    Literal* var = new(LocalPool()) Literal(Literal::kVariable, last_exp->line_number());
    var->set_value(tree->symbol()->value());
    var->AddChild(cond);
    Function* fn = info->translator_data()->function();
    if (fn) {
      fn->set_variable_list(var);
    }
    return var;
  } else {
    AssignmentExp* assign = new(LocalPool()) AssignmentExp('=', tree->symbol()->Clone(LocalPool()), cond, last_exp->line_number());
    return assign;
  }
}



NodeList* DstaProcessor::IterateTree(NodeList* result, AstNode* first, ProcessorInfo *info, bool is_assign) {
  AstNode* maybe_callexp = 0;//init after.
  AstNode* last_exp = 0;//init after.
  //The Children of tree.
  NodeIterator exps = first->ChildNodes();
  /**
   * The iteration of each Tree children.
   * Tree                 Tree
   * |--------|-------|   |--------|-------|   
   * CallExp  CallExp ... CallExp  CallExp ... 
   */
  while (exps.HasNext()) {
    maybe_callexp = exps.Next();
    CallExp* item = 0;//init after.
    ASSERT(true, maybe_callexp->node_type() == AstNode::kCallExp);
    item = maybe_callexp->CastToExpression()->CastToCallExp();
    //Only first time.
    if (!last_exp) {
      maybe_callexp = exps.Next();
      CallExp* next = 0;//init after.
      ASSERT(AstNode::kCallExp, maybe_callexp->node_type());
      next = maybe_callexp->CastToExpression()->CastToCallExp();
      if (!next->rest()) {
        //Create and exparession. like -> a && b
        last_exp = new(LocalPool()) CompareExp(Token::JS_LOGICAL_AND, item, next, first->line_number());
      } else {
        /*
         * In case of rest,
         * we don't set an item to logical_and_expression.
         */
        last_exp = item;
      }
    } else {
      if (!item->rest()) {
        last_exp = new(LocalPool()) CompareExp(Token::JS_LOGICAL_AND, last_exp, item, first->line_number());
      }
    }
  }
  AstNode* ret = CreateConditional(last_exp, first, info, is_assign);
  if (!ret) {
    return 0;
  }
  result->AddChild(ret);
  return result;
}



/**
 * Simple property accessor.
 * This Implementation based on firefox's javascript 1.8.5.
 * In javascript, all value treat as Object, so not throw exception if lhs is there,
 * in firefox, destructuring assignment is implemented like this ->
 * <lhs is javascript object except null or undefined> -> no throw
 * <lhs is null or undefined> -> throw TypeError <... is has no property.>
 */
AstNode* DstaProcessor::CreateSimpleAccessor(AstNode* first, TranslatorData* info, bool is_assign) {
  if (!is_assign) {
    Literal* var = new(LocalPool()) Literal(Literal::kVariable, first->line_number());
    DstaTree* tree = first->CastToDstaTree();
    var->set_value(tree->symbol()->value());
    Function* fn = info->function();
    if (fn) {
      fn->set_variable_list(var);
    }
    var->AddChild(first->first_child());
    return var;
  } else {
    DstaTree* tree = first->CastToDstaTree();
    AssignmentExp* assign =
        new(LocalPool()) AssignmentExp('=', tree->symbol()->Clone(LocalPool()), first->first_child(), first->line_number());
    return assign;
  }
}



/**
 * Create a statement,
 * from the results of analyzing dsta expressions.
 */
NodeList* DstaProcessor::CreateDstaExtractedNode(Statement* stmt, ProcessorInfo* info, bool is_assign) {
  NodeList* result = new(LocalPool()) NodeList;
  DstaExtractedExpressions* extr = stmt->destructuring_node();
  ASSERT(true, extr != 0);
  AstNode* node_list = extr->first_child();
  NodeIterator list = node_list->ChildNodes();
  /**
   * The iteration of DstaExtractedExpressions children.
   * DstaExtractedExpressions
   *   |
   *   NodeList
   *   |    |
   * [ Tree Tree ] this line.
   */
  while (list.HasNext()) {
    AstNode *first = list.Next();
    AstNode* maybe_callexp = first->first_child();
    CallExp* exp = 0;//init after.
    ASSERT(true, maybe_callexp != 0 && maybe_callexp->node_type() == AstNode::kCallExp);
    exp = maybe_callexp->CastToExpression()->CastToCallExp();
    if (first->child_length() > 1 && !exp->rest()) {
      AstNode* ret = IterateTree(result, first, info, is_assign);
      if (ret == 0) {
        return 0;
      }
    } else {
      AstNode* ret = CreateSimpleAccessor(first, info->translator_data(), is_assign);
      result->AddChild(ret);
    }
  }
  return result;
}



/**
 * Create a variable statement,
 * from the results of analyzing dsta expressions.
 */
NodeList* DstaProcessor::CreateDstaExtractedVarStmt(Statement* stmt, ProcessorInfo* info) {
  return CreateDstaExtractedNode(stmt, info, false);
}



/**
 * Create a Assignment expression,
 * from the results of analyzing dsta expressions.
 */
NodeList* DstaProcessor::CreateDstaExtractedAssignment(Statement* stmt, ProcessorInfo* info) {
  return CreateDstaExtractedNode(stmt, info, true);
}



Literal* DstaProcessor::ProcessNode() {
  TranslatorData* translator_data = info()->translator_data();
  /**
   * Create a variable has the temporary referrence to assignment right hand side.
   * That like this -> _mochaLocalTmp<current number of tmporary variable> = <LHS>
   */
  Literal* value = 0;//init after
  bool need_tmp = true;
  bool is_var_stmt = node()->parent_node()->node_type() == AstNode::kVariableDeclarationList;
  if (is_var_stmt && node()->first_child()) {
    Literal* literal = node()->first_child()->CastToLiteral();
    if (literal && literal->value_type() == Literal::kIdentifier) {
      need_tmp = false;
      value = literal->Clone(pool())->CastToLiteral();
    }
  } else {
    AstNode* parent = node()->parent_node();
    while (parent) {
      if (parent->node_type() == AstNode::kAssignmentExp) {
        Literal* maybe_literal = parent->CastToExpression()->CastToAssigment()->right_value()->CastToLiteral();
        if (maybe_literal && maybe_literal->value_type() == Literal::kIdentifier) {
          need_tmp = false;
          value = maybe_literal->Clone(pool())->CastToLiteral();
        }
        break;
      } else if (parent->node_type() == AstNode::kFunction ||
                  parent->node_type() == AstNode::kVariableStmt ||
                  parent->node_type() == AstNode::kExpressionStmt) {
        break;
      }
      parent = parent->parent_node();
    }
  }
  if (need_tmp) {
    value = builder()->CreateTmpNode(info()->translator_data()->tmp_index(), node()->line_number());
  }
  /**
   * Create a tree node that is stored the result of processing.
   */
  DstaTree* tree = new(pool()) DstaTree;
  /**
   * If we have not dsta yet,
   * add DstaExtractedAssignment to current active statement.
   */
  Statement* stmt = translator_data->current_statement();
  ASSERT(true, stmt != 0);
  if (stmt && !stmt->IsContainDestructuring()) {
    translator_data->current_statement()->set_destructuring(new(pool()) DstaExtractedExpressions);
    translator_data->current_statement()->destructuring_node()->AddChild(new(pool()) NodeList);
    if (need_tmp) {
      stmt->NeedTmpRef();
    }
  }
  /**
   * Now add a temporary referrence variable to Refs node.
   */
  translator_data->current_statement()->destructuring_node()->set_refs(value);
  if (node()->node_type() == AstNode::kArrayLikeLiteral) {
    ProcessArray(node()->CastToExpression()->CastToArrayLikeLiteral(), tree, 0);
  } else {
    ProcessObject(node()->CastToExpression()->CastToObjectLikeLiteral(), tree, 0);
  }
  Literal* var = builder()->CreateNameNode(value->value()->token(), Token::JS_IDENTIFIER,
                                           node()->line_number(), Literal::kIdentifier);
  if (node()->HasChild()) {
    var->AddChild(node()->first_child()->Clone(pool()));
  } else {
    var->AddChild(new(pool()) Empty);
  }
  /**
   * Convert {x,y,z} => _mochaLocalTmp
   */
  node()->parent_node()->ReplaceChild(node(), var);
  return var;
}


/**
 * Create temporary referrence variable.
 */
VariableStmt* DstaProcessor::CreateTmpVarDecl(Statement* stmt, ProcessorInfo* info) {
  DstaExtractedExpressions* dsta_extr = stmt->destructuring_node();
  ASSERT(true, dsta_extr != 0);
  NodeList* list = dsta_extr->refs();
  NodeIterator iterator = list->ChildNodes();
  VariableDeclarationList* var_list = new(LocalPool()) VariableDeclarationList(stmt->line_number());
  /**
   * Iterate all Refs node, and create variable_declaration node.
   */
  while (iterator.HasNext()) {
    Literal* value = iterator.Next()->Clone(LocalPool())->CastToLiteral();
    ASSERT(true, value != 0);
    if (value->child_length() == 0 || value->first_child()->node_type() == AstNode::kEmpty) {
      if (value->child_length() > 0) {
        value->RemoveAllChild();
      }
      value->AddChild(LocalBuilder()->CreateObjectLiteral(new(LocalPool()) Empty, stmt->line_number()));
    }
    value->set_value_type(Literal::kVariable);
                                                                
    var_list->AddChild(value);
  }
  return LocalBuilder()->CreateVarStmt(var_list, stmt->line_number());
}


}
