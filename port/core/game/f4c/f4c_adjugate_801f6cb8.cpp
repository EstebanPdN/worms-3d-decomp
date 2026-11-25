#include "w3d_ptr.h"
#line 1 "f4c_adjugate_801f6cb8.cpp"
// Matrix and adjugate names are inferred; fields follow original float offsets.
extern "C" float fn_801f7084(float,float,float,float,float,float,float,float,float);
extern "C" Ptr32<float> f4c_adjugate_801f6cb8(Ptr32<float> out,Ptr32<const float> in){
float m0=in[0];
float m1=in[1];
float m2=in[2];
float m3=in[3];
float m4=in[4];
float m5=in[5];
float m6=in[6];
float m7=in[7];
float m8=in[8];
float m9=in[9];
float m10=in[10];
float m11=in[11];
float m12=in[12];
float m13=in[13];
float m14=in[14];
float m15=in[15];
out[0]=fn_801f7084(m5,m9,m13,m6,m10,m14,m7,m11,m15);
out[4]=-fn_801f7084(m4,m8,m12,m6,m10,m14,m7,m11,m15);
out[8]=fn_801f7084(m4,m8,m12,m5,m9,m13,m7,m11,m15);
out[12]=-fn_801f7084(m4,m8,m12,m5,m9,m13,m6,m10,m14);
out[1]=-fn_801f7084(m1,m9,m13,m2,m10,m14,m3,m11,m15);
out[5]=fn_801f7084(m0,m8,m12,m2,m10,m14,m3,m11,m15);
out[9]=-fn_801f7084(m0,m8,m12,m1,m9,m13,m3,m11,m15);
out[13]=fn_801f7084(m0,m8,m12,m1,m9,m13,m2,m10,m14);
out[2]=fn_801f7084(m1,m5,m13,m2,m6,m14,m3,m7,m15);
out[6]=-fn_801f7084(m0,m4,m12,m2,m6,m14,m3,m7,m15);
out[10]=fn_801f7084(m0,m4,m12,m1,m5,m13,m3,m7,m15);
out[14]=-fn_801f7084(m0,m4,m12,m1,m5,m13,m2,m6,m14);
out[3]=-fn_801f7084(m1,m5,m9,m2,m6,m10,m3,m7,m11);
out[7]=fn_801f7084(m0,m4,m8,m2,m6,m10,m3,m7,m11);
out[11]=-fn_801f7084(m0,m4,m8,m1,m5,m9,m3,m7,m11);
out[15]=fn_801f7084(m0,m4,m8,m1,m5,m9,m2,m6,m10);
return out;
}

