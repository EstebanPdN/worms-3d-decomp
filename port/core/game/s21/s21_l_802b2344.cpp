#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_l_802b2344.c"
// desc: Appears to store a state value, inverted in invert mode, only when it changes.
struct S21Toggle { char pad[112]; int state; char pad1[8]; int invert; };
void w3d_s21_toggle_set_state_802b2344(Ptr32<struct S21Toggle> self, int state)
{
    if (self->invert == 1)
        state = state != 1;
    if (self->state != state)
        self->state = state;
}

}
