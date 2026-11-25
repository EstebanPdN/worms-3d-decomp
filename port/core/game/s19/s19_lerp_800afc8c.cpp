#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_lerp_800afc8c.c"
extern float w3d_auto_801610a0(void);

float s19_lerp_800afc8c(float a, float b)
{
    float t = w3d_auto_801610a0();
    return a + (b - a) * t;
}

}
