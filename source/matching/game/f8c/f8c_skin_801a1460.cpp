// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F8cSkinMatrix{float m[16];};
inline bool F8cSkinHasWeight(const float&x){return *(const unsigned*)&x!=0;}
extern "C" void f8c_skin_801a1460( float*src,int influences, float*weights, unsigned char*indices, F8cSkinMatrix* *matrices,float*dst,int count,int srcStride,int dstStride){
while(count--){ float*end=weights+influences;float y=src[1],x=src[0],z=src[2]; float*m=matrices[*indices]->m;float w0=*weights;float a0=(x*m[0]+y*m[4]+z*m[8]+m[12])*w0;float a1=(x*m[1]+y*m[5]+z*m[9]+m[13])*w0;float a2=(x*m[2]+y*m[6]+z*m[10]+m[14])*w0;
++weights;++indices;
while(weights!=end){if(*(const unsigned*)weights){float*m=matrices[*indices]->m;float w=*weights;a0=w*(x*m[0]+y*m[4]+z*m[8]+m[12])+a0;a1=w*(x*m[1]+y*m[5]+z*m[9]+m[13])+a1;a2=w*(x*m[2]+y*m[6]+z*m[10]+m[14])+a2;}++weights;++indices;}
dst[0]=a0;dst[1]=a1;dst[2]=a2;
src=( float*)(( char*)src+srcStride);dst=(float*)((char*)dst+dstStride);
}}

