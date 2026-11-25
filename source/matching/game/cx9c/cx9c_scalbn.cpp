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
#define EXTRACT_WORDS(h,l,d) do {Cx9cDouble u;u.value=(d);h=u.parts.msw;l=u.parts.lsw;} while(0)
extern "C" double cx9c_copysign_802e9e20(double,double);
extern "C" double cx9c_constant_804ac2f0;
extern "C" double cx9c_constant_804ac2f8;
extern "C" double cx9c_constant_804ac300;
extern "C" double cx9c_constant_804ac308;
extern "C" double w3d_cx9c_scalbn_802e8a28(double x,int n)
{
	__int32_t  k,hx,lx;
	EXTRACT_WORDS(hx,lx,x);
        k = (hx&0x7ff00000)>>20;		/* extract exponent */
        if (k==0) {				/* 0 or subnormal x */
            if ((lx|(hx&0x7fffffff))==0) return x; /* +-0 */
	    x *= cx9c_constant_804ac2f0; 
	    GET_HIGH_WORD(hx,x);
	    k = ((hx&0x7ff00000)>>20) - 54; 
            if (n< -50000) return cx9c_constant_804ac2f8*x; 	/*underflow*/
	    }
        if (k==0x7ff) return x+x;		/* NaN or Inf */
        k = k+n; 
        if (k >  0x7fe) return cx9c_copysign_802e9e20(cx9c_constant_804ac300,x)*cx9c_constant_804ac300; /* overflow  */
        if (k > 0) 				/* normal result */
	    {SET_HIGH_WORD(x,(hx&0x800fffff)|(k<<20)); return x;}
        if (k <= -54) {
            if (n > 50000) 	/* in case integer overflow in n+k */
		return cx9c_copysign_802e9e20(cx9c_constant_804ac300,x)*cx9c_constant_804ac300;	/*overflow*/
	    else return cx9c_copysign_802e9e20(cx9c_constant_804ac2f8,x)*cx9c_constant_804ac2f8; 	/*underflow*/
      }
        k += 54;				/* subnormal result */
	SET_HIGH_WORD(x,(hx&0x800fffff)|(k<<20));
        return x*cx9c_constant_804ac308;
}
