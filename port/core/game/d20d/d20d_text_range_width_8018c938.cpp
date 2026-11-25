#include "w3d_ptr.h"
#line 1 "d20d_text_range_width_8018c938.cpp"
/*
 * 0x8018c938: width of part of a laid-out text line.
 *
 * Returns the float at 0x803a7e30 when 'start' is beyond the glyph count
 * (0x8018ca1c). Otherwise sums the glyph values of at most 'count' references
 * from 'start' to the end of the line (same layout as 0x8018c8bc), starting
 * from the float at 0x803a7e30, and scales the sum by the text size over the
 * weight of the first track's first glyph. Field meanings are inferred.
 */
struct D20dValue { float value; float weight; };
struct D20dNode { unsigned int slot[10]; };
struct D20dTrackData { unsigned char unknown00[32]; D20dValue values[1]; };
struct D20dTrackSet { unsigned char unknown00[32]; unsigned int tracks[1]; };
/* A glyph reference: high byte track, low byte glyph index. */
union D20dGlyphRef { unsigned short packed; struct { unsigned char index; unsigned char track; } part; };
struct D20dText {
    unsigned char unknown00[36]; float size;
    unsigned char unknown28[128]; Ptr32<D20dNode> font;
    unsigned char unknownac[8]; Ptr32<D20dGlyphRef> glyphFirst; Ptr32<D20dGlyphRef> glyphLast;
};

extern "C" {
extern const float lbl_803a7e30[];
int w3d_auto_8018ca1c(Ptr32<D20dText> self);
float d20d_text_range_width_8018c938(Ptr32<D20dText> self, unsigned int start, unsigned int count);
}
float d20d_text_range_width_8018c938(Ptr32<D20dText> self, unsigned int start, unsigned int count)
{
    if (start > (unsigned int)w3d_auto_8018ca1c(self)) return lbl_803a7e30[0];
    int slot = 7;
    Ptr32<D20dNode> font = self->font;
    Ptr32<D20dTrackSet> set = (Ptr32<D20dTrackSet>)w3d::G(font->slot[slot]);
    Ptr32<unsigned int> tracks = set->tracks;
    float sum = lbl_803a7e30[0];
    unsigned int first = tracks[0];
    float scale = ((Ptr32<D20dTrackData>)w3d::G(((Ptr32<D20dNode>)w3d::G(first))->slot[slot]))->values[0].weight;
    unsigned int left = count;
    for (Ptr32<D20dGlyphRef> p = self->glyphFirst + start; p != self->glyphLast; ++p) {
        if (left == 0) break;
        --left;
        Ptr32<D20dValue> values = ((Ptr32<D20dTrackData>)w3d::G(((Ptr32<D20dNode>)w3d::G(tracks[p->packed >> 8]))->slot[slot]))->values;
        sum += values[p->part.index].value;
    }
    return sum * self->size / scale;
}


