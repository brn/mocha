#include <mocha/roaster/ast/ast.h>
#include <mocha/roaster/ast/builder/ast_builder.h>
#include <mocha/roaster/ast/visitors/utils/visitor_info.h>
#include <mocha/roaster/ast/visitors/utils/processors/fileroot_processor.h>
#include <mocha/roaster/ast/visitors/utils/processors/processor_info.h>
#include <mocha/roaster/tokens/js_token.h>
#include <mocha/roaster/tokens/symbol_list.h>
namespace mocha {

void FileRootProcessor::ProcessNode() {
  VisitorInfo *visitor_info = info()->visitor_info();
  IVisitor* visitor = info()->visitor();
  NodeIterator iterator = node()->ChildNodes();
  bool is_runtime = visitor_info->runtime();
  while (iterator.HasNext()) {
    iterator.Next()->Accept(visitor);
  }
  if (!is_runtime) {
    Function *fn = builder()->CreateFunctionDecl(new(pool()) Empty,
                                                  new(pool()) Empty, node(), 1);
    ExpressionStmt *stmt = builder()->CreateAnonymousFnCall(fn, new(pool()) Empty, node()->line_number());
    Literal* global_export = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalExport),
                                                       Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
    ObjectLikeLiteral* object_literal = new(pool()) ObjectLikeLiteral(node()->line_number());
    Literal* key = builder()->CreateNameNode(visitor_info->relative_path(), Token::JS_STRING_LITERAL, node()->line_number(), Literal::kString);
                                                                
    CallExp* global_export_accessor = builder()->CreateArrayAccessor(global_export, key, node()->line_number());
    AssignmentExp* exp = builder()->CreateAssignment('=', global_export_accessor, object_literal, node()->line_number());

    Literal* alias = builder()->CreateNameNode(SymbolList::symbol(SymbolList::kGlobalAlias),
                                               Token::JS_IDENTIFIER, node()->line_number(), Literal::kIdentifier);
    Literal* init = builder()->CreateVarInitiliser(alias->value(), global_export_accessor->Clone(pool()), node()->line_number());
    VariableDeclarationList* decl_list = builder()->CreateVarDeclList(node()->line_number(), 1, init);
    VariableStmt* var_stmt = builder()->CreateVarStmt(decl_list, 3);
    ExpressionStmt* extend_global = builder()->CreateExpStmt(exp, 2);
    FileRoot* root = new(pool()) FileRoot(node()->filename());
    root->AddChild(stmt);
    fn->InsertBefore(var_stmt);
    fn->InsertBefore(extend_global);
    fn->MarkAsRoot();
    node()->parent_node()->ReplaceChild(node(), root);
  } else {
    node()->set_runtime();
  }
}

}
