#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ak_801f75c0.c"
// desc: Appears to construct an object with a base constructor and set an embedded three-float member from the three float arguments.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[36]; struct S21Vec3 value; };
extern Ptr32<void> fn_801f6034(Ptr32<struct S21Object>);
static inline void s21_set(Ptr32<struct S21Vec3> v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
Ptr32<void> w3d_s21_construct_801f75c0(Ptr32<struct S21Object> self, float x, float y, float z)
{
    Ptr32<void> base = fn_801f6034(self);
    s21_set(&self->value, x, y, z);
    return base;
}

}
