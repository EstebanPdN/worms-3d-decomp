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
extern "C" float cx9c_copysignf_802e9e78(float,float);
extern "C" float cx9c_constant_804ac310;
extern "C" float cx9c_constant_804ac314;
extern "C" float cx9c_constant_804ac318;
extern "C" float cx9c_constant_804ac31c;
extern "C" float w3d_cx9c_scalbnf_802e8c1c(float x,int n)
{
	__int32_t k,hx;
	GET_FLOAT_WORD(hx,x);
        k = (hx&0x7f800000)>>23;		/* extract exponent */
        if (k==0) {				/* 0 or subnormal x */
            if ((hx&0x7fffffff)==0) return x; /* +-0 */
	    x *= cx9c_constant_804ac310; 
	    GET_FLOAT_WORD(hx,x);
	    k = ((hx&0x7f800000)>>23) - 25; 
            if (n< -50000) return cx9c_constant_804ac314*x; 	/*underflow*/
	    }
        if (k==0xff) return x+x;		/* NaN or Inf */
        k = k+n; 
        if (k >  0xfe) return cx9c_copysignf_802e9e78(cx9c_constant_804ac318,x)*cx9c_constant_804ac318; /* overflow  */
        if (k > 0) 				/* normal result */
	    {SET_FLOAT_WORD(x,(hx&0x807fffff)|(k<<23)); return x;}
        if (k <= -25) {
            if (n > 50000) 	/* in case integer overflow in n+k */
		return cx9c_copysignf_802e9e78(cx9c_constant_804ac318,x)*cx9c_constant_804ac318;	/*overflow*/
	    else return cx9c_copysignf_802e9e78(cx9c_constant_804ac314,x)*cx9c_constant_804ac314; 	/*underflow*/
      }
        k += 25;				/* subnormal result */
	SET_FLOAT_WORD(x,(hx&0x807fffff)|(k<<23));
        return x*cx9c_constant_804ac31c;
}
