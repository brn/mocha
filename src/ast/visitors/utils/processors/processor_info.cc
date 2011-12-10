#include <ast/visitors/utils/processors/processor_info.h>
#include <ast/visitors/ivisitor.h>

namespace mocha {

#define GET_PROC(type,name)                     \
  if ( name.Get() == 0 ) {                      \
    name( new type( info_ ) );                  \
  }                                             \
  return name.Get();

const DstaProcessor* Processors::GetProcessor( const ProcessorTraits<DstaProcessor>& ) {
  GET_PROC(DstaProcessor,dsta_proc_);
}
const VariableProcessor* Processors::GetProcessor( const ProcessorTraits<VariableProcessor>& ) {
  GET_PROC(VariableProcessor,var_proc_);
}
const IterationProcessor* Processors::GetProcessor( const ProcessorTraits<IterationProcessor>& ) {
  GET_PROC(IterationProcessor,iter_proc_);
}
}
