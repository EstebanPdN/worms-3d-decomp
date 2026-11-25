#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801f725c.c"
extern float fn_802e86d4(float angle);
extern float fn_802e88ac(float angle);
void w3d_k5b_matrix4_axis_angle_801f725c(Ptr32<float [4]> m, float x, float y, float z, float angle)
{
    float s = fn_802e88ac(angle);
    float c = fn_802e86d4(angle);
    float t = 1.0f - c;
    m[3][3] = 1.0f;
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[0][0] = t * x * x + c;
    m[0][1] = t * x * y + s * z;
    m[0][2] = t * x * z - s * y;
    m[1][0] = t * x * y - s * z;
    m[1][1] = t * y * y + c;
    m[1][2] = t * y * z + s * x;
    m[2][0] = t * x * z + s * y;
    m[2][1] = t * y * z - s * x;
    m[2][2] = t * z * z + c;
}
// desc: w3d_k5b_matrix4_axis_angle_801f725c: Appears to build a 4x4 rotation matrix (no translation) from a unit axis and an angle (sine 0x802e88ac, cosine 0x802e86d4).

}
