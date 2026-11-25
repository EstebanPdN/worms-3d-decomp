#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_x_8020406c.c"
// desc: Appears to swap the bytes of a 16-bit value taken from an int argument into a stack temporary and pass it to a two-byte write helper.
extern int fn_802047e0(Ptr32<void>, Ptr32<void>, int);
void w3d_s21_write_u16_swapped_8020406c(Ptr32<void> stream, unsigned value)
{
    unsigned short x = value;
    unsigned short swapped = x;
    fn_802047e0(stream, &swapped, 2);
}

}
