
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
M2C_UNK fn_802AFB20(void *);
extern M2C_UNK lbl_8041C590[];
extern M2C_UNK lbl_8041C5E0[];
void *w3d_auto_802af3b4(void *arg0)
{
  fn_8015FEF0();
  fn_802AFB20(arg0 + 0x1C);
  *((M2C_UNK **) (((s8 *) arg0) + 0xD0)) = &(*lbl_8041C590);
  *((M2C_UNK **) (((s8 *) arg0) + 0)) = &(*lbl_8041C5E0);
  *((s32 *) (((s8 *) arg0) + 0xE0)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xE4)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xD4)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xD8)) = 0;
  *((s32 *) (((s8 *) arg0) + 0xDC)) = 0;
  return arg0;
}
