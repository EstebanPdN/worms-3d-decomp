#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10perm_8020ee9c.c"
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
extern M2C_UNK lbl_80419570[];
Ptr32<void> w3d_auto_8020ee9c(Ptr32<void> arg0)
{
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0x10)) = &(*lbl_80419570);
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 4)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 8)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xC)) = 0;
  return arg0;
}

}
