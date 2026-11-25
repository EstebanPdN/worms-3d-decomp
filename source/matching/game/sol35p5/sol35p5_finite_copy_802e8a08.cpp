/*
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice is preserved.
 */
// Experimental adaptation of the retained Sun/newlib finite classifier.
// Reference ABI: big-endian IEEE binary64 double and 32-bit unsigned.
// memcpy reads only the observed high representation word, without aliasing
// through an unrelated pointer type. Other byte orders need a separate view.
extern "C" {
#include <string.h>
}
extern "C" int sol35p5_finite_copy_802e8a08(double value) {
    unsigned high;
    memcpy(&high, &value, sizeof(high));
    return ((high & 0x7fffffffu) - 0x7ff00000u) >> 31;
}
