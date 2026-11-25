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
M2C_UNK fn_8015FEF0();
extern M2C_UNK lbl_8040E478[];
void *w3d_auto_8002dd68(void *arg0)
{
  fn_8015FEF0();
  *((M2C_UNK **) (((s8 *) arg0) + 0)) = &(*lbl_8040E478);
  *((s32 *) (((s8 *) arg0) + 0x1C)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x20)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x24)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x28)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x58)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x5C)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x4C)) = 0;
  return arg0;
}
