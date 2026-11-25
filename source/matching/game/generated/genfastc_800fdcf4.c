/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Quantized-conversion templates built with -mfast-cast (third batch). */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

extern const float lbl_803d83f8[];
extern const float lbl_803d83fc[];
extern const float lbl_803d8400[];
extern const float lbl_803d8404[];
extern const float lbl_803d8408[];

int w3d_init_timed_fade_800fdcf4(void *self, unsigned char from, unsigned char to, int unused, int start,
                                 int duration, int delay)
{
    char *fade = (char *)self + 44;
    if (start == -1)
        FIELD(fade, int, 4) = -1;
    FIELD(self, int, 44) = 0;
    FIELD(fade, int, 4) = start;
    FIELD(self, unsigned int, 92) |= 0x80000000;
    FIELD(fade, float, 16) = (float)from;
    FIELD(fade, float, 20) = (float)to;
    FIELD(fade, int, 12) = -1;
    FIELD(fade, int, 8) = 0;
    if (duration > 0)
        FIELD(fade, int, 8) = duration;
    if (delay > 0)
        FIELD(fade, int, 12) = FIELD(fade, int, 4) - delay;
    return 0;
}

unsigned char w3d_inverse_ratio_802bf798(void *self)
{
    float t = (FIELD(self, float, 64) + FIELD(self, float, 60)) / (FIELD(self, float, 36) + FIELD(self, float, 36))
              * lbl_803d83f8[0] - lbl_803d83fc[0];
    unsigned char amount = 0;
    float u = t * lbl_803d8400[0];
    if (u > lbl_803d83f8[0])
        u = lbl_803d83f8[0];
    if (u > lbl_803d8404[0])
        amount = (unsigned char)(u * lbl_803d8408[0]);
    return 255 - amount;
}
