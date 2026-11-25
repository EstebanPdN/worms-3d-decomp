#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_a.c"
/* Small accessors and forwarding wrappers. */
extern int fn_801ad8c0(Ptr32<char>);
extern int fn_8020b680(Ptr32<void>);
extern void fn_8020c3a0(Ptr32<char>, int);
typedef struct S20Holder { char pad[12]; Ptr32<void> held; } S20Holder;
typedef struct S20Pair { int first; int second; } S20Pair;

int w3d_s20_forward_derived_801ad934(Ptr32<char> self) {
    Ptr32<char> base = self ? w3d::R(self - 4) : 0;
    Ptr32<char> sub = base ? w3d::R(base + 4) : 0;
    return fn_801ad8c0(sub);
}

int w3d_s20_forward_held_8019013c(Ptr32<char> self) {
    if (!((Ptr32<S20Holder>)self)->held)
        return 0;
    return fn_8020b680(((Ptr32<S20Holder>)self)->held);
}

void w3d_s20_copy_pair_801c83e8(Ptr32<char> self, Ptr32<S20Pair> source) {
    *(Ptr32<S20Pair>)(self + 24) = *source;
}

int w3d_s20_reset_range_801b2464(Ptr32<char> self) {
    *(Ptr32<int>)(self + 56) = 0;
    fn_8020c3a0(self + 60, 0);
    return 0;
}

}
