#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_p.c"
/* Push with overflow flush, bump allocation, reference adjust and handle compare. */
extern void fn_80167094(Ptr32<char>);

void w3d_s20_push_pending_8016703c(Ptr32<char> self, int value) {
    Ptr32<char> items;
    int offset;
    if (*(Ptr32<unsigned int>)(self + 5256) > 1023)
        fn_80167094(self);
    items = self + 1160;
    offset = *(Ptr32<int>)(self + 5256) * 4;
    *(Ptr32<int>)(items + offset) = value;
    *(Ptr32<int>)(self + 5256) += 1;
}

typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef struct S20Counter { Ptr32<Ptr32<void>> vtable; char pad[76]; unsigned char count; } S20Counter;
typedef struct S20Holder20 { char pad[20]; Ptr32<S20Object> inner; } S20Holder20;

void w3d_s20_drop_reference_8019ab0c(Ptr32<S20Holder20> self, Ptr32<char> item) {
    Ptr32<S20Object> first = ((Ptr32<Ptr32<S20Object> (Ptr32<S20Object>)>)self->inner->vtable[7])(self->inner);
    Ptr32<S20Counter> second = ((Ptr32<Ptr32<S20Counter> (Ptr32<S20Object>, int)>)first->vtable[9])(first, *(Ptr32<unsigned short>)(item + 16));
    second->count -= 1;
}

extern int fn_801190d0(Ptr32<void>);
extern Ptr32<void> fn_80164fc8(int);
extern int fn_800da7bc(Ptr32<void>);

int w3d_s20_matches_handle_8013f168(Ptr32<char> self, int handle) {
    Ptr32<void> object = fn_80164fc8(fn_801190d0(w3d::G(handle)));
    return object ? fn_800da7bc(object) == *(Ptr32<int>)(self + 112) : 0;
}

}
