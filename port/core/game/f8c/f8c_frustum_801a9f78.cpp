#include "w3d_ptr.h"
#line 1 "f8c_frustum_801a9f78.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_801f5d2c(Ptr32<float>);struct F8cFrustumMat{float m[16];};struct F8cFrustumPlane{float x,y,z,w;};extern "C" void f8c_frustum_801a9f78(Ptr32<void> unknown,Ptr32<F8cFrustumMat> matrix,Ptr32<F8cFrustumPlane> planes){Ptr32<float> m=(Ptr32<float>)matrix;Ptr32<float> out=(Ptr32<float>)planes;Ptr32<float> r0=m; Ptr32<float> r1=m+4; Ptr32<float> r2=m+8; Ptr32<float> r3=m+12;out[0]=r0[3]+r0[0];out[1]=r1[3]+r1[0];out[2]=r2[3]+r2[0];out[3]=r3[3]+r3[0];out[4]=r0[3]-r0[0];out[5]=r1[3]-r1[0];out[6]=r2[3]-r2[0];out[7]=r3[3]-r3[0];out[8]=r0[3]-r0[1];out[9]=r1[3]-r1[1];out[10]=r2[3]-r2[1];out[11]=r3[3]-r3[1];out[12]=r0[3]+r0[1];out[13]=r1[3]+r1[1];out[14]=r2[3]+r2[1];out[15]=r3[3]+r3[1];out[16]=r0[3]+r0[2];out[17]=r1[3]+r1[2];out[18]=r2[3]+r2[2];out[19]=r3[3]+r3[2];out[20]=r0[3]-r0[2];out[21]=r1[3]-r1[2];out[22]=r2[3]-r2[2];out[23]=r3[3]-r3[2];fn_801f5d2c(out+0);fn_801f5d2c(out+4);fn_801f5d2c(out+8);fn_801f5d2c(out+12);fn_801f5d2c(out+16);fn_801f5d2c(out+20);}


