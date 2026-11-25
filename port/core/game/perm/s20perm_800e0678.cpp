#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20perm_800e0678.c"
/* m2c output tuned by decomp-permuter (tools/permute_near_misses.py); verified
 * identical to the original after linking. Placeholder types pending review. */

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
M2C_UNK fn_800DE988(Ptr32<void>);
M2C_UNK fn_8015FEF0();
extern M2C_UNK lbl_8040FFB8[];
extern M2C_UNK lbl_8040FFD8[];
Ptr32<void> w3d_auto_800e0678(Ptr32<void> arg0)
{
  Ptr32<void> new_var;
  fn_8015FEF0();
  fn_800DE988(arg0 + 0x1C);
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0x100)) = &(*lbl_8040FFB8);
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0)) = &(*lbl_8040FFD8);
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x128)) = -1;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x104)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x10C)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x110)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x114)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x118)) = 0;
  new_var = arg0;
  *((Ptr32<s32>) (((Ptr32<s8>) new_var) + 0x120)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x108)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x11C)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x124)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x12C)) = 0;
  return arg0;
}

}
