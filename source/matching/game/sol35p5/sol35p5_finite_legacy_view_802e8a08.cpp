/*
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice is preserved.
 */
// Experimental original fdlibm direct-word access described in retained
// fdlibm.h:232-241. Not an ISO C++ aliasing/portability guarantee and not
// admitted. GC32 big-endian binary64 representation is required.
extern "C" int sol35p5_finite_legacy_view_802e8a08(double value) {
    int high = *(int *)&value;
    return (int)((unsigned)((high & 0x7fffffff) - 0x7ff00000) >> 31);
}
