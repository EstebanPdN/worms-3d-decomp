
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
M2C_UNK fn_8002A914();
extern M2C_UNK lbl_8040FC48[];


extern __typeof__(fn_8002A914) fn_8015fef0;
extern __typeof__(lbl_8040FC48) lbl_80410018;

void *s8_transplant_800e28b0(void *arg0)
{
  s8 *new_var;
  new_var = (s8 *) arg0;
  fn_8015fef0();
  *((s32 *) (new_var + 0x2c)) = 0;
  *((M2C_UNK **) (((s8 *) arg0) + 0)) = &(*lbl_80410018);
  *((s32 *) (new_var + 0x20)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x28)) = 0;
  *((s32 *) (new_var + 0x24)) = 0;
  *((s32 *) (new_var + 0x1c)) = 0;
  *((s32 *) (new_var + 0x30)) = 0;
  *((s32 *) (new_var + 0x2c)) = 0;
  return arg0;
}
