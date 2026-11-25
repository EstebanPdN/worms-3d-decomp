/* m2c output tuned by decomp-permuter (tools/permute_near_misses.py); verified
 * identical to the original after linking. Placeholder types pending review. */

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
extern void *lbl_804B1788;
void w3d_auto_800fc668(void)
{
  void *new_var;
  void **temp_r3;
  temp_r3 = *((void ***) (((s8 *) lbl_804B1788) + 0x64));
  (*((M2C_UNK (**)(void **, void *)) (((s8 *) (*(*((void ***) (((s8 *) lbl_804B1788) + 0x64))))) + 0x70)))(temp_r3, new_var);
  new_var = lbl_804B1788;
  return;
}
