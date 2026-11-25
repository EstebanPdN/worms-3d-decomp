
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
M2C_UNK fn_800DE930(M2C_UNK);
s32 fn_800E0678();
M2C_UNK fn_8020FD04(M2C_UNK *, void *);
extern M2C_UNK lbl_80360CF0[];
s32 s8_permuted_800e05a4(void)
{
  s32 temp_r3;
  s32 var_r4;
  M2C_UNK *new_var;
  fn_800DE930(0x130);
  temp_r3 = fn_800E0678();
  var_r4 = 0;
  if (temp_r3 == 0)
  {
    goto block_2;
  }
  var_r4 = temp_r3 + 4;
  block_2:
  fn_8020FD04(&(*lbl_80360CF0), var_r4);

  new_var = lbl_80360CF0;
  *((u16 *) (((s8 *) (&(*new_var))) + 0x22)) = (u16) ((*((u16 *) (((s8 *) (&(*new_var))) + 0x22))) + 1);
  return temp_r3;
}
