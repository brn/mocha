#ifndef mocha_fileroot_processor_h_
#define mocha_fileroot_processor_h_
#include <mocha/roaster/ast/translator/processors/processor.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class FileRootProcessor : public Processor{
 public :
  FileRootProcessor(FileRoot* ast_node, ProcessorInfo* info)
      : Processor(), ast_node_(ast_node), info_(info) {}
  /**
   * @param {FileRoot*} ast_node
   * @param {ProcessorInfo*} info
   * @static
   * Processing FileRoot node.
   */
  void ProcessNode();
 private :
  FileRoot* node() { return ast_node_; }
  ProcessorInfo* info() { return info_; }
  FileRoot* ast_node_;
  ProcessorInfo* info_;
};

}

#endif
