#include <mocha/roaster/ast/seriarization/byte.h>
#define SWAP_ENDIAN(val) 
namespace mocha {
ByteOrder::ByteOrder() {
  CheckEndian();
}
ByteOrder::ByteOrder(bool not_reverse) {
  if (!not_reverse) {
    CheckEndian();
  } else {
    converter_ = &ByteOrder::Noop;
  }
}
void ByteOrder::CheckEndian() {
#ifndef PACKING_RUNTIME
  int x=1;
  if (*(reinterpret_cast<char*>(&x))) {
    converter_ = &ByteOrder::Reverse;
  }else{
    converter_ = &ByteOrder::Noop;
  }
#else
  converter_ = &ByteOrder::Noop;
#endif
}

int32_t ByteOrder::ToNetwordByteOrder(int32_t val) {
  return converter_(val);
}

int32_t ByteOrder::ToHostByteOrder(int32_t val) {
  return converter_(val);
}

int32_t ByteOrder::Reverse(int32_t val) {
  return static_cast<int32_t>((((val) & 0x000000ff) << 24) | (((val) & 0x0000ff00) <<  8) | (((val) & 0x00ff0000) >>  8) | (((val) & 0xff000000) >> 24));
}
int32_t ByteOrder::Noop(int32_t val) {
  return val;
}
}
