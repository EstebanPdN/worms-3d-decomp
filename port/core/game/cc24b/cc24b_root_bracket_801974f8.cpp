#include "w3d_ptr.h"
#line 1 "cc24b_root_bracket_801974f8.cpp"
struct Cc24bPolynomial {Ptr32<float> coefficients; int degree;};
extern "C" float fn_80197244(float,Ptr32<float>,int);
extern "C" float fn_8019727c(float,float,float,float,float,Ptr32<Cc24bPolynomial>);
extern "C" float lbl_804ab6e4;
extern "C" float w3d_cc24b_root_bracket_801974f8(float a,float b,float tolerance,Ptr32<Cc24bPolynomial> p) {

 float cc24bFrameReservation[8]; Ptr32<float> cc24bFrameAddress=cc24bFrameReservation; float fa=fn_80197244(a,p->coefficients,p->degree);
 if(__builtin_fabsf(fa)<lbl_804ab6e4)return a;
 float fb=fn_80197244(b,p->coefficients,p->degree);
 if(__builtin_fabsf(fb)<lbl_804ab6e4)return b;
 return fn_8019727c(a,b,fa,fb,tolerance,p);
}


