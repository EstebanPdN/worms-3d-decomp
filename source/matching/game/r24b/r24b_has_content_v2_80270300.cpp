// desc: Test the disabled field and four prefixed string lengths in observed order; names inferred.
// Observed: nested state pointer at +0x28, disabled word at +0x98;
// string data pointers at +0x54,+0x50,+0x48,+0x4c. Each length is an
// unsigned 16-bit value four bytes before the pointed-to string data.
// Prefix allocation, string ownership and the caller's interpretation of
// the return value remain unresolved; null string pointers are not guarded.
struct R24bTextPrefix {
    unsigned short length;
    unsigned short unknown_02;
};
struct R24bContentState {
    unsigned char unknown_00[0x48];
    const R24bTextPrefix *text_48;
    const R24bTextPrefix *text_4c;
    const R24bTextPrefix *text_50;
    const R24bTextPrefix *text_54;
    unsigned char unknown_58[0x40];
    int disabled;
};
struct R24bContentObject {
    unsigned char unknown_00[0x28];
    R24bContentState *state;
};
extern "C" int w3d_r24b_has_content_v2_80270300(R24bContentObject *self)
{
    R24bContentState *state = self->state;
    int result = 1;
    if (state->disabled && !state->text_54[-1].length &&
        !state->text_50[-1].length && !state->text_48[-1].length)
        result = !(state->text_4c[-1].length == 0);
    return result;
}
