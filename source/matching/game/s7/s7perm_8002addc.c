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
M2C_UNK fn_8002AF78();
s16 fn_8015F5A0(M2C_UNK *, M2C_UNK);
void *fn_801613F0(s32, M2C_UNK);
M2C_UNK fn_8016239C(void *);
extern M2C_UNK lbl_8040DB38[];
extern M2C_UNK lbl_804ACC3C;
extern M2C_UNK lbl_804ACC54;
extern s32 lbl_804B1754;
void w3d_auto_8002addc(void *arg0)
{
  s32 new_var;
  void *temp_r30;
  void *temp_r30_2;
  fn_8002AF78();
  new_var = lbl_804B1754;
  *((s32 *) (((s8 *) arg0) + 0x3C)) = 2;
  temp_r30 = fn_801613F0(new_var, 8);
  *((s16 *) (((s8 *) temp_r30) + 0)) = fn_8015F5A0(&lbl_804ACC54, 1);
  *((M2C_UNK **) (((s8 *) temp_r30) + 4)) = &(*lbl_8040DB38);
  fn_8016239C(temp_r30);
  temp_r30_2 = fn_801613F0(lbl_804B1754, 8);
  *((s16 *) (((s8 *) temp_r30_2) + 0)) = fn_8015F5A0(&lbl_804ACC3C, 1);
  *((M2C_UNK **) (((s8 *) temp_r30_2) + 4)) = &(*lbl_8040DB38);
  fn_8016239C(temp_r30_2);
  return;
}
