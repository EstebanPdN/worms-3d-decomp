#include "w3d_ptr.h"
#line 1 "f4c_determinant_801f70b0.cpp"
// Layout, determinant name and cofactor roles inferred from original instructions.
extern "C" float fn_801f7084(float,float,float,float,float,float,float,float,float);
extern "C" float f4c_determinant_801f70b0(Ptr32<const float> p){
float m0=p[0];
float m1=p[1];
float m2=p[2];
float m3=p[3];
float m4=p[4];
float m5=p[5];
float m6=p[6];
float m7=p[7];
float m8=p[8];
float m9=p[9];
float m10=p[10];
float m11=p[11];
float m12=p[12];
float m13=p[13];
float m14=p[14];
float m15=p[15];
float a=fn_801f7084(m5,m9,m13,m6,m10,m14,m7,m11,m15);
float b=fn_801f7084(m4,m8,m12,m6,m10,m14,m7,m11,m15);
float c=fn_801f7084(m4,m8,m12,m5,m9,m13,m7,m11,m15);
float d=fn_801f7084(m4,m8,m12,m5,m9,m13,m6,m10,m14);
return (float)(m2*c+(float)(m0*a-(float)(m1*b)))-(float)(m3*d);
}

