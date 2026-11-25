#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_apply_fit_8001c0d8.c"
extern void FUN_8001c36c(Ptr32<void> source, Ptr32<float> out_vec, Ptr32<float> out_scale);
extern void FUN_8001c134(Ptr32<void> self, Ptr32<void> a, Ptr32<void> source, Ptr32<float> vec, float scale);

Ptr32<void> k2a_apply_fit_8001c0d8(Ptr32<void> self, int a, Ptr32<void> source)
{
    float vec[4];
    float scale;
    FUN_8001c36c(source, vec, &scale);
    FUN_8001c134(self, w3d::G(a), source, vec, scale);
    return self;
}

}
