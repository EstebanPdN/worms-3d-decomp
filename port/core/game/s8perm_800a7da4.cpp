#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8perm_800a7da4.c"

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
s32 fn_802EF234(Ptr32<void>, Ptr32<void>);
u32 s8_permuted_800a7da4(Ptr32<void> arg0, s32 arg1)
{
  s32 var_r30;
  u32 var_r31;
  var_r31 = 0U;
  var_r30 = 0;
  loop_1:
  if (fn_802EF234(w3d::G(((*(*((Ptr32<Ptr32<s32>>) (((Ptr32<s8>) arg0) + 0xAC)))) + var_r30) + 1), w3d::G(arg1)) != 0)
  {
    goto block_3;
  }

  return var_r31;
  block_3:
  var_r31 += 1;

  var_r30 += 0x34;
  if (var_r31 <= 0xEU)
  {
    if (var_r31 || var_r30)
    {
      goto loop_1;
    }
    else
    {
      goto loop_1;
    }
  }
  return -1U;
}

}
