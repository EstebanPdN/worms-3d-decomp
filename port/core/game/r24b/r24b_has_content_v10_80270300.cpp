#include "w3d_ptr.h"
#line 1 "r24b_has_content_v10_80270300.cpp"
// desc: Test the disabled field and four prefixed string lengths in observed order; names inferred.
// Observed: nested state pointer at +0x28, disabled word at +0x98;
// string data pointers at +0x54,+0x50,+0x48,+0x4c. Each length is an
// unsigned 16-bit value four bytes before the pointed-to string data.
// Each stored pointer is modeled as one-past its four-byte prefix; [-1]
// reaches that prefix without encoding any original instruction bytes.
// Prefix allocation, string ownership and the caller's interpretation of
// the return value remain unresolved; null string pointers are not guarded.
struct R24bTextPrefix {
    unsigned short length;
    unsigned short unknown_02;

    // Integer-valued emptiness test; this is a recovered source form, not
    // a claim about the original class declaration.
    int empty() const
    {
        return length == 0;
    }
};
struct R24bContentState {
    unsigned char unknown_00[0x48];
    Ptr32<const R24bTextPrefix> text_48;
    Ptr32<const R24bTextPrefix> text_4c;
    Ptr32<const R24bTextPrefix> text_50;
    Ptr32<const R24bTextPrefix> text_54;
    unsigned char unknown_58[0x40];
    int disabled;
};
struct R24bContentObject {
    unsigned char unknown_00[0x28];
    Ptr32<R24bContentState> state;
};
extern "C" bool w3d_r24b_has_content_v10_80270300(Ptr32<R24bContentObject> self)
{
    Ptr32<R24bContentState> state = self->state;
    bool result = true;
    if (state->disabled && !state->text_54[-1].length &&
        !state->text_50[-1].length && !state->text_48[-1].length)
        result = !state->text_4c[-1].empty();
    return result;
}


