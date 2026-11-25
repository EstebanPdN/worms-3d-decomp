// Partial view of the reset-button state word: the top bit records that the
// reset sequence has already been started, the next bit that a press was seen.
struct K10bResetState_801fe314 {
    unsigned handled : 1;
    unsigned pressed : 1;
    unsigned rest : 30;
};

extern "C" {
int fn_802fec74();
void fn_801fe3b0(K10bResetState_801fe314 *state, int mode);
int fn_802fb7ac(const char *format, ...);

void w3d_k10b_reset_poll_801fe314(K10bResetState_801fe314 *self) {
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
