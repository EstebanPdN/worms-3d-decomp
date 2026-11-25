#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10perm_801f86ec.c"
/* Locally permuted decompilation; final files are proved through the post-link gate. */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
Ptr32<Ptr32<void>> fn_801F8F68();
M2C_UNK fn_801F9164(Ptr32<Ptr32<void>>, Ptr32<void>);
M2C_UNK fn_801FE1D8(M2C_UNK);
s32 w3d_auto_801f86ec(s32 arg0, Ptr32<Ptr32<Ptr32<void>>> arg1)
{
  Ptr32<Ptr32<void>> temp_r3;
  fn_801FE1D8(0x20);
  temp_r3 = fn_801F8F68();
  (*((Ptr32<Ptr32<M2C_UNK (void)>>) (((Ptr32<s8>) (*temp_r3)) + 0xC)))();
 do { } while (0);
  fn_801F9164(temp_r3, w3d::G(arg0));
  *arg1 = temp_r3;
  return 0;
}

}
