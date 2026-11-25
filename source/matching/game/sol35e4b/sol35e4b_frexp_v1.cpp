/* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Adapted from the retained newlib-1.10.0 source; reference GC32 layout.
 */
union Sol35e4bDouble {
    double value;
    struct { unsigned int high, low; } words;
};

extern "C" double sol35e4b_two54_804ac110;

extern "C" double sol35e4b_frexp_802e773c(double x, int* exponent)
{
    int hx, ix, lx;
    {
        Sol35e4bDouble bits;
        bits.value = x;
        hx = bits.words.high;
        lx = bits.words.low;
    }
    ix = 0x7fffffff & hx;
    *exponent = 0;
    if (ix >= 0x7ff00000 || ((ix | lx) == 0))
        return x;
    if (ix < 0x00100000) {
        x *= sol35e4b_two54_804ac110;
        Sol35e4bDouble bits;
        bits.value = x;
        hx = bits.words.high;
        ix = hx & 0x7fffffff;
        *exponent = -54;
    }
    *exponent += (ix >> 20) - 1022;
    hx = (hx & 0x800fffff) | 0x3fe00000;
    {
        Sol35e4bDouble bits;
        bits.value = x;
        bits.words.high = hx;
        x = bits.value;
    }
    return x;
}
