#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aj_801f79ac.c"
// desc: Appears to copy four floats from the second argument into the first, starting with the fourth, and return the destination.
struct S21Quat { float x, y, z, w; };
Ptr32<struct S21Quat> w3d_s21_copy_quat_801f79ac(Ptr32<struct S21Quat> dst, Ptr32<const struct S21Quat> src)
{
    dst->w = src->w;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}

}
