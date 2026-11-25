/* m2c draft tuned by the local decomp-permuter; placeholder types. */

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
f32 w3d_auto_802bc778(void *arg0)
{
  f32 new_var;
  new_var = *((f32 *) (((s8 *) arg0) + 0x4C));
  return (2.0f * (*((f32 *) (((s8 *) arg0) + 0x30)))) / (2.0f * new_var);
}
