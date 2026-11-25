#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_d.c"
/* Small helpers: empty loop, handler dispatch, struct copy, forward differences. */
typedef Ptr32<void (Ptr32<char>, Ptr32<char>)> S20Handler2;
typedef struct S20Block24 { int words[6]; } S20Block24;

int w3d_s20_dispatch_item_801a4a58(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 20);
    return ((Ptr32<int (Ptr32<char>, Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)(self + 24))[*(Ptr32<unsigned short>)(record + 6)])(self, record);
}

void w3d_s20_set_block_801c7e34(Ptr32<char> self, Ptr32<S20Block24> value) {
    *(Ptr32<S20Block24>)(self + 20) = *value;
}

void w3d_s20_forward_differences_80197208(Ptr32<void> self, float a, float b, float c, float d, Ptr32<float> out_third, Ptr32<float> out_c, Ptr32<float> out_b, Ptr32<float> out_a) {
    d = d - c;
    c = c - b;
    b = b - a;
    d = d - c;
    c = c - b;
    d = d - c;
    *out_third = d;
    *out_c = c + c + c;
    *out_b = b + b + b;
    *out_a = a;
}

}
