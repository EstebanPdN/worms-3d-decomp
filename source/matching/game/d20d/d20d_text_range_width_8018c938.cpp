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
union D20dGlyphRef { unsigned short packed; struct { unsigned char track, index; } part; };
struct D20dText {
    unsigned char unknown00[36]; float size;
    unsigned char unknown28[128]; D20dNode *font;
    unsigned char unknownac[8]; D20dGlyphRef *glyphFirst, *glyphLast;
};

extern "C" {
extern const float lbl_803a7e30[];
int w3d_auto_8018ca1c(D20dText *self);
float d20d_text_range_width_8018c938(D20dText *self, unsigned int start, unsigned int count);
}
float d20d_text_range_width_8018c938(D20dText *self, unsigned int start, unsigned int count)
{
    if (start > (unsigned int)w3d_auto_8018ca1c(self)) return lbl_803a7e30[0];
    int slot = 7;
    D20dNode *font = self->font;
    D20dTrackSet *set = (D20dTrackSet *)font->slot[slot];
    unsigned int *tracks = set->tracks;
    float sum = lbl_803a7e30[0];
    unsigned int first = tracks[0];
    float scale = ((D20dTrackData *)((D20dNode *)first)->slot[slot])->values[0].weight;
    unsigned int left = count;
    for (D20dGlyphRef *p = self->glyphFirst + start; p != self->glyphLast; ++p) {
        if (left == 0) break;
        --left;
        D20dValue *values = ((D20dTrackData *)((D20dNode *)tracks[p->packed >> 8])->slot[slot])->values;
        sum += values[p->part.index].value;
    }
    return sum * self->size / scale;
}
