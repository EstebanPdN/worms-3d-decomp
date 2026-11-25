/* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Adapted from retained newlib 1.10.0 s_ldexp.c. Names remain inferred.
 */
extern "C" int sol35e5b_finite_802e8a08(double);
extern "C" double sol35e5b_scalbn_802e8a28(double, int);
extern "C" int* sol35e5b_errno_802eafc4();
extern "C" const double sol35e5b_zero_804ac118;

extern "C" double sol35e5b_ldexp_802e77f4(double value, int exponent)
{
    if (!sol35e5b_finite_802e8a08(value) || value == sol35e5b_zero_804ac118)
        return value;
    value = sol35e5b_scalbn_802e8a28(value, exponent);
    if (!sol35e5b_finite_802e8a08(value) || value == sol35e5b_zero_804ac118)
        *sol35e5b_errno_802eafc4() = 34;
    return value;
}
