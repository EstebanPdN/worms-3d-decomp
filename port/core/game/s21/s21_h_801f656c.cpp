#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_h_801f656c.c"
extern void fn_801f6480(float, float, float, float, Ptr32<void>);
void w3d_s21_forward_vector_801f656c(Ptr32<void> self, Ptr32<const float> v, float w)
{
    fn_801f6480(v[0], v[1], v[2], w, (Ptr32<void>)self);
}

}
