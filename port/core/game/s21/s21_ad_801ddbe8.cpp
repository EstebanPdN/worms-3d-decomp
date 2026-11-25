#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ad_801ddbe8.c"
// desc: Appears to return the float stored at an index of an inline float array.
struct S21Floats { char pad[20]; float values[1]; };
float w3d_s21_get_float_801ddbe8(Ptr32<struct S21Floats> self, int index)
{
    return self->values[index];
}

}
