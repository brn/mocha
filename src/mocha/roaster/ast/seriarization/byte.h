#ifndef mocha_ast_seriarization_byte_h_
#define mocha_ast_seriarization_byte_h_
#include <algorithm>
#include <mocha/roaster/misc/int_types.h>
namespace mocha {
template <typename T>
static T* ReverseByteOrder(T* value) {
  char* first = reinterpret_cast<char*>(value);
  char* last = first + sizeof(value);
  std::reverse(first, last);
  return value;
};

template <typename T, int n>
class ByteReverser {
 public :
  static const int check_value = 1;
};

template <typename T>
class ByteReverser<T, 0> {
 public :
  static T* ToBigEndian(T* value) {
    return ReverseByteOrder<T>(value);
  }
  static T* ToLittleEndian(T* value) {
    return value;
  }
};

template <typename T>
class ByteReverser<T, 1> {
 public :
  static T* ToBigEndian(T* value) {
    return value;
  }
  static T* ToLittleEndian(T* value) {
    return ReverseByteOrder<T>(value);
  }
};

template <typename T>
class ByteUtils {
 public :
  ByteUtils(){};
  ~ByteUtils(){}
  static T* ToBigEndian(T* value) {
    return ByteReverser<T, (ByteReverser<T,2>::check_value >> 8)>::ToBigEndian(value);
  }
  static T* ToLittleEndian(T* value) {
    return ByteReverser<T, (ByteReverser<T,2>::check_value >> 8)>::ToLittleEndian(value);
  }
};

class ByteOrder {
  typedef int32_t (*ByteOrderConverter)(int32_t);
 public :
  ByteOrder();
  ByteOrder(bool);
  ~ByteOrder(){}
  int32_t ToNetwordByteOrder(int32_t);
  int32_t ToHostByteOrder(int32_t);  
  bool IsLittleEndian();
  bool IsBigEndian();
 private :
  void CheckEndian();
  static int32_t Noop(int32_t);
  static int32_t Reverse(int32_t);
  bool little_endian_;
  ByteOrderConverter converter_;
};
}
#endif
