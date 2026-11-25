#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7perm_8002225c.c"
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
M2C_UNK fn_80161014();
extern M2C_UNK lbl_8040DDB8[];
Ptr32<void> w3d_auto_8002225c(Ptr32<void> arg0)
{
  int new_var;
  Ptr32<void> temp_r11;
  fn_80161014();
  temp_r11 = arg0 + 0x1C;
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0)) = &(*lbl_8040DDB8);
  *((Ptr32<s32>) (((Ptr32<s8>) temp_r11) + 8)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) temp_r11) + 4)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x1C)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x28)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x2C)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + (new_var = 0x30))) = 0;
  return arg0;
}

}
