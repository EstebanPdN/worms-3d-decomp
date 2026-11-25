#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ae_801de950.c"
// desc: Appears to copy two three-word vectors from the arguments into the object at offsets 32 and 44 and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[32]; struct S21Vec3 first; struct S21Vec3 second; };
int w3d_s21_set_vectors_801de950(Ptr32<struct S21Object> self, Ptr32<const struct S21Vec3> first, Ptr32<const struct S21Vec3> second)
{
    self->second = *second;
    self->first = *first;
    return 0;
}

}
