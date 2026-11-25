#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10perm_801fc330.c"
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
s32 w3d_auto_801fc330(Ptr32<void> arg0, Ptr32<s32> arg1)
{
  s32 temp_r0;
  temp_r0 = (*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 8))) - (*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 4)));
  *arg1 = temp_r0;
  if (temp_r0 == 0)
  {
    if (temp_r0)
    {
      goto block_2;
    }
    else
    {
      goto block_2;
    }
  }
  return *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 4));
  block_2:
  return 0;

}

}
