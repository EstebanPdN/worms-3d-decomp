/* Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this software is freely
 * granted, provided that this notice is preserved.
 * Typed C++ reconstruction from local newlib-1.10.0; names inferred.
 * IEEE big-endian word layouts and constants verified against disassembly. */
typedef int __int32_t;typedef unsigned int __uint32_t;
union Cx9cDouble {double value;struct {unsigned int msw,lsw;} parts;};
union Cx9cFloat {float value;unsigned int word;};
#define GET_HIGH_WORD(i,d) do {Cx9cDouble u;u.value=(d);(i)=u.parts.msw;} while(0)
#define SET_HIGH_WORD(d,v) do {Cx9cDouble u;u.value=(d);u.parts.msw=(v);(d)=u.value;} while(0)
#define INSERT_WORDS(d,h,l) do {Cx9cDouble u;u.parts.msw=(h);u.parts.lsw=(l);(d)=u.value;} while(0)
#define GET_FLOAT_WORD(i,d) do {Cx9cFloat u;u.value=(d);(i)=u.word;} while(0)
#define SET_FLOAT_WORD(d,i) do {Cx9cFloat u;u.word=(i);(d)=u.value;} while(0)
extern "C" float cx9c_zero_804ac2e4;
extern "C" float cx9c_huge_804ac2e0;
extern "C" float w3d_cx9c_floorf_802e87d4(float x)
{
	__int32_t i0,j0;
	__uint32_t i,ix;
	GET_FLOAT_WORD(i0,x);
	ix = (i0&0x7fffffff);
	j0 = ((i0>>23)&0xff)-0x7f;
	if(j0<23) {
	    if(j0<0) { 	/* raise inexact if x != 0 */
		if(x+cx9c_huge_804ac2e0>cx9c_zero_804ac2e4) {/* return 0*sign(x) if |x|<1 */
		    if(i0>=0) {i0=0;} 
		    else {bool iszero=((i0&0x7fffffff)==0);int mask=-(unsigned int)iszero;i0=(i0&mask)|(0xbf800000&~mask);}
		}
	    } else {
		i = (0x007fffff)>>j0;
		if((i0&i)==0) return x; /* x is integral */
		if(x+cx9c_huge_804ac2e0>cx9c_zero_804ac2e4) {	/* raise inexact flag */
		    if(i0<0) i0 += (0x00800000)>>j0;
		    i0 &= (~i);
		}
	    }
	} else {
	    if(j0==0x80) return x+x;	/* inf or NaN */
	    else return x;		/* x is integral */
	}
	SET_FLOAT_WORD(x,i0);
	return x;
}
