#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ae.c"
/* Release of two held objects and a range setter. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;

typedef struct S20HeldPair { char pad0[24]; unsigned int flags; char pad1[20]; Ptr32<S20Object> first; Ptr32<S20Object> second; } S20HeldPair;

int w3d_s20_clear_held_pair_801882c8(Ptr32<S20HeldPair> self) {
    int result = 0;
    self->flags &= 0xffff7fff;
    if (self->first != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)self->first->vtable[4])(self->first);
    self->first = (Ptr32<S20Object>)w3d::G(result);
    if (self->second != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)self->second->vtable[4])(self->second);
    self->second = (Ptr32<S20Object>)w3d::G(result);
    return result;
}

int w3d_s20_set_range_8017dfb4(Ptr32<char> self, unsigned int low, unsigned int high) {
    if (low >= ((Ptr32<unsigned int (Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)self)[44])(self) || high >= ((Ptr32<unsigned int (Ptr32<char>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)self)[44])(self))
        return 0x80004005;
    *(Ptr32<unsigned char>)(self + 9808) = low;
    *(Ptr32<unsigned char>)(self + 9809) = high;
    return 0;
}

}
