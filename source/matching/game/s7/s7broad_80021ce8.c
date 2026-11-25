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
M2C_UNK fn_80035714(void *, s32, f32 *, f32);
extern f32 lbl_8036C174[];
extern s32 lbl_804AA8C8;
s32 w3d_auto_80021ce8(void *arg0)
{
  f32 *new_var;
  fn_80035714(lbl_804AA8C8, *((s32 *) (((s8 *) arg0) + 0x14)), &(*new_var), *lbl_8036C174);
  *((s32 *) (((s8 *) arg0) + 4)) = 1;
  return 0;
}
