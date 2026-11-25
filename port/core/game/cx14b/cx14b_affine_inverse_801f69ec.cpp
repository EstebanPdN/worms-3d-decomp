#include "w3d_ptr.h"
#line 1 "cx14b_affine_inverse_801f69ec.cpp"

// PPC32 matrices contain sixteen four-byte floats. Names and affine interpretation are inferred.
struct Matrix{float m[16];};
extern "C" const float one_803b16a4[],epsilon_803b16a8[],zero_803b16ac[];
extern "C" int w3d_cx14b_affine_inverse_801f69ec(Ptr32<Matrix> out,Ptr32<const Matrix> a){
 float one=one_803b16a4[0];
 if(__builtin_fabsf(a->m[15]-one)>epsilon_803b16a8[0] || __builtin_fabsf(a->m[3])>epsilon_803b16a8[0] || __builtin_fabsf(a->m[7])>epsilon_803b16a8[0] || __builtin_fabsf(a->m[11])>epsilon_803b16a8[0])return 0x80070057;
 float c0=a->m[5]*a->m[10]-a->m[6]*a->m[9];
 float c1=a->m[4]*a->m[10]-a->m[6]*a->m[8];
 float c2=a->m[4]*a->m[9]-a->m[5]*a->m[8];
 float factor=one/(a->m[0]*c0-a->m[1]*c1+a->m[2]*c2);
 float v0=factor*c0;out->m[0]=v0;
 float v1=-factor*(a->m[1]*a->m[10]-a->m[2]*a->m[9]);out->m[1]=v1;
 float v2=factor*(a->m[1]*a->m[6]-a->m[2]*a->m[5]);out->m[2]=v2;out->m[3]=zero_803b16ac[0];
 float v4=-factor*(a->m[4]*a->m[10]-a->m[6]*a->m[8]);out->m[4]=v4;
 float v5=factor*(a->m[0]*a->m[10]-a->m[2]*a->m[8]);out->m[5]=v5;
 float v6=-factor*(a->m[0]*a->m[6]-a->m[2]*a->m[4]);out->m[6]=v6;out->m[7]=zero_803b16ac[0];
 float v8=factor*(a->m[4]*a->m[9]-a->m[5]*a->m[8]);out->m[8]=v8;
 float v9=-factor*(a->m[0]*a->m[9]-a->m[1]*a->m[8]);out->m[9]=v9;
 float v10=factor*(a->m[0]*a->m[5]-a->m[1]*a->m[4]);out->m[10]=v10;out->m[11]=zero_803b16ac[0];
 out->m[12]=-(a->m[12]*v0+a->m[13]*v4+a->m[14]*v8);
 out->m[13]=-(a->m[12]*v1+a->m[13]*v5+a->m[14]*v9);
 out->m[14]=-(a->m[12]*v2+a->m[13]*v6+a->m[14]*v10);out->m[15]=one;return 0;
}



