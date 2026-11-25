// Blender update: clamps an input to the controller range, maps it from
// [-range, range] to [0, 1], moves the blend value toward it by the rate and
// clamps the result to [0, 1]. Range and rate are read through the original
// scalar accessor; constants are original data referenced by address.
// Partial observed layout; no owned initialized data.
template <class T> inline const T &d15b_max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &d15b_min(const T &a, const T &b) { return b < a ? b : a; }
struct d15b_BlendInput {
    unsigned char unknown00[152];
    float blend;
    unsigned char unknown9c[32];
    void *range;
    unsigned char unknownc0[4];
    void *rate;
};
extern "C" float w3d_auto_80178df0(void *);

extern "C" void d15b_blend_toward_input_800abc18(d15b_BlendInput *self, float input) {
    input = d15b_max(input, -w3d_auto_80178df0(self->range));
    input = d15b_min(input, w3d_auto_80178df0(self->range));
    float target = (input / w3d_auto_80178df0(self->range) + 1.0f) * 0.5f;
    self->blend = (target - self->blend) * w3d_auto_80178df0(self->rate) + self->blend;
    self->blend = d15b_max(self->blend, 0.0f);
    self->blend = d15b_min(self->blend, 1.0f);
}
