#include "w3d_ptr.h"
#line 1 "d20e_rsqrt_table_801a118c.cpp"
// Reciprocal-square-root lookup table initializer (inferred from the original
// instructions at 0x801a118c). It allocates 128 bytes through 0x801fe220, stores the
// table pointer in 0x804ab744, and fills entry i with the rounded upper mantissa
// bits of 1.0f / f(x), where x is the float with word 0x3f000000 | (i << 17)
// (0.5 <= x < 1.0) and f is the scalar routine 0x802e82c0 (square root).
// Entry 64 is then forced to 255. The float/word union is the GC32 big-endian
// representation; no portable endian claim. Built with -mps-float (one saved
// FPR in a non-leaf function).
typedef unsigned int u32;

union FloatWord {
    float value;
    u32 bits;
};

extern "C" Ptr32<unsigned char> fn_801fe220(u32 size);
extern "C" float fn_802e82c0(float value);
extern Ptr32<unsigned char> lbl_804ab744;
extern float lbl_803a9b48[]; // 1.0f in the original literal pool

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

extern "C" int w3d_d20e_rsqrt_table_801a118c()
{
    u32 bits = 0;
    Ptr32<unsigned char> cursor;
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


