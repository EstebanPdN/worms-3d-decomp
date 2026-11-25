#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7broad_80015794.c"
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
M2C_UNK fn_800FC270(Ptr32<Ptr32<M2C_UNK>>, Ptr32<f32>, Ptr32<M2C_UNK>);
extern M2C_UNK lbl_8036A5E4[];
f32 w3d_auto_80015794(void)
{
  Ptr32<M2C_UNK> sp8;
  f32 new_var4;
  Ptr32<Ptr32<M2C_UNK>> new_var2;
  Ptr32<M2C_UNK []> new_var;
  Ptr32<Ptr32<M2C_UNK>> new_var3;
  f32 spC;
  sp8 = &(*lbl_8036A5E4);
  new_var2 = (new_var3 = &sp8);
  fn_800FC270(new_var2, &spC, &(*(*new_var)));
  new_var = &lbl_8036A5E4;
  new_var4 = spC;
  return new_var4;
}

}
