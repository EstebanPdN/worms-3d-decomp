/* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Adapted from retained newlib 1.10.0 e_log10.c; names inferred.
 * The word representation uses the reference compiler's union extension.
 */
union Sol35e5bLogDouble {
    double value;
    struct { unsigned int high, low; } words;
};
extern "C" const double sol35e5b_negative_infinity_804abf78;
extern "C" const double sol35e5b_zero_804abf80;
extern "C" const double sol35e5b_two54_804abf88;
extern "C" const double sol35e5b_log10_low_804abf98;
extern "C" const double sol35e5b_inverse_ln10_804abfa0;
extern "C" const double sol35e5b_log10_high_804abfa8;
extern "C" double sol35e5b_log_802e62d4(double);

extern "C" double sol35e5b_log10_802e6564(double x)
{
    int high;
    unsigned int low;
    {
        Sol35e5bLogDouble bits;
        bits.value = x;
        high = bits.words.high;
        low = bits.words.low;
    }
    int k = 0;
    if (high < 0x00100000) {
        if (((high & 0x7fffffff) | low) == 0)
            return sol35e5b_negative_infinity_804abf78;
        if (high < 0)
            return (x - x) / sol35e5b_zero_804abf80;
        k -= 54;
        x *= sol35e5b_two54_804abf88;
        {
            Sol35e5bLogDouble bits;
            bits.value = x;
            high = bits.words.high;
        }
    }
    if (high >= 0x7ff00000)
        return x + x;
    k += (high >> 20) - 1023;
    int i = (static_cast<unsigned int>(k) & 0x80000000u) >> 31;
    high = (high & 0x000fffff) | ((0x3ff - i) << 20);
    double y = static_cast<double>(k + i);
    {
        Sol35e5bLogDouble bits;
        bits.value = x;
        bits.words.high = high;
        x = bits.value;
    }
    double z = y * sol35e5b_log10_low_804abf98 +
        sol35e5b_inverse_ln10_804abfa0 * sol35e5b_log_802e62d4(x);
    return z + y * sol35e5b_log10_high_804abfa8;
}
