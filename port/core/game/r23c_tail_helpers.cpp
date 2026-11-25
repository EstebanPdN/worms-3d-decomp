#include "w3d_ptr.h"
#line 1 "r23c_tail_helpers.cpp"
// Worms 3D PAL GWMP8P rev0: inferred helper names, observed machine layouts.
// No external callees or globals are referenced by these five leaf bodies.
// Compiler layout below is the original 32-bit big-endian ProDG ABI;
// a future platform implementation must explicitly preserve its bit semantics.
typedef unsigned int r23c_u32;
typedef unsigned char r23c_u8;

struct r23c_Flags {
    r23c_u8 unknown0[48];
    unsigned int remaining:31; unsigned int enabled:1;
};
extern "C" int r23c_set_high_flag_80348e1c(Ptr32<r23c_Flags> self, r23c_u32 enabled) {
    self->enabled = enabled;
    return 0;
}

// Half-open byte range; an empty range returns first, ties keep the first maximum.
extern "C" Ptr32<const r23c_u8> r23c_max_byte_80352828(Ptr32<const r23c_u8> first,
                                               Ptr32<const r23c_u8> last) {
    if (first == last) return first;
    Ptr32<const r23c_u8> best = first;
    while (++first != last) {
        if (*best < *first) best = first;
    }
    return best;
}

// Channel meanings are inferred. Observed channel offsets are 0, 1, 2, 3.
struct r23c_Color { r23c_u8 red, green, blue, alpha; };
extern "C" void r23c_rgb_to_opaque_803563b8(Ptr32<r23c_Color> out, Ptr32<const r23c_Color> in) {
    out->red = in->red;
    out->green = in->green;
    out->blue = in->blue;
    out->alpha = 255;
}

// Native halfword load: bits 0..4, 5..9, 10..14 become channels shifted by 3;
// bit 15 becomes alpha 0/255. No low-bit replication: channel maximum is 248.
extern "C" void r23c_expand_1555_8035642c(Ptr32<r23c_Color> out, Ptr32<const unsigned short> in) {
    unsigned value = *in;
    unsigned alpha = value >> 15;
    out->red = (value << 3) & 248;
    out->green = (value >> 2) & 248;
    out->blue = (value >> 7) & 248;
    if (alpha) out->alpha = 255;
    else out->alpha = alpha;
}

// Inferred history structure: index +4, current +8, peak +12;
// parallel 128-word arrays begin at +0x10 and +0x210. Unknown word +0 is untouched.
struct r23c_History {
    r23c_u32 unknown0, writeIndex, current, peak;
    r23c_u32 first[128];
    r23c_u32 second[128];
};
extern "C" int r23c_history_append_80358144(Ptr32<r23c_History> self,
                                          r23c_u32 first, r23c_u32 second) {
    self->first[self->writeIndex & 127] = first;
    self->second[self->writeIndex & 127] = second;
    r23c_u32 current = self->current;
    self->writeIndex++;
    if (current > self->peak) self->peak = current;
    return 0;
}


