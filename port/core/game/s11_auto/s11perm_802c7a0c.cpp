#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11perm_802c7a0c.c"
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
void fn_8020C5C0(Ptr32<s32>);
void fn_8020C5C4(Ptr32<s32>);
M2C_UNK fn_802C7894(Ptr32<void>, s32, M2C_UNK);
M2C_UNK fn_802C78F4(Ptr32<void>, Ptr32<s32>, M2C_UNK);
M2C_UNK fn_80341588(Ptr32<s32>);
Ptr32<u16> fn_80341884(Ptr32<s32>);
void w3d_auto_802c7a0c(s32 arg0, Ptr32<s32> arg1, s32 arg2)
{
  s32 sp8;
  Ptr32<u16> temp_r3;
  fn_8020C5C0(&sp8);
  sp8 = *arg1;
  temp_r3 = fn_80341884(&sp8);
  *temp_r3 += 1;
  fn_802C78F4(w3d::G(arg0), &sp8, 0);
 do { fn_802C7894(w3d::G(arg0), arg2, 1); } while (0);
  return;
}

}
