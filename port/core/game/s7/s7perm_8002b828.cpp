#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7perm_8002b828.c"
/* Recovered from original instructions; inferred types and names. */

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
char fn_8002A914();
extern f32 lbl_803725F0[];
extern M2C_UNK lbl_8040E3A8[];
Ptr32<void> w3d_auto_8002b828(Ptr32<void> arg0)
{
  fn_8002A914();
  *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x5C)) = (f32) (*lbl_803725F0);
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x40)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x44)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x48)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x4C)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x50)) = 0;
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0)) = &(*lbl_8040E3A8);
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x54)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x9C)) = 0;
  return arg0;
}

}
