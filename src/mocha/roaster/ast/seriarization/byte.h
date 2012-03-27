#ifndef mocha_ast_seriarization_byte_h_
#define mocha_ast_seriarization_byte_h_
#include <mocha/roaster/misc/int_types.h>
namespace mocha {
class ByteOrder {
  typedef int32_t (*ByteOrderConverter)(int32_t);
 public :
  ByteOrder();
  ByteOrder(bool);
  ~ByteOrder(){}
  int32_t ToNetwordByteOrder(int32_t);
  int32_t ToHostByteOrder(int32_t);
 private :
  void CheckEndian();
  static int32_t Noop(int32_t);
  static int32_t Reverse(int32_t);
  ByteOrderConverter converter_;
};
}
#endif
