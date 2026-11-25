#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c33_poll_dispatch_801fdbec.c"
/* Reference-only: maps a platform status code to a small state value, then
   forwards to a callback or a default handler. Field offsets, state values
   and meanings are inferred; the status codes are raw values observed in the
   comparisons. Callees are external originals declared by address. */
struct Poll { int state; Ptr32<int (int)> callback; };
extern int fn_80344278(void);
extern void fn_801fe314(Ptr32<void>);
extern int fn_802f76e0(void);
extern int fn_801fde88(Ptr32<struct Poll>);

int tsonnet_c33_poll_dispatch_801fdbec(Ptr32<struct Poll> self) {fn_801fe314((Ptr32<void>)w3d::G(fn_80344278()));
    switch (fn_802f76e0()) {
    case 5: self->state = 1; break;
    case 4: self->state = 2; break;
    case 6: self->state = 3; break;
    case 11: self->state = 4; break;
    case -1: self->state = 5; break;
    case 2: break;
    default: self->state = 0; break;
    }
    if (!self->callback)
        return fn_801fde88(self);
    return self->callback(self->state);
}

}
