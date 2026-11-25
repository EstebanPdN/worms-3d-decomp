/* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Adapted from retained newlib 1.10.0 s_cos.c; inferred reference names.
 */
union Sol35e5bDouble {
    double value;
    struct { unsigned int high, low; } words;
};
extern "C" const double sol35e5b_zero_804ac0f8;
extern "C" double sol35e5b_cos_kernel_802e8d38(double, double);
extern "C" double sol35e5b_sin_kernel_802e8e2c(double, double, int);
extern "C" int sol35e5b_reduce_802e9134(double, double*);

extern "C" double sol35e5b_cos_802e74b4(double x)
{
    double y[2], z = sol35e5b_zero_804ac0f8;
    int n, ix;
    {
        Sol35e5bDouble bits;
        bits.value = x;
        ix = bits.words.high;
    }
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return sol35e5b_cos_kernel_802e8d38(x, z);
    else if (ix >= 0x7ff00000)
        return x - x;
    else {
        n = sol35e5b_reduce_802e9134(x, y);
        switch (n & 3) {
        case 0: return sol35e5b_cos_kernel_802e8d38(y[0], y[1]);
        case 1: return -sol35e5b_sin_kernel_802e8e2c(y[0], y[1], 1);
        case 2: return -sol35e5b_cos_kernel_802e8d38(y[0], y[1]);
        default: return sol35e5b_sin_kernel_802e8e2c(y[0], y[1], 1);
        }
    }
}
