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
M2C_UNK fn_8016E57C(void *, s32, s32, s32);
M2C_UNK fn_8016E5FC();
M2C_UNK fn_8016E6FC(void *);
s32 fn_8035A3A8();
void w3d_auto_801fdf60(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  s32 temp_r30;
 do { temp_r30 = fn_8035A3A8(); fn_8016E5FC(); } while (0);
  fn_8016E57C(temp_r30, arg1, arg2, arg3);
  fn_8016E6FC(temp_r30);
  return;
}
