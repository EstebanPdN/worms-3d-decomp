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
M2C_UNK fn_801628B0();
extern M2C_UNK lbl_8040E8F8[];
extern M2C_UNK **lbl_804AA958;
extern M2C_UNK **lbl_804AA96C;
M2C_UNK **w3d_auto_8003f254(M2C_UNK **arg0)
{
  M2C_UNK *new_var;
  M2C_UNK **new_var2;
  fn_801628B0();
  new_var2 = lbl_804AA96C;
  new_var = lbl_8040E8F8;
  *arg0 = &(*new_var);
  if (((M2C_UNK **) new_var2) != ((void *) 0))
  {
    goto block_2;
  }
  lbl_804AA958 = new_var2;
  lbl_804AA96C = arg0;
  block_2:
  return arg0;

}
