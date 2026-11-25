#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ak_801f757c.c"
// desc: Appears to construct an object with a base constructor and fill an embedded three-float member with a second global constant.
struct S21Vec3 { float x, y, z; };
struct S21Object { char pad[36]; struct S21Vec3 value; };
extern Ptr32<void> fn_801f656c(Ptr32<struct S21Object>, Ptr32<void>, float);
extern float lbl_803b170c[];
static inline void s21_fill(Ptr32<struct S21Vec3> v, float f)
{
    v->x = f;
    v->y = f;
    v->z = f;
}
Ptr32<void> w3d_s21_construct_801f757c(Ptr32<struct S21Object> self, Ptr32<void> arg_r4, float arg_f1)
{
    Ptr32<void> base = fn_801f656c(self, arg_r4, arg_f1);
    s21_fill(&self->value, lbl_803b170c[0]);
    return base;
}

}
