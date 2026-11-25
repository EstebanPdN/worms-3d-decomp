/* @(#)s_tan.c 5.1 93/09/24 */
/* Adapted from vendored newlib 1.10.0 s_tan.c. The original keeps these constants in
 * writable small data, so they are declared as externs at their original addresses.
 * Names are inferred. */
#define __IEEE_BIG_ENDIAN 1
#define tan w3d_d24z_tan_802e795c
#define __ieee754_rem_pio2 d24z_ieee754_rem_pio2_802e9134
#define __kernel_tan d24z_kernel_tan_802e8ed8
#include "fdlibm.h"
extern double d24z_lit_d_0_804ac128; /* 0.0 */
#ifndef _DOUBLE_IS_32BITS

	double tan(double x)

{
	double y[2],z=d24z_lit_d_0_804ac128;
	__int32_t n,ix;

     
	GET_HIGH_WORD(ix,x);

     
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return __kernel_tan(x,z,1);

     
	else if (ix>=0x7ff00000) return x-x;		 

     
	else {
	    n = __ieee754_rem_pio2(x,y);
	    return __kernel_tan(y[0],y[1],1-((n&1)<<1));  
	}
}

#endif
