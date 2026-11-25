#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ab_80204760.c"
// desc: Appears to write an unsigned value as a seven-bits-per-byte variable-length integer through a write helper.
extern int fn_802047e0(Ptr32<void>, Ptr32<void>, int);
void w3d_s21_write_varint_80204760(Ptr32<void> stream, unsigned value)
{
  int new_var;
  unsigned char bytes[8];
  int count = 0;
  do
  {
    unsigned char byte = value & 0x7f;
    if (bytes)
    {
      new_var = 0x7f;
    }
    else
    {
      new_var = 0x7f;
    }
    if (value & (~new_var))
    {
      byte |= 0x80;
    }
    bytes[count] = byte;
    value >>= 7;
    count++;
  }
  while (value);
  fn_802047e0(stream, bytes, count);
}

}
