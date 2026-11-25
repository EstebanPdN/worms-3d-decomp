#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801f6350.c"
extern float fn_802e86d4(float angle);
extern float fn_802e88ac(float angle);
void w3d_k5b_matrix3_rotate_rows02_801f6350(Ptr32<float [3]> rows, float angle)
{
    float c = fn_802e86d4(angle);
    float s = fn_802e88ac(angle);
    int i;
    Ptr32<float> first = rows[0];
    for (i = 0; i < 3; i++) {
        float a = first[i];
        float b = first[i + 6];
        first[i] = a * c - b * s;
        first[i + 6] = b * c + a * s;
    }
}
// desc: w3d_k5b_matrix3_rotate_rows02_801f6350: Appears to rotate rows 0 and 2 of a 3x3 float matrix by an angle, with 0x802e86d4 and 0x802e88ac giving the cosine and sine.

}
