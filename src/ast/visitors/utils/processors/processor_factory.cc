#include <ast/visitors/utils/processors/processor_factory.h>

namespace mocha {
ProcessorFactory::ProcessorFactory( AstVisitor* visitor , Scope* scope , VisitorInfo* info ) :
    visitor_( visitor ) , scope_( scope ) , info_( info ){}
}
