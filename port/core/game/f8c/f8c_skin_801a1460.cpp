#include "w3d_ptr.h"
#line 1 "f8c_skin_801a1460.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F8cSkinMatrix{float m[16];};
inline bool F8cSkinHasWeight(const float&x){return *(Ptr32<const unsigned int>)&x!=0;}
extern "C" void f8c_skin_801a1460( Ptr32<float> src,int influences, Ptr32<float> weights, Ptr32<unsigned char> indices, Ptr32<Ptr32<F8cSkinMatrix>> matrices,Ptr32<float> dst,int count,int srcStride,int dstStride){
while(count--){ Ptr32<float> end=weights+influences;float y=src[1],x=src[0],z=src[2]; Ptr32<float> m=matrices[*indices]->m;float w0=*weights;float a0=(x*m[0]+y*m[4]+z*m[8]+m[12])*w0;float a1=(x*m[1]+y*m[5]+z*m[9]+m[13])*w0;float a2=(x*m[2]+y*m[6]+z*m[10]+m[14])*w0;
++weights;++indices;
while(weights!=end){if(*(Ptr32<const unsigned int>)weights){Ptr32<float> m=matrices[*indices]->m;float w=*weights;a0=w*(x*m[0]+y*m[4]+z*m[8]+m[12])+a0;a1=w*(x*m[1]+y*m[5]+z*m[9]+m[13])+a1;a2=w*(x*m[2]+y*m[6]+z*m[10]+m[14])+a2;}++weights;++indices;}
dst[0]=a0;dst[1]=a1;dst[2]=a2;
src=(Ptr32<float>)((Ptr32<char>)src+srcStride);dst=(Ptr32<float>)((Ptr32<char>)dst+dstStride);
}}



