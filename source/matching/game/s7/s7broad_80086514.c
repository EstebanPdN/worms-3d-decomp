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
void fn_8007F278();
M2C_UNK fn_8007FA08(void *, f32 *, s32);
M2C_UNK fn_80085FF8(void *);
M2C_UNK fn_80086288(void *);
void fn_80086324(void *);
extern s32 lbl_804ADB20;
extern s32 lbl_804ADB24;
void w3d_auto_80086514(s32 arg0, void *arg1, s32 arg2)
{
  f32 sp8[3];
  f32 new_var;
  s8 *new_var2;
  fn_8007F278();
  if ((lbl_804ADB20 | lbl_804ADB24) == 0)
  {
    goto block_2;
  }
  fn_80085FF8(arg0);
  fn_80086288(arg0);
  fn_80086324(arg0);
  sp8[0] = *((f32 *) (((s8 *) arg1) + 0));
  new_var2 = (s8 *) (&sp8);
  *((f32 *) (new_var2 + 4)) = (f32) (*((f32 *) (((s8 *) arg1) + 4)));
  *((f32 *) (new_var2 + 8)) = (f32) (new_var = *((f32 *) (((s8 *) arg1) + 8)));
  fn_8007FA08(arg0, &sp8, arg2);
  block_2:
  return;

}
