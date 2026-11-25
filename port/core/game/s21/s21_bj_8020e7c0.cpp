#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bj_8020e7c0.c"
// desc: Appears to convert each float of the source to an unsigned integer in the destination for a given count and return zero.
int w3d_s21_convert_float_to_uint_8020e7c0(Ptr32<float> src, int unused1, Ptr32<unsigned int> dst, int unused2, unsigned count)
{
    while (count--) {
        *dst = (unsigned)*src;
        dst++;
        src++;
    }
    return 0;
}

}
