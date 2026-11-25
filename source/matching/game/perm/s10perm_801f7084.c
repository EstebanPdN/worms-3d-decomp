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
f32 w3d_auto_801f7084(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5, f32 farg6, f32 farg7, f32 arg_sp8)
{
  float new_var;
  float new_var2;
  new_var = farg0 * ((farg4 * arg_sp8) - (farg5 * farg7));
  new_var2 = farg3 * ((farg1 * arg_sp8) - (farg2 * farg7));
  return (farg6 * ((farg1 * farg5) - (farg2 * farg4))) + (new_var - new_var2);
}
