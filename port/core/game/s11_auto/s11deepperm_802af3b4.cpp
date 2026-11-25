#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11deepperm_802af3b4.c"

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
M2C_UNK fn_8015FEF0();
M2C_UNK fn_802AFB20(Ptr32<void>);
extern M2C_UNK lbl_8041C590[];
extern M2C_UNK lbl_8041C5E0[];
Ptr32<void> w3d_auto_802af3b4(Ptr32<void> arg0)
{
  fn_8015FEF0();
  fn_802AFB20(arg0 + 0x1C);
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0xD0)) = &(*lbl_8041C590);
  *((Ptr32<Ptr32<M2C_UNK>>) (((Ptr32<s8>) arg0) + 0)) = &(*lbl_8041C5E0);
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xE0)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xE4)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xD4)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xD8)) = 0;
  *((Ptr32<s32>) (((Ptr32<s8>) arg0) + 0xDC)) = 0;
  return arg0;
}

}
