/*
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice is preserved.
 */
/* Experimental C-frontend comparison of the retained newlib word-view idiom.
 * Not admitted and not evidence of a matching C++-frontend reconstruction.
 * Requires the native big-endian binary64 and 32-bit integer representation. */
union Sol35p5CShape {
    double value;
    struct { unsigned msw, lsw; } parts;
};
int sol35p5_finite_c_frontend_802e8a08(double x) {
    union Sol35p5CShape bits;
    int high;
    bits.value = x;
    high = bits.parts.msw;
    return (int)((unsigned)((high & 0x7fffffff) - 0x7ff00000) >> 31);
}
