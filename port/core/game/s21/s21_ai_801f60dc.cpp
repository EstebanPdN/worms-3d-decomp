#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ai_801f60dc.c"
// desc: Appears to copy a three-by-three float matrix from the second argument into the first with rows and columns exchanged.
struct S21Matrix3 { float m[3][3]; };
void w3d_s21_transpose3_801f60dc(Ptr32<struct S21Matrix3> dst, Ptr32<const struct S21Matrix3> src)
{
    int i, j;
    for (i = 0; i <= 2; i++)
        for (j = 0; j < 3; j++)
            dst->m[i][j] = src->m[j][i];
}

}
