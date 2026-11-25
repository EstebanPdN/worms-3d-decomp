/* Recovery s9: reference-verified decomp-permuter output. */

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
M2C_UNK fn_8015FC84(void *, void *);
void *fn_801613F0(void *, M2C_UNK);
extern M2C_UNK lbl_8040DB38[];
extern s32 lbl_804B1754;
void s9_permute_80160708(s32 arg0, s8 arg1, s32 arg2, f32 farg0)
{
  f32 new_var;
  void *temp_r3;
  temp_r3 = fn_801613F0(lbl_804B1754, 0x14);
  *((s16 *) (((s8 *) temp_r3) + 0)) = 0x1003;
  new_var = farg0;
  *((M2C_UNK **) (((s8 *) temp_r3) + 4)) = &(*lbl_8040DB38);
  *((s32 *) (((s8 *) temp_r3) + 8)) = arg2;
  *((s8 *) (((s8 *) temp_r3) + 0xC)) = arg1;
  *((f32 *) (((s8 *) temp_r3) + 0x10)) = new_var;
  fn_8015FC84(arg0, temp_r3);
  return;
}
