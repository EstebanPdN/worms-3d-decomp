#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fm_801f606c.c"
// desc: Appears to multiply two three-by-three float matrices and store the product in the first argument.
struct S21Matrix3 { float m[3][3]; };
void w3d_s21_multiply3_801f606c(Ptr32<struct S21Matrix3> result, Ptr32<const struct S21Matrix3> a, Ptr32<const struct S21Matrix3> b)
{
    int i, j;
    for (i = 0; i <= 2; i++)
        for (j = 0; j < 3; j++)
            result->m[i][j] = a->m[i][0] * b->m[0][j] + a->m[i][1] * b->m[1][j] + a->m[i][2] * b->m[2][j];
}

}
