#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ad_801dea60.c"
// desc: Appears to copy the three-word vector at offset 56 into the output argument and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[56]; struct S21Vec3 value; };
int w3d_s21_get_second_vector_801dea60(Ptr32<struct S21Object> self, Ptr32<struct S21Vec3> out)
{
    *out = self->value;
    return 0;
}

}
