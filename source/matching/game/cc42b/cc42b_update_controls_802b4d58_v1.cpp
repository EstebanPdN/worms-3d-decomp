// Original 0x802b4d58. Partial observed layout; no complete class size claim.
// Flags are 32-bit XOR operands, not normalized booleans. Callbacks may mutate
// the three slots, so each slot is loaded immediately before its callback.
struct cc42b_Control;
struct cc42b_ControlVtable {
    unsigned int unknown00[22];
    void (*set_state)(cc42b_Control *, unsigned int);
};
struct cc42b_Control { cc42b_ControlVtable *vtable; };
struct cc42b_ControlGroup {
    unsigned char unknown00[140];
    unsigned int mode;
    unsigned char unknown90[32];
    unsigned int selected;
    unsigned char unknownb4[44];
    cc42b_Control *first;
    cc42b_Control *second;
    cc42b_Control *third;
};
extern "C" void cc42b_update_controls_802b4d58(cc42b_ControlGroup *self) {
    unsigned int selected = self->selected;
    unsigned int mode = self->mode;
    unsigned int first_state = selected ^ 1;
    unsigned int third_state = mode ^ 1;
    if (mode == 0) {
        first_state = 1;
        if (self->third) first_state = 0;
        selected = 0;
    }
    cc42b_Control *control = self->first;
    if (control) control->vtable->set_state(control, first_state);
    control = self->second;
    if (control) control->vtable->set_state(control, selected);
    control = self->third;
    if (control) control->vtable->set_state(control, third_state);
}
