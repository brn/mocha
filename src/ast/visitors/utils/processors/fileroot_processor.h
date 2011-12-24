#ifndef mocha_fileroot_processor_h_
#define mocha_fileroot_processor_h_
#include <utils/class_traits/static.h>
#include <ast/ast_foward_decl.h>
namespace mocha {
class ProcessorInfo;
class FileRootProcessor : public Static {
 public :
  /**
   * @param {FileRoot*} ast_node
   * @param {ProcessorInfo*} info
   * @static
   * Processing FileRoot node.
   */
  static void ProcessNode( FileRoot* ast_node , ProcessorInfo* info );
};

}

#endif
