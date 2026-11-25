/* Sums a weighted value over a zero-terminated list of 16-bit keys. Each key
   is mapped to a 16-bit entry by a helper on the object; entries whose top
   nibble is 0xf are skipped. Otherwise the entry's high byte picks a row
   pointer and its low byte selects a float (8 bytes apart) in that row's
   block, which is divided by a scale read through two pointers and added to a
   running total that starts at a global constant. Offsets are observed; field
   names and meanings are inferred. The unused volatile array only reserves
   the 16 bytes of frame the original keeps below its saved registers; it is
   a matching device, not recovered source. */
extern float lbl_803a7da0[];
extern int fn_8018b260(char *self, unsigned int key);
float tsonnet_b37_weighted_sum_8018b404(char *self, unsigned short *keys)
{
    volatile char pad[16];
    int o = 28;
    char *tbl = *(char **)(self + 36);
    char *a = *(char **)(tbl + o);
    char *b = *(char **)(tbl + 36);
    char *rows = a + 32;
    char *ents = b + 32;
    float sum = lbl_803a7da0[0];
    float scale = *(float *)(*(char **)(*(char **)(a + 32) + o) + 36);
    unsigned int k;
    for (k = *keys; k != 0; k = *++keys) {
        unsigned int e = ((unsigned short *)ents)[fn_8018b260(self, k)];
        if ((e & 0xf000) != 0xf000) {
            char *row = *(char **)(rows + ((e >> 8) << 2));
            char *block = *(char **)(row + 28) + 32;
            sum += ((float *)block)[(e & 0xff) << 1] / scale;
        }
    }
    return sum;
}
