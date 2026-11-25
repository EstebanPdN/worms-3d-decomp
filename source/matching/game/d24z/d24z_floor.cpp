/* @(#)s_floor.c 5.1 93/09/24 */
/* Adapted from vendored newlib 1.10.0 s_floor.c. The original keeps these constants in
 * writable small data, so they are declared as externs at their original addresses.
 * Names are inferred. */
#define __IEEE_BIG_ENDIAN 1
#define floor w3d_d24z_floor_802e75d0
extern "C" {
#include "fdlibm.h"
extern double d24z_huge_804ac100; /* 1e+300 */
extern double d24z_lit_d_0_804ac108; /* 0.0 */
#ifndef _DOUBLE_IS_32BITS




	double floor(double x)

{
	__int32_t i0,i1,j0;
	__uint32_t i,j;
	EXTRACT_WORDS(i0,i1,x);
	j0 = ((i0>>20)&0x7ff)-0x3ff;
	if(j0<20) {
	    if(j0<0) { 	 
		if(x+d24z_huge_804ac100>d24z_lit_d_0_804ac108) { 
		    if(i0>=0) {i0=i1=0;} 
		    else if(((i0&0x7fffffff)|i1)!=0)
			{ i0=0xbff00000;i1=0;}
		}
	    } else {
		i = (0x000fffff)>>j0;
		if(((i0&i)|i1)==0) return x;  
		if(x+d24z_huge_804ac100>d24z_lit_d_0_804ac108) {	 
		    if(i0<0) i0 += (0x00100000)>>j0;
		    i0 &= (~i); i1=0;
		}
	    }
	} else if (j0>51) {
	    if(j0==0x400) return x+x;	 
	    else return x;		 
	} else {
	    i = ((__uint32_t)(0xffffffff))>>(j0-20);
	    if((i1&i)==0) return x;	 
	    if(x+d24z_huge_804ac100>d24z_lit_d_0_804ac108) { 		 
		if(i0<0) {
		    if(j0==20) i0+=1; 
		    else {
			j = i1+(1<<(52-j0));
			{ bool carry = j<i1; int mask = -(unsigned int)!carry; i0 = (i0&mask)|((i0+1)&~mask); } 	 
			i1=j;
		    }
		}
		i1 &= (~i);
	    }
	}
	INSERT_WORDS(x,i0,i1);
	return x;
}

#endif
}
