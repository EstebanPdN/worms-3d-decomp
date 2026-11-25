#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9perm_8018b4cc.c"
/* Recovery s9: reference-verified decomp-permuter output. */

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
s32 fn_8018A864(Ptr32<void>);
f32 fn_8018B404(Ptr32<void>, Ptr32<void>);
M2C_UNK fn_801FE160(s32);
f32 s9_permute_8018b4cc(s32 arg0, s32 arg1)
{
  f32 temp_f31;
  volatile unsigned int new_var;
  s32 temp_r3;
  temp_r3 = fn_8018A864(w3d::G(arg1));
  temp_f31 = fn_8018B404(w3d::G(arg0), w3d::G(temp_r3));
  ;
  fn_801FE160(temp_r3);
  return temp_f31;
}

}
