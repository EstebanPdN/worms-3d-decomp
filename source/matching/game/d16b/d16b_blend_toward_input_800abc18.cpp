// Blender update: clamps an input to the controller range, maps it from
// [-range, range] to [0, 1], moves the blend value toward it by the rate and
// clamps the result to [0, 1]. Range and rate are read through the original
// scalar accessor. Partial observed layout. The float literals 1.0f, 0.5f and
// 0.0f form the original literal pool at 0x80381c20..0x80381c2b (owned
// initialized data, first-use order).
// Built with the original paired-single float switch (-mps-float), which
// reserves the 16 frame bytes that pair the two saved FPRs.
template <class T> inline const T &d16b_max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &d16b_min(const T &a, const T &b) { return a < b ? a : b; }
struct d16b_BlendInput {
    unsigned char unknown00[152];
    float blend;
    unsigned char unknown9c[32];
    void *range;
    unsigned char unknownc0[4];
    void *rate;
};
extern "C" float w3d_auto_80178df0(void *);

extern "C" void d16b_blend_toward_input_800abc18(d16b_BlendInput *self, float input) {
    input = d16b_max(-w3d_auto_80178df0(self->range), input);
    input = d16b_min(input, w3d_auto_80178df0(self->range));
    float target = (input / w3d_auto_80178df0(self->range) + 1.0f) * 0.5f;
    self->blend = (target - self->blend) * w3d_auto_80178df0(self->rate) + self->blend;
    self->blend = d16b_max(0.0f, self->blend);
    self->blend = d16b_min(self->blend, 1.0f);
}
