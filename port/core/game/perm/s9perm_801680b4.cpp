#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9perm_801680b4.c"
/* Recovery s9: reference-verified decomp-permuter output. */

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
M2C_UNK fn_80168200();
extern s32 lbl_804AB4FC;
s32 s9_permute_801680b4(void)
{
  if (((s32) lbl_804AB4FC) != 0)
  {
    if (lbl_804AB4FC)
    {
      goto block_2;
    }
    else
    {
      goto block_2;
    }
  }
  return 0;
  block_2:
  fn_80168200();

  return 1;
}

}
