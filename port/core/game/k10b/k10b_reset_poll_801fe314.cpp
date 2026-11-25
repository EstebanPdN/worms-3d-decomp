#include "w3d_ptr.h"
#line 1 "k10b_reset_poll_801fe314.cpp"
// Partial view of the reset-button state word: the top bit records that the
// reset sequence has already been started, the next bit that a press was seen.
struct K10bResetState_801fe314 {
    unsigned int rest:30; unsigned int pressed:1; unsigned int handled:1;
};

extern "C" {
int fn_802fec74();
void fn_801fe3b0(Ptr32<K10bResetState_801fe314> state, int mode);
int fn_802fb7ac(Ptr32<const char> format, ...);

void w3d_k10b_reset_poll_801fe314(Ptr32<K10bResetState_801fe314> self) {
    if (!self->handled) {
        if (self->pressed) {
            if (!fn_802fec74()) {
                self->handled = 1;
                fn_801fe3b0(self, 0);
            }
        } else {
            self->pressed = fn_802fec74() != 0;
            if (self->pressed) fn_802fb7ac("RESET PRESSED\n");
        }
    }
}
}


