#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_x_802040a8.c"
// desc: Appears to swap the bytes of a 16-bit argument into a stack temporary and pass it to a two-byte write helper.
extern int fn_802047e0(Ptr32<void>, Ptr32<void>, int);
void w3d_s21_write_u16_swapped_802040a8(Ptr32<void> stream, unsigned short value)
{
    unsigned short swapped = value;
    fn_802047e0(stream, &swapped, 2);
}

}
