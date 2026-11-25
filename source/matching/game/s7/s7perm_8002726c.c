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
void *fn_800FC6DC();
s32 fn_80178C48();
M2C_UNK fn_803426B4(s32);
extern f32 lbl_8036CB60[];
f32 w3d_auto_8002726c(void *arg0)
{
  fn_803426B4(*((s32 *) (((s8 *) arg0) + 0x1C)));
  if (fn_80178C48() != (-1))
  {
    if (lbl_8036CB60)
    {
      goto block_2;
    }
    else
    {
      goto block_2;
    }
  }
  return *lbl_8036CB60;
  block_2:
  return *((f32 *) (((s8 *) fn_800FC6DC()) + 0x74));

}
