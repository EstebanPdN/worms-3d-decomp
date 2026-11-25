#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fo_801f675c.c"
// desc: Appears to be a static initialization entry that sets a global three-by-three float matrix to the identity using two global float constants when called with the final priority.
struct S21Matrix3 { float m[3][3]; };
extern struct S21Matrix3 lbl_8045e6e4[];
extern float lbl_803b1644[];
extern float lbl_803b1648[];
void w3d_s21_static_identity3_801f675c(int initialize, int priority)
{
    float one, zero;
    if (priority == 0xffff && initialize) {
        one = lbl_803b1644[0];
        zero = lbl_803b1648[0];
        lbl_8045e6e4->m[0][0] = one;
        lbl_8045e6e4->m[0][1] = zero;
        lbl_8045e6e4->m[0][2] = zero;
        lbl_8045e6e4->m[1][0] = zero;
        lbl_8045e6e4->m[1][1] = one;
        lbl_8045e6e4->m[1][2] = zero;
        lbl_8045e6e4->m[2][0] = zero;
        lbl_8045e6e4->m[2][1] = zero;
        lbl_8045e6e4->m[2][2] = one;
    }
}

}
