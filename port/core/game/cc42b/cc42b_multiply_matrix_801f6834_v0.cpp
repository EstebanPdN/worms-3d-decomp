#include "w3d_ptr.h"
#line 1 "cc42b_multiply_matrix_801f6834_v0.cpp"
// Original scalar single-precision 4x4 product, with the observed expression
// tree retained for the reference compiler's fmuls/fmadds contraction.
// No restrict qualifier or alias-disallowing contract is introduced.
struct cc42b_Matrix4 { float element[4][4]; };
extern "C" void cc42b_multiply_matrix_801f6834(Ptr32<cc42b_Matrix4> out,Ptr32<const cc42b_Matrix4> left,Ptr32<const cc42b_Matrix4> right) {
    for (int row=0; row<4; ++row) {
        for (int column=0; column<4; ++column) {
            out->element[row][column] =
                left->element[row][0]*right->element[0][column] +
                left->element[row][1]*right->element[1][column] +
                left->element[row][2]*right->element[2][column] +
                left->element[row][3]*right->element[3][column];
        }
    }
}


