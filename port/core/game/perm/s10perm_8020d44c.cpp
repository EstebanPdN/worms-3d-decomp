#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10perm_8020d44c.c"
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
M2C_UNK fn_8020C3A0(Ptr32<void>, s32);
M2C_UNK fn_8020C43C(Ptr32<void>, s32, s32);
s32 w3d_auto_8020d44c(Ptr32<void> arg0, s32 arg1, s32 arg2, Ptr32<s32> arg3)
{
  fn_8020C3A0(w3d::G(*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x14))), *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x18)));
 do { fn_8020C43C(w3d::G(*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x14))), arg1, arg2); *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x18)) = (s32) ((*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x18))) + arg2); if (arg3 == ((Ptr32<void>) 0)) { goto block_2; } *arg3 = arg2; block_2: return 0; } while (0);
}

}
