#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7perm_80015860.c"
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
u32 fn_80162BA8();
s32 w3d_auto_80015860(s32 arg0)
{
  if (arg0 > 0x100)
  {
    goto block_2;
    block_2:
    return fn_80162BA8() % arg0;

  }
  return (fn_80162BA8() >> 5U) % arg0;
}

}
