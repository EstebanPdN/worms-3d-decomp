/* @(#)s_sin.c 5.1 93/09/24 */
/* Adapted from vendored newlib 1.10.0 s_sin.c. The original keeps these constants in
 * writable small data, so they are declared as externs at their original addresses.
 * Names are inferred. */
#define __IEEE_BIG_ENDIAN 1
#define sin w3d_d24z_sin_802e787c
#define __ieee754_rem_pio2 d24z_ieee754_rem_pio2_802e9134
#define __kernel_cos d24z_kernel_cos_802e8d38
#define __kernel_sin d24z_kernel_sin_802e8e2c
#include "fdlibm.h"
extern double d24z_lit_d_0_804ac120; /* 0.0 */
#ifndef _DOUBLE_IS_32BITS

	double sin(double x)

{
	double y[2],z=d24z_lit_d_0_804ac120;
	__int32_t n,ix;

     
	GET_HIGH_WORD(ix,x);

     
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return __kernel_sin(x,z,0);

     
	else if (ix>=0x7ff00000) return x-x;

     
	else {
	    n = __ieee754_rem_pio2(x,y);
	    switch(n&3) {
		case 0: return  __kernel_sin(y[0],y[1],1);
		case 1: return  __kernel_cos(y[0],y[1]);
		case 2: return -__kernel_sin(y[0],y[1],1);
		default:
			return -__kernel_cos(y[0],y[1]);
	    }
	}
}

#endif
