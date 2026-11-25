// Inferred reciprocal-square-root lookup-table initializer.
// Observed GC32 float/word union representation; no portable endian claim.
typedef unsigned int u32;
union FloatWord { float value; u32 bits; };
extern "C" unsigned char *fn_801fe220(u32);
extern "C" float fn_802e82c0(float);
extern unsigned char *lbl_804ab744;
extern float lbl_803a9b48[];
inline float float_from_word(u32 bits)
{
    FloatWord v;
    v.bits = bits;
    return v.value;
}
inline u32 word_from_float(float value)
{
    FloatWord v;
    v.value = value;
    return v.bits;
}
extern "C" int sol35c3_rsqrt_table_801a118c()
{
    u32 bits = 0;
    unsigned char *cursor;
    int remaining = 128;
    lbl_804ab744 = fn_801fe220(128);
    cursor = lbl_804ab744;
    float numerator = lbl_803a9b48[0];
    do {
        float input = float_from_word(bits | 0x3f000000u);
        bits += 0x20000;
        *cursor++ = (word_from_float(numerator / fn_802e82c0(input)) + 0x2000u) >> 15;
    } while (--remaining);
    lbl_804ab744[64] = 255;
    return 0;
}
