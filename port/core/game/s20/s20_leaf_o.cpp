#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_o.c"
/* Small struct copies and a counter stamp. */
typedef struct S20Pair { int first; int second; } S20Pair;
typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;
extern unsigned short lbl_804ab788;

void w3d_s20_stamp_sequence_801afaa4(Ptr32<char> self) {
    unsigned short next = ++lbl_804ab788;
    *(Ptr32<unsigned short>)(self + 56) = next;
    *(Ptr32<int>)(self + 52) = 0;
}

Ptr32<S20Pair> w3d_s20_get_pair_801c83fc(Ptr32<S20Pair> out, Ptr32<char> source) {
    *out = *(Ptr32<S20Pair>)(source + 24);
    return out;
}

void w3d_s20_set_quad_and_flag_801c8488(Ptr32<char> self, Ptr32<S20Quad> value) {
    *(Ptr32<S20Quad>)(self + 72) = *value;
    *(Ptr32<int>)(self + 88) = 1;
}

int w3d_s20_set_quad_801ab934(Ptr32<char> self, Ptr32<S20Quad> value) {
    *(Ptr32<S20Quad>)(self + 96) = *value;
    return 0;
}

}
