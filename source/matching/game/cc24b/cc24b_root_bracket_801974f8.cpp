struct Cc24bPolynomial {float *coefficients; int degree;};
extern "C" float fn_80197244(float,float*,int);
extern "C" float fn_8019727c(float,float,float,float,float,Cc24bPolynomial*);
extern "C" float lbl_804ab6e4;
extern "C" float w3d_cc24b_root_bracket_801974f8(float a,float b,float tolerance,Cc24bPolynomial *p) {

 float cc24bFrameReservation[8]; float *cc24bFrameAddress=cc24bFrameReservation; float fa=fn_80197244(a,p->coefficients,p->degree);
 if(__builtin_fabsf(fa)<lbl_804ab6e4)return a;
 float fb=fn_80197244(b,p->coefficients,p->degree);
 if(__builtin_fabsf(fb)<lbl_804ab6e4)return b;
 return fn_8019727c(a,b,fa,fb,tolerance,p);
}
