#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dt_801dea1c.c"
// desc: Appears to copy the three-word vectors at offsets 32 and 44 into two output arguments and return zero.
struct S21Vec3 { int x, y, z; };
struct S21Object { char pad[32]; struct S21Vec3 first; struct S21Vec3 second; };
static inline void s21_copy(Ptr32<struct S21Vec3> dst, Ptr32<const struct S21Vec3> src)
{
    *dst = *src;
}
int w3d_s21_get_vectors_801dea1c(Ptr32<struct S21Object> self, Ptr32<struct S21Vec3> first, Ptr32<struct S21Vec3> second)
{
    s21_copy(first, &self->first);
    s21_copy(second, &self->second);
    return 0;
}

}
