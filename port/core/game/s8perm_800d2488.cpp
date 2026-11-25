#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8perm_800d2488.c"

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
M2C_UNK fn_8002A914();
extern M2C_UNK lbl_8040FC48[];
Ptr32<void> s8_permuted_800d2488(Ptr32<void> arg0)
{
  Ptr32<s8> new_var;
  new_var = (Ptr32<s8>) arg0;
  fn_8002A914();
  *((Ptr32<s32>) (new_var + 0x3C)) = 0;
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0)) = &(*lbl_8040FC48);
  *((Ptr32<s32>) (new_var + 0x40)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x4C)) = 0;
  *((Ptr32<s32>) (new_var + 0x44)) = 0;
  *((Ptr32<s32>) (new_var + 0x48)) = 0;
  *((Ptr32<s32>) (new_var + 0x54)) = 0;
  *((Ptr32<s32>) (new_var + 0x3C)) = 0;
  return arg0;
}

}
