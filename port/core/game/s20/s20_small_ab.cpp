#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ab.c"
/* Calls built from resolved handles. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_80341584(int);
extern Ptr32<char> fn_801797b4(Ptr32<void>);

int w3d_s20_forward_resolved_800e45d0(Ptr32<char> self, int first, int second) {
    Ptr32<char> resolved = fn_801797b4(w3d::G(fn_80341584(*(Ptr32<int>)(self + 156))));
    Ptr32<S20Object> owner = *(Ptr32<Ptr32<S20Object>>)(self + 32);
    Ptr32<char> result = ((Ptr32<Ptr32<char> (Ptr32<S20Object>, int)>)owner->vtable[5])(owner, first);
    Ptr32<Ptr32<void>> table = *(Ptr32<Ptr32<Ptr32<void>>>)(result + 112);
    return ((Ptr32<int (Ptr32<char>, int, int, Ptr32<char>, int)>)table[9])(result, *(Ptr32<int>)(self + 36), second, resolved, 0);
}

}
