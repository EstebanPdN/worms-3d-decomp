#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11deepperm_80267fe8.c"

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
M2C_UNK fn_8026710C(Ptr32<void>);
M2C_UNK fn_80268568(Ptr32<void>, s32);
unsigned int fn_802B16C4(Ptr32<void>, Ptr32<void>);
extern f32 lbl_803CB71C[];
extern f32 lbl_803CB720[];
void w3d_auto_80267fe8(Ptr32<void> arg0, s32 arg1)
{
  f32 var_f0;
  f32 var_f0_2;
  if (arg1 == ((s32) (*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xBC)))))
  {
    goto block_8;
  }
  fn_802B16C4(arg0 + 0x1C, (Ptr32<void>)w3d::G(arg1));
  if (((s32) (*((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xBC)))) != 0)
  {
    goto block_3;
  }
  var_f0 = *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x21C));
  goto block_4;
  block_3:
  var_f0 = *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x220));

  block_4:
  *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x228)) = var_f0;

  if (arg1 != 0)
  {
    goto block_6;
  }
 do { var_f0_2 = *lbl_803CB71C; goto block_7; block_6: var_f0_2 = *lbl_803CB720; block_7: *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x2B4)) = var_f0_2; } while (0);
  *((Ptr32<f32>) (((Ptr32<s8>) arg0) + 0x278)) = var_f0_2;
  fn_8026710C(arg0);
  fn_80268568(arg0, arg1);
  block_8:
  return;

}

}
