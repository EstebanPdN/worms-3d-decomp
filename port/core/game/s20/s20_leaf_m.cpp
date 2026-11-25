#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_m.c"
/* Matrix copies, slot scanning and a string hash. */
typedef struct S20Mat4 { float m[12]; } S20Mat4;

int w3d_s20_set_inner_matrix_8017b0b8(Ptr32<char> self, Ptr32<S20Mat4> value) {
    Ptr32<char> inner = *(Ptr32<Ptr32<char>>)(*(Ptr32<Ptr32<char>>)(self + 120) + 48);
    *(Ptr32<S20Mat4>)(inner + 20) = *value;
    {
        Ptr32<char> flags = inner + 4;
        *(Ptr32<unsigned char>)(flags + 4) &= 0xfd;
    }
    return 0;
}

int w3d_s20_get_inner_matrix_8017b5f4(Ptr32<char> self, Ptr32<S20Mat4> out) {
    Ptr32<char> inner = *(Ptr32<Ptr32<char>>)(*(Ptr32<Ptr32<char>>)(self + 120) + 48);
    *out = *(Ptr32<S20Mat4>)(inner + 20);
    return 0;
}


}
