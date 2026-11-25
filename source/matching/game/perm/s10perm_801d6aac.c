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
extern f32 lbl_803AF654[];
extern f32 lbl_803AF658[];
extern f32 lbl_803AF65C[];
extern f32 lbl_803AF660[];
extern f32 lbl_803AF664[];
extern f32 lbl_803AF668[];
f32 w3d_auto_801d6aac(f32 farg0)
{
  float new_var;
  f32 temp_f13;
  f32 var_f12;
  var_f12 = farg0;
  if (!(var_f12 < (*lbl_803AF654)))
  {
    goto block_2;
  }
  var_f12 = -var_f12;
  block_2:
  if (!(var_f12 < (*lbl_803AF658)))
  {
    goto block_4;
  }

  temp_f13 = var_f12 * var_f12;
  new_var = temp_f13 * (*lbl_803AF65C);
  return ((new_var * var_f12) - temp_f13) + (*lbl_803AF660);
  block_4:
  if (!(var_f12 < (*lbl_803AF664)))
  {
    goto block_7;
  }

  var_f12 = (*lbl_803AF664) - var_f12;
  return ((var_f12 * var_f12) * var_f12) * (*lbl_803AF668);
  block_7:
  return *lbl_803AF654;

}
