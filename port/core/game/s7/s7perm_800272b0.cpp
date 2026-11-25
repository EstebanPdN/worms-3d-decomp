#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s7perm_800272b0.c"
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
f32 fn_80027114(Ptr32<void>, s32);
M2C_UNK fn_800271EC(Ptr32<void>, s32);
Ptr32<void> fn_80165254();
void w3d_franco_latch_aim(void);   /* Port (francotirador de UM): factor de puntería al pulsar */
void w3d_auto_800272b0(Ptr32<void> arg0, s32 arg1, s32 arg2)
{
  f32 temp_f1;
  s32 temp_r30;
  w3d_franco_latch_aim();
  temp_r30 = *((Ptr32<s32>) (((Ptr32<s8>) fn_80165254()) + 0x34));
  if (((s32) (*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x4C)))) != 0)
  {
    goto block_2;
  }
  if (((s32) (*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x50)))) == 0)
  {
    goto block_3;
  }
  block_2:
  fn_800271EC(arg0, temp_r30);

  block_3:
  temp_f1 = fn_80027114(arg0, temp_r30);

  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x50)) = arg2;
 do { *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x54)) = temp_f1; *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x60)) = temp_r30; } while (0);
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0x4C)) = arg1;
  return;
}

}
