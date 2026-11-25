#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_n.c"
/* Pool acquisition, quad copy with forward, and dispatch of a stored record. */
extern Ptr32<char> fn_801ef048(Ptr32<char>, int, int, int);

Ptr32<char> w3d_s20_acquire_pooled_80171fa0(Ptr32<char> self) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 76);
    Ptr32<char> list = owner + 40;
    Ptr32<char> pool = *(Ptr32<Ptr32<char>>)list;
    int arg = *(Ptr32<int>)(pool + 24);
    if (*(Ptr32<unsigned short>)(pool + 4) != 1)
        return fn_801ef048(list, arg, 8, 2);
    *(Ptr32<unsigned short>)(pool + 28) += 1;
    return pool + 32;
}

Ptr32<char> w3d_s20_acquire_pooled_80171ff8(Ptr32<char> self) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 76);
    Ptr32<char> list = owner + 36;
    Ptr32<char> pool = *(Ptr32<Ptr32<char>>)list;
    int arg = *(Ptr32<int>)(pool + 24);
    if (*(Ptr32<unsigned short>)(pool + 4) != 1)
        return fn_801ef048(list, arg, 8, 2);
    *(Ptr32<unsigned short>)(pool + 28) += 1;
    return pool + 32;
}

typedef struct S20Quad { int a; int b; int c; int d; } S20Quad;
extern void fn_801f5724(Ptr32<char>, Ptr32<char>);

int w3d_s20_set_quad_and_forward_801a55f0(Ptr32<char> self, Ptr32<S20Quad> value) {
    *(Ptr32<S20Quad>)(self + 44) = *value;
    fn_801f5724(self + 60, self + 44);
    return 0;
}

typedef Ptr32<int (Ptr32<char>, Ptr32<char>)> S20DispatchN;

int w3d_s20_dispatch_stored_801a3c6c(Ptr32<char> self, Ptr32<char> item) {
    Ptr32<char> record = *(Ptr32<Ptr32<char>>)(item + 28);
    if (*(Ptr32<int>)(record + 24) != 0) {
        Ptr32<char> target = *(Ptr32<Ptr32<char>>)(record + 32);
        Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(self + 24);
        unsigned short slot = *(Ptr32<unsigned short>)(target + 6);
        int result = ((S20DispatchN)table[slot])(self, target);
        if (result < 0)
            return result;
    }
    return 0;
}

}
