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
extern "C" float cx9c_zero_804ac2e8;
extern "C" float cx9c_cos_kernel_802e9498(float,float);
extern "C" float cx9c_sin_kernel_802e9580(float,float,int);
extern "C" int cx9c_reduce_802e9ad0(float,volatile float *);
extern "C" float w3d_cx9c_sinf_802e88ac(float x)
{
	volatile float y[2];float z=cx9c_zero_804ac2e8;
	__int32_t n,ix;

	GET_FLOAT_WORD(ix,x);

    /* |x| ~< pi/4 */
	ix &= 0x7fffffff;
	if(ix <= 0x3f490fd8) return cx9c_sin_kernel_802e9580(x,z,0);

    /* sin(Inf or NaN) is NaN */
	else if (ix>0x7f7fffff) return x-x;

    /* argument reduction needed */
	else {
	    n = cx9c_reduce_802e9ad0(x,y);
	    switch(n&3) {
		case 0: return  cx9c_sin_kernel_802e9580(y[0],y[1],1);
		case 1: return  cx9c_cos_kernel_802e9498(y[0],y[1]);
		case 2: return -cx9c_sin_kernel_802e9580(y[0],y[1],1);
		default:
			return -cx9c_cos_kernel_802e9498(y[0],y[1]);
	    }
	}
}
