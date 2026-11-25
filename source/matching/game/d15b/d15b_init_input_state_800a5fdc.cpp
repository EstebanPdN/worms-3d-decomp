// Partial view of an input/selection state object initialized in place.
// Offsets are observed from the original; names and roles are inferred.
// The float operands are original read-only constants referenced by address.
struct d15b_InputRange {
    unsigned int first, second, third, fourth, fifth;
    void clear() { first = 0; second = 0; third = 0; fourth = 0; fifth = 0; }
};
struct d15b_InputState {
    const void *vtable;
    unsigned char unknown04[24];
    d15b_InputRange range;
    unsigned char unknown30[8];
    unsigned int cursor[3];
    float origin[3];
    float low;
    float high;
    float step;
    float span;
    unsigned int locked : 1;
    unsigned int visible : 1;
    unsigned int flag0 : 1;
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int flag4 : 1;
    unsigned int flag5 : 1;
    unsigned int pending : 1;
    unsigned int armed : 1;
    unsigned int unknown60_bits : 22;
    unsigned int selection;
    unsigned int targets[5];
    unsigned char unknown7c[8];
    int slots[8];
    unsigned char unknownA4[8];
    unsigned int hold;
    unsigned int repeat;
};
extern "C" void w3d_ctor_801628b0(d15b_InputState *);
extern "C" void cc39c_seek_slot_level_800a7ee4(d15b_InputState *);
extern const unsigned char w3d_vtable_8040f628[];
extern const float w3d_zero_803812a8[], w3d_half_803812ac[], w3d_quarter_803812b0[], w3d_one_803812b4[];
extern d15b_InputState *w3d_input_804aac54;

extern "C" d15b_InputState *d15b_init_input_state_800a5fdc(d15b_InputState *self) {
    w3d_ctor_801628b0(self);
    self->vtable = w3d_vtable_8040f628;
    self->range.clear();
    float zero = w3d_zero_803812a8[0];
    float quarter = w3d_quarter_803812b0[0];
    self->low = zero;
    self->high = w3d_half_803812ac[0];
    self->span = w3d_one_803812b4[0] - quarter;
    self->locked = 0;
    self->visible = 1;
    self->flag0 = 0;
    self->flag1 = 0;
    self->flag2 = 0;
    self->flag3 = 0;
    self->flag4 = 0;
    self->flag5 = 0;
    self->armed = 1;
    self->pending = 0;
    self->targets[0] = 0;
    self->targets[1] = 0;
    self->targets[2] = 0;
    self->targets[3] = 0;
    self->targets[4] = 0;
    self->cursor[0] = 0;
    self->cursor[1] = 0;
    self->cursor[2] = 0;
    self->origin[0] = zero;
    self->origin[1] = zero;
    self->origin[2] = zero;
    self->step = quarter;
    self->selection = 0;
    int *slot = self->slots;
    for (int i = 8; i != 0; i--)
        *slot++ = -1;
    cc39c_seek_slot_level_800a7ee4(self);
    w3d_input_804aac54 = self;
    self->hold = 0;
    self->repeat = 0;
    return self;
}
