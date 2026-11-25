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
M2C_UNK fn_8004B3F0(f32 *, f32);
extern f32 lbl_80377108[];
void w3d_auto_8004b3c8(void)
{
  f32 *new_var;
  f32 new_var3;
  f32 *new_var4[2];
  new_var = new_var4[0];
  new_var4[1] = &(*lbl_80377108);
  new_var4[0] = new_var4[1];
  fn_8004B3F0(new_var, new_var3 = *lbl_80377108);
  return;
}
