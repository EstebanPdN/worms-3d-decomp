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
M2C_UNK fn_8002BC14();
extern f32 lbl_80372644[];
extern f32 lbl_80372648[];
extern void *lbl_804B1788;
void w3d_auto_8002c17c(void *arg0)
{
  f32 temp_f0;
  f32 new_var;
  new_var = *lbl_80372648;
  temp_f0 = (*((f32 *) (((s8 *) arg0) + 0x5C))) * (*lbl_80372644);
  *((f32 *) (((s8 *) arg0) + 0x5C)) = temp_f0;
  if (!(temp_f0 > new_var))
  {
    goto block_2;
  }
  *((f32 *) (((s8 *) arg0) + 0x5C)) = (f32) new_var;
  *((s32 *) (((s8 *) arg0) + 0x58)) = 0;
  block_2:
  fn_8002BC14();

  *((s32 *) (((s8 *) lbl_804B1788) + 0xBC)) = (s32) ((*((s32 *) (((s8 *) lbl_804B1788) + 0xBC))) | 4);
  return;
}
