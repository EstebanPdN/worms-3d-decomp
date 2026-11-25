#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8perm_800a4bf4.c"

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
M2C_UNK fn_8015ADF4(Ptr32<M2C_UNK>, s32, M2C_UNK);
M2C_UNK fn_8020BB54(Ptr32<M2C_UNK>, Ptr32<M2C_UNK>);
void fn_8020C5C4(Ptr32<M2C_UNK>);
M2C_UNK fn_80341588(Ptr32<M2C_UNK>);
extern M2C_UNK lbl_80380F9C[];
void s8_permuted_800a4bf4(s32 arg0)
{
  unsigned char sp8;
  Ptr32<unsigned char> new_var;
  fn_8020BB54(&sp8, &(*lbl_80380F9C));
  fn_8015ADF4(&sp8, arg0 + 0x20, 0xFF);
  new_var = &sp8;
  fn_8020C5C4(new_var);
  fn_80341588(&sp8);
  return;
}

}
