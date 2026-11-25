// desc: Appears to be a static initialization entry that sets a global four-by-four float matrix to the identity using two global float constants when called with the final priority.
struct S21Matrix4 { float m[4][4]; };
extern struct S21Matrix4 lbl_8045e708[];
extern float lbl_803b16f8[];
extern float lbl_803b16fc[];
void w3d_s21_static_identity4_801f736c(int initialize, int priority)
{
    float one, zero;
    if (priority == 0xffff && initialize) {
        one = lbl_803b16f8[0];
        zero = lbl_803b16fc[0];
        lbl_8045e708->m[0][0] = one;
        lbl_8045e708->m[0][1] = zero;
        lbl_8045e708->m[0][2] = zero;
        lbl_8045e708->m[0][3] = zero;
        lbl_8045e708->m[1][0] = zero;
        lbl_8045e708->m[1][1] = one;
        lbl_8045e708->m[1][2] = zero;
        lbl_8045e708->m[1][3] = zero;
        lbl_8045e708->m[2][0] = zero;
        lbl_8045e708->m[2][1] = zero;
        lbl_8045e708->m[2][2] = one;
        lbl_8045e708->m[2][3] = zero;
        lbl_8045e708->m[3][0] = zero;
        lbl_8045e708->m[3][1] = zero;
        lbl_8045e708->m[3][2] = zero;
        lbl_8045e708->m[3][3] = one;
    }
}
