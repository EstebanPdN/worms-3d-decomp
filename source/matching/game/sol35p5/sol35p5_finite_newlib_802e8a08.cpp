/*
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 */
// C++ adaptation of retained newlib-1.10.0 s_finite.c and fdlibm.h.
// Native big-endian union representation follows the reference compiler's
// extension. API/version identity and ISO C++ portability are not proved.
union Sol35p5DoubleShape {
    double value;
    struct { unsigned msw, lsw; } parts;
};
extern "C" int sol35p5_finite_newlib_802e8a08(double x) {
    int hx;
    do {
        Sol35p5DoubleShape gh_u;
        gh_u.value = x;
        hx = gh_u.parts.msw;
    } while (0);
    return (int)((unsigned)((hx & 0x7fffffff) - 0x7ff00000) >> 31);
}
