#include "w3d_ptr.h"
#line 1 "d20d_text_width_8018c8bc.cpp"
/*
 * 0x8018c8bc: width of a laid-out text line.
 *
 * The text keeps its font node at +168 (slot 7: track set, as in the glyph
 * table of 0x8018b404) and a vector of 16-bit glyph references at +180/+184
 * (filled by 0x8018c60c). The glyph values of all references are summed,
 * starting from the float at 0x803a7e2c, then multiplied by the text size
 * (+36) and divided by the weight of the first track's first glyph.
 *
 * Track entries are 32-bit handles read into an integer before use; the low
 * byte of a reference is read through its byte view. Field meanings are
 * inferred.
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
extern const float lbl_803a7e2c[];
float d20d_text_width_8018c8bc(Ptr32<D20dText> self);
}
float d20d_text_width_8018c8bc(Ptr32<D20dText> self)
{
    int slot = 7;
    Ptr32<D20dNode> font = self->font;
    Ptr32<D20dTrackSet> set = (Ptr32<D20dTrackSet>)w3d::G(font->slot[slot]);
    Ptr32<unsigned int> tracks = set->tracks;
    float sum = lbl_803a7e2c[0];
    unsigned int first = tracks[0];
    float scale = ((Ptr32<D20dTrackData>)w3d::G(((Ptr32<D20dNode>)w3d::G(first))->slot[slot]))->values[0].weight;
    for (Ptr32<D20dGlyphRef> p = self->glyphFirst; p != self->glyphLast; ++p) {
        Ptr32<D20dValue> values = ((Ptr32<D20dTrackData>)w3d::G(((Ptr32<D20dNode>)w3d::G(tracks[p->packed >> 8]))->slot[slot]))->values;
        sum += values[p->part.index].value;
    }
    return sum * self->size / scale;
}


