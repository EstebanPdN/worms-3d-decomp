#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ad_801de9f8.c"
// desc: Appears to copy the three-word vector at offset 20 into the output argument and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[20]; struct S21Vec3 value; };
int w3d_s21_get_vector_801de9f8(Ptr32<struct S21Object> self, Ptr32<struct S21Vec3> out)
{
    *out = self->value;
    return 0;
}

}
