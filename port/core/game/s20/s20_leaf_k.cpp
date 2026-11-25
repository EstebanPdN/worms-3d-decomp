#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_k.c"
/* Small virtual helpers on flag words. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
typedef Ptr32<int (Ptr32<void>)> S20Query;
typedef Ptr32<void (Ptr32<S20Object>)> S20Call0;
typedef struct S20Holder { char pad0[24]; unsigned int flags; char pad1[4]; S20Query validate; char pad2[4]; Ptr32<S20Object> held; } S20Holder;

int w3d_s20_validate_and_flag_801745bc(Ptr32<S20Holder> self) {
    int result = self->validate(self);
    if (result >= 0)
        self->flags |= 0x8000;
    return result;
}

int w3d_s20_release_held_80174620(Ptr32<S20Holder> self) {
    int result = 0;
    if (self->held != 0)
        ((S20Call0)self->held->vtable[4])(self->held);
    self->held = 0;
    self->flags &= ~0x8000u;
    return result;
}

}
