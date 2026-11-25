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
M2C_UNK fn_8020C3A0(void *, s32);
M2C_UNK fn_8020C43C(void *, s32, s32);
s32 w3d_auto_8020d44c(void *arg0, s32 arg1, s32 arg2, s32 *arg3)
{
  fn_8020C3A0(*((s32 *) (((s8 *) arg0) + 0x14)), *((s32 *) (((s8 *) arg0) + 0x18)));
 do { fn_8020C43C(*((s32 *) (((s8 *) arg0) + 0x14)), arg1, arg2); *((s32 *) (((s8 *) arg0) + 0x18)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x18))) + arg2); if (arg3 == ((void *) 0)) { goto block_2; } *arg3 = arg2; block_2: return 0; } while (0);
}
