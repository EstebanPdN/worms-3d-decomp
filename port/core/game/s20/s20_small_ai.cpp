#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ai.c"
/* Scaled offset with an unused stack pair. */
extern float lbl_8039f900[];
extern float lbl_8039f904[];
extern float lbl_8039f908[];
extern float lbl_8039f90c[];
float w3d_s20_compute_scaled_offset_8013c844(Ptr32<char> self) {
    volatile float words[2];
    float ratio = (*(Ptr32<float>)(self + 580) + lbl_8039f900[0]) / lbl_8039f904[0];
    float result;
    words[1] = lbl_8039f90c[0];
    result = 2.0f * (lbl_8039f908[0] - ratio);
    words[0] = result;
    return result;
}

}
