#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1a_tick_state_8003e370.c"
struct K1aState { char pad0[84]; int state; };
extern void k1a_fn_8003ed10(Ptr32<struct K1aState>);

void k1a_state_dispatch_8003e370(Ptr32<struct K1aState> self)
{
    if (self->state == 0)
        goto done;
    if (self->state != 1)
        goto done;
    k1a_fn_8003ed10(self);
done:
    return;
}

}
