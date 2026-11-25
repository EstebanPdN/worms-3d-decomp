#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7broad_8008659c.c"
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
void fn_8007F95C();
M2C_UNK fn_800840F0(Ptr32<void>, Ptr32<f32>, s32);
void fn_80086160(s32);
M2C_UNK fn_80086288(Ptr32<void>);
void fn_80086324(Ptr32<void>);
extern s32 lbl_804ADB14;
extern s32 lbl_804ADB1C;
extern s32 lbl_804ADB20;
extern s32 lbl_804ADB24;
void w3d_auto_8008659c(int arg0, Ptr32<void> arg1, s32 arg2)
{
  f32 sp8[3];
  Ptr32<void> new_var2;
  Ptr32<f32 [3]> new_var;
  lbl_804ADB1C = (lbl_804ADB14 = 0);
  fn_8007F95C();
  if ((lbl_804ADB20 | lbl_804ADB24) == 0)
  {
    goto block_2;
  }
  fn_80086160(arg0);
  fn_80086288(w3d::G(arg0));
  new_var2 = arg1;
  fn_80086324(w3d::G(arg0));
  sp8[0] = *((Ptr32<f32>) (((Ptr32<s8>) new_var2) + 0));
  new_var = &sp8;
  *((Ptr32<f32>) (((Ptr32<s8>) new_var) + 4)) = (f32) (*((Ptr32<f32>) (((Ptr32<s8>) new_var2) + 4)));
  *((Ptr32<f32>) (((Ptr32<s8>) new_var) + 8)) = (f32) (*((Ptr32<f32>) (((Ptr32<s8>) new_var2) + 8)));
  fn_800840F0(w3d::G(arg0), new_var, arg2);
  block_2:
  return;

}

}
