#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bj_8020e9d0.c"
// desc: Appears to convert each signed integer of the source to a float in the destination for a given count and return zero.
int w3d_s21_convert_int_to_float_8020e9d0(Ptr32<int> src, int unused1, Ptr32<float> dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = (float)*src++;
    }
    return 0;
}

}
