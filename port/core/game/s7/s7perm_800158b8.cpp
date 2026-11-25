#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7perm_800158b8.c"
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
f32 fn_80015810();
extern f32 lbl_8036A61C[];
void w3d_auto_800158b8(Ptr32<f32> arg0, f32 farg0)
{
  float new_var;
  new_var = (farg0 * ((2.0f * fn_80015810()) - (*lbl_8036A61C))) + (*lbl_8036A61C);
  *arg0 *= new_var;
  return;
}

}
