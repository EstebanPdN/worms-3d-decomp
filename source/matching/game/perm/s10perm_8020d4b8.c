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
s32 w3d_auto_8020d4b8(void *arg0, u32 arg1, s32 arg2, u32 *arg3)
{
  u32 var_r11;
  var_r11 = *((u32 *) (((s8 *) arg0) + 0x18));
  if (arg3 == ((void *) 0))
  {
    goto block_2;
  }
  if (1)
  {
    *arg3 = var_r11;
    block_2:
    if (arg2 == 1)
    {
      goto block_8;
    }

  }
  if (arg2 > 1)
  {
    goto block_6;
  }
  if (arg2 == 0)
  {
    goto block_10;
  }
  goto block_11;
  block_6:
  if (arg2 == 2)
  {
    goto block_9;
  }

  goto block_11;
  block_8:
  var_r11 += arg1;

  goto block_11;
  block_9:
  var_r11 = (*((u16 *) (((s8 *) (*(*((void ***) (((s8 *) arg0) + 0x14))))) + (-4)))) + arg1;

  goto block_11;
  block_10:
  var_r11 = arg1;

  block_11:
  if (var_r11 > ((u16) (*((u16 *) (((s8 *) (*(*((void ***) (((s8 *) arg0) + 0x14))))) + (-4))))))
  {
    if (arg0)
    {
      goto block_13;
    }
    else
    {
      goto block_13;
    }
  }

  *((u32 *) (((s8 *) arg0) + 0x18)) = var_r11;
  return 0;
  block_13:
  return 0x90000003;

}
