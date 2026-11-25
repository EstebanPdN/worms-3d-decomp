#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_j.c"
/* Struct copies and entry allocation. */
typedef struct S20Mat4 { float m[16]; } S20Mat4;
typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;

Ptr32<S20Quad> w3d_s20_get_quad_8016768c(Ptr32<char> self, Ptr32<S20Quad> out) {
    *out = *(Ptr32<S20Quad>)(self + 24);
    return out;
}

Ptr32<S20Mat4> w3d_s20_get_matrix_80167824(Ptr32<char> self, Ptr32<S20Mat4> out) {
    *out = *(Ptr32<S20Mat4>)(self + 48);
    return out;
}

int w3d_s20_set_matrix_80167898(Ptr32<char> self, Ptr32<S20Mat4> value) {
    *(Ptr32<S20Mat4>)(self + 112) = *value;
    return 0;
}


}
