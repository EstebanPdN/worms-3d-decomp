#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_aj_801f69a8.c"
// desc: Appears to copy a four-by-four float matrix from the second argument into the first with rows and columns exchanged.
struct S21Matrix4 { float m[4][4]; };
void w3d_s21_transpose4_801f69a8(Ptr32<struct S21Matrix4> dst, Ptr32<const struct S21Matrix4> src)
{
    int i, j;
    for (i = 0; i <= 3; i++)
        for (j = 0; j < 4; j++)
            dst->m[i][j] = src->m[j][i];
}

}
