#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7broad_8006ce8c.c"
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
M2C_UNK fn_800FC230(Ptr32<Ptr32<M2C_UNK>>, Ptr32<s32>, Ptr32<M2C_UNK>);
extern M2C_UNK lbl_8037C044[];
s32 w3d_auto_8006ce8c(void)
{
  Ptr32<M2C_UNK> sp8;
  unsigned int spC;
  Ptr32<M2C_UNK> new_var2;
  Ptr32<M2C_UNK> new_var3;
  Ptr32<Ptr32<M2C_UNK>> new_var;
  spC = 0;
  sp8 = &(*lbl_8037C044);
 do { new_var = &sp8; ; } while (0);
  fn_800FC230(new_var, &spC, new_var3);
  new_var3 = &(*(new_var2 = lbl_8037C044));
  return 0;
}

}
