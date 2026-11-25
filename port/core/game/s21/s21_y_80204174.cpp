#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_y_80204174.c"
// desc: Appears to write an eight-byte value from an unaligned argument pair into a stack temporary and pass it to a write helper.
extern int fn_802047e0(Ptr32<void>, Ptr32<void>, int);
void w3d_s21_write_u64_80204174(Ptr32<void> stream, int unused, long long value)
{
    long long copy = value;
    fn_802047e0(stream, &copy, 8);
}

}
