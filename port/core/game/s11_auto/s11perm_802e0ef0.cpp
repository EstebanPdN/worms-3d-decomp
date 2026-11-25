#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11perm_802e0ef0.c"
/* m2c draft tuned by the local decomp-permuter; placeholder types. */

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
extern f32 lbl_803DB308[];
f32 w3d_auto_802e0ef0(Ptr32<void> arg0)
{
  Ptr32<void> temp_r9;
  temp_r9 = *((Ptr32<Ptr32<void>>) (((Ptr32<s8>) arg0) + 4));
  if (((s32) (*((Ptr32<s32>) (((Ptr32<s8>) temp_r9) + 0xA0)))) != 0)
  {
    if (temp_r9)
    {
      goto block_2;
    }
    else
    {
      goto block_2;
    }
  }
  return *lbl_803DB308;
  block_2:
  return *((Ptr32<f32>) (((Ptr32<s8>) temp_r9) + 0x4C));

}

}
