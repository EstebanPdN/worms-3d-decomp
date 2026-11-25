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
extern f32 lbl_803AF63C[];
extern f32 lbl_803AF640[];
f32 w3d_auto_801d6a18(f32 farg0)
{
  f32 var_f1;
  var_f1 = farg0;
  if (!(var_f1 < (*lbl_803AF63C)))
  {
    goto block_2;
  }
  var_f1 = -var_f1;
  block_2:
  if (var_f1 < (*lbl_803AF640))
  {
    block_4:
    return (*lbl_803AF640) - var_f1;

    goto block_4;
  }

  return *lbl_803AF63C;
}
