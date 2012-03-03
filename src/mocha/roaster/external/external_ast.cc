#include <mocha/roaster/external/external_ast.h>
#include <mocha/roaster/ast/ast.h>
namespace mocha {

Handle<ExternalAst> ExternalAst::Create() {
  return Handle<ExternalAst>( new ExternalAst );
}

ExternalAst::ExternalAst() : root_( AstRoot::New() ){}

}
