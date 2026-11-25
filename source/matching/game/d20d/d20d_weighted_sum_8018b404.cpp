/*
 * 0x8018b404: weighted sum over a zero-terminated list of 16-bit keys.
 *
 * The owner keeps a node at +36 whose slot 7 is a track set and slot 9 an
 * index table. The table search (0x8018b260) maps each key to an index; the 16-bit
 * entry at that index selects a track (high byte) and a value (low byte).
 * Entries whose top nibble is 0xf are skipped. Every selected value is
 * divided by the weight of the first track's first value and added to a
 * total that starts at the float at 0x803a7da0.
 *
 * Track entries are stored as 32-bit handles and read into an integer
 * before use; field meanings are inferred from the access pattern.
 */
struct D20dValue { float value; float weight; };
struct D20dNode { unsigned int slot[10]; };
struct D20dTrackData { unsigned char unknown00[32]; D20dValue values[1]; };
struct D20dTrackSet { unsigned char unknown00[32]; unsigned int tracks[1]; };
struct D20dIndexSet { unsigned char unknown00[32]; unsigned short entries[1]; };
/* The owner is the glyph table searched by 0x8018b260 (entries +68, count +72). */
struct K1dTable { unsigned char unknown00[36]; D20dNode *root; unsigned char unknown40[28]; void *entries; int count; };

extern "C" {
extern const float lbl_803a7da0[];
unsigned short w3d_k1d_lookup_entry_8018b260(K1dTable *t, unsigned short key);
float d20d_weighted_sum_8018b404(K1dTable *self, unsigned short *keys);
}

float d20d_weighted_sum_8018b404(K1dTable *self, unsigned short *keys)
{
    int slot = 7;
    D20dNode *root = self->root;
    D20dTrackSet *set = (D20dTrackSet *)root->slot[slot];
    D20dIndexSet *index = (D20dIndexSet *)root->slot[9];
    unsigned int *tracks = set->tracks;
    unsigned short *entries = index->entries;
    float sum = lbl_803a7da0[0];
    unsigned int first = tracks[0];
    float scale = ((D20dTrackData *)((D20dNode *)first)->slot[slot])->values[0].weight;
    unsigned int k;
    for (k = *keys; k != 0; k = *++keys) {
        unsigned int e = entries[w3d_k1d_lookup_entry_8018b260(self, k)];
        if ((e & 0xf000) != 0xf000) {
            D20dValue *values = ((D20dTrackData *)((D20dNode *)tracks[e >> 8])->slot[7])->values;
            sum += values[e & 0xff].value / scale;
        }
    }
    return sum;
}
