// Reset of a small state object that starts with a tag word, a float
// component and two zeroed components.
//
// Observed layout:
//   +0x00 : tag word; only the low 21 bits survive the reset
//   +0x04 : float component initialised from the shared zero float at
//           0x80373c20
//   +0x08, +0x0c : words cleared to zero
//   +0x10 : trailing word cleared to zero
//
// The zero float at 0x80373c20 is a shared engine global, referenced here as
// external original data (the unit owns no initialized data).

struct W3dTaggedState {
    unsigned int tag;      // +0x00
    float x;               // +0x04
    unsigned int y;        // +0x08
    unsigned int z;        // +0x0c
    unsigned int tail;     // +0x10
};

extern float w3d_zero_float_80373c20;

extern "C" void e13d_reset_flags_80343748(W3dTaggedState *self)
{
    self->tail = 0;
    self->tag &= 0x001fffff;
    self->x = w3d_zero_float_80373c20;
    self->y = 0;
    self->z = 0;
}
