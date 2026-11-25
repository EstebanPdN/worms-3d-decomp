#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_dg_802bccac.c"
// desc: Appears to copy two three-float vectors into the object at offsets 32 and 44 and call a follow-up helper when the mode field at offset 80 equals one.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[32]; struct S21Vec3 first; struct S21Vec3 second; char pad1[24]; int mode; };
extern void fn_802bc1d4(Ptr32<struct S21Object>);
static inline void s21_copy(Ptr32<struct S21Vec3> dst, Ptr32<const struct S21Vec3> src)
{
    float x, y, z;
    x = src->x;
    y = src->y;
    z = src->z;
    dst->x = x;
    dst->y = y;
    dst->z = z;
}
void w3d_s21_set_positions_802bccac(Ptr32<struct S21Object> self, Ptr32<const struct S21Vec3> first, Ptr32<const struct S21Vec3> second)
{
    s21_copy(&self->first, first);
    s21_copy(&self->second, second);
    if (self->mode == 1)
        fn_802bc1d4(self);
}

}
