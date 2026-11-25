#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bj_8020e834.c"
// desc: Appears to convert each unsigned integer of the source to a float in the destination for a given count and return zero.
int w3d_s21_convert_uint_to_float_8020e834(Ptr32<unsigned int> src, int unused1, Ptr32<float> dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = (float)*src++;
    }
    return 0;
}

}
