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
s32 w3d_auto_801f8de0(void *arg0)
{
  int new_var;
  s32 temp_r0;
  new_var = 0;
  temp_r0 = *((s32 *) (((s8 *) arg0) + 0x24));
  if (temp_r0 == new_var)
  {
    goto block_3;
 do { } while (new_var);
  }
  return temp_r0;
  block_3:
  return new_var;

}
