#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_y_802041a4.c"
// desc: Appears to write a second eight-byte integer value, byte-identical to its sibling, through the same write helper.
extern int fn_802047e0(Ptr32<void>, Ptr32<void>, int);
void w3d_s21_write_i64_802041a4(Ptr32<void> stream, int unused, long long value)
{
    long long copy = value;
    fn_802047e0(stream, &copy, 8);
}

}
