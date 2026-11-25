/* @(#)s_frexp.c 5.1 93/09/24 */
/* Adapted from vendored newlib 1.10.0 s_frexp.c. The original keeps these constants in
 * writable small data, so they are declared as externs at their original addresses.
 * Names are inferred. */
#define __IEEE_BIG_ENDIAN 1
#define frexp w3d_d24z_frexp_802e773c
#include "fdlibm.h"
extern double d24z_two54_804ac110; /* 1.8014398509481984e+16 */
#ifndef _DOUBLE_IS_32BITS

  

	double frexp(double x, int *eptr)

{
	__int32_t hx, ix, lx;
	EXTRACT_WORDS(hx,lx,x);
	ix = 0x7fffffff&hx;
	*eptr = 0;
	if(ix>=0x7ff00000||((ix|lx)==0)) return x;	 
	if (ix<0x00100000) {		 
	    x *= d24z_two54_804ac110;
	    GET_HIGH_WORD(hx,x);
	    ix = hx&0x7fffffff;
	    *eptr = -54;
	}
	*eptr += (ix>>20)-1022;
	hx = (hx&0x800fffff)|0x3fe00000;
	SET_HIGH_WORD(x,hx);
	return x;
}

#endif
