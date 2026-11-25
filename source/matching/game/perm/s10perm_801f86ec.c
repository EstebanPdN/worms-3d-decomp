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
void **fn_801F8F68();
M2C_UNK fn_801F9164(void **, void *);
M2C_UNK fn_801FE1D8(M2C_UNK);
s32 w3d_auto_801f86ec(s32 arg0, void ***arg1)
{
  void **temp_r3;
  fn_801FE1D8(0x20);
  temp_r3 = fn_801F8F68();
  (*((M2C_UNK (**)()) (((s8 *) (*temp_r3)) + 0xC)))();
 do { } while (0);
  fn_801F9164(temp_r3, arg0);
  *arg1 = temp_r3;
  return 0;
}
