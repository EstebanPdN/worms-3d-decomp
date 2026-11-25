// desc: Appears to store a state value, inverted in invert mode, only when it changes.
struct S21Toggle { char pad[112]; int state; char pad1[8]; int invert; };
void w3d_s21_toggle_set_state_802b2344(struct S21Toggle *self, int state)
{
    if (self->invert == 1)
        state = state != 1;
    if (self->state != state)
        self->state = state;
}
