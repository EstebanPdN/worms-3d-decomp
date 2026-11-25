#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ca_8026cde8.c"
// desc: Appears to compute a 4-bit-shift string hash with the top nibble folded back in, over a NUL-terminated string.
unsigned w3d_s21_hash_string_8026cde8(int unused, Ptr32<const char> text)
{
  unsigned hash = 0;
  while (*text)
  {
    unsigned high;
    hash = hash << 4;
    hash = hash + (*text);
    text++;
    high = hash & 0xf0000000;
    if (high)
    {
      hash ^= high >> 24;
      hash ^= high;
    }
  }

  return hash;
}

}
