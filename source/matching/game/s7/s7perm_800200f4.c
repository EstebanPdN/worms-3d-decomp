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
M2C_UNK fn_801FE1F8(s32);
void w3d_auto_800200f4(s32 arg0)
{
  s32 *var_r31;
  int new_var;
  s32 var_r30;
  new_var = 0;
  var_r31 = arg0 + 0x3C;
  var_r30 = 2;
  loop_1:
  fn_801FE1F8(*var_r31);

  *var_r31 = new_var;
  var_r30 -= 1;
  var_r31 += 1;
  if (var_r30 != 0)
  {
    goto loop_1;
  }
  return;
}
