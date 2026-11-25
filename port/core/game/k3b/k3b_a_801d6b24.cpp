#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k3b_a_801d6b24.c"
extern float w3d_math_sinf_802e88ac(float x);
float w3d_k3b_math_sinc_801d6b24(float x)
{
    float t = x * 3.1415927f;
    float r;
    if (t == 0.0f)
        r = 1.0f;
    else
        r = w3d_math_sinf_802e88ac(t) / t;
    return r;
}
// desc: Appears to compute the normalized sinc function sin(pi*x)/(pi*x), returning one at zero.

}
