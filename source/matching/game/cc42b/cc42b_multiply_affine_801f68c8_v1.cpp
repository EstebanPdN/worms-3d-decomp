// Observed packed 4x3 left operand and 4x4 right/output operands. Expressions
// retain the original single-precision product tree and final translation add.
// Operands may alias; no restrict qualifier is used.
struct cc42b_AffineRow { float x,y,z; };
struct cc42b_Affine3 { cc42b_AffineRow rows[4]; };
struct cc42b_AffineMatrix4 { float element[4][4]; };
extern "C" void cc42b_multiply_affine_801f68c8(cc42b_AffineMatrix4 *out,const cc42b_Affine3 *left,const cc42b_AffineMatrix4 *right) {
    for (int row=0; row<3; ++row) {
        for (int column=0; column<4; ++column) {
            out->element[row][column] =
                left->rows[row].x*right->element[0][column] +
                left->rows[row].y*right->element[1][column] +
                left->rows[row].z*right->element[2][column];
        }
    }
    for (int column=0; column<4; ++column) {
        out->element[3][column] =
            left->rows[3].x*right->element[0][column] +
            left->rows[3].y*right->element[1][column] +
            left->rows[3].z*right->element[2][column] +
            right->element[3][column];
    }
}
