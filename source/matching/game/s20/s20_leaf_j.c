/* Struct copies and entry allocation. */
typedef struct S20Mat4 { float m[16]; } S20Mat4;
typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;

S20Quad *w3d_s20_get_quad_8016768c(char *self, S20Quad *out) {
    *out = *(S20Quad *)(self + 24);
    return out;
}

S20Mat4 *w3d_s20_get_matrix_80167824(char *self, S20Mat4 *out) {
    *out = *(S20Mat4 *)(self + 48);
    return out;
}

int w3d_s20_set_matrix_80167898(char *self, S20Mat4 *value) {
    *(S20Mat4 *)(self + 112) = *value;
    return 0;
}

