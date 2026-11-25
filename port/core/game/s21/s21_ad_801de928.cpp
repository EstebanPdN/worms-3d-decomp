#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ad_801de928.c"
// desc: Appears to copy a three-word vector from the argument into the object at offset 20 and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[20]; struct S21Vec3 value; };
int w3d_s21_set_vector_801de928(Ptr32<struct S21Object> self, Ptr32<const struct S21Vec3> value)
{
    self->value = *value;
    return 0;
}

}
