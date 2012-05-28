#ifndef mocha_array_processor_h_
#define mocha_array_processor_h_
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/translator/processors/processor.h>
#include <mocha/roaster/misc/class_traits/uncopyable.h>
namespace mocha {
class ProcessorInfo;
class ArrayProcessor : public Processor{
 public :
  ArrayProcessor(ArrayLikeLiteral* literal, ProcessorInfo* info);
  ~ArrayProcessor(){}
  void ProcessNode();
 private :
  void ProcessTuple();
  ArrayLikeLiteral* node() {return literal_;}
  ProcessorInfo* info() {return info_;}
  ArrayLikeLiteral* literal_;
  ProcessorInfo* info_;
};

}

#endif
