#include <compiler/external/external_ast.h>
#include <ast/ast.h>
namespace mocha {

Handle<ExternalAst> ExternalAst::Create() {
  return Handle<ExternalAst>( new ExternalAst );
}

ExternalAst::ExternalAst() : root_( ManagedHandle::Retain<AstRoot>() ){}

}
