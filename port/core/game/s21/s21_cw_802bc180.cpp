#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cw_802bc180.c"
// desc: Appears to copy a three-float vector into the object at offset 44 and call a follow-up helper when the pointer vector at offset 56 is not empty.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[44]; struct S21Vec3 position; Ptr32<int> begin; Ptr32<int> end; };
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
extern void fn_802bc1d4(Ptr32<struct S21Object>);
void w3d_s21_set_position_802bc180(Ptr32<struct S21Object> self, Ptr32<const struct S21Vec3> position)
{
    s21_copy(&self->position, position);
    if ((unsigned)(self->end - self->begin) != 0)
        fn_802bc1d4(self);
}

}
