#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/ast/ast.h>
namespace mocha {

SharedPtr<ExternalAst> ExternalAst::Create() {
  return SharedPtr<ExternalAst>(new ExternalAst);
}

ExternalAst::ExternalAst() : root_(new(&pool_) AstRoot){}

}
