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

extern "C" double sol35e4b_zero_804ac128;
extern "C" double sol35e4b_kernel_tan_802e8ed8(double, double, int);
extern "C" int sol35e4b_reduce_802e9134(double, double*);

extern "C" double sol35e4b_tan_802e795c(double x)
{
    double y[2];
    double z = sol35e4b_zero_804ac128;
    Sol35e4bDouble bits;
    bits.value = x;
    int ix = bits.words.high;
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return sol35e4b_kernel_tan_802e8ed8(x, z, 1);
    else if (ix >= 0x7ff00000)
        return x - x;
    else {
        int n = sol35e4b_reduce_802e9134(x, y);
        return sol35e4b_kernel_tan_802e8ed8(y[0], y[1], 1 - ((n & 1) << 1));
    }
}
