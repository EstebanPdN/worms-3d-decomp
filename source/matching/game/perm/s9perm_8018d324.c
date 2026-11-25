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
s32 fn_8018CA30();
s32 s9_permute_8018d324(void *arg0, s32 arg1)
{
  if (((s32) (*((s32 *) (((s8 *) arg0) + 0xC0)))) == arg1)
  {
    if (arg1)
    {
      goto block_2;
    }
    else
    {
      goto block_2;
    }
  }
  *((s32 *) (((s8 *) arg0) + 0xC0)) = arg1;
  return fn_8018CA30();
  block_2:
  return 0;

}
