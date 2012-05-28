#ifndef mocha_ast_seriarization_packer_h_
#define mocha_ast_seriarization_packer_h_
#include <vector>
#include <mocha/roaster/misc/int_types.h>
#include <mocha/roaster/ast/ast_foward_decl.h>
#include <mocha/roaster/ast/visitors/ivisitor.h>
namespace mocha {
typedef std::vector<int32_t> Packed;
class ByteOrder;
class Packer : public IVisitor {
 public :
  Packer(Packed* packed, ByteOrder* b_order);
  ~Packer(){};
#include <mocha/roaster/ast/visitors/visitor_decl.h>
 private :
  void PushBack(int32_t val);
  void CharPacker(const char* str, int size);
  void BasePacker(AstNode* node);
  void TokenPacker(TokenInfo* info, int type);
  void IterateChildren(AstNode* node);
  void ArrayAccessorProccessor_(CallExp* exp);
  void DotAccessorProccessor_(CallExp* exp);
  void NewCallProccessor_(CallExp* exp);
  void NormalFunctionCall_(CallExp* exp);
  void ArrayProccessor_(AstNode* ast_node);
  void ObjectProccessor_(AstNode* ast_node);
  Packed* packed_;
  ByteOrder* b_order_;
};

}

#endif
