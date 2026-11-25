#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_curve_eval_8009dfd4.c"
typedef struct K2aCurve {
    char pad0[20];
    float offset[8];
    float scale[8];
    float gain[8];
} K2aCurve;
extern float FUN_802e88ac(float);

float k2a_curve_eval_8009dfd4(Ptr32<K2aCurve> self, int index, float x)
{
    Ptr32<float> scale = self->scale;
    float v = FUN_802e88ac(self->offset[index] + self->gain[index] * x);
    return *(Ptr32<float>)((Ptr32<char>)scale + (index << 2)) * v;
}

}
