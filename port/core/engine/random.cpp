#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "random.c"
/* Reference compiler form for GWMP8P; exact original entry names retained.
 * This variant intentionally preserves the original two global SDA words.
 * Portable context-based implementation: source/portable/random.c.
 */
typedef unsigned int u32;
extern u32 lbl_804B00C4;
extern u32 lbl_804B00C8;

u32 fn_80162BA8(void)
{
    u32 value = lbl_804B00C4 * 0x41c64e6dU + 0x3039U;
    lbl_804B00C4 = value;
    return value;
}

float fn_80162BC8(void)
{
    u32 value = lbl_804B00C4 * 0x41c64e6dU + 0x3039U;
    lbl_804B00C4 = value;
    return (float)value * 2.3283064365386962890625e-10f;
}

void fn_80162C18(u32 seed)
{
    lbl_804B00C4 = seed;
}

u32 fn_80162C20(void)
{
    u32 value = lbl_804B00C8 * 0x41c64e6dU + 0x3039U;
    lbl_804B00C8 = value;
    return value;
}

float fn_80162C40(void)
{
    u32 value = lbl_804B00C8 * 0x41c64e6dU + 0x3039U;
    lbl_804B00C8 = value;
    return (float)value * 2.3283064365386962890625e-10f;
}

void fn_80162C90(u32 seed)
{
    lbl_804B00C8 = seed;
}

}
