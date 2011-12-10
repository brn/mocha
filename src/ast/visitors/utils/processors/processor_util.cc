#include <ast/visitors/utils/processors/processor_util.h>
namespace mocha {
void ProcessorUtil::Destructor_( void* data ) {
  ProcessorBase* processor = reinterpret_cast<ProcessorBase*>( data );
  delete data;
}
ThreadLocalStorageKey ProcessorUtil::local_key_( ProcessorUtil::Destructor_ );
}
