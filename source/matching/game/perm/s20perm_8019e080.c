/* m2c output tuned by decomp-permuter (tools/permute_near_misses.py); verified
 * identical to the original after linking. Placeholder types pending review. */

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
M2C_UNK fn_802CD808(void *, M2C_UNK);
s32 fn_802CD9E8(s32, M2C_UNK);
M2C_UNK fn_802CDFD4(s32, void *);
M2C_UNK fn_802CE244(void *, s32);
M2C_UNK fn_802CE264(void *, M2C_UNK);
M2C_UNK fn_802CE6E4(void *, M2C_UNK, M2C_UNK);
s32 w3d_auto_8019e080(void *arg0, s32 arg1, s32 arg2)
{
  fn_802CDFD4(*((s32 *) (((s8 *) arg0) + 0x14)), (void *)arg1);
  fn_802CE264(*((s32 *) (((s8 *) arg0) + 0x14)), -0x2711);
  if (fn_802CD9E8(*((s32 *) (((s8 *) arg0) + 0x14)), -1) != 0)
  {
    if (arg0)
    {
      goto block_2;
    }
    else
    {
      goto block_2;
    }
  }
  fn_802CD808(*((s32 *) (((s8 *) arg0) + 0x14)), -2);
  return 0x80004005;
  block_2:
  fn_802CE244(*((s32 *) (((s8 *) arg0) + 0x14)), arg2);

  fn_802CE6E4(*((s32 *) (((s8 *) arg0) + 0x14)), 1, 0);
  return 0;
}
