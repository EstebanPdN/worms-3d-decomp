/*
 * 0x8018b524: count how many bytes of a UTF-8 string fit in a width.
 *
 * Same glyph-table layout as 0x8018b404: the owner's node (+36) holds a
 * track set in slot 7 and a 16-bit entry table in slot 9. Each character is
 * decoded (0x8018b360); a zero length returns 0 at once. The table search
 * (0x8018b260) maps the code to an entry whose high byte selects a track and
 * low byte a glyph value. The running width starts at the float at
 * 0x803a7db0 and adds scale * value / divisor, where the divisor is the
 * weight of the first track's first glyph. When the width exceeds the limit
 * the bytes counted so far are returned; otherwise the count grows by the
 * character length until the terminating zero byte.
 *
 * Track entries are 32-bit handles read into an integer before use; field
 * meanings are inferred.
 */
struct D20dValue { float value; float weight; };
struct D20dNode { unsigned int slot[10]; };
struct D20dTrackData { unsigned char unknown00[32]; D20dValue values[1]; };
struct D20dTrackSet { unsigned char unknown00[32]; unsigned int tracks[1]; };
struct D20dIndexSet { unsigned char unknown00[32]; unsigned short entries[1]; };
/* The owner is the glyph table searched by 0x8018b260 (entries +68, count +72). */
struct K1dTable { unsigned char unknown00[36]; D20dNode *root; unsigned char unknown40[28]; void *entries; int count; };

extern "C" {
extern const float lbl_803a7db0[];
unsigned short cc39d_utf8_decode_8018b360(const unsigned char *text, unsigned int *length);
unsigned short w3d_k1d_lookup_entry_8018b260(K1dTable *t, unsigned short key);
int d20d_fit_width_8018b524(K1dTable *self, const unsigned char *text, float limit, float scale);
}

int d20d_fit_width_8018b524(K1dTable *self, const unsigned char *text, float limit, float scale)
{
    int slot = 7;
    D20dNode *root = self->root;
    D20dTrackSet *set = (D20dTrackSet *)root->slot[slot];
    D20dIndexSet *index = (D20dIndexSet *)root->slot[9];
    unsigned int *tracks = set->tracks;
    unsigned short *entries = index->entries;
    float total = lbl_803a7db0[0];
    unsigned int first = tracks[0];
    float divisor = ((D20dTrackData *)((D20dNode *)first)->slot[slot])->values[0].weight;
    int count = 0;
    while (*text) {
        unsigned int size;
        unsigned short code = cc39d_utf8_decode_8018b360(text, &size);
        if (!size) return 0;
        unsigned int e = entries[w3d_k1d_lookup_entry_8018b260(self, code)];
        D20dValue *values = ((D20dTrackData *)((D20dNode *)tracks[e >> 8])->slot[7])->values;
        total += scale * values[e & 0xff].value / divisor;
        if (total > limit) break;
        text += size;
        count += size;
    }
    return count;
}
